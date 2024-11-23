/*
 * xgetenv.c - interface to getenv
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xgetenv.c,v 2.5 1997/02/06 09:50:45 ushijima Exp $
 */

#include <config/stdlib.h>

#include <clu2c.h>


/*
 * _external_getenv = proc(name: string) returns(string) signals(not_found)
 */

int AF__external__getenv(name)
string name;
{
    char *value;

    value = getenv(OFstring_D__s2cs(name));
    if (!value) {
	SIGNAL0(SLNOT_FOUND);
    }
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(value)));
}
