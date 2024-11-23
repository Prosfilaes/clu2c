/*
 * dfltroot.c - get default root directory
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: dfltroot.c,v 2.1 1996/10/07 05:06:45 ushijima Exp $
 */

#include <clu2c.h>

#include <dfltroot.h>


/*
 * default_root_directory = proc() returns(string)
 */

int AFdefault__root__directory()
{
    RETURN1(OFstring_D__cs2s(CLU2C_ROOTDIR));
}
