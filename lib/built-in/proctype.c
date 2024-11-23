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


/*
 * Operations
 */


/*
 * equal = proc(p1, p2: proctype(...)) returns(bool)
 */

int OFproctype_Dequal(p1, p2)
proctype p1;			/* left hand side */
proctype p2;			/* right hand side */
{
    RETURN1(OMproctype_Dequal(p1, p2));
}


/*
 * similar = proc(p1, p2: proctype(...)) returns(bool)
 */

int OFproctype_Dsimilar(p1, p2)
proctype p1;			/* left hand side */
proctype p2;			/* right hand side */
{
    RETURN1(OMproctype_Dsimilar(p1, p2));
}


/*
 * copy = proc(p: proctype(...)) returns(proctype(...))
 */

int OFproctype_Dcopy(p)
proctype p;			/* target */
{
    RETURN1(OMproctype_Dcopy(p));
}
