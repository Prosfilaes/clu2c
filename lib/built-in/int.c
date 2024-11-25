/*
 * int.c - implementation of int
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: int.c,v 2.12 1996/10/07 05:01:13 ushijima Exp $
 */

#include <clu2c.h>
#include <stdio.h>

#define INT_MAX 2147483647	/* maximum integer: 2^31 - 1 */
#define INT_MIN (-INT_MAX - 1)	/* minimum integer: -(2^31) */
#define INT_BITS 32		/* number of bits in integer */

#define MAX_NUM_LEN 30


/*
 * Internal functions
 */


/*
 * _log2 - approximation of base-two logarithm
 *
 * Requires:
 *	X is a positive integer.
 *
 * Effecs:
 *	Returns the integer part of the base-two logarithm of X.
 */

static int OFint_D__log2(x)
int x;
{
    int log;

    for (log = INT_BITS - 2; log > 0; --log) {
	if (x & (1 << log)) {
	    break;
	}
    }
    return log;
}


/*
 * Operations
 */


/*
 * add = proc(i1, i2: int) returns(int) signals(overflow)
 */

int OFint_Dadd(i1, i2)
int i1;
int i2;
{
    if ((i2 > 0 && i1 > INT_MAX - i2) || (i2 < 0 && i1 < INT_MIN - i2)) {
	SIGNAL0(SLOVERFLOW);
    }
    RETURN1(OMint_Dadd(i1, i2));
}


/*
 * sub = proc(i1, i2: int) returns(int) signals(overflow)
 */

int OFint_Dsub(i1, i2)
int i1;
int i2;
{
    if ((i2 < 0 && i1 > INT_MAX + i2) || (i2 > 0 && i1 < INT_MIN + i2)) {
	SIGNAL0(SLOVERFLOW);
    }
    RETURN1(OMint_Dsub(i1, i2));
}


/*
 * mul = proc(i1, i2: int) returns(int) signals(overflow)
 */

int OFint_Dmul(i1, i2)
int i1;
int i2;
{
    int a1, a2, d1, d2;

    /*
     * Handles special cases.
     */
    if (i1 == INT_MIN) {
	switch (i2) {
	case 0:
	    RETURN1(0);
	case 1:
	    RETURN1(INT_MIN);
	default:
	    SIGNAL0(SLOVERFLOW);
	}
    }
    if (i2 == INT_MIN) {
	switch (i1) {
	case 0:
	    RETURN1(0);
	case 1:
	    RETURN1(INT_MIN);
	default:
	    SIGNAL0(SLOVERFLOW);
	}
    }

    /*
     * Checks for the OVERFLOW exception.  Note that we can safely get
     * absolute values of I1 and/or I2 whenever we want because
     * INT_MIN's have already ruled out.
     */
    if (i2 > 1 && i1 > INT_MAX / i2 || i2 < -1 && -i1 > INT_MAX / (-i2)) {
	/* The product is over INT_MAX.  */
	SIGNAL0(SLOVERFLOW);
    } else if (i1 > 1 && i2 < -1 || i1 < -1 && i2 > 1) {
	/*
	 * The product is negative and may be under INT_MIN.  Be
	 * careful not to rule out the case where the product is
	 * INT_MIN.
	 */
	int a1, a2, l1, l2;
	a1 = OMint_Dabs(i1);
	a2 = OMint_Dabs(i2);
	l1 = OFint_D__log2(a1);
	l2 = OFint_D__log2(a2);
	if (l1 + l2 == INT_BITS - 1
	    && (a1 & ~(1 << l1)) == 0
	    && (a2 & ~(1 << l2)) == 0)
	{
	    /* The product is INT_MIN.  */
	    RETURN1(INT_MIN);
	} else if (a1 > INT_MAX / a2) {
	    SIGNAL0(SLOVERFLOW);
	}
    }

    RETURN1(OMint_Dmul(i1, i2));
}


/*
 * minus = proc(i: int) returns(int) signals(overflow)
 */

int OFint_Dminus(i)
int i;
{
    if (i == INT_MIN) {
	SIGNAL0(SLOVERFLOW);
    }
    RETURN1(OMint_Dminus(i));
}


/*
 * div = proc(i1, i2: int) returns(int) signals(zero_divide, overflow)
 */

