/*
 * dirent.h - header for struct dirent
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: dirent.h,v 2.0 1996/06/10 09:05:39 ushijima Exp $
 */

#ifndef CONFIG_DIRENT_H
#define CONFIG_DIRENT_H


#include <config.h>


/*
 * The <sys/type.h> header is needed for off_t on some systems.
 */

#ifdef HAVE_SYS_TYPES_H
#   include <sys/types.h>
#endif


#ifdef HAVE_DIRENT_H
#   include <dirent.h>
#else
#   define dirent direct
#   ifdef HAVE_SYS_NDIR_H
#	include <sys/ndir.h>
#   endif
#   ifdef HAVE_SYS_DIR_H
#	include <sys/dir.h>
#   endif
#   ifdef HAVE_NDIR_H
#	include <ndir.h>
#   endif
#endif


#endif /* not CONFIG_DIRENT_H */
