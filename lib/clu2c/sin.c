/*
 * sin.c - sine
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: sin.c,v 2.1 1996/10/07 05:06:40 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * sin = proc(R: real) returns(real) signals(underflow)
 *
 * Effects:
 *	Returns the sine of R (measured in radians).
 */

AFsin(r)
real r;
{
    RETURN1(OFreal_D__d2r(sin(OFreal_D__r2d(r))));
}
