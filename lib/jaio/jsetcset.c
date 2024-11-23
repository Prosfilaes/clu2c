/*
 * jsetcset.c - character set designation utility
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jsetcset.c,v 2.0 1996/06/10 08:59:47 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_setcset - set character set
 *
 * Requires:
 *	The stream pointed to by STREAM is an output or update stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *   	Attempts to designate to G0 the character set specified by CS.
 *	Returns CS on success; otherwise returns EOF.
 */

int ja_setcset(cs, stream)
int cs;
ja_FILE *stream;
{
    FILE *fp = stream->fp;

    switch (cs) {
    case CSET_ASCII:
	putc('\033', fp);
	putc('(', fp);
	putc(stream->fc_ascii, fp);
	break;
    case CSET_JISX0208:
	putc('\033', fp);
	putc('$', fp);
	putc(stream->fc_jis, fp);
	break;
    default:
	return EOF;
    }
    if (stream->tty >= 0) {
	fflush(fp);
    }
    if (ferror(fp)) {
	return EOF;
    }
    return cs;
}
