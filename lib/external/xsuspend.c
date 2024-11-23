/*
 * xsuspend.c - suspend current process
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xsuspend.c,v 2.4 1997/02/05 09:56:23 ushijima Exp $
 */

#include <clu2c.h>

#ifdef X68000
#   include <process.h>
#else
#   ifndef GO32
#	include <signal.h>
#   endif
#endif

/*
 * _external_suspend = proc()
 */

#define DEFAULT

int AF__external__suspend()
{
#ifdef GO32
    system("command.com");
#   undef DEFAULT
#endif

#ifdef X68000
    /* XC ver1.0 lib has BUG. */
    spawnlp(P_WAIT, "command.x", "command", NULL);
#   undef DEFAULT
#endif

#ifdef DEFAULT
    kill(getpid(), SIGTSTP);
#endif

    return RET;
}
