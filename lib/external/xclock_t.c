/*
 * xclock_t.c - interface to clock_t
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xclock_t.c 2.4 1997/02/05 09:56:07 ushijima Exp $
 */

#include <config/time.h>

#include <clu2c.h>

/*
 * _external_clock_t = cluster is get_sec, get_msec, get_usec
 */


/*
 * get_sec = proc(t: _external_clock_t) returns(int)
 */

int OF__external__clock__t_Dget__sec(t)
clock_t t;
{
    RETURN1(t / CLOCKS_PER_SEC);
}


/*
 * get_msec = proc(t: _external_clock_t) returns(int)
 */

int OF__external__clock__t_Dget__msec(t)
clock_t t;
{
    if (CLOCKS_PER_SEC <= 1) {
	t = 0;
    } else {
	t %= CLOCKS_PER_SEC;
	t *= 1000;
	t /= CLOCKS_PER_SEC;
    }
    RETURN1(t);
}


/*
 * get_usec = proc(t: _external_clock_t) returns(int)
 */

int OF__external__clock__t_Dget__usec(t)
clock_t t;
{
    if (CLOCKS_PER_SEC <= 1000) {
	t = 0;
    } else {
	t %= CLOCKS_PER_SEC;
	t *= 1000;
	t %= CLOCKS_PER_SEC;
	t *= 1000;
	t /= CLOCKS_PER_SEC;
    }
    RETURN1(t);
}
