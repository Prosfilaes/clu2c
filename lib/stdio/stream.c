/*
 * stream.c - implementation of the stream cluster
 *
 * Copyright (c) 1992, 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: stream.c,v 2.30 1997/02/05 09:52:54 ushijima Exp $
 */

#include <config.h>
#ifdef MSDOS_TEXT
#   include <fcntl.h>		/* for O_TEXT and O_BINARY */
#endif
#include <config/stat.h>
#include <config/unistd.h>
#include <config/time.h>
#include <ctype.h>

#include <clu2c.h>

#include <clu2c/stream.h>


/*
 * Support for text file formats.
 *
 * In this implementation two kind of formats are supported: (1)
 * MSDOS-like format, in which a newline is encoded in two bytes CR
 * (015 in octal) and LF (012 in octal) in this order, and the ^Z (032
 * in octal) character, called EOF code, is treated as a mark of an
 * end-of-file; and (2) UNIX-like format, in which a newline is
 * encoded in a single LF (012 in octal) and there is no EOF code as
 * in MSDOS-like format exist.
 *
 * For MSDOS-like format, text files are opend in binary mode so that
 * operations in image mode can treat CRLF's and EOF codes correctly.
 */

#ifdef MSDOS_TEXT

#define Setmode(fd, mode)	setmode(fd, mode)

#define READ_MODE	"rb"
#define WRITE_MODE	"wb"
#define APPEND_MODE	"ab"
#define TEXTGETC(c, p)				\
    ((((c) = Getc(p)) == '\r')			\
     ? ((((c) = Getc(p)) == '\n')		\
	? (c)					\
	: (Ungetc((c), (p)), (c) = '\r'))	\
     : (((c) == '\032')				\
	? (Ungetc((c), (p)), (c) = EOF)		\
	: (c)))
#define TEXTPUTC(c, p)		\
    (((c) == '\n')		\
     ? ((Putc('\r', p) == EOF)	\
	? (EOF)			\
	: (Putc(c, p)))		\
     : (Putc(c, p)))

#else				/* not MSDOS_TEXT */

#define Setmode(fd, mode)	0

#define READ_MODE	"r"
#define WRITE_MODE	"w"
#define APPEND_MODE	"a"
#define TEXTGETC(c, p)	((c) = Getc(p))
#define TEXTPUTC(c, p)	Putc(c, p)

#endif				/* not MSDOS_TEXT */


/*
 * Japanized CLU has the string$width operation, which is preferable
 * to the string$size operation in order for the putright and putleft
 * operations to get the number of padding spaces.
 */

#ifdef J10N
#define STRWIDTH(s)	OFstring_Dwidth(s)
#else
#define STRWIDTH(s)	OFstring_Dsize(s)
#endif


/*
 * Prediction of the maximum length of strings returned by the getl
 * and gets operations.  It is just a prediction; longer strings are
 * safely handled.
 */

#define MAXLINE 256


/*
 * Own variables.
 */

static bool WVstream_D_Downinit = FALSE;
static array WVstream_Dstreamlist = NULL;
static stream WVstream_D__primary__input = NULL;
static stream WVstream_D__primary__output = NULL;
static stream WVstream_D__error__output = NULL;

static int OFstream_D_Downinit(void);

/********************************************************************
 *								    *
 *			  Internal functions			    *
 *								    *
 ********************************************************************/


/*-
 * OFstream_D__noimpl
 */

static OFstream_D__noimpl(op)
string op;
{
    /* make a string "stream$OP: not implemented" */
    OFstring_Dconcat(OFstring_D__cs2s("stream$"), op);
    OFstring_Dconcat(retval_area[0], OFstring_D__cs2s(": not implemented"));

    /* make an exception */
    signame = SLFAILURE;
    sigarg_area[0] = retval_area[0];
}


/*-
 * OFstream_D__putprompt
 */

static OFstream_D__putprompt(s, prompt)
stream s;
{
    if (OMstring_Dempty(prompt)) {
	return;
    }
    OFstream_Dputs(s, prompt);
    OFstream_Dflush(s);
}


/*-
 * OFstream_D__mkrbuf
 */

static struct buf *OFstream_D__mkrbuf(fp)
FILE_T *fp;
{
    struct buf *b;

    b = (struct buf *) malloc(sizeof(struct buf));
    b->tag = BUF_READ;
    b->val.read = (struct rbuf *) malloc(sizeof(struct rbuf));
    b->val.read->fp = fp;
    b->val.read->line = 1;
#ifndef STRICT_CLU
    b->val.read->buffered = TRUE;
#endif
    return b;
}


/*-
 * OFstream_D__mkwbuf
 */

static struct buf *OFstream_D__mkwbuf(fp)
FILE_T *fp;
{
    struct buf *b;

    b = (struct buf *) malloc(sizeof(struct buf));
    b->tag = BUF_WRITE;
    b->val.write = (struct wbuf *) malloc(sizeof(struct wbuf));
    b->val.write->fp = fp;
    b->val.write->buffered = TRUE;
    return b;
}


/*-
 * OFstream_D__mktbuf
 */

static struct buf *OFstream_D__mktbuf(ifp, ofp)
FILE_T *ifp;
FILE_T *ofp;
{
    struct buf *b;

    b = (struct buf *) malloc(sizeof(struct buf));
    b->tag = BUF_TTY;
    b->val.tty = (struct tbuf *) malloc(sizeof(struct tbuf));
    b->val.tty->ifp = ifp;
    b->val.tty->ofp = ofp;
    b->val.tty->ibuffered = TRUE;
    b->val.tty->obuffered = TRUE;
    b->val.tty->line = 1;
    b->val.tty->prompt = SLNULL;
    b->val.tty->bol = TRUE;
    return b;
}


/*-
 * OFstream_D__mkistr
 */

static struct buf *OFstream_D__mkistr(chars)
string chars;
{
    struct buf *b;

    b = (struct buf *) malloc(sizeof(struct buf));
    b->tag = BUF_ISTR;
    b->val.istr = (struct sbuf *) malloc(sizeof(struct sbuf));
    b->val.istr->chars = chars;
    b->val.istr->index = 1;
    b->val.istr->line = 1;
    return b;
}


/*-
 * OFstream_D__mkostr
 */

static struct buf *OFstream_D__mkostr()
{
    struct buf *b;

    b = (struct buf *) malloc(sizeof(struct buf));
    b->tag = BUF_OSTR;
    OFarray_Dnew();
    b->val.ostr = (array) retval_area[0];
    return b;
}


/*-
 * OFstream_D__mkclosed
 */

static struct buf *OFstream_D__mkclosed()
{
    struct buf *b;

    b = (struct buf *) malloc(sizeof(struct buf));
    b->tag = BUF_CLOSED;
    b->val.closed = NIL;	/* dummy (no meaning) */
    return b;
}


/*-
 * OFstream_D__cons
 */

static stream OFstream_D__cons(fn, b)
object fn;
struct buf *b;
{
    int low;			/* low bound of list */
    int high;			/* high bound of list */
    int index;
    stream res;

    if (WVstream_D_Downinit == FALSE) {
	OFstream_D_Downinit();
    }
    
    /*
     * Finds the index in the list for the result stream.
     */
    low = OMarray_Dlow(WVstream_Dstreamlist);
    high = OMarray_Dhigh(WVstream_Dstreamlist);
    for (index = low; index <= high; index++) {
	if (OMarray_Dfetch(WVstream_Dstreamlist, index) == NULL) {
	    break;
	}
    }
    if (index > high) {
	OMarray_Daddh(WVstream_Dstreamlist, NULL);
    }

    /*
     * Constructs a stream object.
     */
    res = (stream) malloc(sizeof(struct stream_rep));
    res->index = index;
    res->name = fn;
    OFsequence_Dnew();
    res->scripts = (sequence) retval_area[0];
    res->scripting = FALSE;
    res->buf = b;

    /*
     * Registers the resulting stream to the list.
     */
    OMarray_Dstore(WVstream_Dstreamlist, index, res);

    /*
     * Returns the result;
     */
    return res;
}


#ifdef J10N


/*-
 * OFstream_D__cutblank
 */

static int OFstream_D__cutblank(s)
string s;
{
    int i;
    int j;
    string t;

    OFstring_Dindexc(' ', s);
    i = (int) retval_area[0];
    while (i > 0) {
	j = i + 1;
	while (TRUE) {
	    if (OMstring_Dbounds(s, j) || OMstring_Dfetch(s, j) != ' ') {
		break;
	    }
	    j++;
	}
	OFstring_Dsubstr(s, 1, i - 1);
	t = (string) retval_area[0];
	OFstring_Drest(s, j);
	OFstring_Dconcat(t, retval_area[0]);
	s = (string) retval_area[0];
	OFstring_Dindexc(' ', s);
	i = (int) retval_area[0];
    }
    RETURN1(s);
}


/*-
 * _splitcode = proc(code: string) returns(array[string])
 */

