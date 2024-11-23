/*
 * xargv.c - interface to argv
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xargv.c,v 2.4 1997/02/05 09:56:01 ushijima Exp $
 */

#include <clu2c.h>

extern int gargc;
extern char **gargv;


/*
 * _external_argv = proc(i: int) returns(string) signals(bounds)
 */

int AF__external__argv(i)
int i;
{
    if (i < 0 || gargc <= i) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(gargv[i])));
}