int OFint_Ddiv(i1, i2)
int i1;
int i2;
{
    /*
     * Note that the behavior of C's division operator is
     * underspecified when ether or both of the operands are negative.
     */

    int t1, t2;			/* temporary */

    if (OMint_Dzero__divide(i2)) {
	SIGNAL0(SLZERO_DIVIDE);
    } else if (i1 == INT_MIN && i2 == -1) {
	/* This check assumes that integers are represented by the
           two's complement format.  */
	SIGNAL0(SLOVERFLOW);
    }
    RETURN1(OMint_Ddiv(i1, i2));
}


/*
 * mod = proc(i1, i2: int) returns(int) signals(zero_divide, overflow)
 */

int OFint_Dmod(i1, i2)
int i1;
int i2;
{
    /*
     * Note that the behavior of C's modulo operator is underspecified
     * when ether or both of the operands are negative.
     */

    int t1, t2;			/* temporary */

    if (OMint_Dzero__divide(i2)) {
	SIGNAL0(SLZERO_DIVIDE);
    }
    RETURN1(OMint_Dmod(i1, i2));
}


/*
 * power = proc(i1, i2: int) returns(int) signals(negative_exponent, overflow)
 */

int OFint_Dpower(i1, i2)
int i1;
int i2;
{
    int res, i;

    if (i2 < 0) {
	SIGNAL0(SLNEGATIVE_EXPONENT);
    } else if (i2 == 0) {
	res = 1;
    } else if (i1 == 0) {
	res = 0;
    } else {
	res = i1;
	for (i = 1; i < i2; i++) {
	    if (OFint_Dmul(res, i1) == SIG) {
		return SIG;
	    }
	    res = retval_area[0];
	}
    }
    RETURN1(res);
}


/*
 * abs = proc(i: int) returns(int) signals(overflow)
 */

int OFint_Dabs(i)
int i;
{
    if (i == INT_MIN) {
	SIGNAL0(SLOVERFLOW);
    }
    RETURN1(OMint_Dabs(i));
}


/*
 * max = proc(i1, i2: int) returns(int)
 */

int OFint_Dmax(i1, i2)
int i1;
int i2;
{
    RETURN1(OMint_Dmax(i1, i2));
}


/*
 * min = proc(i1, i2: int) returns(int)
 */

int OFint_Dmin(i1, i2)
int i1;
int i2;
{
    RETURN1(OMint_Dmin(i1, i2));
}


/*
 * from_to_by = iter(from, to, by: int) yields(int)
 */

#define ARSIZE	3
#define LVfrom	((*ivarp)[0])
#define LVto	((*ivarp)[1])
#define LVby	((*ivarp)[2])

int OFint_Dfrom__to__by(init, ivarp, from, to, by)
bool init;
object **ivarp;
int from;
int to;
int by;
{
    if (init) {
	*ivarp = (object *) malloc_atomic(ARSIZE * sizeof(object));
	LVfrom = from;
	LVto = to;
	LVby = by;
    } else {
	goto resume1;
    }

    while ((LVby > 0)
	   ? (LVfrom <= LVto)
	   : ((LVby < 0) ? (LVfrom >= LVto) : 1))
    {
	retval_area[0] = LVfrom;
	return YIELD;
    resume1:
	LVfrom += LVby;
    }
    RETURN0;
}

#undef ARSIZE
#undef LVfrom
#undef LVto
#undef LVby


/*
 * from_to = iter(from, to: int) yields(int)
 */

#define ARSIZE	2
#define LVfrom	((*ivarp)[0])
#define LVto	((*ivarp)[1])

int OFint_Dfrom__to(init, ivarp, from, to)
bool init;
object **ivarp;
int from;
int to;
{
    if (init) {
	*ivarp = (object *) malloc_atomic(ARSIZE * sizeof(object));
	LVfrom = from;
	LVto = to;
    } else {
	goto resume1;
    }

    while (LVfrom <= LVto) {
	retval_area[0] = LVfrom;
	return YIELD;
      resume1:
	LVfrom++;
    }
    RETURN0;
}

#undef ARSIZE
#undef LVfrom
#undef LVto

 
/*
 * parse = proc(s: string) returns(int) signals(bad_format, overflow)
 */

