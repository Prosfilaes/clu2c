/*
 * time.h - header for time-related functions
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: time.h,v 2.0 1996/06/10 09:05:47 ushijima Exp $
 */

#ifndef CONFIG_TIME_H
#define CONFIG_TIME_H


#include <config.h>


/*
 * Required for time_t.
 */

#ifdef HAVE_SYS_TYPES_H
#   include <sys/types.h>
#endif


/*
 * Some systems have a problem with including both <sys/time.h> and
 * <time.h>.  On those systems, <sys/types.h> includes <time.h>.
 */

#ifdef TIME_WITH_SYS_TIME
#   include <sys/time.h>
#   include <time.h>
#else
#   ifdef HAVE_SYS_TIME_H
#	include <sys/time.h>
#   else
#	include <time.h>
#   endif
#endif


/*
 * Support for the clock function.
 */

#ifdef HAVE_CLOCK
#   ifndef CLOCKS_PER_SEC
	/* Seems to work at least for SunOS 4.1.  */
#	define CLOCKS_PER_SEC 1000000
#   endif
#else
#   ifdef X68000
	/* Uses the ONTIME call.  */
#	define IOCS_INLINE
#	include <iocslib.h>
#	define clock_t int
#	define CLOCKS_PER_SEC 1000
#   else
	/* Assumes the existence of getrusage.  */
#	include <sys/resource.h>
#	define clock_t long
#	define CLOCKS_PER_SEC 1000
#   endif
#endif



#endif /* not CONFIG_TIME_H */
