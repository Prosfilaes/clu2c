/*
 * string.h - header for string functions
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: string.h,v 2.0 1996/06/10 09:05:47 ushijima Exp $
 */

#ifndef CONFIG_STRING_H
#define CONFIG_STRING_H


#include <config.h>


/*
 * There is no problem if the system has standard C headers; otherwise
 * it is probably sufficient to declare strchr, strrchr, and strerror.
 * Some systems may not have strchr/strrchr.  Use BSD-equivalents on
 * those system.  Also, some systems may not have strerror.  The
 * global sys_errlist variable is probably available on those systems.
 */

#ifdef STDC_HEADERS
#   include <string.h>
#else
#   ifndef HAVE_STRCHR
#	define strchr index
#	define strrchr rindex
#   endif
    extern char *strchr(), *strrchr();
#   ifdef HAVE_STRERROR
	extern char *strerror();
#   else
	extern char *sys_errlist[];
#	define strerror(n) (sys_errlist[(n)])
#   endif
#endif


/*
 * Configure memory operations.  If the library has memcpy, it
 * probably has memcmp, memset, and so on.  If they are not available,
 * try to substitute BSD functions (bcmp, bcopy, and bzero) for them.
 * In general, however, bcmp can not be used as a replacement for
 * memcmp, and bzero for memset.  In order to increase the chance to
 * use system library functions, the following two macros are defined
 * for restricted use of memset and memcmp:
 *   MEMCLR - clear memory area.
 *   MEMEQ - compare memory areas for equality.
 */

#if defined(HAVE_MEMCPY) && !defined(WITH_BSD_BYTE_OPERATIONS)
#   define MEMCLR(m, n)		memset((m), 0, (n))
#   define MEMEQ(m1, m2, n)	(memcmp((m1), (m2), (n)) == 0)
#else
    extern void bzero();
    extern int bcmp();
    extern void bcopy();
#   define MEMCLR(m, n)		bzero((m), (n))
#   define MEMEQ(m1, m2, n)	(bcmp((m1), (m2), (n)) == 0)
#   define memcpy(d, s, n)	bcopy((s), (d), (n))
#endif


#endif /* not CONFIG_STRING_H */
