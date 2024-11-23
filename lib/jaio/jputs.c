/*
 * jputs.c - implementation of ja_puts
 *
 * Copyright (c) 1995
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jputs.c,v 2.0 1996/06/10 08:59:44 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_puts - put line to stream
 *
 * Modifies:
 *	The stream pointed to by ja_stdout.
 */

int ja_puts(string)
ja_char *string;
{
    if (ja_fputs(string, ja_stdout) == EOF) {
	return EOF;
    }
    return ja_putchar('\n');
}
