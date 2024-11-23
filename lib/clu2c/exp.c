/*
 * exp.c - exponential function
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: exp.c,v 2.1 1996/10/07 05:06:44 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * exp = proc(R: real) returns(real) signals(overflow, underflow)
 *
 * Effects:
 *	Returns the exponential function of R.
 */

AFexp(r)
real r;
{
    RETURN1(OFreal_D__d2r(exp(OFreal_D__r2d(r))));
}