static int OFstream_D__splitcode(code)
string code;
{
    array res;
    int i;
    int j;
    int t1;

    OFarray_Dnew();
    res = (array) retval_area[0];
    OFstream_D__cutblank(code);
    code = (string) retval_area[0];
    OFstring_Dindexc('[', code);
    i = (int) retval_area[0];
    if (i == 0) {
	OMarray_Daddh(res, code);
	RETURN1(res);
    }
    j = OMstring_Dsize(code);
    if (OMstring_Dfetch(code, j) != ']') {
	SIGNAL0(SLBAD_FORMAT);
    }
    OFstring_Dsubstr(code, 1, i - 1);
    OMarray_Daddh(res, retval_area[0]);
    OFstring_Dsubstr(code, i + 1, j - i - 1);
    code = (string) retval_area[0];
    OFstring_Dindexc(',', code);
    i = retval_area[0];
    while (i > 0) {
	OFstring_Dsubstr(code, 1, i - 1);
	OMarray_Daddh(res, retval_area[0]);
	OFstring_Drest(code, i + 1);
	code = (string) retval_area[0];
	OFstring_Dindexc(',', code);
	i = (int) retval_area[0];
    }
    OMarray_Daddh(res, code);
    RETURN1(res);
}


/*-
 * OFstream_D__parsecode
 */

static int OFstream_D__parsecode(code, csys, csys_default)
string code;
struct ja_csys *csys;
int csys_default;
{
    static string noconv = NULL;
    static string eucjp = NULL;
    static string sjis = NULL;
    static string autoconv = NULL;
    static string iso2022jp = NULL;
    static string ascii = NULL;
    static string jisx0201 = NULL;
    static string jisx0208_1978 = NULL;
    static string jisx0208_1983 = NULL;
    static string default_ = NULL;

    array codespec;
    int size;
    string primary;
    string cset1;
    string cset2;

    if (noconv == NULL) {
	noconv = OFstring_D__cs2s("noconv");
	eucjp = OFstring_D__cs2s("euc-japan");
	sjis = OFstring_D__cs2s("sjis");
	autoconv = OFstring_D__cs2s("autoconv");
	iso2022jp = OFstring_D__cs2s("iso-2022-jp");
	ascii = OFstring_D__cs2s("ascii");
	jisx0201 = OFstring_D__cs2s("jisx0201");
	jisx0208_1978 = OFstring_D__cs2s("jisx0208-1978");
	jisx0208_1983 = OFstring_D__cs2s("jisx0208-1983");
	default_ = OFstring_D__cs2s("default");
    }

    csys->csys_number = 0;
    csys->csys_fc_ascii = '\0';
    csys->csys_fc_jis = '\0';

    if (OFstream_D__splitcode(code) == SIG) {
	/* Resignals BAD_FORMAT. */
	return SIG;
    }
    codespec = (array) retval_area[0];
    size = OMarray_Dsize(codespec);
    primary = (string) OMarray_Dbottom(codespec);
    switch (size) {
    case 1:
	if (OMstring_Dequal(primary, noconv)) {
	    /* "noconv" */
	    csys->csys_number = CSYS_NOCONV;
	} else if (OMstring_Dequal(primary, eucjp)) {
	    /* "euc-japan" */
	    csys->csys_number = CSYS_EUCJP;
	} else if (OMstring_Dequal(primary, sjis)) {
	    /* "sjis" */
	    csys->csys_number = CSYS_SJIS;
	} else if (OMstring_Dequal(primary, autoconv)) {
	    /* "autoconv" */
	    csys->csys_number = CSYS_AUTOCONV;
	} else if (OMstring_Dequal(primary, iso2022jp)) {
	    /* "iso-2022-jp" */
	    csys->csys_number = CSYS_ISO2022JP;
	    csys->csys_fc_ascii = FC_ASCII;
	    csys->csys_fc_jis = FC_JISX0208_83;
	} else if (OMstring_Dequal(primary, default_)) {
	    /* default coding system */
	    csys->csys_number = csys_default;
	    if (csys_default == CSYS_ISO2022JP) {
		csys->csys_fc_ascii = FC_ASCII;
		csys->csys_fc_jis = FC_JISX0208_83;
	    }
	} else {
	    SIGNAL0(SLBAD_FORMAT);
	}
	break;
    case 3:
	/* Signals BAD_FORMAT unless PRIMARY is "iso-2022-jp". */
	if (!OMstring_Dequal(primary, iso2022jp)) {
	    SIGNAL0(SLBAD_FORMAT);
	}
	csys->csys_number = CSYS_ISO2022JP;
	/* Examines character sets. */
	cset1 = (string) OMarray_Dfetch(codespec, 2);
	if (OMstring_Dequal(cset1, ascii)) {
	    csys->csys_fc_ascii = FC_ASCII;
	} else if (OMstring_Dequal(cset1, jisx0201)) {
	    csys->csys_fc_ascii = FC_JISX0201;
	} else {
	    SIGNAL0(SLBAD_FORMAT);
	}
	cset2 = (string) OMarray_Dfetch(codespec, 3);
	if (OMstring_Dequal(cset2, jisx0208_1978)) {
	    csys->csys_fc_jis = FC_JISX0208_78;
	} else if (OMstring_Dequal(cset2, jisx0208_1983)) {
	    csys->csys_fc_jis = FC_JISX0208_83;
	} else {
	    SIGNAL0(SLBAD_FORMAT);
	}
	break;
    default:
	SIGNAL0(SLBAD_FORMAT);
    }
    return RET;
}


/*
 * _splitcode_old
 */

static int OFstream_D__splitcode__old(code, delim)
string code;			/* code description */
char_ delim;			/* delimiter */
{
    array res;			/* result */
    int i;

    OFarray_Dnew();
    res = (array) retval_area[0];
    for (i = (OFstring_Dindexc(delim, code), retval_area[0]);
	 i > 0;
	 i = (OFstring_Dindexc(delim, code), retval_area[0]))
    {
	OFstring_Dsubstr(code, 1, i - 1);
	OMarray_Daddh(res, retval_area[0]);
	OFstring_Drest(code, i + 1);
	code = (string) retval_area[0];
    }
    if (!OMstring_Dempty(code)) {
	OMarray_Daddh(res, code);
    }
    RETURN1(res);
}


/*
 * _parsecode_old
 */

static int OFstream_D__parsecode__old(code, csys)
string code;
struct ja_csys *csys;
{
    static string ascii = NULL;
    static string auto_ = NULL;
    static string jis = NULL;
    static string jisx0201 = NULL;
    static string jisx0208 = NULL;
    static string jisx0208_78 = NULL;
    static string jisx0208_83 = NULL;
    static string sjis = NULL;
    static string ujis = NULL;

    array codespec;
    int size;
    int i;
    string c;

    if (ascii == NULL) {
	ascii = OFstring_D__cs2s("ascii");
	auto_ = OFstring_D__cs2s("auto");
	jis = OFstring_D__cs2s("jis");
	jisx0201 = OFstring_D__cs2s("jisx0201");
	jisx0208 = OFstring_D__cs2s("jisx0208");
	jisx0208_78 = OFstring_D__cs2s("jisx0208-1978");
	jisx0208_83 = OFstring_D__cs2s("jisx0208-1983");
	sjis = OFstring_D__cs2s("sjis");
	ujis = OFstring_D__cs2s("ujis");
    }

    csys->csys_fc_jis = FC_JISX0208_83;
    csys->csys_fc_ascii = FC_ASCII;
    csys->csys_number = -1;

    OFstream_D__splitcode__old(code, '/');
    codespec = (array) retval_area[0];
    size = OMarray_Dsize(codespec);
    for (i = 1; i <= size; i++) {
	c = (string) OMarray_Dfetch(codespec, i);
	if (OMstring_Dequal(c, jis)
	    || OMstring_Dequal(c, jisx0208)
	    || OMstring_Dequal(c, jisx0208_83))
	{
	    csys->csys_number = CSYS_ISO2022JP;
	    csys->csys_fc_jis = FC_JISX0208_83;
	} else if (OMstring_Dequal(c, jisx0208_78)) {
	    csys->csys_number = CSYS_ISO2022JP;
	    csys->csys_fc_jis = FC_JISX0208_78;
	} else if (OMstring_Dequal(c, ujis)) {
	    csys->csys_number = CSYS_EUCJP;
	} else if (OMstring_Dequal(c, sjis)) {
	    csys->csys_number = CSYS_SJIS;
	} else if (OMstring_Dequal(c, ascii)) {
	    if (csys->csys_number < 0) {
		csys->csys_number = CSYS_NOCONV;
	    }
	    csys->csys_fc_ascii = FC_ASCII;
	} else if (OMstring_Dequal(c, jisx0201)) {
	    if (csys->csys_number < 0) {
		csys->csys_number = CSYS_NOCONV;
	    }
	    csys->csys_fc_ascii = FC_JISX0201;
	} else if (OMstring_Dequal(c, auto_)) {
	    csys->csys_number = CSYS_AUTOCONV;
	} else {
	    SIGNAL0(SLBAD_FORMAT);
	}
    }
    RETURN0;
}


/*-
 * OFstream_D__unparsecode
 */

static string OFstream_D__unparsecode(csys)
struct ja_csys *csys;
{
    static string noconv = NULL;
    static string eucjp = NULL;
    static string sjis = NULL;
    static string autoconv = NULL;
    static string iso2022jp = NULL;
    static string ascii = NULL;
    static string jisx0201 = NULL;
    static string jisx0208_1978 = NULL;
    static string jisx0208_1983 = NULL;

    string res;
    string cset1;
    string cset2;

