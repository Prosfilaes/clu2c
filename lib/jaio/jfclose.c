/*
 * jfclose.c - implementation of ja_fclose
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfclose.c,v 2.0 1996/06/10 08:59:19 ushijima Exp $
 */

#include <config/stdlib.h>
#include <jaio.h>
#include <local.h>


/*
 * ja_fclose - close a stream
 *
 * Requires:
 *	STREAM is a valid pointer to a stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *	
 * Effects:
 *	Flushes any unwritten buffer contents to the associated file
 *	and removes the association between the stream and the file.
 *	Returns zero on success; otherwise returns EOF.
 */

int ja_fclose(stream)
ja_FILE *stream;
{
    int fstatus, cstatus;

    fstatus = ja_almost_close(stream);
    cstatus = fclose(stream->fp);
    if (fstatus == EOF || cstatus == EOF) {
	return EOF;
    } else {
	return 0;
    }
}


/*
 * ja_almost_close - almost close a stream
 *
 * Requires:
 *	STREAM is a valid pointer to a stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 * 	This function is equivalent to `ja_fclose', except that the
 *	underlying standard I/O stream is not closed.
 */

int ja_almost_close(stream)
ja_FILE *stream;
{
    int status = 0;

    if (!READING(stream)) {
	status = ja_fflush(stream);
	if (stream->csd == CSYS_ISO2022JP && stream->charset != CSET_ASCII) {
	    ja_setcset(CSET_ASCII, stream);
	}
    }
    if (stream->base != NULL && AUTO_BUFFER(stream)) {
	free(stream->base);
	stream->base = NULL;
    }
    if (stream->bytes != NULL) {
	free(stream->bytes);
	stream->bytes = NULL;
    }
    stream->flags = 0;
    return status;
}
