/*
 * sqrt.c - square root
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: sqrt.c,v 2.1 1996/10/07 05:06:38 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * sqrt = proc(R: real) returns(real)
 *        signals(complex_result, overflow, underflow)
 *
 * Effects:
 *   	Signals COMPLEX_RESULT if R is negative; otherwise returns the
 *	square root of R.
 */

AFsqrt(r)
real r;
{
    double d;

    d = OFreal_D__r2d(r);
    if (d < 0.0) {
	SIGNAL0(SLCOMPLEX_RESULT);
    }
    RETURN1(OFreal_D__d2r(sqrt(d)));
}