    if (noconv == NULL) {
	noconv = OFstring_D__cs2s("noconv");
	eucjp = OFstring_D__cs2s("euc-japan");
	sjis = OFstring_D__cs2s("sjis");
	autoconv = OFstring_D__cs2s("autoconv");
	iso2022jp = OFstring_D__cs2s("iso-2022-jp");
	ascii = OFstring_D__cs2s("ascii");
	jisx0201 = OFstring_D__cs2s("jisx0201");
	jisx0208_1978 = OFstring_D__cs2s("jisx0208-1978");
	jisx0208_1983 = OFstring_D__cs2s("jisx0208-1983");
    }

    switch (csys->csys_number) {
    case CSYS_NOCONV:
	res = noconv;
	break;
    case CSYS_EUCJP:
	res = eucjp;
	break;
    case CSYS_SJIS:
	res = sjis;
	break;
    case CSYS_AUTOCONV:
	res = autoconv;
	break;
    case CSYS_ISO2022JP:
	res = iso2022jp;
	switch (csys->csys_fc_ascii) {
	case FC_ASCII:
	    cset1 = ascii;
	    break;
	case FC_JISX0201:
	    cset1 = jisx0201;
	    break;
	default:
	    cset1 = SLNULL;
	}
	switch (csys->csys_fc_jis) {
	case FC_JISX0208_78:
	    cset2 = jisx0208_1978;
	    break;
	case FC_JISX0208_83:
	    cset2 = jisx0208_1983;
	    break;
	default:
	    cset2 = SLNULL;
	}
	if (!OMstring_Dempty(cset1) && !OMstring_Dempty(cset2)) {
	    OFstring_Dappend(res, '[');
	    res = (string) retval_area[0];
	    OFstring_Dconcat(res, cset1);
	    res = (string) retval_area[0];
	    OFstring_Dappend(res, ',');
	    res = (string) retval_area[0];
	    OFstring_Dconcat(res, cset2);
	    res = (string) retval_area[0];
	    OFstring_Dappend(res, ']');
	    res = (string) retval_area[0];
	}
	break;
    default:
	/* Can't happen */
	res = SLNULL;
    }
    return res;
}


#endif /* J10N */


/*-
 * OFstream_D_Downinit
 */

static int OFstream_D_Downinit()
{
    int stdin_is_tty;		/* whether stdin is a terminal */
    int stdout_is_tty;		/* whether stdout is a terminal */
    int stderr_is_tty;		/* whether stderr is a terminal */
    char *stdin_name;		/* name of the stdin terminal */
    char *stdout_name;		/* name of the stdout terminal */
    char *stderr_name;		/* name of the stderr terminal */
    FILE_T *fp;			/* complementary stream for terminal stream */
    struct buf *pi_buf;		/* primary input buffer */
    struct buf *po_buf;		/* primary output buffer */
    struct buf *eo_buf;		/* error output buffer */
    object pi_name;		/* name of primary input (file_name) */
    object po_name;		/* name of primary output (file_name) */
    object eo_name;		/* name of error output (file_name) */

    WVstream_D_Downinit = TRUE;
    OFarray_Dnew();
    WVstream_Dstreamlist = (array) retval_area[0];

    /*
     * Checks if standard input/output is connected to a terminal
     * device.  In case of a terminal, the name of the terminal is
     * also checked.  Note that the result of ttyname(3) is a pointer
     * to the static memory area.
     */
    stdin_is_tty = isatty(Fileno(Stdin));
    stdout_is_tty = isatty(Fileno(Stdout));
    if (stdin_is_tty && stdout_is_tty) {
	char *name = ttyname(Fileno(Stdin));
	stdin_name = (char *) malloc_atomic(strlen(name) + 1);
	strcpy(stdin_name, name);
	stdout_name = ttyname(Fileno(Stdout));
    } else if (stdin_is_tty) {
	stdin_name = ttyname(Fileno(Stdin));
    } else if (stdout_is_tty) {
	stdout_name = ttyname(Fileno(Stdout));
    }

    /*
     * Creates the primary input/output streams.  If both standard
     * input and standard output are connected to the same terminal
     * device, the primary streams shares the same buffer; otherwise a
     * buffer is assigned to each primary stream.
     */
    if (stdin_is_tty
	&& stdout_is_tty
	&& strcmp(stdin_name, stdout_name) == 0)
    {
	pi_buf = OFstream_D__mktbuf(Stdin, Stdout);
	OFfile__name_Dparse(OFstring_D__cs2s(stdin_name));
	pi_name = (object) retval_area[0];
	WVstream_D__primary__input = OFstream_D__cons(pi_name, pi_buf);
	WVstream_D__primary__output = WVstream_D__primary__input;
    } else {
	/*
	 * Creates the primary input stream.
	 */
	if (stdin_is_tty && (fp = Fopen(stdin_name, WRITE_MODE)) != NULL) {
	    pi_buf = OFstream_D__mktbuf(Stdin, fp);
	    OFfile__name_Dparse(OFstring_D__cs2s(stdin_name));
	    pi_name = (object) retval_area[0];
	} else {
	    pi_buf = OFstream_D__mkrbuf(Stdin);
	    pi_name = NULL;
	}
	/*
	 * Creates the primary output stream.
	 */
	WVstream_D__primary__input = OFstream_D__cons(pi_name, pi_buf);
	if (stdout_is_tty && (fp = Fopen(stdout_name, READ_MODE)) != NULL) {
	    po_buf = OFstream_D__mktbuf(fp, Stdout);
	    OFfile__name_Dparse(OFstring_D__cs2s(stdout_name));
	    po_name = (object) retval_area[0];
	} else {
	    po_buf = OFstream_D__mkwbuf(Stdout);
	    po_name = NULL;
	}
	WVstream_D__primary__output = OFstream_D__cons(po_name, po_buf);
    }

    /*
     * Creates the error output stream.
     */
    stderr_is_tty = isatty(Fileno(Stderr));
    if (stderr_is_tty) {
	stderr_name = ttyname(Fileno(Stderr));
    }
    if (stderr_is_tty && (fp = Fopen(stderr_name, READ_MODE)) != NULL) {
	eo_buf = OFstream_D__mktbuf(fp, Stderr);
	OFfile__name_Dparse(OFstring_D__cs2s(stderr_name));
	eo_name = (object) retval_area[0];
    } else {
	eo_buf = OFstream_D__mkwbuf(Stderr);
	eo_name = NULL;
    }
    WVstream_D__error__output = OFstream_D__cons(eo_name, eo_buf);

    return 0;
}


/*-
 * OFstream_D__ttygetc - get one character from terminal without echo back
 */

#ifdef MSDOS

#include <dos.h>

int OFstream_D__ttygetc()
{
    static union REGS reg_in, reg_out;
    reg_in.h.ah = 0x07;
    intdos(&reg_in, &reg_out);
    return ((unsigned char) reg_out.h.al);
}

#endif				/* MSDOS */

#ifdef X68000

#include <doslib.h>

#define OFstream_D__ttygetc()	INKEY()

#endif				/* X68000 */


/************************************************************************
 *									*
 *			      Operations				*
 *									*
 ************************************************************************/


/*-
 * open = proc(fn: file_name, access: string) returns(stream)
 *        signals(not_possible(string))
 */

int OFstream_Dopen(fn, mode)
object fn;			/* file_name */
string mode;
{
    static string read = NULL;
    static string write = NULL;
    static string append = NULL;

    char *c_fn;			/* file name in C string */
    char *c_mode;		/* access mode for Fopen */
    FILE_T *fp;			/* stdio stream */
    bool readable;		/* is opened stream readable? */
    bool writable;		/* is opened stream writable? */
    struct buf *b;

    /*
     * Initilizes string literals unless already initialized.
     */
    if (read == NULL) {
	read = OFstring_D__cs2s("read");
	write = OFstring_D__cs2s("write");
	append = OFstring_D__cs2s("append");
    }

    /* 
     * Gets file name in C's (char *) representation.
     */
    AFfile__name__to__string(fn);
    c_fn = OFstring_D__s2cs((string) retval_area[0]);

    /* 
     * Checks the given access mode (MODE), and gets the corresponding
     * access mode for FOPEN into C_MODE if MODE is a legal access
     * mode; otherwise signals NOT_POSSIBLE("bad access mode").
     */
    readable = FALSE;
    writable = FALSE;
    if (OMstring_Dequal(mode, read)) {
	readable = TRUE;
	c_mode = READ_MODE;
    } else if (OMstring_Dequal(mode, write)) {
	writable = TRUE;
	c_mode = WRITE_MODE;
    } else if (OMstring_Dequal(mode, append)) {
	writable = TRUE;
	c_mode = APPEND_MODE;
    } else {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad access mode"));
    }

    /*
     * Opens the specified file.
     */
    fp = Fopen(c_fn, c_mode);
    if (fp == NULL) {
	syserror();
	return SIG;
    }
    if (isatty(Fileno(fp))) {
	FILE_T *ifp, *ofp;
	Fclose(fp);
	ifp = Fopen(c_fn, READ_MODE);
	ofp = Fopen(c_fn, WRITE_MODE);
	if (ifp == NULL || ofp == NULL) {
	    syserror();
	    return SIG;
	}
	b = OFstream_D__mktbuf(ifp, ofp);
    } else if (readable) {
	b = OFstream_D__mkrbuf(fp);
    } else if (writable) {
	b = OFstream_D__mkwbuf(fp);
    }
    RETURN1(OFstream_D__cons(fn, b));
}


