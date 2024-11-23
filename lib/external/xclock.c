/*
 * xclock.c - interface to clock
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xclock.c,v 2.4 1997/02/05 09:56:05 ushijima Exp $
 */

#include <config/time.h>

#include <clu2c.h>


/*
 * Private implementation of the clock function.
 */

#ifndef HAVE_CLOCK

#ifdef X68000

static clock_t clock()
{
    return ONTIME();
}

#else  /* not X68000 */

static clock_t clock()
{
    struct rusage usage;

    if (getrusage(RUSAGE_SELF, &usage) < 0) {
	return -1;
    }
    return ((usage.ru_utime.tv_sec * 1000 + usage.ru_utime.tv_usec / 1000)
	    + (usage.ru_stime.tv_sec * 1000 + usage.ru_stime.tv_usec / 1000));
}

#endif /* not X68000 */

#endif /* not HAVE_CLOCK */



/*
 * _external_clock = proc() returns(__external_clock_t)
 *                   signals(not_possible(string))
 */

AF__external__clock()
{
    clock_t time;

    time = clock();
    if (time < 0) {
	syserror();
	return SIG;
    }
    RETURN1(time);
}
