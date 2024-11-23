/*
 * jsetvbuf.c
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jsetvbuf.c,v 2.0 1996/06/10 08:59:49 ushijima Exp $
 */

#include <config/stdio.h>
#include <config/stdlib.h>
#include <jaio.h>
#include "local.h"


#ifndef HAVE_SETVBUF

/* Emulate the `setvbuf' function using the `setbuffer' and
   `setlinebuf' functions (these two functions are assumed to be
   available).  */

int setvbuf(fp, buf, mode, size)
FILE *fp;
char *buf;
int mode;
int size;
{
    /* This function returns -1 for a invalid mode.  */

    /* There is no way to see whether the `setbuffer' and `setlinebuf'
       functions have actually done their work. */

    switch (mode) {
    case _IOFBF:
	if (buf == NULL) {
	    buf = (char *) malloc(BUFSIZ);
	    if (buf == NULL) {
		return -1;
	    }
	    size = BUFSIZ;
	}
	setbuffer(fp, buf, size);
	break;
    case _IOLBF:
	setlinebuf(fp);
	break;
    case _IONBF:
	setbuffer(fp, NULL, 0);
	break;
    default:
	/* invalid mode */
	return -1;
    }
    return 0;
}

#endif /* not HAVE_SETVBUF */


/*
 * ja_setvbuf
 */

int ja_setvbuf(stream, buf, mode, size)
ja_FILE *stream;
ja_char *buf;
int mode;
int size;
{
    /* This is a tentative version: only buffering mode can be set.  */

    switch (mode) {
    case ja_IOFBF:
	stream->flags &= ~(ja_LINE_BUFFERED | ja_UNBUFFERED);
	mode = _IOFBF;
	break;
    case ja_IOLBF:
	stream->flags &= ~ja_UNBUFFERED;
	stream->flags |= ja_LINE_BUFFERED;
	mode = _IOLBF;
	break;
    case ja_IONBF:
	stream->flags &= ~ja_LINE_BUFFERED;
	stream->flags |= ja_UNBUFFERED;
	mode = _IONBF;
	break;
    default:
	/* invalid mode */
	return -1;
    }
    return setvbuf(stream->fp, NULL, mode, 0);
}
