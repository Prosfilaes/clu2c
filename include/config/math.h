/*
 * math.h - configured version of <math.h>
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: math.h,v 2.0 1996/06/10 09:05:41 ushijima Exp $
 */

#ifndef CONFIG_MATH_H
#define CONFIG_MATH_H


#include <math.h>

#ifndef HUGE_VAL
#   ifdef HUGE
#	define HUGE_VAL HUGE
#   else
#	include <config/float.h>
#	define HUGE_VAL DBL_MAX
#   endif
#endif


#endif /* not CONFIG_MATH_H */
