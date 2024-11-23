/*
 * jfgetpos.c - implementation of ja_fgetpos
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfgetpos.c,v 2.0 1996/06/10 08:59:23 ushijima Exp $
 */

#include <config.h>
#include <jaio.h>
#include <local.h>


static int ja_bytes_already_read();
static int ja_bytes_to_be_written();


/*
 * ja_fgetpos - get file position
 *
 * Modifies:
 *	The file position pointed to by POSITION.
 *
 * Effects:
 *	Attempts to get the current file position for the stream
 *	pointed to by STREAM.  On success, stores the obtained
 *	information in the file position pointed to by POSITION and
 *	returns zero.  Otherwise returns nonzero.  If this function
 *	terminates successfully, the resulting file position may be
 *	used as an argument to the `ja_fsetpos' function on the same
 *	stream.
 */

int ja_fgetpos(stream, position)
ja_FILE *stream;
ja_fpos_t *position;
{
    long offset;

    /* Gets the current value of the file position indicator for the
       underlying standard I/O stream.  */
    offset = ftell(stream->fp);
    if (offset < 0) {
	return offset;
    }

    /* Adjusts the file offset.  */
    if (READING(stream)) {
	offset -= ja_bytes_already_read(stream);
    } else if (WRITING(stream)) {
	offset += ja_bytes_to_be_written(stream);
    }

    position->offset = offset;
    if (stream->ptr && stream->ptr > stream->base && *(stream->ptr - 1) > 0x100) {
	position->charset = CSET_JISX0208;
    } else {
	position->charset = CSET_ASCII;
    }
    return 0;
}


/*
 * ja_bytes_already_read
 *
 * Effects:
 *   	Returns the number of the bytes read from the underlying
 *	standard I/O stream
 */

static int ja_bytes_already_read(stream)
ja_FILE *stream;
{
    int bytes;
    int i;
    ja_char c;
    int base;

    if (stream->base == NULL) {
	return 0;
    }
    bytes = 0;
    switch (stream->csd) {
    case CSYS_NOCONV:
	bytes = stream->cnt;
	break;
    case CSYS_EUCJP:
	for (i = 0; i < stream->cnt; i++) {
	    c = stream->ptr[i];
	    bytes += (c > 0x100 || IS_GR(c)) ? 2 : 1;
	}
	break;
    case CSYS_SJIS:
	for (i = 0; i < stream->cnt; i++) {
	    bytes += (stream->ptr[i] < 0x100) ? 1 : 2;
	}
	break;
    case CSYS_ISO2022JP:
    case CSYS_AUTOCONV:
	base = stream->ptr - stream->base;
	for (i = 0; i < stream->cnt; i++) {
	    bytes += stream->bytes[base + i];
	}
	break;
    }
    if (stream->decoder) {
	bytes += stream->decoder->pending_size;
    }
    return bytes;
}


/*
 * ja_bytes_to_be_written
 *
 * Effects:
 *   	Returns the number of the bytes written to the underlying
 *	standard I/O stream when the buffered characters in the stream
 *	pointed to by STREAM are flushed, without actually flushing
 *	the buffer.
 */

static int ja_bytes_to_be_written(stream)
ja_FILE *stream;
{
    int csd;
    int bytes;
    ja_char *p;
    int charset;

    if (stream->base == NULL) {
	return 0;
    }
    csd = stream->csd;
    if (csd == CSYS_AUTOCONV) {
	csd = DEFAULT_OUTPUT_CODING_SYSTEM;
    }
    bytes = 0;
    switch (csd) {
    case CSYS_NOCONV:
	bytes = stream->ptr - stream->base;
	break;
    case CSYS_EUCJP:
	for (p = stream->base; p < stream->ptr; p++) {
	    bytes += (*p > 0x100 || IS_GR(*p)) ? 2 : 1;
	}
	break;
    case CSYS_SJIS:
	for (p = stream->base; p < stream->ptr; p++) {
	    bytes += (*p < 0x100) ? 1 : 2;
	}
	break;
    case CSYS_ISO2022JP:

	/* Needs to count the bytes for the escape sequence for
           synchronizing character set.  */

	charset = stream->charset;
	for (p = stream->base; p < stream->ptr; p++) {
	    if (*p < 0x100) {
		if (charset != CSET_ASCII) {
		    bytes += 3;
		    charset = CSET_ASCII;
		}
		bytes++;
	    } else {
		if (charset != CSET_JISX0208) {
		    bytes += 3;
		    charset = CSET_JISX0208;
		}
		bytes += 2;
	    }
	}
	break;
    }
    return bytes;
}
