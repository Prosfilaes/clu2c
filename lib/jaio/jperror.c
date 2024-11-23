/*
 * jperror.c - implementation of ja_perror
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jperror.c,v 2.0 1996/06/10 08:59:41 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_perror
 */

void ja_perror(s)
ja_char *s;
{
    ja_fputs(s, ja_stderr);
    ja_fflush(ja_stderr);
    perror("");
}
