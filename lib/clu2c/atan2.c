/*
 * atan2.c - arc tangent
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: atan2.c,v 2.1 1996/10/07 05:06:49 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * atan2 = proc(y, x: real) returns(real) signals(undefined, underflow)
 *
 * Effects:
 *	Signals UNDEFINED if both X and Y are zero; otherwise returns
 *	the arc tangent of Y/X in the range [-PI, +PI] radians.
 */

AFatan2(y, x)
real y;
real x;
{
    double dx, dy;

    dx = OFreal_D__r2d(x);
    dy = OFreal_D__r2d(y);
    if (dx == 0.0 && dy == 0.0) {
	SIGNAL0(SLUNDEFINED);
    }
    RETURN1(OFreal_D__d2r(atan2(dy, dx)));
}
