/*
 * jaio.h - header for the Japanese I/O library
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jaio.h,v 2.0 1996/06/10 09:00:04 ushijima Exp $
 */

#ifndef JAIO_H
#define JAIO_H 1


/*
 * Makes use of the standard I/O library.
 */

#include <stdio.h>


/*
 * Character set descriptors
 */

#define CSET_ASCII	0
#define CSET_JISX0208	1


/*
 * Coding system descriptors
 */

#define CSYS_NOCONV	0	/* no conversion */
#define CSYS_EUCJP	1	/* EUC-Japan (aka UJIS) */
#define CSYS_SJIS	2	/* Shift-JIS */
#define CSYS_ISO2022JP	3	/* ISO-20220-JP (See RFC 1468) */
#define CSYS_AUTOCONV	4	/* automatic conversion */
#define MAX_CSYS	4


/*
 * Final character for escape sequences
 */

#define FC_ASCII	'B'	/* ASCII */
#define FC_JISX0201	'J'	/* JIS X 0201-Roman */
#define FC_JISX0208_78	'@'	/* JIS X 0208-1978 */
#define FC_JISX0208_83	'B'	/* JIS X 0208-1983 */


/*
 * Buffering modes
 */

#define ja_IOFBF	0	/* fully buffered */
#define ja_IOLBF	1	/* line buffered */
#define ja_IONBF	2	/* unbuffered */


/*
 * Buffer size
 */

#define ja_BUFSIZ	BUFSIZ


/*
 * Number of files that can be opened simultaneously
 */

#ifdef FOPEN_MAX
#define ja_FOPEN_MAX	FOPEN_MAX
#else
#define ja_FOPEN_MAX	20	/* arbitrary */
#endif


/*
 * Support for ja_fseek
 */

#ifndef SEEK_SET
#   define SEEK_SET 0
#endif
#ifndef SEEK_CUR
#   define SEEK_CUR 1
#endif
#ifndef SEEK_END
#   define SEEK_END 2
#endif


/*
 * Flags (internal use only)
 *
 * ja_LINE_BUFFERED
 * 	Indicates that the stream is line buffered.  This flag is set
 *	by default for a stream associated with an interactive device.
 *	May be changed by an invocation of ja_setvbuf.
 *
 * ja_UNBUFFERED
 *	Indicates that the stream is unbuffered.
 *
 * ja_READING
 * 	Indicates that the stream is an input stream or an update
 *	stream in which the most recent operation was input.
 *
 * ja_WRITING
 * 	Indicates that the stream is an output stream or an update
 *	stream in which the most recent operation was output.
 *
 * ja_UPDATE
 *	Indicates that the stream is an update stream.  This flag may
 *	be set when the stream is opened and not changed thereafter.
 *
 * ja_AUTO_BUFFER
 *	Indicates that the buffer is allocated within the Japanese I/O
 *	library and that the Japanese I/O library is responsible for
 *	freeing the buffer when the stream is closed.  This flag is
 *	set whenever a buffer is allocated and cleared when ja_setvbuf
 *	in invoked with the buffer.
 *
 * For all flag F, the following invariants shall hold.
 *	(F & (ja_LINE_BUFFERED | ja_UNBUFFERED)) != (ja_LINE_BUFFERED | ja_UNBUFFERED)
 *	(F & (ja_READING | ja_WRITING)) != (ja_READING | ja_WRITING)
 */

#define ja_LINE_BUFFERED	0x01	/* line buffered */
#define ja_UNBUFFERED		0x02	/* unbuffered */
#define ja_READING		0x04	/* input stream */
#define ja_WRITING		0x08	/* output stream */
#define ja_UPDATE		0x10	/* update stream */
#define ja_AUTO_BUFFER	0x20	/* buffer is malloc'ed */


/*
 * Macro version of some functions
 */

#define ja_mclearerr(p)	clearerr((p)->fp)
#define ja_mfeof(p)		(feof((p)->fp) && (p)->cnt == 0)
#define ja_mferror(p)		ferror((p)->fp)
#define ja_mfileno(p)		fileno((p)->fp)
#define ja_mgetc(p)		\
    ((--((p)->cnt) >= 0)	\
     ? (*((p)->ptr++))		\
     : (ja_fill(p)))
