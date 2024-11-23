/*
 * jgetcsys.c - implementation of ja_getcsys
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jgetcsys.c,v 2.0 1996/06/10 08:59:40 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_getcsys - get coding system
 *
 * Modifies:
 *	The structure pointed to by CSYS.
 *
 * Effects:
 *   	Attempts to set the members of the structure pointed to by
 *	CSYS so that it represents the current coding system
 *	associated with the stream pointed to by STREAM.  Returns zero on
 *	success; otherwise returns a negative integer.
 */

int ja_getcsys(stream, csys)
ja_FILE *stream;
struct ja_csys *csys;
{
    csys->csys_number = stream->csd;
    csys->csys_fc_ascii = stream->fc_ascii;
    csys->csys_fc_jis = stream->fc_jis;
    return 0;
}
