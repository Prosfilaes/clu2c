/*
 * local.h - local header for the Japanese I/O library
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: local.h,v 2.0 1996/06/10 09:00:05 ushijima Exp $
 */


/*
 * Support for character handling
 */

#define GR2GL(c)	((c) & 0x7f)
#define GL2GR(c)	((c) | 0x80)
#define GET_HIGH(c)	((c) >> 8)
#define GET_LOW(c)	((c) & 0xff)

#define IS_GR(c)	((0xa1 <= (c)) & ((c) <= 0xfe))

#define ESC '\033'		/* escape */
#define ICS '('			/* intermediate char for single char set */
#define ICM '$'			/* intermediate char for multi char set */
#define SS2 ((unsigned char) '\216') /* single shift 2 */


/*
 * Support for flags
 */

#define LINE_BUFFERED(x)	((x)->flags & ja_LINE_BUFFERED)
#define UNBUFFERED(x)		((x)->flags & ja_UNBUFFERED)
#define READING(x)		((x)->flags & ja_READING)
#define WRITING(x)		((x)->flags & ja_WRITING)
#define UPDATE(x)		((x)->flags & ja_UPDATE)
#define AUTO_BUFFER(x)		((x)->flags & ja_AUTO_BUFFER)


/*
 * Terminal entry
 */

struct ja_ttyent {
    char *name;			/* name of the terminal */
    int fd;			/* last file descriptor */
    int charset;		/* current character set */
    ja_FILE *fp;		/* output stream */
};


/*
 * Support for print functions
 */

/* Generalization of the destination for the formatted output. */
struct destination {

    /* The body of the destination to which output characters are
       written.  */
    union {
	ja_FILE *stream;
	ja_char *string;
    } body;

    /* The number of the characters written to the destination so far.  */
    int size;

    /* Pointer to the function that appends one character to the
       destination.  The function pointed to returns the given
       character on success; otherwise returns EOF.  */
#   undef putc
    int (*putc)();

    /* Pointer to the function that does something after all the
       output characters have been written.  Can be a null pointer.  */
    void (*finish)();

};


/*
 * Support for scan functions
 */

/* Generalization of the source for the formatted input. */
struct source {

    /* The body of the source from which input characters are read.  */
    union {
	ja_FILE *stream;
	ja_char *string;
    } body;

    /* Pointer to the function that reads one character from the
       source.  The function pointed to returns the read character on
       success; otherwise returns EOF.  */
#   undef getc
    int (*getc)();

    /* Pointer to the function that pushes back a character to the
       source.  */
    int (*ungetc)();

};


/*
 * Global variable declaration
 */

extern int ja_initialized;


/*
 * External function declarations that are for internal use only
 */

extern ja_FILE *ja_flookup();
extern ja_FILE *ja_create_stream();
extern int ja_almost_close();
extern int ja_forall();
extern int ja_tty_lookup();
extern void ja_init();
extern int ja_tty_set();
extern int ja_tty_sync();
extern int ja_sjis2jis();
extern int ja_jis2sjis();
extern int ja_v_printf();
extern int ja_v_scanf();
