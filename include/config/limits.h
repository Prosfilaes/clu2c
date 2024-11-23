/*
 * limits.h - configured version of <limits.h>
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: limits.h,v 2.0 1996/06/10 09:05:41 ushijima Exp $
 */

#ifndef CONFIG_LIMITS_H
#define CONFIG_LIMITS_H


#include <config.h>


#ifdef STDC_HEADERS
#   include <limits.h>
#else
#   ifdef HAVE_VALUES_H
#	include <values.h>
#	define INT_MAX MAXINT
#   endif
#endif

#ifndef CHAR_BIT
#   define CHAR_BIT 8
#endif

#ifndef INT_MAX
#   ifdef MAXINT
#	define INT_MAX MAXINT
#   else
#	define _INT_BIT (sizeof(int) * CHAR_BIT)
#	define _INT_MSB (1 << (_INT_BIT - 2))
#	define INT_MAX ((_INT_MSB - 1) + _INT_MSB)
#   endif
#endif

#ifndef INT_MIN
#   define INT_MIN (-INT_MAX-1)
#endif

#ifndef UINT_MAX
#   define _UINT_BIT (sizeof(unsigned) * CHAR_BIT)
#   define _UINT_MSB ((unsigned) (1 << (_UINT_BIT - 1)))
#   define UINT_MAX ((_UINT_MSB - 1) + _UINT_MSB)
#endif


#endif /* not CONFIG_LIMITS_H */
