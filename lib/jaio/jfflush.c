/*
 * jfflush.c - implementation of ja_fflush
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfflush.c,v 2.0 1996/06/10 08:59:22 ushijima Exp $
 */

#include <jaio.h>
#include <local.h>


/*
 * ja_fflush - flush output buffer
 *
 * Requires:
 *	STREAM points to an output stream or an update stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *	Attempts any unwritten data to be written to the file
 *	associated with the stream pointed to by STREAM.  Returns zero on
 *	success; otherwise returns EOF;
 */

int ja_fflush(stream)
ja_FILE *stream;
{
    int res;

    if (stream == NULL) {
	return ja_forall(ja_fflush);
    }

    /*
     * STREAM->BASE being a null pointer means that any output operation
     * has not been performed so far.  In this case there is nothing
     * to do.
     */
    if (stream->base == NULL) {
	return 0;
    }

    /*
     * Ignores input stream.
     */
    if (!WRITING(stream) && !UPDATE(stream)) {
	return 0;
    }
    
    /*
     * Synchronizes character set.
     */
    if (stream->tty >= 0) {
	ja_tty_sync(stream);
    }

    /*
     * Does flushing.
     */
    res = (*stream->flush)(stream);
    res |= fflush(stream->fp);

    /*
     * Resets the buffer.
     */
    stream->ptr = stream->base;
    if (UNBUFFERED(stream)) {
	stream->cnt = 0;
    } else {
	stream->cnt = ja_BUFSIZ;
    }
    
    return res;
}
