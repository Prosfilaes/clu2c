/*
 * jfopen.c - implementation of ja_fopen
 *
 * Copyrght (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfopen.c,v 2.0 1996/06/10 08:59:28 ushijima Exp $
 */

#include <config.h>
#include <jaio.h>
#include <local.h>


/*
 * Internal function declarations
 */

static int ja_flags();


/*
 * ja_fopen - open a stream associated to a file
 */

ja_FILE *ja_fopen(filename, mode)
char *filename;
char *mode;
{
    FILE *fp;

    fp = fopen(filename, mode);
    if (fp == NULL) {
	return NULL;
    }
    return ja_create_stream(mode, fp, NULL);
}


/*
 * ja_create_stream - create a stream from standard I/O stream
 *
 * Requires:
 *   	FP is a valid pointer to a standard I/O stream, which has been
 *	(re)opened with MODE as an access mode.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *   	Attempts to open a stream, using FP as an underlying standard
 *	I/O stream.  The stream pointed to by STREAM is used as a
 *	resulting stream unless STREAM is a null pointer, in which
 *	case a new stream is created.  Returns the resulting stream on
 *	success; otherwise returns a null pointer.
 */

ja_FILE *ja_create_stream(mode, fp, stream)
char *mode;
FILE *fp;
ja_FILE *stream;
{
    int flags;

    flags = ja_flags(mode);
    if (flags < 0) {
	return NULL;
    }

    if (stream == NULL) {
	stream = ja_flookup();
	if (stream == NULL) {
	    return NULL;
	}
    }

    stream->fp = fp;
    stream->base = NULL;
    stream->ptr = NULL;
    stream->cnt = 0;
    stream->flags = flags;
    stream->flush = NULL;
    stream->charset = CSET_ASCII;
    stream->fc_ascii = FC_ASCII;
    stream->fc_jis = FC_JISX0208_83;
    stream->decoder = NULL;
    stream->tty = -1;
    stream->bytes = NULL;

    switch (mode[0]) {
    case 'r':
	stream->csd = DEFAULT_INPUT_CODING_SYSTEM;
	break;
    case 'w':
    case 'a':
	stream->csd = DEFAULT_OUTPUT_CODING_SYSTEM;
	break;
    default:
	/* can't happen ... */
	return NULL;
    }
    return stream;
}


/*
 * ja_flags
 */

static int ja_flags(mode)
char *mode;
{
    int flags;

    switch (mode[0]) {
    case 'r':
	flags = ja_READING;	/* read */
	break;
    case 'w':
    case 'a':
	flags = ja_WRITING;	/* write */
	break;
    default:
	return -1;
    }
    if (mode[1] == '+' || (mode[1] == 'b' && mode[2] == '+')) {
	flags = ja_UPDATE;	/* read & write */
    }
    return flags;
}
