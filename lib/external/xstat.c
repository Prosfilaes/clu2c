/*
 * xstat.c - interface to stat
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xstat.c,v 2.4 1997/02/05 09:56:22 ushijima Exp $
 */

#include <config/stat.h>

#include <clu2c.h>


/*
 * _external_stat = proc(path: string) returns(_external_struct_stat)
 *                  signals(not_possible(string))
 */

int AF__external__stat(path)
string path;
{
    static struct stat res;	/* result */

    if (stat(OFstring_D__s2cs(path), &res) < 0) {
	syserror();
	return SIG;
    }
    RETURN1(&res);
}
