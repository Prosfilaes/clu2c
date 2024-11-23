/*
 * xargc.c - interface to argc
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xargc.c,v 2.4 1997/02/05 09:56:00 ushijima Exp $
 */

#include <clu2c.h>

extern int gargc;


/*
 * _external_argc = proc() returns(int)
 */

int AF__external__argc()
{
    RETURN1(gargc);
}
