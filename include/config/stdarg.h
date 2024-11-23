/*
 * stdarg.h - header for variable argument list handling
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: stdarg.h,v 2.0 1996/06/10 09:05:44 ushijima Exp $
 */

#ifndef CONFIG_STDARG_H
#define CONFIG_STDARG_H


#include <config.h>


#ifdef HAVE_STDARG_H
#   include <stdarg.h>
#   define VA_ARGS(x, y) (y)
#   define VA_AND ,
#   define VA_DCL ...
#   define VA_LIST va_list
#   define VA_START(x, y) va_start(x, y)
#   define VA_ARG(x, y) va_arg(x, y)
#   define VA_END(x) va_end(x)
#else
#   include <varargs.h>
#   define VA_ARGS(x, y) x y
#   define VA_AND ;
#   define VA_DCL va_dcl
#   define VA_LIST va_list
#   define VA_START(x, y) va_start(x)
#   define VA_ARG(x, type) va_arg(x, y)
#   define VA_END(x) va_end(x)
#endif


#endif /* not CONFIG_STDARG_H */
