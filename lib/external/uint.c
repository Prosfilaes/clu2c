/*
 * uint.c - unsigned integers
 *
 * Copyright (c) 1997
 * 	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: uint.c,v 1.2 1997/02/05 09:55:59 ushijima Exp $
 */

#include <config/limits.h>
#include <clu2c.h>

#define UINT_BIT (sizeof(unsigned) * CHAR_BIT)

/*
 * uint = data type is create, to_int, add, sub, mul, div, mod, max, min, lt,
 *	  le, ge, gt, and, or, xor, not, shift, parse, hex_parse, oct_parse,
 *	  unparse, hex_unparse, oct_unparse, equal, similar, copy, encode,
 *	  decode, print
 *
 *
 * Overview
 *
 * Objects of type `uint' are immutable and represent nonnegative integers
 * less than UINT_MODULO, where UINT_MODULO = 2 ** UINT_BIT and UINT_BIT is the
 * implementation-defined constant such that UINT_MODULO > Int_Max.
 */


/* Operations */


/*
 * create = proc(I: int) returns(uint) signals(negative_argument)
 *	effects  Signals `negative_argument' if I < 0; otherwise returns the
 *	    unsigned integer that has the same value as I.
 */

int OFuint_Dcreate(i)
object i;
{
    static string str_negative_argument = 0;

    if ((int) i < 0) {
	if (!str_negative_argument)
	    str_negative_argument = OFstring_D__cs2s("negative_argument");
	SIGNAL0(str_negative_argument);
    }
    RETURN1(i);
}


/*
 * to_int = proc(U: uint) returns(int) signals(overflow)
 *	effects  Signals `overflow' if U can not be represented as an `int'
 *	    object; otherwise returns the integer that has the same value as U.
 */

int OFuint_Dto__int(u)
object u;
{
    if ((unsigned) u > INT_MAX) {
	SIGNAL0(SLOVERFLOW);
    }
    RETURN1(u);
}


/*
 * add = proc(U1, U2: uint) returns(U3: uint)
 *	effects  U3 is congruent to (U1 + U2) (modulo UINT_MODULO).
 */

int OFuint_Dadd(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 + (unsigned) u2);
}


/*
 * sub = proc(U1, U2: uint) returns(U3: uint)
 *	effects  U3 is congruent to (U1 - U2) (modulo UINT_MODULO).
 */

int OFuint_Dsub(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 - (unsigned) u2);
}


/*
 * mul = proc(U1, U2: uint) returns(U3: uint)
 *	effects  U3 is congruent to (U1 * U2) (modulo UINT_MODULO).
 */

int OFuint_Dmul(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 * (unsigned) u2);
}


/*
 * div = proc(U1, U2: uint) returns(U3: uint) signals(zero_divide)
 *	effects  Signals `zero_divide' if U2 is zero; otherwise U1 is equal to
 *	    (U2 * U3 + R) for some nonnegative integer R less than U2.
 */

int OFuint_Ddiv(u1, u2)
object u1;
object u2;
{
    if ((unsigned) u2 == 0) {
	SIGNAL0(SLZERO_DIVIDE);
    }
    RETURN1((unsigned) u1 / (unsigned) u2);
}


/*
 * mod = proc(U1, U2: uint) returns(U3: uint) signals(zero_divide)
 *	effects  Signals `zero_divide' if U2 is zero; otherwise U3 is less than
 *	    U2 and U1 is equal to (U2 * Q + U3) for some nonnegative integer Q.
 */

int OFuint_Dmod(u1, u2)
object u1;
object u2;
{
    if ((unsigned) u2 == 0) {
	SIGNAL0(SLZERO_DIVIDE);
    }
    RETURN1((unsigned) u1 % (unsigned) u2);
}


/*
 * max = proc(U1, U2: uint) returns(uint)
 *	effects  Returns the larger of U1 and U2.
 */

int OFuint_Dmax(u1, u2)
object u1;
object u2;
{
    if ((unsigned) u1 > (unsigned) u2) {
	RETURN1(u1);
    } else {
	RETURN1(u2);
    }
}


