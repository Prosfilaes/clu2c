/*
 * stdio.h - header for the standard I/O functions.
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: stdio.h,v 2.0 1996/06/10 09:05:45 ushijima Exp $
 */

#ifndef CONFIG_STDIO_H
#define CONFIG_STDIO_H


#include <config.h>


#if defined(X68000) && !defined(MYUHEAD)
#   define MACRO
#endif

#include <stdio.h>


/* Support for the `setvbuf' function */

#ifndef HAVE_SETVBUF
    /* The <stdio.h> header may define `_IOLBF' and/or `_IONBF' even
       if the `setvbuf' function is not available.  So we must be
       careful not to redefine these macros.  */
#   ifndef _IOFBF
#	define _IOFBF 0
#   endif
#   ifndef _IOLBF
#	define _IOLBF 1
#   endif
#   ifndef _IONBF
#	define _IONBF 2
#   endif
    extern int setvbuf();
#endif /* not HAVE_SETVBUF */


#endif /* not CONFIG_STDIO_H */
