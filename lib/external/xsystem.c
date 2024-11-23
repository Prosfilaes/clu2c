/*
 * xsystem.c - interface to system
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xsystem.c,v 2.5 1997/02/05 09:56:24 ushijima Exp $
 */

#include <clu2c.h>


/*
 * _external_system = proc(comand: string) returns(int)
 */

int AF__external__system(command)
string command;
{
    RETURN1(system(OFstring_D__s2cs(command)));
}