/*
 * min = proc(U1, U2: uint) returns(uint)
 *	effects  Returns the smaller of U1 and U2.
 */

int OFuint_Dmin(u1, u2)
object u1;
object u2;
{
    if ((unsigned) u1 < (unsigned) u2) {
	RETURN1(u1);
    } else {
	RETURN1(u2);
    }
}


/*
 * lt = proc(U1, U2: uint) returns(bool)
 *	effects  Returns `true' if and only if U1 is less than U2.
 */

int OFuint_Dlt(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 < (unsigned) u2);
}


/*
 * le = proc(U1, U2: uint) returns(bool)
 *	effects  Returns `true' if and only if U1 is less than or equal to U2.
 */

int OFuint_Dle(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 <= (unsigned) u2);
}


/*
 * ge = proc(U1, U2: uint) returns(bool)
 *	effects  Returns `true' if and only if U1 is greater than or equal to
 *	    U2.
 */

int OFuint_Dge(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 >= (unsigned) u2);
}


/*
 * gt = proc(U1, U2: uint) returns(bool)
 *	effects  Returns `true' if and only if U1 is greater than U2.
 */

int OFuint_Dgt(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 > (unsigned) u2);
}


/*
 * and = proc(U1, U2: uint) returns(uint)
 *	effects  Returns the bitwise AND of U1 and U2.
 */

int OFuint_Dand(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 & (unsigned) u2);
}


/*
 * or = proc(U1, U2: uint) returns(uint)
 *	effects  Returns the bitwise inclusive OR of U1 and U2.
 */

int OFuint_Dor(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 | (unsigned) u2);
}


/*
 * xor = proc(U1, U2: uint) returns(uint)
 *	effects  Returns the bitwise exclusive OR of U1 and U2.
 */

int OFuint_Dxor(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 ^ (unsigned) u2);
}


/*
 * not = proc(U: uint) returns(uint)
 *	effects  Returns the one's complement of U.
 */

int OFuint_Dnot(u)
object u;
{
    RETURN1(~((unsigned) u));
}


/*
 * shift = proc(U: uint, COUNT: int) returns(uint)
 *	effects  Returns an unsigned integer that is the result of shifting U
 *	    left by COUNT bit positions if COUNT is positive; otherwise returns
 *	    an unsigned integer that is the result of shifting U right by
 *	    -COUNT bit positions.
 */

int OFuint_Dshift(u, count)
object u;
object count;
{
    if ((int) count > 0) {
	RETURN1((unsigned) u << (int) count);
    } else {
	RETURN1((unsigned) u >> (int) -count);
    }
}


/*
 * parse = proc(S: string) returns(U: uint) signals(bad_format)
 *	effects  Signals `bad_format' if S contains any character other than
 *	    decimal digits; otherwise U is congruent to the integer represented
 *	    by S (modulo UINT_MODULO).
 */

int OFuint_Dparse(s)
object s;
{
    unsigned u;
    int size;
    int i;

    u = 0;
    size = OMstring_Dsize(s);
    if (size == 0) {
	SIGNAL0(SLBAD_FORMAT);
    }
    for (i = 1; i <= size; ++i) {
	int c = OMstring_Dfetch(s, i);
	if (c >= '0' && c <= '9')
	    u = u * 10 + c - '0';
	else {
	    SIGNAL0(SLBAD_FORMAT);
	}
    }
    RETURN1(u);
}


/*
 * hex_parse = proc(S: string) returns(U: uint) signals(bad_format)
 *	effects  Signals `bad_format' if S contains any character other than
 *	    hexadecimal digits; otherwise U is congruent to X (modulo
 *	    UINT_MODULO), where X is the integer represented by S in
 *	    hexadecimal notation.
 */

int OFuint_Dhex__parse(s)
object s;
{
    unsigned u;
    int size;
    int i;

