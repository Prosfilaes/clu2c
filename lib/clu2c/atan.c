/*
 * atan.c - arc tangent
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: atan.c,v 2.1 1996/10/07 05:06:50 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * atan = proc(R: real) returns(real) signals(underflow)
 *
 * Effects:
 *   	Returns the arc tangent of R in the range [-PI/2, +PI/2]
 *	radians.
 */

AFatan(r)
real r;
{
    RETURN1(OFreal_D__d2r(atan(OFreal_D__r2d(r))));
}
