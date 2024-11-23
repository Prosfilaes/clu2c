/*
 * char.c - implementation of char
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: char.c,v 2.10 1996/10/07 05:01:14 ushijima Exp $
 */

#include <clu2c.h>


/*
 * Operations
 */


/*
 * i2c = proc(i: int) returns(char) signals(illegal_char)
 */

int OFchar_Di2c(i)
int i;
{
    if (OMchar_Dillegal__char(i)) {
	SIGNAL0(SLILLEGAL_CHAR);
    }
    RETURN1(OMchar_Di2c(i));
}


/*
 * c2i = proc(c: char) returns(int)
 */

int OFchar_Dc2i(c)
int c;
{
    RETURN1(OMchar_Dc2i(c));
}


/*
 * lt = proc(c1, c2: char) returns(bool)
 */

int OFchar_Dlt(c1, c2)
int c1;
int c2;
{
    RETURN1(OMchar_Dlt(c1, c2));
}


/*
 * le = proc(c1, c2: char) returns(bool)
 */

int OFchar_Dle(c1, c2)
int c1;
int c2;
{
    RETURN1(OMchar_Dle(c1, c2));
}


/*
 * ge = proc(c1, c2: char) returns(bool)
 */

int OFchar_Dge(c1, c2)
int c1;
int c2;
{
    RETURN1(OMchar_Dge(c1, c2));
}


/*
 * gt = proc(c1, c2: char) returns(bool)
 */

int OFchar_Dgt(c1, c2)
int c1;
int c2;
{
    RETURN1(OMchar_Dgt(c1, c2));
}


/*
 * equal = proc(c1, c2: char) returns(bool)
 */

int OFchar_Dequal(c1, c2)
int c1;
int c2;
{
    RETURN1(OMchar_Dequal(c1, c2));
}


/*
 * similar = proc(c1, c2: char) returns(bool)
 */

int OFchar_Dsimilar(c1, c2)
int c1;
int c2;
{
    RETURN1(OMchar_Dsimilar(c1, c2));
}


/*
 * copy = proc(c: char) returns(char)
 */

int OFchar_Dcopy(c)
int c;
{
    RETURN1(OMchar_Dcopy(c));
}


/*
 * print = proc(c: char, pst: pstream)
 */

int OFchar_Dprint(c, pst)
int c;
object pst;
{
    static string quote = 0;
    char text[5];

    if (!quote) {
	quote = OFstring_D__cs2s("'");
    }

    if (OFpstream_Dtext(pst, quote) == SIG) {
	out_handler();
	return SIG;
    }
    if (32 <= c && c <= 127) {
	/* printable character */
	OFstring_Dc2s(c);
	if (OFpstream_Dtext(pst, retval_area[0]) == SIG) {
	    out_handler();
	    return SIG;
	}
    } else {
	/* unprintable character */
	sprintf(text, "\\%03o", (unsigned) c);
	if (OFpstream_Dtext(pst, OFstring_D__cs2s(text)) == SIG) {
	    out_handler();
	    return SIG;
	}
    }
    if (OFpstream_Dtext(pst, quote) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*
 * encode = proc(c: char, ist: istream) signals(not_possible(string))
 */

int OFchar_Dencode(c, ist)
int c;
object ist;			/* istream */
{
    return OFistream_Dputi(ist, (int) c);
}


/*
 * decode = proc(ist: istream) returns(char)
 *          signals(end_of_file, not_possible(string))
 */

int OFchar_Ddecode(ist)
object ist;			/* istream */
{
    return OFistream_Dgeti(ist);
}


/*
 * _gcd = proc(c: char, tab: gcd_tab) returns(int)
 */

int OFchar_D__gcd(c, tab)
int c;
object tab;
{
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("char$_gcd: not implemented"));
}


/*
 * width = proc(c: char) returns(int)
 */

int OFchar_Dwidth(c)
int c;
{
    RETURN1(OMchar_Dwidth(c));
}