    u = 0;
    size = OMstring_Dsize(s);
    if (size == 0) {
	SIGNAL0(SLBAD_FORMAT);
    }
    for (i = 1; i <= size; ++i) {
	int c = OMstring_Dfetch(s, i);
	if (c >= '0' && c <= '9')
	    u = u * 16 + c - '0';
	else if (c >= 'A' && c <= 'F')
	    u = u * 16 + c - 'A' + 10;
	else if (c >= 'a' && c <= 'f')
	    u = u * 16 + c - 'a' + 10;
	else {
	    SIGNAL0(SLBAD_FORMAT);
	}
    }
    RETURN1(u);
}


/*
 * oct_parse = proc(S: string) returns(U: uint) signals(bad_format)
 *	effects  Signals `bad_format' if S contains any character other than
 *	    octal digits; otherwise U is congruent to X (modulo UINT_MODULO),
 *	    where X is the integer represented by S in octal notation.
 */

int OFuint_Doct__parse(s)
object s;
{
    unsigned u;
    int size;
    int i;

    u = 0;
    size = OMstring_Dsize(s);
    if (size == 0) {
	SIGNAL0(SLBAD_FORMAT);
    }
    for (i = 1; i <= size; ++i) {
	int c = OMstring_Dfetch(s, i);
	if (c >= '0' && c <= '7')
	    u = u * 16 + c - '0';
	else {
	    SIGNAL0(SLBAD_FORMAT);
	}
    }
    RETURN1(u);
}


/*
 * unparse = proc(U: uint) returns(string)
 *	effects  Returns the string such that parse(unparse(U)) = U.  Leading
 *	    zeros are suppressed.
 */

int OFuint_Dunparse(u)
object u;
{
    static char buffer[(UINT_BIT + 2) / 3 + 1];	/* somwhat overestimating */

    sprintf(buffer, "%u", (unsigned) u);
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(buffer)));
}


/*
 * hex_unparse = proc(U: uint) returns(string)
 *	effects  Returns the string such that hex_parse(hex_unparse(U)) = U.
 *	    Leading zeros are suppressed.  The letters from `a' through 'f' are
 *	    used for hexadecimal digits with values from 10 to 15,
 *	    respectively.
 */

int OFuint_Dhex__unparse(u)
object u;
{
    static char buffer[(UINT_BIT + 3) / 4 + 1];

    sprintf(buffer, "%x", (unsigned) u);
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(buffer)));
}


/*
 * oct_unparse = proc(U: uint) returns(string)
 *	effects  Returns the string such that oct_parse(oct_unparse(U)) = U.
 *	    Leading zeros are suppressed.
 */

int OFuint_Doct__unparse(u)
object u;
{
    static char buffer[(UINT_BIT + 2) / 3 + 1];

    sprintf(buffer, "%o", (unsigned) u);
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(buffer)));
}


/*
 * equal = proc(U1, U2: uint) returns(bool)
 *	effects  Returns `true' if and only if U1 and U2 is the same unsigned
 *	    integer.
 */

int OFuint_Dequal(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 == (unsigned) u2);
}


/*
 * similar = proc(U1, U2: uint) returns(bool)
 *	effects  Equivalent to the `equal' operation.
 */

int OFuint_Dsimilar(u1, u2)
object u1;
object u2;
{
    RETURN1((unsigned) u1 == (unsigned) u2);
}


/*
 * copy = proc(U: uint) returns(uint)
 *	effects  Simply returns U.
 */

int OFuint_Dcopy(u)
object u;
{
    RETURN1(u);
}


/*
 * encode = proc(U: uint, OUTPUT: istream) signals(not_possible(string))
 */

int OFuint_Dencode(u, output)
object u;
object output;
{
    return OFistream_Dputi(output, (int) u);
}


/*
 * decode = proc(INPUT: istream) returns(uint)
 *          signals(end_of_file, not_possible(string))
 */

int OFuint_Ddecode(input)
object input;
{
    return OFistream_Dgeti(input);
}


/*
 * print = proc(u: uint, output: pstream)
 */

int OFuint_Dprint(u, output)
object u;
object output;
{
    OFuint_Dunparse(u);
    if (OFpstream_Dtext(output, retval_area[0]) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/* end uint */
