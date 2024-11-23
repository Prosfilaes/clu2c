/*
 * tanh.c - hyperbolic tangent
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: tanh.c,v 2.1 1996/10/07 05:06:36 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * tanh = proc(R: real) returns(real) signals(overflow, underflow)
 *
 * Effects:
 *	Returns the hyperbolic tangent of R.
 */

AFtanh(r)
real r;
{
    RETURN1(OFreal_D__d2r(tanh(OFreal_D__r2d(r))));
}
