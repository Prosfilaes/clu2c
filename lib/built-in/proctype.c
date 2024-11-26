/*
 * proctype.c - implementation of proctype
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: proctype.c,v 2.5 1996/10/07 05:01:08 ushijima Exp $
 */

#include <clu2c.h>
#include "proctype.h"


/*
 * Operations
 */


/*
 * equal = proc(p1, p2: proctype(...)) returns(bool)
 */

int OFproctype_Dequal(proctype p1, proctype p2)
{
    RETURN1(OMproctype_Dequal(p1, p2));
}


/*
 * similar = proc(p1, p2: proctype(...)) returns(bool)
 */

int OFproctype_Dsimilar(proctype p1, proctype p2)
{
    RETURN1(OMproctype_Dsimilar(p1, p2));
}


/*
 * copy = proc(p: proctype(...)) returns(proctype(...))
 */

int OFproctype_Dcopy(proctype p)
{
    RETURN1(OMproctype_Dcopy(p));
}
