/*
 * jsetcsys.c - set coding system
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jsetcsys.c,v 2.0 1996/06/10 08:59:48 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_setcsys - set coding system
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *	Returns EOF if CSD is an invalid coding system descriptor;
 *	otherwise modies the coding system associated with the stream
 *	pointed to by STREAM to one specified by the structure pointed to
 *	by CSYS and returns zero.
 */

int ja_setcsys(stream, csys)
ja_FILE *stream;
struct ja_csys *csys;
{
    int csd;

    csd = csys->csys_number;
    if (csd < 0 || csd > MAX_CSYS) {
	return EOF;
    }
    stream->csd = csd;
    stream->flush = NULL;
    stream->fc_ascii = csys->csys_fc_ascii;
    stream->fc_jis = csys->csys_fc_jis;
    if (stream->decoder) {
	ja_reset_decoder(stream->decoder);
	stream->decoder->csd = csd;
    }
    return 0;
}
