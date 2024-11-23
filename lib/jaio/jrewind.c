/*
 * jrewind.c - implementation of ja_rewind
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jrewind.c,v 2.0 1996/06/10 08:59:45 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_rewind - rewind stream
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *	Every invocation of this function is equivalent to
 *	    (void) ja_fseek(STREAM, 0L, SEEK_SET)
 */

void ja_rewind(stream)
ja_FILE *stream;
{
    ja_fseek(stream, 0L, SEEK_SET);
}
