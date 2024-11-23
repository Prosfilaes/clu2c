/*
 * param.h - header for system parameters
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: param.h,v 2.0 1996/06/10 09:05:42 ushijima Exp $
 */

#ifndef CONFIG_PARAM_H
#define CONFIG_PARAM_H


#include <config.h>


#ifdef HAVE_SYS_PARAM_H
#   include <sys/param.h>
#else
#   define MAXPATHLEN 256	/* may be an underestimate */
#endif


#endif /* not CONFIG_PARAM_H */

