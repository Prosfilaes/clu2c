/*
 * cos.c - cosine
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: cos.c,v 2.1 1996/10/07 05:06:47 ushijima Exp $
 */

#include <math.h>

#include <clu2c.h>


/*
 * cos = proc(R: real) returns(real) signals(underflow)
 *
 * Effects:
 *	Returns the cosine of R (measured in radians).
 */

AFcos(r)
real r;
{
    RETURN1(OFreal_D__d2r(cos(OFreal_D__r2d(r))));
}