/*-
 * primary_input = proc() returns(stream)
 */

int OFstream_Dprimary__input()
{
    if (WVstream_D_Downinit == FALSE) {
	OFstream_D_Downinit();
    }
    RETURN1(WVstream_D__primary__input);
}


/*-
 * primary_output = proc() returns(stream)
 */

int OFstream_Dprimary__output()
{
    if (WVstream_D_Downinit == FALSE) {
	OFstream_D_Downinit();
    }
    RETURN1(WVstream_D__primary__output);
}


/*-
 * error_output = proc() returns(stream)
 */

int OFstream_Derror__output()
{
    if (WVstream_D_Downinit == FALSE) {
	OFstream_D_Downinit();
    }
    RETURN1(WVstream_D__error__output);
}


/*-
 * can_read = proc(st: stream) returns(bool)
 */

int OFstream_Dcan__read(s)
stream s;
{
    switch (s->buf->tag) {
    case BUF_WRITE:
    case BUF_OSTR:
    case BUF_CLOSED:
	RETURN1(FALSE);
    default:
	RETURN1(TRUE);
    }
}


/*-
 * can_write = proc(st: stream) returns(bool)
 */

int OFstream_Dcan__write(s)
stream s;
{
    switch (s->buf->tag) {
    case BUF_READ:
    case BUF_ISTR:
    case BUF_CLOSED:
	RETURN1(FALSE);
    default:
	RETURN1(TRUE);
    }
}


/*-
 * getc = proc(st: stream) returns(char)
 *        signals(end_of_file, not_possible(string))
 */

int OFstream_Dgetc(s)
stream s;
{
    int c;
    
    switch (s->buf->tag) {
	FILE_T *fp;
	struct rbuf *rb;
	struct tbuf *tb;
	struct sbuf *sb;

    case BUF_READ:
	rb = s->buf->val.read;
	fp = rb->fp;
	TEXTGETC(c, fp);
	if (c == EOF) {
	    if (Ferror(fp)) {
		syserror();
		return SIG;
	    } else {
		SIGNAL0(SLEND_OF_FILE);
	    }
	}
	if (c == '\n') {
	    rb->line++;
	}
	break;

    case BUF_TTY:
	tb = s->buf->val.tty;
	if (tb->bol && !OMstring_Dempty(tb->prompt)) {
	    OFstream_D__putprompt(s, tb->prompt);
	}
	fp = tb->ifp;
	TEXTGETC(c, fp);
	if (c == EOF) {
	    if (Ferror(fp)) {
		syserror();
		return SIG;
	    } else {
		SIGNAL0(SLEND_OF_FILE);
	    }
	}
	if (c == '\n') {
	    tb->line++;
	    tb->bol = TRUE;
	} else {
	    tb->bol = FALSE;
	}
	break;

    case BUF_ISTR:
	sb = s->buf->val.istr;
	if (OFstring_Dfetch(sb->chars, sb->index) == SIG) {
	    /* Exception is assumed to be "bounds" */
	    SIGNAL0(SLEND_OF_FILE);
	} else {
	    c = (int) retval_area[0];
	    sb->index++;
	}
	if (c == '\n') {
	    sb->line++;
	}
	break;

    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this stream"));

    }

    if (s->scripting) {
	/*【scripting の処理】 */
    }

    RETURN1(c);
}


/*-
 * peekc = proc(st: stream) returns(char)
 *         signals(end_of_file, not_possible(string))
 */

int OFstream_Dpeekc(s)
stream s;
{
    int c;

    if (OFstream_Dgetc(s) == SIG) {
	return SIG;
    }
    c = retval_area[0];

    switch (s->buf->tag) {
    case BUF_READ:
	Ungetc(c, s->buf->val.read->fp);
	if (c == '\n')
	    --s->buf->val.read->line;
	break;
    case BUF_TTY:
	Ungetc(c, s->buf->val.tty->ifp);
	s->buf->val.tty->bol = FALSE;
	if (c == '\n')
	    --s->buf->val.tty->line;
	break;
    case BUF_ISTR:
	--s->buf->val.istr->index;
	if (c == '\n')
	    --s->buf->val.istr->line;
	break;
    }
    RETURN1(c);
}


/*-
 * empty = proc(st: stream) returns(bool) signals(not_possible(string))
 */

int OFstream_Dempty(s)
stream s;
{
    if (OFstream_Dpeekc(s) == SIG) {
	if (OMstring_Dequal(signame, SLEND_OF_FILE)) {
	    RETURN1(TRUE);
	} else {
	    /* Resignals NOT_POSSIBLE. */
	    return SIG;
	}
    }
    RETURN1(FALSE);
}


/*-
 * putc = proc(st: stream, c: char) signals(not_possible(string))
 */

