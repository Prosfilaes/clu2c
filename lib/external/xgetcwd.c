/*
 * xgetcwd.c - interface to getcwd
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xgetcwd.c,v 2.4 1997/02/05 09:56:11 ushijima Exp $
 */

#include <config/errno.h>
#include <config/param.h>
#include <config/unistd.h>

#include <clu2c.h>


/*
 * Figure out whether we need to define getcwd by ourselves.
 */

#if defined(GO32) || defined(X68000)
#   define GETCWD_WITH_GETDCWD
    extern char *getdcwd();
#else
#   if !defined(HAVE_GETCWD) || defined(WITH_GETWD)
#	define GETCWD_WITH_GETWD
	extern char *getwd();
#   endif
#endif


#ifdef GETCWD_WITH_GETDCWD

char *getcwd(buf, size)
char *buf;
#ifdef DJGPP			/* DJGPP Version 2.xx */
size_t size;
#else				/* DJGPP Version 1.xx */
int size;
#endif
{
    return getdcwd(0, buf, size);
}

#endif /* GETCWD_WITH_GETDCWD */


#ifdef GETCWD_WITH_GETWD

char *getcwd(buf, size)
char *buf;
size_t size;
{
    char pathname[MAXPATHLEN];

    if (size <= 0) {
	errno = EINVAL;
	return 0;
    }
    if (!buf) {
	buf = (char *) malloc(size);
	if (!buf) {
	    errno = ENOMEM;
	    return 0;
	}
    }
    if (size < MAXPATHLEN) {
	if (!getwd(pathname)) {
	    return 0;
	}
	if (size < strlen(pathname) + 1) {
	    errno = ERANGE;
	    return 0;
	}
	strcpy(buf, pathname);
    } else {
	if (!getwd(buf)) {
	    return 0;
	}
    }
    return buf;
}

#endif /* GETCWD_WITH_GETWD */


/*
 * _external_getcwd = proc() returns(string) signals(not_possible(string))
 */

int AF__external__getcwd()
{
    static char prev[MAXPATHLEN] = "";
    static string res;

    char buf[MAXPATHLEN];

    if (!getcwd(buf, MAXPATHLEN)) {
	syserror();
	return SIG;
    }
    if (strcmp(buf, prev) != 0) {
	strcpy(prev, buf);
	res = OFstring_D__cs2s(OFstring_D__copy(prev));
    }
    RETURN1(res);
}
