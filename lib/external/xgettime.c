/*
 * xgettime.c - get current date and time
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xgettime.c,v 2.4 1997/02/05 09:56:15 ushijima Exp $
 */

#include <config/time.h>

#ifdef X68000
#   define DOS_INLINE
#   include <doslib.h>
#endif

#include <clu2c.h>


/*
 * gettime - get current date and time
 *
 * Modifies:
 *	The integers pointed to by all the arguments.
 *
 * Effects:
 *   	Tries to assign the current date and time to the integers
 *	pointed to by the arguments.  Returns zero on success;
 *	otherwise returns a negative integer.
 */

static int gettime(year, month, day, hour, min, sec)
int *year;
int *month;
int *day;
int *hour;
int *min;
int *sec;
{
#ifdef X68000
    int date;
    int time;
#else  /* not X68000 */
    struct timeval tv;
    struct tm *time;
#endif /* not X68000 */

#ifdef X68000
    date = GETDATE();
    time = GETTIM2();
    *year = ((date >> 9) & 0x7f) + 1980;
    *month = (date >> 5) & 0xf;
    *day = date & 0x1f;
    *hour = time >> 16;
    *min = (time >> 8) & 0xff;
    *sec = time & 0xff;
    return RET;
#else  /* not X68000 */
    if (gettimeofday(&tv, (struct timezone *) 0) < 0) {
	return -1;
    }
    time = localtime(&(tv.tv_sec));
    *year = time->tm_year + 1900;
    *month = time->tm_mon + 1;
    *day = time->tm_mday;
    *hour = time->tm_hour;
    *min = time->tm_min;
    *sec = time->tm_sec;
#endif /* not X68000 */
    return 0;
}


/*
 * _external_gettime = proc() returns(int, int, int, int, int, int)
 *                     signals(not_possible(string))
 */

int AF__external__gettime()
{
    int year, month, day, hour, min, sec;

    if (gettime(&year, &month, &day, &hour, &min, &sec) < 0) {
	syserror();
	return SIG;
    }
    retval_area[0] = year;
    retval_area[1] = month;
    retval_area[2] = day;
    retval_area[3] = hour;
    retval_area[4] = min;
    retval_area[5] = sec;
    return RET;
}
