/*
 * jgetchar.c - implementation of ja_getchar
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jgetchar.c,v 2.0 1996/06/10 08:59:38 ushijima Exp $
 */

#include <jaio.h>
#undef ja_getchar


/*
 * ja_getchar - get character from standard input
 *
 * Modifies:
 *	The stream pointed to by ja_stdin.
 *
 * Effects:
 *   	This function is equivalent to ja_getc with the argument
 *	ja_stdin.
 */

int ja_getchar()
{
    return ja_mgetchar();
}
