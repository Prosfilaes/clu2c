/*
 * stdlib.h - configured version of <stdlib.h>
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: stdlib.h,v 2.0 1996/06/10 09:05:46 ushijima Exp $
 */

#ifndef CONFIG_STDLIB_H
#define CONFIG_STDLIB_H


#include <config.h>


#ifdef STDC_HEADERS
#   include <stdlib.h>
#else
    extern char *getenv();
    extern double strtod();
    extern long strtol();
#endif


/* Support for the exit function */

#ifndef EXIT_SUCCESS
#   define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#   define EXIT_FAILURE 1
#endif


/* Support for the atexit function */

#ifndef HAVE_ATEXIT
#   ifdef HAVE_ON_EXIT
	extern int on_exit();
#	define atexit(x) on_exit(x, 0)
#   else
#	define atexit(x) (-1)
#   endif
#endif


#endif /* not CONFIG_STDLIB_H */
