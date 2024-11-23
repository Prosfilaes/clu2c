/*
 * tan.c - tangent
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: tan.c,v 2.1 1996/10/07 05:06:37 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * tan = proc(R: real) returns(real) signals(underflow)
 *
 * Effects:
 *	Returns the tangent of R (measured in radians).
 */

AFtan(r)
real r;
{
    RETURN1(OFreal_D__d2r(tan(OFreal_D__r2d(r))));
}
