/*
 * istream.c - implementation of istream
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: istream.c,v 2.16 1996/10/07 05:20:29 ushijima Exp $
 */

#include <config/limits.h>
#include <config/time.h>
#include <config/stat.h>

#include <clu2c.h>
#include <clu2c/istream.h>


#ifdef MSDOS_TEXT

#define READ_TYPE "rb"
#define WRITE_TYPE "wb"
#define APPEND_TYPE "ab"

#else  /* not MSDOS_TEXT */

#define READ_TYPE "r"
#define WRITE_TYPE "w"
#define APPEND_TYPE "a"

#endif /* not MSDOS_TEXT */


/*
 * REPRESENTATION INVARIANT
 *      r->mode == READ_MODE | r->mode == WRITE_MODE | r->mode == CLOSED.
 *      lower bound of r->history is one.
 */


#define READ_MODE	0
#define WRITE_MODE	1
#define CLOSED		2

#define rhist_hash(x) (abs((int) x) % RHIST_SIZE)


/*
 * open = proc(fn: file_name, mode: string) signals(not_possible(string)) 
 */

int OFistream_Dopen(f, access)
object f;			/* file_name */
string access;
{
    static string read = NULL;
    static string write = NULL;
    static string append = NULL;

    char *filename, *type;
    int mode, i;
    FILE *fp;
    istream s;

    if (read == NULL) {
	read = OFstring_D__cs2s("read");
	write = OFstring_D__cs2s("write");
	append = OFstring_D__cs2s("append");
    }

    AFfile__name__to__string(f);
    filename = (char *) OFstring_D__s2cs(retval_area[0]);

    if (OMstring_Dequal(access, read)) {
	type = READ_TYPE;
	mode = READ_MODE;
    } else if (OMstring_Dequal(access, write)) {
	type = WRITE_TYPE;
	mode = WRITE_MODE;
    } else if (OMstring_Dequal(access, append)) {
	type = APPEND_TYPE;
	mode = WRITE_MODE;
    } else {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad access mode"));
    }

    if ((fp = fopen(filename, type)) == NULL) {
	syserror();
	return SIG;
    }
    s = (istream) malloc(sizeof(struct istream_rep));
    s->fp = fp;
    s->mode = mode;
    s->fn = f;
    OFarray_Dnew();
    s->history = (array) retval_area[0];
    for (i = 0; i < RHIST_SIZE; i++) {
	s->rhistory[i] = NULL;
    }

    RETURN1(s);
}


/*
 * can_read = proc(s: istream) returns(bool)
 */

int OFistream_Dcan__read(s)
istream s;
{
    switch (s->mode) {
    case READ_MODE:
	RETURN1(TRUE);
    default:
	RETURN1(FALSE);
    }
}


/*
 * can_write = proc(s: istream) returns(bool)
 */

int OFistream_Dcan__write(s)
istream s;
{
    switch (s->mode) {
    case WRITE_MODE:
	RETURN1(TRUE);
    default:
	RETURN1(FALSE);
    }
}


/*
 * empty = proc(istream) returns(bool) 
 */

int OFistream_Dempty(s)
istream s;
{
    FILE *fp;
    int c;

    switch (s->mode) {
    case READ_MODE:
	fp = s->fp;
	c = getc(fp);		/* touch the stream */
	ungetc(c, fp);		/* (ditto) */
	if (feof(fp)) {
	    RETURN1(TRUE);
	} else {
	    RETURN1(FALSE);
	}
    default:

	/*
	 * Here the not_possible exception is signaled, although not
	 * described in the manual to do so.  We think this is
	 * preferable.  The MIT implementation of istream$empty also
	 * signals this execption.
	 */

	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this istream"));
    }
}


/*
 * reset = proc(s: istream) signals(not_possible(string)) 
 */

int OFistream_Dreset(s)
istream s;
{
    int i;

    switch (s->mode) {
    case READ_MODE:
    case WRITE_MODE:
	if (fseek(s->fp, 0L, 0) == -1) {
	    syserror();
	    return SIG;
	}
	OFarray_Dtrim(s->history, 1, 0);
	for (i = 0; i < RHIST_SIZE; i++) {
	    s->rhistory[i] = NULL;
	}
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot reset closed istream"));
    }
    RETURN0;
}


/*
 * flush = proc(s: istream) signals(not_possible(string))
 */

int OFistream_Dflush(s)
istream s;
{
    switch (s->mode) {
    case WRITE_MODE:
	if (fflush(s->fp) == EOF) {
	    syserror();
	    return SIG;
	}
	RETURN0;
    case READ_MODE:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot flush input istream"));
    case CLOSED:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot flush closed istream"));
    }
}


/*
 * get_date = proc(s: istream) returns(date) signals(not_possible(string)) 
 */

int OFistream_Dget__date(s)
istream s;
{
    struct stat buf;
    struct tm *time;

    switch (s->mode) {
    case READ_MODE:
    case WRITE_MODE:
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("cannot get date"));
    }

    if (fstat(fileno(s->fp), &buf) < 0) {
	syserror();
	return SIG;
    }
    time = localtime(&(buf.st_mtime));
    if (OFdate_Dcreate(time->tm_mday,
		       time->tm_mon + 1,
		       time->tm_year + 1900,
		       time->tm_hour,
		       time->tm_min,
		       time->tm_sec) == SIG) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("cannot get date"));
    }

    /*
     * Here we have the result date object in retval_area[0], so we do
     * not have to set return value into retval_area[0].
     */
    return (RET);
}