int OFint_Dparse(s)
string s;
{
    int size;			/* size of S */
    int sign;			/* sign of result */
    int res;			/* result */
    int i;

    size = OMstring_Dsize(s);
    if (size == 0) {
	SIGNAL0(SLBAD_FORMAT);
    }
    sign = 1;
    res = 0;
    for (i = 1; i <= size; i++) {
	int c = OMstring_Dfetch(s, i);
	if (i == 1 && c == '+') {
	    continue;
	} else if (i == 1 && c == '-') {
	    sign = -1;
	} else if (c < '0'|| '9'< c) {
	    SIGNAL0(SLBAD_FORMAT);
	} else if (OFint_Dmul(res, 10) == SIG) {
	    return SIG;
	} else {
	    res = retval_area[0];
	    if (OFint_Dadd(res, sign * (c - '0')) == SIG) {
		return SIG;
	    }
	    res = retval_area[0];
	}
    }
    RETURN1(res);
}


/*
 * unparse = proc(i: int) returns(string)
 */

int OFint_Dunparse(i)
int i;
{
    static char res[MAX_NUM_LEN];

    sprintf(res, "%d", i);
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(res)));
}


/*
 * lt = proc(i1, i2: int) returns(bool)
 */

int OFint_Dlt(i1, i2)
int i1;
int i2;
{
    RETURN1(OMint_Dlt(i1, i2));
}


/*
 * le = proc(i1, i2: int) returns(bool)
 */

int OFint_Dle(i1, i2)
int i1;
int i2;
{
    RETURN1(OMint_Dle(i1, i2));
}


/*
 * ge = proc(i1, i2: int) returns(bool)
 */

int OFint_Dge(i1, i2)
int i1;
int i2;
{
    RETURN1(OMint_Dge(i1, i2));
}


/*
 * gt = proc(i1, i2: int) returns(bool)
 */

int OFint_Dgt(i1, i2)
int i1;
int i2;
{
    RETURN1(OMint_Dgt(i1, i2));
}


/*
 * equal = proc(i1, i2: int) returns(bool)
 */

int OFint_Dequal(i1, i2)
int i1;
int i2;
{
    RETURN1(OMint_Dequal(i1, i2));
}


/*
 * similar = proc(i1, i2: int) returns(bool)
 */

int OFint_Dsimilar(i1, i2)
int i1;
int i2;
{
    RETURN1(OMint_Dsimilar(i1, i2));
}


/*
 * copy = proc(i: int) returns(bool)
 */

int OFint_Dcopy(i)
int i;
{
    RETURN1(OMint_Dcopy(i));
}


/*
 * print = proc(i: int, pst: pstream)
 */

int OFint_Dprint(i, pst)
int i;
object pst;			/* pstream */
{
    OFint_Dunparse(i);
    if (OFpstream_Dtext(pst, retval_area[0]) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*
 * encode = proc(i: int, ist: istream) signals(not_possible(string))
 */

int OFint_Dencode(i, ist)
int i;
object ist;			/* istream */
{
    return OFistream_Dputi(ist, i);
}


/*
 * decode = proc(ist: istream) returns(int)
 *          signals(end_of_file, not_possible(string))
 */

int OFint_Ddecode(ist)
object ist;			/* istream */
{
    return OFistream_Dgeti(ist);
}


/*
 * _gcd = proc(i: int, tab: gcd_tab) returns(int)
 */

int OFint_D__gcd(i, tab)
int i;
object tab;			/* gcd_tab */
{
    /* stub version */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("int$_gcd: not implemented"));
}


/*
 * Hidden operations
 */


/*
 * _div
 */

int OFint_D__div(i1, i2)
int i1;
int i2;
{
    int quotient;
    int remainder;

    quotient = i1 / i2;
    remainder = i1 % i2;
    if (remainder >= 0) {
	return quotient;
    } else if (i2 > 0) {
	return quotient - 1;
    } else {
	return quotient + 1;
    }
}


/*
 * _mod
 */

int OFint_D__mod(i1, i2)
int i1;
int i2;
{
    int remainder;

    remainder = i1 % i2;
    if ((i1 >= 0 && i2 > 0) || remainder >= 0) {
	return remainder;
    } else if (i2 > 0) {
	return remainder + i2;
    } else {
	return -(i2 - remainder);
    }
}
