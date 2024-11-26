/*
 * null.c - implementation of null
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: null.c,v 2.8 1996/10/07 05:01:11 ushijima Exp $
 */

#include <clu2c.h>


/*
 * Operations
 */


/*
 * equal = proc(n1, n2: null) returns(bool)
 */

int OFnull_Dequal(null n1, null n2)
{
    RETURN1(OMnull_Dequal(n1, n2));
}


/*
 * similar = proc(n1, n2: null) returns(null)
 */

int OFnull_Dsimilar(null n1, null n2)
{
    RETURN1(OMnull_Dsimilar(n1, n2));
}


/*
 * copy = proc(n: null) returns(null)
 */

int OFnull_Dcopy(null n)
{
    RETURN1(OMnull_Dcopy(n));
}


/*
 * print = proc(n: null, pst: pstream) 
 */

int OFnull_Dprint(null n, object pst)
{
    static string nil = 0;

    if (!nil) {
	nil = OFstring_D__cs2s("nil");
    }

    if (OFpstream_Dtext(pst, nil) == SIG) {
	out_handler();
	return(SIG);
    }
    RETURN0;
}


/*
 * encode = proc(n: null, ist: istream) signals(not_possible(string))
 */

int OFnull_Dencode(null n, object ist)
{
    return OFistream_Dputi(ist, NIL);
}


/*
 * decode = proc(ist: istream) returns(null)
 *          signals(end_of_file, not_possible(string))
 */

int OFnull_Ddecode(object ist)
{
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    if (retval_area[0] != NIL) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    }
    return RET;
}


/*
 * _gcd = proc(n: null, tab: gcd_tab) returns(int)
 */

int OFnull_D__gcd(null n, object tab)
{
    /* stub version */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("null$_gcd: not implemented"));
}
