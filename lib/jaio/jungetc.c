/*
 * jungetc.c
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jungetc.c,v 2.0 1996/06/10 08:59:52 ushijima Exp $
 */

#include <jaio.h>
#include <local.h>


/*
 * ja_ungetc
 */

int ja_ungetc(c, stream)
int c;
ja_FILE *stream;
{
    if (c == EOF || !READING(stream)) {
	return EOF;
    }
    if (stream->base < stream->ptr) {
	*--stream->ptr = c;
	stream->cnt++;
	return c;
    }
    return EOF;
}
