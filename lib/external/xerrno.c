/*
 * xerrno.c - interface to errno
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xerrno.c,v 2.4 1997/02/05 09:56:09 ushijima Exp $
 */

#include <config/errno.h>

#include <clu2c.h>


/*
 * _external_errno = proc() returns(int)
 */

int AF__external__errno()
{
    RETURN1(errno);
}