int OFstream_Dputc(s, c)
stream s;
char_ c;
{
    switch (s->buf->tag) {
    case BUF_WRITE:
	if (TEXTPUTC(c, s->buf->val.write->fp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_TTY:
	if (TEXTPUTC(c, s->buf->val.tty->ofp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_OSTR:
	OFarray_Daddh(s->buf->val.ostr, c);
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot write to this stream"));
    }
    RETURN0;
}


/*-
 * putc_image = proc(st: stream, c: char) signals(not_possible(string))
 */

int OFstream_Dputc__image(s, c)
stream s;
char_ c;
{
    switch (s->buf->tag) {
    case BUF_WRITE:
	if (Putc(c, s->buf->val.write->fp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_TTY:
	if (Putc(c, s->buf->val.tty->ofp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_OSTR:
	OFarray_Daddh(s->buf->val.ostr, c);
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot write to this stream"));
    }
    RETURN0;
}


/*-
 * getc_image = proc(st: stream) returns(char)
 *              signals(end_of_file, not_possible(string))
 */

/* X68000/MSDOS only */

int OFstream_Dgetc__image(s)
stream s;
{
#if !defined(X68000) && !defined(MSDOS)
    /* signal failure("stream$getc_image: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("getc_image"));
    return SIG;
#else
    int c;
    FILE_T *fp;
    struct rbuf *rb;
    struct tbuf *tb;
    struct sbuf *sb;

    switch (s->buf->tag) {
    case BUF_READ:
	rb = s->buf->val.read;
	fp = rb->fp;
	c = Getc(fp);
	if (c == EOF && Ferror(fp)) {
	    syserror();
	    return SIG;
	} else if (c == EOF) {
	    SIGNAL0(SLEND_OF_FILE);
	}
	break;
    case BUF_TTY:
	tb = s->buf->val.tty;
	fp = tb->ifp;
	if (tb->bol) {
	    c = OFstream_D__ttygetc();
	} else {
	    c = Getc(fp);
	    if (c == EOF) {
		if (Ferror(fp)) {
		    syserror();
		    return SIG;
		} else {
		    SIGNAL0(SLEND_OF_FILE);
		}
	    }
	    if (c == '\n') {
		tb->line++;
		tb->bol = TRUE;
	    } else {
		tb->bol = FALSE;
	    }
	}
	break;
    case BUF_ISTR:
	sb = s->buf->val.istr;
	if (OFstring_Dfetch(sb->chars, sb->index) == SIG) {
	    /* signame is assumed to be "bounds" */
	    SIGNAL0(SLEND_OF_FILE);
	} else {
	    c = (int) retval_area[0];
	    sb->index++;
	}
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this stream"));
    }
    if (s->scripting) {
	/*【scripting の処理】 */
    }
    RETURN1(c);
#endif
}


/*-
 * get_lineno = proc(st: stream) returns(int) signals(not_possible(string))
 */

int OFstream_Dget__lineno(s)
stream s;
{
    static string no_line_numbers = NULL;

    int lineno;

    switch (s->buf->tag) {
    case BUF_READ:
	lineno = s->buf->val.read->line;
	break;
    case BUF_TTY:
	lineno = s->buf->val.tty->line;
	break;
    case BUF_ISTR:
	lineno = s->buf->val.istr->line;
	break;
    default:
	/* Signals NOT_POSSIBLE("no line numbers"). */
	if (no_line_numbers == NULL) {
	    no_line_numbers = OFstring_D__cs2s("no line numbers");
	}
	SIGNAL1(SLNOT_POSSIBLE, no_line_numbers);
    }
    RETURN1(lineno);
}


/*-
 * set_lineno = proc(st: stream, ln: int) signals(not_possible(string))
 */

int OFstream_Dset__lineno(s, i)
stream s;
int i;
{
    /* 
     * This operation is simply ignored.
     */
    RETURN0;
}


/*-
 * reset = proc(st: stream) signals(not_possible(string))
 */

int OFstream_Dreset(s)
stream s;
{
    FILE_T *fp;
    struct rbuf *rb;
    struct sbuf *sb;

    switch (s->buf->tag) {
    case BUF_READ:
	rb = s->buf->val.read;
	fp = rb->fp;
	if (Fseek(fp, 0L, 0) == -1) {
	    syserror();
	    return SIG;
	}
	Clearerr(fp);
	rb->line = 1;
	break;
    case BUF_WRITE:
	fp = s->buf->val.write->fp;
	if (Fseek(fp, 0L, 0) == -1) {
	    syserror();
	    return SIG;
	}
	Clearerr(fp);
	break;
    case BUF_TTY:
	Clearerr(s->buf->val.tty->ifp);
	Clearerr(s->buf->val.tty->ofp);
	break;
    case BUF_ISTR:
	sb = s->buf->val.istr;
	sb->index = 1;
	sb->line = 1;
	break;
    case BUF_OSTR:
	OFarray_Dtrim(s->buf->val.ostr, 1, 0);
	break;
    default:
	break;
    }
    RETURN0;
}


/*-
 * flush = proc(st: stream) signals(not_possible(string))
 */

int OFstream_Dflush(s)
stream s;
{
    switch (s->buf->tag) {
    case BUF_WRITE:
	if (Fflush(s->buf->val.write->fp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_TTY:
	if (Fflush(s->buf->val.tty->ofp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    default:
	break;
    }
    RETURN0;
}


/*-
 * get_line_length = proc(st: stream) returns(int) signals(no_limit)
 */

/* tentative version */

int OFstream_Dget__line__length(s)
stream s;
{
    int res;

    switch (s->buf->tag) {
    case BUF_TTY:
	res = 80;		/* tentative result */
	break;
    default:
	SIGNAL0(SLNO_LIMIT);
    }
    RETURN1(res);
}


/*-
 * get_page_length = proc(st: stream) returns(int) signals(no_limit)
 */

/* tentative version */

int OFstream_Dget__page__length(s)
stream s;
{
    int res;

    switch (s->buf->tag) {
    case BUF_TTY:
	res = 24;		/* tentative result */
	break;
    default:
	SIGNAL0(SLNO_LIMIT);
    }
    RETURN1(res);
}


/*-
 * get_date = proc(st: stream) returns(date) signals(not_possible(string))
 */

int OFstream_Dget__date(s)
stream s;
{
    static string cannot_get_date = NULL;

    struct stat status;
    struct tm *time;
    int fd;

    switch (s->buf->tag) {
    case BUF_READ:
	fd = Fileno(s->buf->val.read->fp);
	break;
    case BUF_WRITE:
	fd = Fileno(s->buf->val.write->fp);
	break;
    default:
	/* Signals NOT_POSSIBLE("cannot get date"). */
	if (cannot_get_date == NULL) {
	    cannot_get_date = OFstring_D__cs2s("cannot get date");
	}
	SIGNAL1(SLNOT_POSSIBLE, cannot_get_date);
    }

    if (fstat(fd, &status) != 0) {
	syserror();
	return SIG;
    }
    time = localtime(&(status.st_mtime));

    if (OFdate_Dcreate(time->tm_mday, time->tm_mon + 1, time->tm_year + 1900,
		     time->tm_hour, time->tm_min, time->tm_sec) == SIG) {
	out_handler();
	return SIG;
    }

    /* retval_area[0] is return value of date$create */
    return RET;
}


/*-
 * set_date = proc(st: stream, new_date: date) signals(not_possible(string))
 */

int OFstream_Dset__date(s, d)
stream s;
object d;			/* date */
{
    static string cannot_set_date = NULL;

    if (cannot_set_date == NULL) {
	cannot_set_date = OFstring_D__cs2s("cannot set date");
    }
    SIGNAL1(SLNOT_POSSIBLE, cannot_set_date);
}


/*-
 * get_name = proc(st: stream) returns(file_name) signals(not_possible(string))
 */

int OFstream_Dget__name(s)
stream s;
{
    static string no_name_for_this_stream = NULL;
    
    if (s->name == NULL) {
	if (no_name_for_this_stream == NULL) {
	    no_name_for_this_stream
		= OFstring_D__cs2s("no name for this stream");
	}
	SIGNAL1(SLNOT_POSSIBLE, no_name_for_this_stream);
    }
    RETURN1(s->name);
}


/*-
 * close = proc(st: stream) signals(not_possible(string))
 */

int OFstream_Dclose(s)
stream s;
{
    switch (s->buf->tag) {
    case BUF_READ:
	if (Fclose(s->buf->val.read->fp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_WRITE:
	if (Fclose(s->buf->val.write->fp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_TTY:
	if (Fclose(s->buf->val.tty->ifp) == EOF) {
	    syserror();
	    return SIG;
	}
	if (Fclose(s->buf->val.tty->ofp) == EOF) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_ISTR:
    case BUF_OSTR:
	break;
    case BUF_CLOSED:
	RETURN0;
    }
    s->buf = OFstream_D__mkclosed();
    OFsequence_Dnew();
    s->scripts = (sequence) retval_area[0];
    s->scripting = FALSE;
    OMarray_Dstore(WVstream_Dstreamlist, s->index, NULL);
    RETURN0;
}


/*-
 * abort = proc(st: stream)
 */

int OFstream_Dabort(s)
stream s;
{
    if (OFstream_Dclose(s) == SIG) {
	s->buf = OFstream_D__mkclosed();
	OFsequence_Dnew();
	s->scripts = (sequence) retval_area[0];
	s->scripting = FALSE;
    }
    OMarray_Dstore(WVstream_Dstreamlist, s->index, NULL);
    RETURN0;
}


/*-
 * is_closed = proc(st: stream) returns(bool)
 */

int OFstream_Dis__closed(s)
stream s;
{
    RETURN1(s->buf->tag == BUF_CLOSED);
}


/*-
 * is_terminal = proc(st: stream) returns(bool)
 */

int OFstream_Dis__terminal(s)
stream s;
{
    RETURN1(s->buf->tag == BUF_TTY);
}


/*-
 * getl = proc(st: stream) returns(string)
 *        signals(end_of_file, not_possible(string))
 */

int OFstream_Dgetl(s)
stream s;
{
    static int uninit = TRUE;
    static array line;
    int c;
    FILE_T *fp;
    struct rbuf *rb;
    struct tbuf *tb;
    struct sbuf *sb;
    string chars;

    /* 
     * Signals END_OF_FILE if S is empty.  It is only here that this
     * operation signals the exception.
     */
    if (OFstream_Dempty(s) == SIG) {
	/* Resignals NOT_POSSIBLE. */
	return SIG;
    }
    if (retval_area[0]) {
	SIGNAL0(SLEND_OF_FILE);
    }

    /*
     * Creates the buffer for a resulting string unless already
     * created, and initializes it.
     */
    if (uninit) {
	OFarray_Dpredict(1, MAXLINE);
	line = (array) retval_area[0];
	uninit = FALSE;
    }
    OFarray_Dtrim(line, 1, 0);

    /*
     * Case analysys on the type of S.
     */
    switch (s->buf->tag) {
    case BUF_READ:
	rb = s->buf->val.read;
	fp = rb->fp;
	while (TEXTGETC(c, fp) != EOF) {
	    if (c == '\n') {
		break;
	    }
	    OFarray_Daddh(line, c);
	}
	if (c == EOF && Ferror(fp)) {
	    syserror();
	    return SIG;
	}
	rb->line++;
	break;
    case BUF_TTY:
	tb = s->buf->val.tty;
	fp = tb->ifp;
	if (tb->bol && !OMstring_Dempty(tb->prompt)) {
	    OFstream_D__putprompt(s, tb->prompt);
	}
	while (TEXTGETC(c, fp) != EOF) {
	    if (c == '\n') {
		break;
	    }
	    OFarray_Daddh(line, c);
	}
	if (c == EOF && Ferror(fp)) {
	    syserror();
	    return SIG;
	}
	tb->line++;
	tb->bol = TRUE;
	break;
    case BUF_ISTR:
	sb = s->buf->val.istr;
	chars = sb->chars;
	while (OFstring_Dfetch(chars, sb->index) != SIG) {
	    c = retval_area[0];
	    sb->index++;
	    if (c == '\n') {
		break;
	    }
	    OFarray_Daddh(line, c);
	}
	sb->line++;
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this stream"));
    }

    /*
     * Now the result is in LINE, in any case.
     */
    OFstring_Dac2s(line);
    return RET;
}


/*-
 * putl = proc(st: stream, line: string) signals(not_possible(string))
 */

int OFstream_Dputl(s, line)
stream s;
string line;
{
    if (OFstream_Dputs(s, line) == SIG) {
	/* Resignals NOT_POSSIBLE. */
	return SIG;
    }
    if (OFstream_Dputc(s, '\n') == SIG) {
	/* Resignals NOT_POSSIBLE. */
	return SIG;
    }
    RETURN0;
}


/*-
 * gets = proc(st: stream, term: string) returns(string)
 *        signals(end_of_file, not_possible(string))
 */

int OFstream_Dgets(s, term)
stream s;
string term;
{
    static int uninit = TRUE;
    static array line;
    int c;
    FILE_T *fp;
    struct rbuf *rb;
    struct tbuf *tb;
    struct sbuf *sb;
    string chars;

    /* 
     * Signals END_OF_FILE if S is empty.  It is only here that this
     * operation signals the exception.
     */
    if (OFstream_Dempty(s) == SIG) {
	/* Resignals NOT_POSSIBLE. */
	return SIG;
    }
    if (retval_area[0]) {
	SIGNAL0(SLEND_OF_FILE);
    }

    /*
     * Creates the buffer for a resulting string unless already
     * created, and initializes it.
     */
    if (uninit) {
	OFarray_Dpredict(1, MAXLINE);
	line = (array) retval_area[0];
	uninit = FALSE;
    }
    OFarray_Dtrim(line, 1, 0);

    /*
     * Case analysys on the type of S.
     */
    switch (s->buf->tag) {
    case BUF_READ:
	rb = s->buf->val.read;
	fp = rb->fp;
	while (TEXTGETC(c, fp) != EOF) {
	    OFstring_Dindexc(c, term);
	    if (retval_area[0] > 0) {
		Ungetc(c, fp);
		break;
	    }
	    if (c == '\n') {
		rb->line++;
	    }
	    OFarray_Daddh(line, c);
	}
	if (c == EOF && Ferror(fp)) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_TTY:
	tb = s->buf->val.tty;
	fp = tb->ifp;
	if (tb->bol && !OMstring_Dempty(tb->prompt)) {
	    OFstream_D__putprompt(s, tb->prompt);
	}
	while (TEXTGETC(c, fp) != EOF) {
	    OFstring_Dindexc(c, term);
	    if (retval_area[0] > 0) {
		Ungetc(c, fp);
		break;
	    }
	    if (c == '\n') {
		tb->line++;
	    }
	    OFarray_Daddh(line, c);
	}
	if (c == EOF && Ferror(fp)) {
	    syserror();
	    return SIG;
	} else if (c == '\n') {
	    tb->bol = TRUE;
	} else {
	    tb->bol = FALSE;
	}
	break;
    case BUF_ISTR:
	sb = s->buf->val.istr;
	chars = sb->chars;
	while (OFstring_Dfetch(chars, sb->index) != SIG) {
	    c = retval_area[0];
	    OFstring_Dindexc(c, term);
	    if (retval_area[0] > 0) {
		break;
	    }
	    if (c == '\n') {
		sb->line++;
	    }
	    sb->index++;
	    OFarray_Daddh(line, c);
	}
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this stream"));
    }

    /*
     * Now the result is in LINE, in any case.
     */
    OFstring_Dac2s(line);
    return RET;
}


/*-
 * gets_image = proc(st: stream, term: string) returns(string)
 */

/* X68000/MSDOS only */

int OFstream_Dgets__image(s, term)
stream s;
string term;
{
#if !defined(X68000) && !defined(MSDOS)
    /* Signals FAILURE("stream$gets_image: not implemented"). */
    OFstream_D__noimpl(OFstring_D__cs2s("gets_image"));
    return SIG;
#else
    static int uninit = TRUE;
    static array line;
    int c;
    FILE_T *fp;
    struct rbuf *rb;
    struct tbuf *tb;
    struct sbuf *sb;
    string chars;

    /* 
     * Signals END_OF_FILE if S is empty.  It is only here that this
     * operation signals the exception.
     */
    if (OFstream_Dempty(s) == SIG) {
	/* Resignals NOT_POSSIBLE. */
	return SIG;
    }
    if (retval_area[0]) {
	SIGNAL0(SLEND_OF_FILE);
    }

    /*
     * Creates the buffer for a resulting string unless already
     * created, and initializes it.
     */
    if (uninit) {
	OFarray_Dpredict(1, MAXLINE);
	line = (array) retval_area[0];
	uninit = FALSE;
    }
    OFarray_Dtrim(line, 1, 0);

    /*
     * Case analysys on the type of S.
     */
    switch (s->buf->tag) {
    case BUF_READ:
	rb = s->buf->val.read;
	fp = rb->fp;
	while ((c = Getc(fp)) != EOF) {
	    OFstring_Dindexc(c, term);
	    if (retval_area[0] > 0) {
		Ungetc(c, fp);
		break;
	    }
	    if (c == '\n') {
		rb->line++;
	    }
	    OFarray_Daddh(line, c);
	}
	if (c == EOF && Ferror(fp)) {
	    syserror();
	    return SIG;
	}
	break;
    case BUF_TTY:
	tb = s->buf->val.tty;
	fp = tb->ifp;
	while (TRUE) {
	    if (tb->bol) {
		c = OFstream_D__ttygetc();
	    } else {
		c = Getc(fp);
	    }
	    if (c == EOF) {
		break;
	    }
	    OFstring_Dindexc(c, term);
	    if (retval_area[0] > 0) {
		Ungetc(c, fp);
		break;
	    }
	    if (c == '\n') {
		tb->line++;
		tb->bol = TRUE;
	    }
	    OFarray_Daddh(line, c);
	}
	if (c == EOF && Ferror(fp)) {
	    syserror();
	    return SIG;
	} else if (c == '\n') {
	    tb->bol = TRUE;
	} else {
	    tb->bol = FALSE;
	}
	break;
    case BUF_ISTR:
	sb = s->buf->val.istr;
	chars = sb->chars;
	while (OFstring_Dfetch(chars, sb->index) != SIG) {
	    c = retval_area[0];
	    OFstring_Dindexc(c, term);
	    if (retval_area[0] > 0) {
		break;
	    }
	    if (retval_area[0] == '\n') {
		sb->line++;
	    }
	    sb->index++;
	    OFarray_Daddh(line, c);
	}
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this stream"));
    }

    /*
     * Now the result is in LINE, in any case.
     */
    OFstring_Dac2s(line);
    return RET;
#endif
}


/*-
 * puts = proc(st: stream, s: string) signals(not_possible(string))
 */

int OFstream_Dputs(s, line)
stream s;
string line;
{
    int sz;
    FILE_T *fp;
    int i;
    array chars;

    sz = OMstring_Dsize(line);
    switch (s->buf->tag) {
    case BUF_WRITE:
	fp = s->buf->val.write->fp;
#ifdef MSDOS_TEXT
	OFstring_Dindexc('\n', line);
	if (retval_area[0] > 0) {
	    for (i = 1; i <= sz; i++) {
		if (TEXTPUTC(OMstring_Dfetch(line, i), fp) == EOF) {
		    syserror();
		    return SIG;
		}
	    }
	    RETURN0;
	}
#endif
#if (CLU2C_CHAR_VERSION == 1 && defined(J10N)) || (CLU2C_CHAR_VERSION == 2 && !defined(J10N))
	for (i = 1; i <= sz; i++) {
	    if (Putc(OMstring_Dfetch(line, i), fp) == EOF) {
		syserror();
		return SIG;
	    }
	}
#else
	if (Fnputs(OMstring_D__chars(line), sz, fp) == EOF) {
	    syserror();
	    return SIG;
	}
#endif
	break;
    case BUF_TTY:
	fp = s->buf->val.tty->ofp;
	for (i = 1; i <= sz; i++) {
	    if (TEXTPUTC(OMstring_Dfetch(line, i), fp) == EOF) {
		syserror();
		return SIG;
	    }
	}
	break;
    case BUF_OSTR:
	chars = s->buf->val.ostr;
	for (i = 1; i <= sz; i++) {
	    OFarray_Daddh(chars, OMstring_Dfetch(line, i));
	}
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot write to this stream"));
    }
    RETURN0;
}


/*-
 * puts_image = proc(st: stream, s: string) signals(not_possible(string))
 */

int OFstream_Dputs__image(s, line)
stream s;
string line;
{
    int sz;
    int i;
    FILE_T *fp;
    array chars;

    sz = OMstring_Dsize(line);
    switch (s->buf->tag) {
    case BUF_WRITE:
	fp = s->buf->val.write->fp;
	for (i = 1; i <= sz; i++) {
	    if (Putc(OMstring_Dfetch(line, i), fp) == EOF) {
		syserror();
		return SIG;
	    }
	}
	break;
    case BUF_TTY:
	fp = s->buf->val.tty->ofp;
	for (i = 1; i <= sz; i++) {
	    if (Putc(OMstring_Dfetch(line, i), fp) == EOF) {
		syserror();
		return SIG;
	    }
	}
	break;
    case BUF_OSTR:
	chars = s->buf->val.ostr;
	for (i = 1; i <= sz; i++) {
	    OFarray_Daddh(chars, OMstring_Dfetch(line, i));
	}
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot write to this stream"));
    }
    RETURN0;
}


/*-
 * putzero = proc(st: stream, s: string, size: int)
 *           signals(not_possible(string), negative_field_width)
 */

int OFstream_Dputzero(output, s, field_width)
stream output;
string s;
int field_width;
{
    int width;			/* width of S */
    int size;
    int i;
    int j;
    int c;

    if (field_width < 0) {
	SIGNAL0(SLNEGATIVE_FIELD_WIDTH);
    }
    OFstring_Dwidth(s);
    width = retval_area[0];
    if (width < field_width) {
	size = OMstring_Dsize(s);
	for (i = 1; i <= size; i++) {
	    c = OMstring_Dfetch(s, i);
	    if (c >= 0 && c <= 0x7f && (isdigit(c) || c == '.')) {
		break;
	    }
	    if (OFstream_Dputc(output, c) == SIG) {
		return SIG;
	    }
	}
	for (j = 0; j < field_width - width; j++) {
	    if (OFstream_Dputc(output, '0') == SIG) {
		return SIG;
	    }
	}
	for (; i <= size; i++) {
	    if (OFstream_Dputc(output, OMstring_Dfetch(s, i)) == SIG) {
		return SIG;
	    }
	}	
    } else {
	if (OFstream_Dputs(output, s) == SIG) {
	    return SIG;
	}
    }
    RETURN0;
}


/*-
 * putleft = proc(st: stream, s: string, size: int)
 *           signals(not_possible(string), negative_field_width)
 */

int OFstream_Dputleft(st, s, size)
stream st;
string s;
int size;
{
    int n;

    if (size < 0) {
	SIGNAL0(SLNEGATIVE_FIELD_WIDTH);
    }
    if (OFstream_Dputs(st, s) == SIG) {
	/* Resignals NOT_POSSIBLE. */
	return SIG;
    }
    STRWIDTH(s);
    n = size - (int) retval_area[0];
    if (n > 0) {
	if (OFstream_Dputspace(st, n) == SIG) {
	    /* Resignals NOT_POSSIBLE. */
	    return SIG;
	}
    }
    RETURN0;
}


/*-
 * putright = proc(st: stream, s: string, size: int)
 *            signals(not_possible(string), negative_field_width)
 */

int OFstream_Dputright(st, s, size)
stream st;
string s;
int size;
{
    int n;

    if (size < 0) {
	SIGNAL0(SLNEGATIVE_FIELD_WIDTH);
    }
    STRWIDTH(s);
    n = size - (int) retval_area[0];
    if (n > 0) {
	if (OFstream_Dputspace(st, n) == SIG) {
	    /* Resignals NOT_POSSIBLE. */
	    return SIG;
	}
    }
    if (OFstream_Dputs(st, s) == SIG) {
	/* Resignals NOT_POSSIBLE. */
	return SIG;
    }
    RETURN0;
}


/*-
 * putspace = proc(st: stream, len: int)
 *            signals(not_possible(string), negative_field_width)
 */

int OFstream_Dputspace(st, len)
stream st;
int len;
{
    int i;

    if (len < 0) {
	SIGNAL0(SLNEGATIVE_FIELD_WIDTH);
    }
    for (i = 0; i < len; i++) {
	if (OFstream_Dputc(st, ' ') == SIG) {
	    /* Resignals NOT_POSSSIBLE. */
	    return SIG;
	}
    }
    RETURN0;
}


/*-
 * set_output_buffered = proc(st: stream, flag: bool)
 */

int OFstream_Dset__output__buffered(st, flag)
stream st;
bool flag;
{
    struct wbuf *wb;
    struct tbuf *tb;

    switch (st->buf->tag) {
    case BUF_WRITE:
	wb = st->buf->val.write;
	if (flag && !wb->buffered) {
	    if (Setvbuf(wb->fp, NULL, IOFBF, 0) != 0) {
		syserror();
		return SIG;
	    }
	} else if (!flag && wb->buffered) {
	    if (Fflush(wb->fp) == EOF) {
		syserror();
		return SIG;
	    }
	    if (Setvbuf(wb->fp, NULL, IONBF, 0) != 0) {
		syserror();
		return SIG;
	    }
	}
	wb->buffered = flag;
	break;
    case BUF_TTY:
	tb = st->buf->val.tty;
	if (flag && !tb->obuffered) {
	    if (Setvbuf(tb->ofp, NULL, IOLBF, 0) != 0) {
		syserror();
		return SIG;
	    }
	} else if (!flag && tb->obuffered) {
	    if (Fflush(tb->ofp) == EOF) {
		syserror();
		return SIG;
	    }
	    if (Setvbuf(tb->ofp, NULL, IONBF, 0) != 0) {
		syserror();
		return SIG;
	    }
	}
	tb->obuffered = flag;
	break;
    case BUF_OSTR:
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("output is always buffered"));
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot write to this stream"));
    }
    RETURN0;
}


/*-
 * get_output_buffered = proc(st: stream) returns(bool)
 */

int OFstream_Dget__output__buffered(st)
stream st;
{
    bool res;

    switch (st->buf->tag) {
    case BUF_WRITE:
	res = st->buf->val.write->buffered;
	break;
    case BUF_TTY:
	res = st->buf->val.tty->obuffered;
	break;
    case BUF_OSTR:
	res = TRUE;
	break;
    default:
	res = FALSE;
	break;
    }
    RETURN1(res);
}


/*-
 * equal = proc(x, y: stream) returns(bool)
 */

int OFstream_Dequal(s1, s2)
stream s1;
stream s2;
{
    RETURN1(s1 == s2);
}


/*-
 * similar = proc(x, y: stream) returns(bool)
 */

int OFstream_Dsimilar(s1, s2)
stream s1;
stream s2;
{
    RETURN1(s1 == s2);
}


/*-
 * copy = proc(st: stream) returns(stream)
 */

int OFstream_Dcopy(s)
stream s;
{
    RETURN1(s);
}


/**************
 * string I/O *
 **************/


/*-
 * create_input = proc(s: string) returns(stream)
 */

int OFstream_Dcreate__input(s)
string s;
{
    RETURN1(OFstream_D__cons(NULL, OFstream_D__mkistr(s)));
}


/*-
 * create_output = proc() returns(stream)
 */

int OFstream_Dcreate__output()
{
    RETURN1(OFstream_D__cons(NULL, OFstream_D__mkostr()));
}


/*-
 * get_contents = proc(st: stream) returns(string)
 *                                 signals(not_possible(string))
 */

int OFstream_Dget__contents(st)
stream st;
{
    switch (st->buf->tag) {
    case BUF_OSTR:
	OFstring_Dac2s(st->buf->val.ostr);
	return RET;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("not a string output stream"));
    }
}


/****************
 * terminal I/O *
 ****************/


/*-
 * getbuf = proc(st: stream, term: string) returns(string)
 *          signals(not_possible(string), end_of_file)
 */

/* stub version */

int OFstream_Dgetbuf(s)
stream s;
{
    /* signal failure("stream$getbuf: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("getbuf"));
    return SIG;
}


/*-
 * get_prompt = proc(st: stream) returns(string)
 */

int OFstream_Dget__prompt(st)
stream st;
{
    switch (st->buf->tag) {
    case BUF_TTY:
	RETURN1(st->buf->val.tty->prompt);
    default:
	RETURN1(SLNULL);
    }
}


/*-
 * set_prompt = proc(st: stream, prompt: string)
 */

int OFstream_Dset__prompt(st, prompt)
stream st;
string prompt;
{
    if (st->buf->tag == BUF_TTY) {
	st->buf->val.tty->prompt = prompt;
    }
    RETURN0;
}


/*-
 * get_input_buffered = proc(st: stream) returns(bool)
 */

int OFstream_Dget__input__buffered(st)
stream st;
{
    bool res;

    switch (st->buf->tag) {
    case BUF_READ:
	res = st->buf->val.read->buffered;
	break;
    case BUF_TTY:
	res = st->buf->val.tty->ibuffered;
	break;
    default:
	res = FALSE;
	break;
    }
    RETURN1(res);
}


/*-
 * set_input_buffered = proc(st: stream, flag: bool)
 */

int OFstream_Dset__input__buffered(st, flag)
stream st;
bool flag;
{
    struct rbuf *rb;
    struct tbuf *tb;

    switch (st->buf->tag) {
    case BUF_READ:
	rb = st->buf->val.read;
#ifdef STRICT_CLU
	if (flag == FALSE) {
	    SIGNAL1(SLNOT_POSSIBLE,
		    OFstring_D__cs2s("input is always buffered"));
	}
#else  /* not STRICT_CLU */
	if (flag && !rb->buffered) {
	    if (Setvbuf(rb->fp, NULL, IOFBF, 0) != 0) {
		syserror();
		return SIG;
	    }
	} else if (!flag && rb->buffered) {
	    if (Setvbuf(rb->fp, NULL, IONBF, 0) != 0) {
		syserror();
		return SIG;
	    }
	}
	rb->buffered = flag;
#endif /* not STRICT_CLU */
	break;
    case BUF_TTY:
	tb = st->buf->val.tty;
	if (flag && !tb->ibuffered) {
	    if (Setvbuf(tb->ifp, NULL, IOLBF, 0) != 0) {
		syserror();
		return SIG;
	    }
	} else if (!flag && tb->ibuffered) {
	    if (Setvbuf(tb->ifp, NULL, IONBF, 0) != 0) {
		syserror();
		return SIG;
	    }
	}
	tb->ibuffered = flag;
	break;
    case BUF_ISTR:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("input is always buffered"));
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this stream"));
    }
    RETURN0;
}


/*************
 * scripting *
 *************/

/*-
 * add_script = proc(st1, st2: stream) signals(script_failed)
 */

/* stub version */

int OFstream_Dadd__script(st1, st2)
stream st1;
stream st2;
{
    /* signal failure("stream$add_script: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("add_script"));
    return SIG;
}


/*-
 * rem_script = proc(st1, st2: stream)
 */

/* stub version */

int OFstream_Drem__script(st1, st2)
stream st1;
stream st2;
{
    /* signal failure("stream$rem_script: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("rem_script"));
    return SIG;
}


/*-
 * unscript = proc(st: stream)
 */

/* stub version */

int OFstream_Dunscript(st)
stream st;
{
    /* signal failure("stream$unscript: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("unscript"));
    return SIG;
}


/*********************************************************************
 * Following operations are not specified in "CLU Reference Manual", *
 * but implemented in MIT CLU.                                       *
 *********************************************************************/


/*-
 * pending = proc(st: stream) returns(bool) signals(not_possible(string))
 */

/* tentative version */

int OFstream_Dpending(st)
stream st;
{
    OFstream_Dempty(st);
    OFbool_Dnot(retval_area[0]);
    RETURN0;
}


/*-
 * display = proc(st: stream, s: string) returns(bool)
 *           signals(not_possible(string))
 */

/* tentative version */

int OFstream_Ddisplay(st, s)
stream st;
string s;
{
    bool res;

    switch (st->buf->tag) {
    case BUF_TTY:
	res = FALSE;
	break;
    case BUF_WRITE:
	res = FALSE;
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot write to this stream"));
    }
    RETURN1(res);
}


/*-
 * modify_display = proc(st: stream, term: string)
 *                  signals(not_possible(string))
 */

/* stub versin */

int OFstream_Dmodify__display(st, term)
stream st;
string term;
{
    /* signal failure("stream$modify_display: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("modify_display"));
    return SIG;
}


/*-
 * get_rescan = proc(st: stream) returns(string)
 */

/* stub version */

int OFstream_Dget__rescan(st)
stream st;
{
    /* signal failure("stream$get_rescan: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("get_rescan"));
    return SIG;
}


/*-
 * set_rescan = proc(st: stream, s: string) signals(not_posssible(string))
 */

/* stub version */

int OFstream_Dset__rescan(st, s)
stream st;
string s;
{
    /* signal failure("stream$set_rescan: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("set_rescan"));
    return SIG;
}


/*-
 * get_eof_flag = proc(st: stream) returns(bool)
 */

/* tentative version */

int OFstream_Dget__eof__flag(st)
stream st;
{
    bool res;

    switch (st->buf->tag) {
    case BUF_READ:
    case BUF_TTY:
	res = TRUE;
	break;
    default:
	res = FALSE;
	break;
    }
    RETURN1(res);
}


/*-
 * set_eof_flag = proc(st: stream, eofok: bool) signals(not_possible(string))
 */

/* tentative version */

int OFstream_Dset__eof__flag(st, eofok)
stream st;
bool eofok;
{
    switch (st->buf->tag) {
    case BUF_TTY:
	break;
    case BUF_READ:
    case BUF_ISTR:
    case BUF_CLOSED:
	if (!eofok) {
	    SIGNAL1(SLNOT_POSSIBLE,
		    OFstring_D__cs2s("cannot disable eof on this stream"));
	}
	break;
    default:
	if (eofok) {
	    SIGNAL1(SLNOT_POSSIBLE,
		    OFstring_D__cs2s("cannot enable eof on this stream"));
	}
	break;
    }
    RETURN0;
}


/*-
 * print = proc(x: stream, ps: pstream)
 */

/* tentative version */

int OFstream_Dprint(x, ps)
stream x;
object ps;			/* pstream */
{
    if (OFpstream_Dtext(ps, OFstring_D__cs2s("(stream)")) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*-
 * _reset = proc()
 */

/* stub version */

int OFstream_D__reset()
{
    /* signal failure("stream$_reset: not implemented") */
    OFstream_D__noimpl(OFstring_D__cs2s("_reset"));
    return SIG;
}


/*-
 * _open_streams = iter() yields(stream)
 */

#define ARSIZE	4
#define LVlow	((*ivarp)[0])
#define LVhigh	((*ivarp)[1])
#define LVi	((*ivarp)[2])
#define LVs	((*ivarp)[3])

int OFstream_D__open__streams(init, ivarp)
bool init;
object **ivarp;
{
    if (init) {
	*ivarp = (object *) malloc(ARSIZE * sizeof(object));
    } else {
	goto resume1;
    }

    LVlow = OMarray_Dlow(WVstream_Dstreamlist);
    LVhigh = OMarray_Dhigh(WVstream_Dstreamlist);
    for (LVi = LVlow; LVi <= LVhigh; LVi++) {
	LVs = OMarray_Dfetch(WVstream_Dstreamlist, LVi);
	if (LVs != NULL) {
	    retval_area[0] = (object) LVs;
	    return YIELD;
	resume1:
	    NO_OPERATION;
	}
    }
    return RET;
}

#undef ARSIZE
#undef LVlow
#undef LVhigh
#undef LVi
#undef LVs


/*
 * _close_all = proc()
 */

/* stub version */

int OFstream_D__close__all()
{
    int low;
    int high;
    int i;
    stream s;

    if (WVstream_D_Downinit == FALSE) {
	/*
	 * There is no stream objects.
	 */
	return RET;
    }

    low = OMarray_Dlow(WVstream_Dstreamlist);
    high = OMarray_Dhigh(WVstream_Dstreamlist);
    for (i = low; i <= high; i++) {
	s = (stream) OMarray_Dfetch(WVstream_Dstreamlist, i);
	if (s != NULL) {
	    OFstream_Dclose(s);
	}
    }
    return RET;
}


#ifdef J10N

/*****************************
 * Support for Japanese text *
 *****************************/


/*
 * set_input_code = proc(st: stream, code: string)
 *                  signals(not_possible(string))
 */

int OFstream_Dset__input__code(st, code)
stream st;
string code;
{
    FILE_T *fp;
    struct ja_csys csys;

    switch (st->buf->tag) {
    case BUF_READ:
	fp = st->buf->val.read->fp;
	break;
    case BUF_TTY:
	fp = st->buf->val.tty->ifp;
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot set code on this stream"));
    }
    if (OFstream_D__parsecode(code, &csys, DEFAULT_INPUT_CODING_SYSTEM) == SIG
	&& OFstream_D__parsecode__old(code, &csys) == SIG) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad coding system"));
    }
    if (ja_setcsys(fp, &csys) == EOF) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad coding system"));
    }
    RETURN0;
}


/*
 * set_output_code = proc(st: stream, code: string)
 *                   signals(not_possible(string))
 */

int OFstream_Dset__output__code(st, code)
stream st;
string code;
{
    FILE_T *fp;
    struct ja_csys csys;

    switch (st->buf->tag) {
    case BUF_WRITE:
	fp = st->buf->val.write->fp;
	break;
    case BUF_TTY:
	fp = st->buf->val.tty->ofp;
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot set code on this stream"));
    }
    if (OFstream_D__parsecode(code, &csys, DEFAULT_OUTPUT_CODING_SYSTEM) == SIG
	&& OFstream_D__parsecode__old(code, &csys) == SIG) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad coding system"));
    }
    if (ja_setcsys(fp, &csys) == EOF) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad coding system"));
    }
    RETURN0;
}


/*-
 * set_code = proc(st: stream, code: string) signals(not_possible(string))
 *
 * WARNING: This operation is obsolete: use set_input_code or set_output_code.
 */

int OFstream_Dset__code(st, code)
stream st;
string code;
{
    FILE_T *fp;
    int csys_default;
    struct ja_csys csys;

    switch (st->buf->tag) {
    case BUF_READ:
	fp = st->buf->val.read->fp;
	csys_default = DEFAULT_INPUT_CODING_SYSTEM;
	break;
    case BUF_WRITE:
	fp = st->buf->val.write->fp;
	csys_default = DEFAULT_OUTPUT_CODING_SYSTEM;
	break;
    case BUF_TTY:
	/* THIS IS NOT ALWAYS A APPROPRIATE FILE POINTER.  */
	fp = st->buf->val.tty->ifp;
	OFstream_Dcan__read(st);
	if (retval_area[0]) {
	    csys_default = DEFAULT_INPUT_CODING_SYSTEM;
	} else {
	    csys_default = DEFAULT_OUTPUT_CODING_SYSTEM;
	}
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot set code on this stream"));
    }
    if (OFstream_D__parsecode(code, &csys, csys_default) == SIG
	&& OFstream_D__parsecode__old(code, &csys) == SIG) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad coding system"));
    }
    if (ja_setcsys(fp, &csys) == EOF) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad coding system"));
    }
    RETURN0;
}


/*
 * get_input_code = proc(st: stream) returns(string)
 *                  signals(not_possible(string))
 */

int OFstream_Dget__input__code(st)
stream st;
{
    FILE_T *fp;
    struct ja_csys csys;

    switch (st->buf->tag) {
    case BUF_READ:
	fp = st->buf->val.read->fp;
	break;
    case BUF_TTY:
	fp = st->buf->val.tty->ifp;
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot get code from this stream"));
    }
    ja_getcsys(fp, &csys);
    RETURN1(OFstream_D__unparsecode(&csys));
}


/*
 * get_output_code = proc(st: stream) returns(string)
 *                   signals(not_possible(string))
 */

int OFstream_Dget__output__code(st)
stream st;
{
    FILE_T *fp;
    struct ja_csys csys;

    switch (st->buf->tag) {
    case BUF_WRITE:
	fp = st->buf->val.write->fp;
	break;
    case BUF_TTY:
	fp = st->buf->val.tty->ofp;
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot get code from this stream"));
    }
    ja_getcsys(fp, &csys);
    RETURN1(OFstream_D__unparsecode(&csys));
}


/*-
 * get_code = proc(st: stream) returns(string) signals(not_possible(string))
 *
 * WARNING: This operation is obsolete: use get_input_code or get_output_code.
 */

int OFstream_Dget__code(st)
stream st;
{
    FILE_T *fp;
    struct ja_csys csys;

    switch (st->buf->tag) {
    case BUF_READ:
	fp = st->buf->val.read->fp;
	break;
    case BUF_WRITE:
	fp = st->buf->val.write->fp;
	break;
    case BUF_TTY:
	/* THIS IS NOT ALWAYS A APPROPRIATE FILE POINTER.  */
	fp = st->buf->val.tty->ifp;
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot get code from this stream"));
    }
    ja_getcsys(fp, &csys);
    RETURN1(OFstream_D__unparsecode(&csys));
}

#endif /* J10N */
