/*
 * unistd.h - configured version of <unistd.h>
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: unistd.h,v 2.0 1996/06/10 09:05:48 ushijima Exp $
 */

#ifndef CONFIG_UNISTD_H
#define CONFIG_UNISTD_H


#include <config.h>


/*
 * Required for size_t.
 */

#ifdef HAVE_SYS_TYPES_H
#   include <sys/types.h>
#endif


#ifdef HAVE_UNISTD_H
#   include <unistd.h>
#else
    extern char *getcwd();
#   if defined(MSDOS) || defined(X68000)
#	define ttyname(fd) "con"
#   else
	extern char *ttyname();
#   endif
#endif


#endif /* not CONFIG_UNISTD_H */
