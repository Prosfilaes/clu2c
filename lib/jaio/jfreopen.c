/*
 * jfreopen.c - implementation of ja_freopen
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfreopen.c,v 2.0 1996/06/10 08:59:33 ushijima Exp $
 */

#include <jaio.h>
#include <local.h>


/*
 * ja_freopen
 */

ja_FILE *ja_freopen(filename, mode, stream)
char *filename;
char *mode;
ja_FILE *stream;
{
    ja_almost_close(stream);
    if (freopen(filename, mode, stream->fp) == NULL) {
	return NULL;
    }
    return ja_create_stream(mode, stream->fp, stream);
}
