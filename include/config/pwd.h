/*
 * pwd.h - header for struct passwd
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: pwd.h,v 2.0 1996/06/10 09:05:43 ushijima Exp $
 */

#ifndef CONFIG_PWD_H
#define CONFIG_PWD_H


#include <config.h>


/*
 * If the system has the <pwd.h> header, it probably has getpwnam and
 * getpwuid.  If there is no such header, getpw* functions are not
 * available.  Here stub version of those functions are provided,
 * which always fail.
 */

#ifdef HAVE_PWD_H
#   include <pwd.h>
#else
#   define getpwnam(u) 0
#   define getpwuid(u) 0
    struct passwd {
	char *pw_name;
	char *pw_passwd;
	int pw_uid;
	int pw_gid;
	int pw_quota;
	char *pw_comment;
	char *pw_gecos;
	char *pw_dir;
	char *pw_shell;
    };
#endif

#define HAVE_PW_PASSWD
#define HAVE_PW_GECOS
#ifdef DJGPP			/* Version 2.xx */
#   undef HAVE_PW_PASSWD
#   undef HAVE_PW_GECOS
#endif


#endif /* not CONFIG_PWD_H */
