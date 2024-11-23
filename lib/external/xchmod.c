/*
 * xchmod.c - interface to chmod
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xchmod.c,v 2.4 1997/02/05 09:56:04 ushijima Exp $
 */

#include <config/unistd.h>

#include <clu2c.h>


/*
 * _external_chmod = proc(path: string, mode: int) signals(not_possible(string))
 */

int AF__external__chmod(path, mode)
char *path;
int mode;
{
    if (chmod(OFstring_D__s2cs(path), mode) < 0) {
	syserror();
	return SIG;
    }
    RETURN0;
}
