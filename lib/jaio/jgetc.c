/*
 * jgetc.c - implementation of ja_getc
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jgetc.c,v 2.0 1996/06/10 08:59:38 ushijima Exp $
 */

#include <jaio.h>
#undef ja_getc


/*
 * ja_getc - get character from stream
 *
 * Requires:
 *	The stream pointed to by STREAM is an input stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *   	ja_getc is the same as ja_fgetc except that it may be
 *	implemented as a macro.  With a macro implementation, STREAM may
 *	be evaluated more than one.
 */

int ja_getc(stream)
ja_FILE *stream;
{
    return ja_mgetc(stream);
}
