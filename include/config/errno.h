/*
 * errno.h - header for errno
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: errno.h,v 2.0 1996/06/10 09:05:40 ushijima Exp $
 */

#ifndef CONFIG_ERRNO_H
#define CONFIG_ERRNO_H


#include <config.h>


/*
 * On most systems this variable is declared in the <errno.h> header,
 * but a few systems provides the declaration in the <error.h> header.
 */

#ifdef HAVE_ERRNO_H
#   include <errno.h>
#else
#   ifdef HAVE_ERROR_H
#	include <error.h>
#   else
	extern int errno;
#   endif
#endif


#endif /* not CONFIG_ERRNO_H */
