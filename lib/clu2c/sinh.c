/*
 * sinh.c - hyperbolic sine
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: sinh.c,v 2.1 1996/10/07 05:06:39 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * sinh = proc(R: real) returns(real) signals(overflow, underflow)
 *
 * Effects:
 *	Returns the hyperbolic sine of R.
 */

AFsinh(r)
real r;
{
    RETURN1(OFreal_D__d2r(sinh(OFreal_D__r2d(r))));
}