#define ja_mgetchar()		ja_getc(ja_stdin)
#define ja_mputc(c, p)						\
    ((--(p)->cnt >= 0 && !(((p)->flags & ja_LINE_BUFFERED) && c == '\n'))	\
     ? (*(p)->ptr++ = (c))						\
     : (ja_flush(c, p)))
#define ja_mputchar(c)	ja_putc(c, ja_stdout)


/*
 * Type definitions
 */

typedef short ja_char;

/* Input decoder */

struct ja_decoder_rep {
    int csd;			/* coding system descriptor */
    int state;			/* current state */
    int charset;		/* currently designated character set */
    int pending_size;		/* number of pending characters */
    unsigned char pending[2];	/* pending characters */
};

typedef struct ja_decoder_rep *ja_decoder;

/* Stream representation */

typedef struct {
    FILE *fp;			/* file pointer of stdio */
    ja_char *base;		/* base pointer of the buffer */
    ja_char *ptr;		/* cursor for the buffer */
    int cnt;
    int flags;
    int csd;			/* coding system descriptor */
    int (*flush)();		/* flushing method */
    int charset;		/* currently designated character set */
    char fc_ascii;		/* final char for ASCII/JIS X 0201 */
    char fc_jis;		/* final char for JIS X 0208 */
    ja_decoder decoder;	/* input decoder */
    int tty;			/* terminal entry */
    unsigned char *bytes;
} ja_FILE;

/* Coding system */

struct ja_csys {
    int csys_number;
    char csys_fc_ascii;
    char csys_fc_jis;
};

/* File position */

typedef struct {
    long offset;
    int charset;
} ja_fpos_t;


/*
 * Standard streams
 */

extern ja_FILE ja_stdio[];

#define ja_stdin	(&ja_stdio[0])
#define ja_stdout	(&ja_stdio[1])
#define ja_stderr	(&ja_stdio[2])


/*
 * External function declarations
 */

#ifdef HAVE_STDARG_H
#   define ja_PROTO(x) x
#else
#   define ja_PROTO(x) ()
#endif

extern int ja_fclose();
extern int ja_fflush();
extern ja_FILE *ja_fopen();
extern ja_FILE *ja_freopen();
extern void ja_setbuf();
extern int ja_setvbuf();
extern int ja_fprintf ja_PROTO((ja_FILE *, ja_char *, ...));
extern int ja_fscanf ja_PROTO((ja_FILE *, ja_char *, ...));
extern int ja_printf ja_PROTO((ja_char *, ...));
extern int ja_scanf ja_PROTO((ja_char *, ...));
extern int ja_sprintf ja_PROTO((ja_char *, ja_char *, ...));
extern int ja_sscanf ja_PROTO((ja_char *, ja_char *, ...));
extern int ja_vfprintf();
extern int ja_vprintf();
extern int ja_vsprintf();
extern int ja_fgetc();
extern ja_char *ja_fgets();
extern int ja_fputc();
extern int ja_fputs();
extern int ja_getc();
extern int ja_getchar();
extern ja_char *ja_gets();
extern int ja_putc();
extern int ja_putchar();
extern int ja_puts();
extern int ja_ungetc();
extern int ja_fgetpos();
extern int ja_fseek();
extern int ja_fsetpos();
extern long ja_ftell();
extern void ja_rewind();
extern void ja_clearerr();
extern int ja_feof();
extern int ja_ferror();
extern void ja_perror();

extern int ja_fnputs();
extern int ja_setcset();
extern int ja_setcsys();
extern char *ja_encode();
extern ja_decoder ja_create_decoder();
extern int ja_decode();
extern int ja_flush_decoder();
extern int ja_reset_decoder();


/*
 * The following functions are external but should not be invoked by
 * the user directly.
 */

extern int ja_flush();
extern int ja_fill();


/*
 * Macro version of some functions
 */

#define ja_clearerr(p)	ja_mclearerr(p)
#define ja_feof(p)		ja_mfeof(p)
#define ja_ferror(p)		ja_mferror(p)
#define ja_fileno(p)		ja_mfileno(p)
#define ja_getc(p)		ja_mgetc(p)
#define ja_getchar()		ja_mgetchar()
#define ja_putc(c, p)		ja_mputc(c, p)
#define ja_putchar(c)		ja_mputchar(c)


#endif /* not JAIO_H */
