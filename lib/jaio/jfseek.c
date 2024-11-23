/*
 * jfseek.c - implementation of ja_fseek
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfseek.c,v 2.0 1996/06/10 08:59:35 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_fseek - set file position
 *
 * Requires:
 *   	OFFSET is either 0L or a return value of a proper invocation
 *	of the `ja_ftell' function on the same stream as pointed to
 *	by STREAM.  WHENCE is equal to SEEK_SET.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *	Attempts to set the file position for the stream pointed to by
 *	STREAM as specified by OFFSET.  Returns zero on success;
 *	otherwise returns nonzero.
 */

int ja_fseek(stream, offset, whence)
ja_FILE *stream;
long offset;
int whence;
{
    ja_fpos_t position;

    if (whence != SEEK_SET) {
	return EOF;
    }
    position.offset = offset;
    position.charset = CSET_ASCII;
    return ja_fsetpos(stream, &position);
}
