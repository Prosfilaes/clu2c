/*
 * jputc.c - implementation of ja_putc
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jputc.c,v 2.0 1996/06/10 08:59:43 ushijima Exp $
 */

#include <jaio.h>
#undef ja_putc


/*
 * ja_putc - put character to stream
 *
 * Requires:
 *	The stream pointed to by STREAM is an output or update stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *   	ja_putc is the same as ja_fputc except that it may be
 *	implemented as a macro.  With a macro implementation, STREAM may
 *	be evaluated more than one.
 */

int ja_putc(c, stream)
int c;
ja_FILE *stream;
{
    return ja_mputc(c, stream);
}