/*
 * set_date = proc(s: istream, d: date) signals(not_possible(string))
 */

int OFistream_Dset__date(s)
istream s;
{
    SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("cannot set date"));
}


/*
 * get_name = proc(s: istream) returns(file_name) 
 */

int OFistream_Dget__name(s)
istream s;
{
    RETURN1(s->fn);
}


/*
 * close = proc(s: istream) signals(not_possible(string))
 */

int OFistream_Dclose(s)
istream s;
{
    if (fclose(s->fp) == EOF) {
	syserror();
	return SIG;
    }
    s->mode = CLOSED;
    RETURN0;
}


/*
 * abort = proc(s: istream)
 */

int OFistream_Dabort(s)
istream s;
{
    fclose(s->fp);
    s->mode = CLOSED;
    RETURN0;
}


/*
 * is_closed = proc(s: istream) returns(bool)
 */

int OFistream_Dis__closed(s)
istream s;
{
    switch (s->mode) {
    case CLOSED:
	RETURN1(TRUE);
    default:
	RETURN1(FALSE);
    }
}


/*
 * equal = proc(s1, s2: istream) returns(bool)
 */

int OFistream_Dequal(s1, s2)
istream s1;
istream s2;
{
    RETURN1(s1 == s2);
}


/*
 * similar = proc(s1, s2: istream) returns(bool)
 */

int OFistream_Dsimilar(s1, s2)
istream s1;
istream s2;
{
    RETURN1(s1 == s2);
}


/*
 * copy = proc(s: istream) returns(istream)
 */

int OFistream_Dcopy(s)
istream s;
{
    RETURN1(s);
}


/*
 *    internal operations
 */


/*
 * geti = proc(s: istream) returns(int)
 *        signals(end_of_file, not_possible(string))
 */

int OFistream_Dgeti(s)
istream s;
{
    FILE *fp = s->fp;
    unsigned char bytes[sizeof(int)];
    int n;

    if (s->mode != READ_MODE) {
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this istream"));
    }
    n = fread(bytes, sizeof(unsigned char), sizeof(int), fp);
    if (n == sizeof(int)) {
	unsigned u = 0;
	int i;
	for (i = 0; i < sizeof(int); i++) {
	    u = ((u << CHAR_BIT) | bytes[i]);
	}
	RETURN1(u);
    } else if (feof(fp)) {
	SIGNAL0(SLEND_OF_FILE);
    } else {
	syserror();
	return SIG;
    }
}


/*
 * puti = proc(s: istream, i: int) signals(not_possible(string))
 */

int OFistream_Dputi(s, i)
istream s;
int i;
{
    unsigned u;
    int j;
    unsigned char bytes[sizeof(int)];
    int n;

    if (s->mode != WRITE_MODE) {
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot write to this istream"));
    }
    u = i;
    for (j = sizeof(int) - 1; j >= 0; --j) {
	bytes[j] = u & 0xff;
	u >>= CHAR_BIT;
    }
    n = fwrite(bytes, sizeof(unsigned char), sizeof(int), s->fp);
    if (n < sizeof(int)) {
	syserror();
	return SIG;
    }
    RETURN0;
}


/*
 * getc = proc(s: istream) returns(char)
 *        signals(end_of_file, not_possible(string))
 */

int OFistream_Dgetc(s)
istream s;
{
    FILE *fp = s->fp;
    int i;

    switch (s->mode) {
    case READ_MODE:
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot read from this istream"));
    }

    i = getc(fp);
    ungetc(i, fp);
    if (feof(fp)) {
	SIGNAL0(SLEND_OF_FILE);
    }
    if ((i = getc(fp)) == EOF) {
	syserror();
	return SIG;
    }
    RETURN1(i);
}


/*
 * putc = proc(s: istream, c: char) signals(not_possible(string))
 */

int OFistream_Dputc(s, c)
istream s;
char_ c;
{
    FILE *fp = s->fp;

    switch (s->mode) {
    case WRITE_MODE:
	break;
    default:
	SIGNAL1(SLNOT_POSSIBLE,
		OFstring_D__cs2s("cannot write to this istream"));
    }

    if (putc(c, fp) == EOF) {
	syserror();
	return SIG;
    }
    RETURN0;
}


/*
 * check_history
 */

int OFistream_Dcheck__history(s, x)
istream s;
object x;
{
    struct bucket *buck, *buck0;
    int id, i;

    for (buck = s->rhistory[rhist_hash(x)]; buck != NULL; buck = buck->next) {
	if (buck->key == x) {
	    RETURN1(buck->val);
	}
    }

    /* not found */

    OFarray_Daddh(s->history, x);
    OFarray_Dhigh(s->history);
    id = (int) retval_area[0];
    i = rhist_hash(x);
    buck0 = s->rhistory[i];
    buck = (struct bucket *) malloc(sizeof(struct bucket));
    buck->key = x;
    buck->val = id;
    buck->next = buck0;
    s->rhistory[i] = buck;
    RETURN1(NOT_YET);
}


/*
 * add_history
 */

int OFistream_Dadd__history(s, x)
istream s;
object x;
{
    OFarray_Daddh(s->history, x);
    RETURN0;
}


/*
 * get_obj = proc(s: istream, id: int) returns(???) signals(bounds)
 *     effects Signals BOUNDS if there is no object corresponding to
 *          ID; otherwise returns object corresponding to id in
 *          history.
 */

int OFistream_Dget__obj(s, id)
istream s;
int id;
{
    return (OFarray_Dfetch(s->history, id));
}
