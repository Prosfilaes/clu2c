/*
 * log.c - natural logarithm
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: log.c,v 2.1 1996/10/07 05:06:43 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * log = proc(R: real) returns(real)
 *	 signals(complex_result, undefined, overflow, underflow)
 *
 * Effects:
 *   	Signals COMPLEX_RESULT if R is negative; signals UNDEFINED if
 *	R is zero; otherwise returns the natural logarithm of R.
 */

AFlog(r)
real r;
{
    double d;

    d = OFreal_D__r2d(r);
    if (d < 0.0) {
	SIGNAL0(SLCOMPLEX_RESULT);
    } else if (d == 0.0) {
	SIGNAL0(SLUNDEFINED);
    }
    RETURN1(OFreal_D__d2r(log(d)));
}
