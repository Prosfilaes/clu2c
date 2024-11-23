/*
 * xchdir.c - interface to chdir
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xchdir.c,v 2.4 1997/02/05 09:56:02 ushijima Exp $
 */

#include <config/unistd.h>

#include <clu2c.h>


/*
 * _external_chdir = proc(path: string) signals(not_possible(string))
 */

int AF__external__chdir(path)
string path;
{
    if (chdir(OFstring_D__s2cs(path)) < 0) {
	syserror();
	return SIG;
    }
    RETURN0;
}
