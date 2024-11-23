/*
 * xlocalti.c - interface to localtime
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xlocalti.c,v 2.4 1997/02/05 09:56:16 ushijima Exp $
 */

#include <config/time.h>

#include <clu2c.h>


/*
 * _external_localtime = proc(clock: int) returns(_external_struct_tm)
 */

int AF__external__localtime(clock)
time_t clock;
{
    RETURN1(localtime(&clock));
}
