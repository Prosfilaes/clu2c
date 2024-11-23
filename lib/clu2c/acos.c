/*
 * acos.c - arc cosine
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: acos.c,v 2.1 1996/10/07 05:06:52 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * acos = proc(R: real) returns(real) signals(undefined, underflow)
 *
 * Effects:
 *   	Signals `undefined' if R is less than -1 or greater than 1;
 *	otherwise returns the arc cosine of R in the range [0, PI]
 *	radians.
 */

AFacos(r)
real r;
{
    double d;

    d = OFreal_D__r2d(r);
    if (d < -1.0 || 1.0 < d) {
	SIGNAL0(SLUNDEFINED);
    }
    RETURN1(OFreal_D__d2r(acos(d)));
}
