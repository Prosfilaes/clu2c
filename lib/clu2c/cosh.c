/*
 * cosh.c - hyperbolic cosine
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: cosh.c,v 2.1 1996/10/07 05:06:46 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * cosh = proc(R: real) returns(real) signals(overflow, underflow)
 *
 * Effects:
 *	Returns the hyperbolic cosine of R.
 */

AFcosh(r)
real r;
{
    RETURN1(OFreal_D__d2r(cosh(OFreal_D__r2d(r))));
}
