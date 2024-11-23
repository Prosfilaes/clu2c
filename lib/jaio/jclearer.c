/*
 * jclearer.c - implementation of ja_clearerr
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jclearer.c,v 2.0 1996/06/10 08:59:15 ushijima Exp $
 */

#include <jaio.h>
#undef ja_clearerr


/*
 * ja_clearerr
 */

void ja_clearerr(stream)
ja_FILE *stream;
{
    ja_mclearerr(stream);
}
