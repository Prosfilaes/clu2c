/*
 * stat.h - header for stat, lstat and fstat
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: stat.h,v 2.0 1996/06/10 09:05:44 ushijima Exp $
 */

#ifndef CONFIG_STAT_H
#define CONFIG_STAT_H


#include <config.h>


/*
 * The <sys/types.h> header is needed because the definition of the
 * stat structure may refer types defined in it.
 */

#ifdef HAVE_SYS_TYPES_H
#   include <sys/types.h>
#endif


/*
 * On most systems the stat structure is defined in the <sys/stat.h>
 * header, while a few systems provides the definition in the <stat.h>
 * header.
 */

#ifdef HAVE_SYS_STAT_H
#   include <sys/stat.h>
#else
#   ifdef HAVE_STAT_H
#	include <stat.h>
#   endif
#endif


/*
 * Macro definitions for getting file type from the `st_mode' member.
 * It seems that S_IFMT, S_IFCHR, S_IFDIR, and S_IFREG are defined on
 * all systems.
 */

#define S_IFNONEXISTENT (~S_IFMT)
#ifndef S_IFBLK
#   define S_IFBLK S_IFNONEXISTENT
#endif
#ifndef S_IFIFO
#   define S_IFIFO S_IFNONEXISTENT
#endif
#ifndef S_IFLNK
#   define S_IFLNK S_IFNONEXISTENT
#endif


#endif /* not CONFIG_STAT_H */
