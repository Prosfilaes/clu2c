/*
 * jputchar.c - implementation of ja_putchar
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jputchar.c,v 2.0 1996/06/10 08:59:43 ushijima Exp $
 */

#include <jaio.h>
#undef ja_putchar


/*
 * ja_putchar - put character to standard output
 *
 * Modifies:
 *	The stream pointed to by ja_stdout.
 *
 * Effects:
 * 	This function is equivalent to ja_putc with the second
 *	argument ja_stdout.
 */

int ja_putchar(c)
int c;
{
    return ja_mputchar(c);
}
