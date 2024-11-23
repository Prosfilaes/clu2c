/*
 * bool.c - implementation of bool
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: bool.c,v 2.8 1996/10/07 05:01:15 ushijima Exp $
 */

#include <clu2c.h>


/*
 * Operations
 */


/*
 * and = proc(b1, b2: bool) returns(bool)
 */

int OFbool_Dand(b1, b2)
bool b1;
bool b2;
{
    RETURN1(OMbool_Dand(b1, b2));
}


/*
 * or = proc(b1, b2: bool) returns(bool)
 */

int OFbool_Dor(b1, b2)
bool b1;
bool b2;
{
    RETURN1(OMbool_Dor(b1, b2));
}


/*
 * not = proc(b: bool) returns(bool)
 */

int OFbool_Dnot(b)
bool b;
{
    RETURN1(OMbool_Dnot(b));
}


/*
 * equal = proc(b1, b2: bool) returns(bool)
 */

int OFbool_Dequal(b1, b2)
bool b1;
bool b2;
{
    RETURN1(OMbool_Dequal(b1, b2));
}


/*
 * similar = proc(b1, b2: bool) returns(bool)
 */

int OFbool_Dsimilar(b1, b2)
bool b1;
bool b2;
{
    RETURN1(OMbool_Dsimilar(b1, b2));
}


/*
 * copy = proc(b: bool) returns(bool)
 */

int OFbool_Dcopy(b)
bool b;
{
    RETURN1(OMbool_Dcopy(b));
}


/*
 * print = proc(b: bool, pst: pstream)
 */

int OFbool_Dprint(b, pst)
bool b;
object pst;			/* pstream */
{
    static string false = 0;
    static string true = 0;

    string text;

    if (!false) {
	false = OFstring_D__cs2s("false");
	true = OFstring_D__cs2s("true");
    }

    if (OFpstream_Dtext(pst, b ? true : false) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*
 * encode = proc(b: bool, ist: istream) signals(not_possible(string))
 */

int OFbool_Dencode(b, ist)
bool b;
object ist;			/* istream */
{
    return OFistream_Dputi(ist, (int) b);
}


/*
 * decode = proc(ist: istream) returns(bool)
 *          signals(end_of_file, not_possible(string))
 */

int OFbool_Ddecode(ist)
object ist;			/* istream */
{
    bool b;

    if (OFistream_Dgeti(ist) == SIG) {
	return(SIG);
    }
    b = (bool) retval_area[0];
    if (b != TRUE && b != FALSE) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    }
    return RET;
}


/*
 * _gcd = proc(b: bool, tab: gcd_tab) returns(int)
 */

int OFbool_D__gcd(b, tab)
bool b;
object tab;			/* gcd_tab */
{
    /* stub version */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("bool$_gcd: not implemented"));
}
