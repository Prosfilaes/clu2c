/*
 * jftell.c - implementation of ja_ftell
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jftell.c,v 2.0 1996/06/10 08:59:37 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_ftell - get current file position
 *
 * Requires:
 *   	The last character read from or written to the stream pointed
 *	to by STREAM, if any, is an ASCII character.
 *
 * Effects:
 *   	Returns information that corresponds to the current file
 *	position, which can be used as the second argument to the
 *	ja_fseek function.
 */

long ja_ftell(stream)
ja_FILE *stream;
{
    ja_fpos_t position;

    if (ja_fgetpos(stream, &position) != 0) {
	return -1;
    }
    return position.offset;
}
