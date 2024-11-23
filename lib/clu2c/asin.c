/*
 * asin.c - arc sine
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: asin.c,v 2.1 1996/10/07 05:06:51 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * asin = proc(R: real) returns(real) signals(undefined, underflow)
 *
 * Effects:
 *   	Signals `undefined' if R is less than -1 or greater than 1;
 *	otherwise returns the arc sine of R in the range
 *	[-PI/2, +PI/2] radians.
 */

AFasin(r)
real r;
{
    double d;

    d = OFreal_D__r2d(r);
    if (d < -1.0 || 1.0 < d) {
	SIGNAL0(SLUNDEFINED);
    }
    RETURN1(OFreal_D__d2r(asin(d)));
}
