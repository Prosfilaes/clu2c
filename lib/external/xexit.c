/*
 * xexit.c - interface to exit
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xexit.c,v 2.4 1997/02/05 09:56:10 ushijima Exp $
 */

#include <config/stdlib.h>

#include <clu2c.h>


/*
 * _external_exit = proc(status: int)
 */

int AF__external__exit(status)
int status;
{
    exit(status);
}
