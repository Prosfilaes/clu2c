/*
 * xs_tm.c - interface to struct tm
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xs_tm.c,v 2.4 1997/02/05 09:56:21 ushijima Exp $
 */

#include <config/string.h>
#include <config/time.h>

#include <clu2c.h>


/*
 * _external_struct_tm = cluster is
 *	get_sec, get_min, get_hour, get_mday, get_mon, get_year,
 *	get_wday, get_yday, get_isdst, equal, similar, copy
 */


/*
 * get_sec = proc(time: _external_struct_tm) returns(int)
 */

int OF__external__struct__tm_Dget__sec(time)
struct tm *time;
{
    RETURN1(time->tm_sec);
}


/*
 * get_min = proc(time: _external_struct_tm) returns(int)
 */

int OF__external__struct__tm_Dget__min(time)
struct tm *time;
{
    RETURN1(time->tm_min);
}


/*
 * get_hour = proc(time: _external_struct_tm) returns(int)
 */

int OF__external__struct__tm_Dget__hour(time)
struct tm *time;
{
    RETURN1(time->tm_hour);
}


/*
 * get_mday = proc(time: _external_struct_tm) returns(int)
 */

int OF__external__struct__tm_Dget__mday(time)
struct tm *time;
{
    RETURN1(time->tm_mday);
}


/*
 * get_mon = proc(time: _external_struct_tm) returns(int)
 */

int OF__external__struct__tm_Dget__mon(time)
struct tm *time;
{
    RETURN1(time->tm_mon);
}


/*
 * get_year = proc(time: _external_struct_tm) returns(int)
 */

int OF__external__struct__tm_Dget__year(time)
struct tm *time;
{
    RETURN1(time->tm_year);
}


/*
 * get_wday = proc(time: _external_struct_tm) returns(int)
 */

int OF__external__struct__tm_Dget__wday(time)
struct tm *time;
{
    RETURN1(time->tm_wday);
}


/*
 * get_yday = proc(time: _external_struct_tm) returns(int)
 */

int OF__external__struct__tm_Dget__yday(time)
struct tm *time;
{
    RETURN1(time->tm_yday);
}


/*
 * get_isdst = proc(time: _external_struct_tm) returns(bool)
 */

int OF__external__struct__tm_Dget__isdst(time)
struct tm *time;
{
    RETURN1(time->tm_isdst);
}


/*
 * equal = proc(time1, time2: _external_struct_tm) returns(bool)
 */

int OF__external__struct__tm_Dequal(time1, time2)
struct tm *time1;
struct tm *time2;
{
    RETURN1(MEMEQ((char *) time1, (char *) time2, sizeof(struct tm)));
}


/*
 * similar = proc(time1, time2: _external_struct_tm) returns(bool)
 */

int OF__external__struct__tm_Dsimilar(time1, time2)
struct tm *time1;
struct tm *time2;
{
    RETURN1(MEMEQ((char *) time1, (char *) time2, sizeof(struct tm)));
}


/*
 * copy = proc(time: _external_struct_tm) returns(_external_struct_tm)
 */

int OF__external__struct__tm_Dcopy(time)
struct tm *time;
{
    struct tm *res;		/* result */

    res = (struct tm *) malloc(sizeof(struct tm));
    memcpy((char *) res, (char *) time, sizeof(struct tm));
    RETURN1(res);
}
