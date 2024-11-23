/*
 * xgetpwna.c - interface to getpwnam
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xgetpwna.c,v 2.5 1997/02/05 09:56:14 ushijima Exp $
 */

#include <config/pwd.h>

#include <clu2c.h>


/*
 * _external_getpwnam = proc(user: string) returns(_external_struct_passwd)
 *                      signals(not_found)
 */

int AF__external__getpwnam(user)
string user;
{
    struct passwd *res;		/* result */

    res = getpwnam(OFstring_D__s2cs(user));
    if (!res) {
	SIGNAL0(SLNOT_FOUND);
    }
    RETURN1(res);
}
