/*
 * stream.h - header for stream
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: stream.h,v 2.10 1996/05/12 06:46:36 ushijima Exp $
 */

#include <config/stdio.h>


/* Support for Japanization */

#ifdef J10N
#   error
#   define FILE_T		ja_FILE
#   define IOFBF		ja_IOFBF
#   define IOLBF		ja_IOLBF
#   define IONBF		ja_IONBF
#   define Clearerr(p)		ja_clearerr(p)
#   define Fclose(p)		ja_fclose(p)
#   define Ferror(p)		ja_ferror(p)
#   define Fflush(p)		ja_fflush(p)
#   define Fileno(p)		ja_fileno(p)
#   define Fnputs(s, n, p)	ja_fnputs(s, n, p)
#   define Fopen(f, m)		ja_fopen(f, m)
#   define Fseek(p, o, w)	ja_fseek(p, o, w)
#   define Getc(p)		ja_getc(p)
#   define Putc(c, p)		ja_putc(c, p)
#   define Setvbuf(p, b, m, s)	ja_setvbuf(p, b, m, s)
#   define Stderr		ja_stderr
#   define Stdin		ja_stdin
#   define Stdout		ja_stdout
#   define Ungetc(c, p)		ja_ungetc(c, p)
#else  /* not J10N */
#   define FILE_T		FILE
#   define IOFBF		_IOFBF
#   define IOLBF		_IOLBF
#   define IONBF		_IONBF
#   define Clearerr(p)		clearerr(p)
#   define Fclose(p)		fclose(p)
#   define Ferror(p)		ferror(p)
#   define Fflush(p)		fflush(p)
#   define Fileno(p)		fileno(p)
#   define Fnputs(s, n, p)	fwrite((s), 1, (n), (p))
#   define Fopen(f, m)		fopen(f, m)
#   define Fseek(p, o, w)	fseek(p, o, w)
#   define Getc(p)		getc(p)
#   define Putc(c, p)		putc(c, p)
#   define Setvbuf(p, b, m, s)	setvbuf(p, b, m, s)
#   define Stderr		stderr
#   define Stdin		stdin
#   define Stdout		stdout
#   define Ungetc(c, p)		ungetc(c, p)
#endif /* not J10N */


/* Representation */

struct rbuf {
    FILE_T *fp;
    int line;
#ifndef STRICT_CLU
    bool buffered;
#endif
};

struct wbuf {
    FILE_T *fp;
    bool buffered;
};

struct tbuf {
    FILE_T *ifp;
    FILE_T *ofp;
    bool ibuffered;
    bool obuffered;
    int line;
    string prompt;
    bool bol;
};

struct sbuf {
    string chars;
    int index;
    int line;
};

struct buf {
    int tag;
    union {
	struct rbuf *read;
	struct wbuf *write;
	struct tbuf *tty;
	struct sbuf *istr;
	array ostr;
	null closed;
    } val;
};

#define BUF_READ	0
#define BUF_WRITE	1
#define BUF_TTY		2
#define BUF_ISTR	3
#define BUF_OSTR	4
#define BUF_CLOSED	5

struct stream_rep {
    int index;			/* index in list */
    object name;		/* file name */
    sequence scripts;		/* script files */
    bool scripting;		/* true => script files */
    struct buf *buf;		/* everything else */
};

typedef struct stream_rep *stream;
