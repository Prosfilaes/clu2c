/*
 * jfputs.c - implementation of ja_fputs
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfputs.c,v 2.0 1996/06/10 08:59:32 ushijima Exp $
 */

#include <jaio.h>

/*
 * ja_fputs - put string to stream
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 */

int ja_fputs(string, stream)
ja_char *string;
ja_FILE *stream;
{
    int size;

    for (size = 0; string[size]; size++) {
	/* empty */
    }

    return ja_fnputs(string, size, stream);
}
