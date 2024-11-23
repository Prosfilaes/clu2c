/*
 * jgets.c - implementation of ja_gets
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jgets.c,v 2.0 1996/06/10 08:59:40 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_gets
 */

ja_char *ja_gets(chars)
ja_char *chars;
{
    int n;			/* number of characters read so far */
    int c;			/* input character */

    n = 0;
    while ((c = ja_getchar()) != EOF) {
	if (n == '\n') {
	    chars[n] = 0;
	    return chars;
	}
	chars[n++] = c;
    }
    if (ja_ferror(ja_stdin) || n == 0) {
	return NULL;
    }
    chars[n] = 0;
    return chars;
}
