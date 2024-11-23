/*
 * jfgetc.c - implementation of ja_fgetc
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfgetc.c,v 2.0 1996/06/10 08:59:23 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_fgetc - get character from stream
 *
 * Requires:
 *	The stream pointed to by STREAM is an input stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *   	Returns EOF if the stream pointed to by STREAM is at end-of-file
 *	or read error occurs; otherwise removes the next (possibly
 *	Japanese) character from the stream pointed to by STREAM and
 *	returns it.
 */

int ja_fgetc(stream)
ja_FILE *stream;
{
    return ja_getc(stream);
}
