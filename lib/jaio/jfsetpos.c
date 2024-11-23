/*
 * jfsetpos.c - implementation of ja_fsetpos
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfsetpos.c,v 2.0 1996/06/10 08:59:36 ushijima Exp $
 */

#include <jaio.h>
#include <local.h>


/*
 * ja_fsetpos - set file position
 *
 * Requires:
 *   	The file position pointed to by POSITION has been obtained
 *	from applying the `ja_fgetpos' function to the same stream
 *	as pointed to by STREAM.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *	Attempts to set the file position for the stream pointed to by
 *	STREAM as specified by the file position pointed to by
 *	POSITION.  Returns zero on success; otherwise returns nonzero.
 *	If the stream pointed to by STREAM is an update stream and
 *	this function terminates successfully, the next operation on
 *	it may be either input or output.
 */

int ja_fsetpos(stream, position)
ja_FILE *stream;
ja_fpos_t *position;
{
    int status;

    if (WRITING(stream)) {
	status = ja_fflush(stream);
	if (status == EOF) {
	    return EOF;
	}
    }
    status = fseek(stream->fp, position->offset, SEEK_SET);
    if (status != 0) {
	return EOF;
    }
    stream->cnt = 0;
    stream->ptr = stream->base;
    stream->charset = position->charset;
    if (UPDATE(stream)) {
	stream->flags &= ~(ja_READING | ja_WRITING);
    }
    return 0;
}
