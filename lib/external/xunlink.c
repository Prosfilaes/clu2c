/*
 * xunlink.c - interface to _external_unlink
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xunlink.c,v 2.4 1997/02/05 09:56:25 ushijima Exp $
 */

#include <config/unistd.h>

#include <clu2c.h>


/*
 * _external_unlink = proc(path: string) signals(not_possible(string))
 */

int AF__external__unlink(path)
string path;
{
    if (unlink(OFstring_D__s2cs(path)) < 0) {
	syserror();
	return SIG;
    }
    RETURN0;
}
