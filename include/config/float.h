/*
 * float.h - configured version of <float.h>
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: float.h,v 2.0 1996/06/10 09:05:40 ushijima Exp $
 */

#ifndef CONFIG_FLOAT_H
#define CONFIG_FLOAT_H


#include <config.h>


#ifdef HAVE_FLOAT_H
#   include <float.h>
#else
#   ifdef HAVE_VALUES_H
#	include <math.h>
#	include <values.h>
#	define FLT_ROUNDS	1 /* really? */
#	define FLT_RADIX	2 /* really? */
#	define FLT_MANT_DIG	FSIGNIF
#	define FLT_DIG		((int) ((FLT_MANT_DIG - 1) * log10(FLT_RADIX)))
#	define FLT_MIN_EXP	(FMINEXP + FSIGNIF - 1)
#	define FLT_MIN_10_EXP	((int) log10(FLT_MIN))
#	define FLT_MAX_EXP	FMAXEXP
#	define FLT_MAX_10_EXP	((int) log10(FLT_MAX))
#	define FLT_MAX		MAXFLOAT
#	define FLT_EPSILON	((float) ldexp(1.0, 1 - FLT_MANT_DIG))
#	define FLT_MIN		((float) ldexp(1.0, FLT_MIN_EXP - 1))
#	define DBL_MANT_DIG	DSIGNIF
#	define DBL_DIG		((int) ((DBL_MANT_DIG - 1) * log10(FLT_RADIX)))
#	define DBL_MIN_EXP	(DMINEXP + DSIGNIF - 1)
#	define DBL_MIN_10_EXP	((int) log10(DBL_MIN))
#	define DBL_MAX_EXP	DMAXEXP
#	define DBL_MAX_10_EXP	((int) log10(DBL_MAX))
#	define DBL_MAX		MAXDOUBLE
#	define DBL_EPSILON	ldexp(1.0, 1 - DBL_MANT_DIG)
#	define DBL_MIN		ldexp(1.0, DBL_MIN_EXP - 1)
#   else
	/* We assume IEEE 754.  */
#	define FLT_ROUNDS	1
#	define FLT_RADIX	2
#	define FLT_MANT_DIG	24
#	define FLT_DIG		6
#	define FLT_MIN_EXP	-125
#	define FLT_MIN_10_EXP	-37
#	define FLT_MAX_EXP	128
#	define FLT_MAX_10_EXP	38
#	define FLT_MAX		((float) 3.40282347e+38)
#	define FLT_EPSILON	((float) 1.19209290e-07)
#	define FLT_MIN		((float) 1.17549435e-38)
#	define DBL_MANT_DIG	53
#	define DBL_DIG		15
#	define DBL_MIN_EXP	-1021
#	define DBL_MIN_10_EXP	-307
#	define DBL_MAX_EXP	1024
#	define DBL_MAX_10_EXP	308
#	define DBL_MAX		1.7976931348623157e+308
#	define DBL_EPSILON	2.2204460492503131e-16
#	define DBL_MIN		2.2250738585072014e-308
#   endif
#endif


#endif /* not CONFIG_FLOAT_H */
