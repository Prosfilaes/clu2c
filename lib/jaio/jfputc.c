/*
 * jfputc.c - implementation of ja_fputc
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfputc.c,v 2.0 1996/06/10 08:59:31 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_fputc - put character to stream
 *
 * Requires:
 *	The stream pointed to by STREAM is an output or update stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *	Returns EOF if write error occurs; otherwise appends C to the
 *	stream pointed to by STREAM and returns C.
 */

int ja_fputc(c, stream)
int c;
ja_FILE *stream;
{
    return ja_putc(c, stream);
}
