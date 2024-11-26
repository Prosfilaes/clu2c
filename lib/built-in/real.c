/*
 * real.c - implementation of real
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: real.c,v 2.17 1996/10/07 05:01:07 ushijima Exp $
 */

#include <config/errno.h>
#include <config/float.h>
#include <config/limits.h>
#include <config/math.h>
#include <config/stdlib.h>

#include <clu2c.h>

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "real.h"
/*
 * Tricks for converting float into int and vice versa
 */

static union {
    int i;
    float f;
} conv;

#define f2i(x) (conv.f = (x), conv.i)
#define i2f(x) (conv.i = (x), conv.f)


/*
 * Support for multiple-precision numbers
 */

#define UINT_BIT	(sizeof (unsigned) * CHAR_BIT)
#define UINT_HALF_BIT	(UINT_BIT / 2)
#define UINT_HALF_MAX	((1 << UINT_HALF_BIT) - 1)
#define UINT_HIGH(u)	((u) >> UINT_HALF_BIT)
#define UINT_LOW(u)	((u) & UINT_HALF_MAX)

typedef struct {
    int size;
    unsigned *digits;
} mpn_t;

static mpn_t *mpn_new();
static void mpn_clear();
static int mpn_resize();
static int mpn_init();
static int mpn_significant_size();
static void mpn_add();
static void mpn_sub();
static void mpn_mul();
static void mpn_div10();
static int mpn_divmod();
static void mpn_copy();
static int mpn_cmp();


/*
 * Internal operation declarations.
 */

static int OFreal_D__owninit();
static int OFreal_D__approx();
static double OFreal_D__huge__val();
static int OFreal_D____unparse();


/*
 * Own variables.
 */

static bool initialized = FALSE;
static int max_width = 0;
static int exp_width = 0;
static char *decimal_digits = 0;
static char *unparse_buffer = 0;


/*
 * Operations
 */


/*
 * add = proc(r1, r2: real) returns(real) signals(overflow, underflow)
 */

int OFreal_Dadd(int r1, int r2)
{
    double d1, d2;

    d1 = (double) i2f(r1);
    d2 = (double) i2f(r2);
    return OFreal_D__approx(d1 + d2);
}


/*
 * sub = proc(r1, r2: real) returns(real) signals(overflow, underflow)
 */

int OFreal_Dsub(int r1, int r2)
{
    double d1, d2;

    d1 = (double) i2f(r1);
    d2 = (double) i2f(r2);
    return OFreal_D__approx(d1 - d2);
}


/*
 * mul = proc(r1, r2: real) returns(real) signals(overflow, underflow)
 */

int OFreal_Dmul(int r1, int r2)
{
    double d1, d2;

    d1 = (double) i2f(r1);
    d2 = (double) i2f(r2);
    return OFreal_D__approx(d1 * d2);
}


/*
 * minus = proc(r: real) returns(real)
 */

int OFreal_Dminus(int r)
{
    float f;

    f = i2f(r);
    RETURN1(f2i(-f));
}


/*
 * div = proc(r1, r2: real) returns(real)
 *       signals(zero_divide, overflow, underflow)
 */

int OFreal_Ddiv(int r1, int r2)
{
    double d1, d2;

    d1 = (double) i2f(r1);
    d2 = (double) i2f(r2);
    if (d2 == 0.0) {
	SIGNAL0(SLZERO_DIVIDE);
    }
    return OFreal_D__approx(d1 / d2);
}


/*
 * power = proc(r1, r2: real) returns(real)
 *         signals(zero_divide, complex_result, overflow, underflow)
 */

int OFreal_Dpower(int r1, int r2)
{
    double d1, d2;
    double i;
    double result;

    d1 = (double) i2f(r1);
    d2 = (double) i2f(r2);
  
    /* Checks for the `zero_divide' and `complex_result' exceptions.  */
    if (d1 == 0.0 && d2 < 0.0) {
	SIGNAL0(SLZERO_DIVIDE);
    } else if (d1 < 0.0 && modf(d2, &i) != 0.0) {
	SIGNAL0(SLCOMPLEX_RESULT);
    }

    /* Deals with trivial cases.  */
    if (d2 == 0.0) {
	RETURN1(f2i(1.0));
    }
    
    result = pow(d1, d2);
    if (OFreal_D__checkrange(result) == SIG) {
	return SIG;
    }
    return OFreal_D__approx(result);
}

  
/*
 * abs = proc(r: real) returns(real)
 */

int OFreal_Dabs(int r)
{
    double d;

    d = (double) i2f(r);
    RETURN1(f2i(fabs(d)));
}


/*
 * max = proc(r1, r2: real) returns(real)
 */

int OFreal_Dmax(int r1, int r2)
{
    float f1, f2;

    f1 = i2f(r1);
    f2 = i2f(r2);
    RETURN1(f2i((f1 > f2) ? f1 : f2));
}


/*
 * min = proc(r1, r2: real) returns(real)
 */

int OFreal_Dmin(int r1, int r2)
{
    float f1, f2;

    f1 = i2f(r1);
    f2 = i2f(r2);
    RETURN1(f2i((f1 < f2) ? f1 : f2));
}


/*
 * i2r = proc(i: int) returns(real) signals(overflow)
 */

int OFreal_Di2r(int i)
{
    return OFreal_D__approx((double) i);
}


/*
 * r2i = proc(r: real) returns(int) signals(overflow)
 */

int OFreal_Dr2i(int r)
{
    double d;
    double i;
    double result;

    d = (double) i2f(r);
    if (fabs(modf(d, &i)) == 0.5) {
	/* Returns the integer part in the case of a tie. */
	result = (double) i;
    } else if (d > 0.0) {
	result = floor(d + 0.5);
    } else {
	result = ceil(d - 0.5);
    }
    if (result > (double) INT_MAX || result < (double) INT_MIN) {
	SIGNAL0(SLOVERFLOW);
    }
    RETURN1((int) result);
}


/*
 * trunc = proc(r: real) returns(int) signals(overflow)
 */

int OFreal_Dtrunc(int r)
{
    double d;

    d = (double) i2f(r);
    if (d > (double) INT_MAX || d < (double) INT_MIN) {
	SIGNAL0(SLOVERFLOW);
    }
    RETURN1((int) d);
}


/*
 * exponent = proc(r: real) returns(int) signals(undefined)
 */

int OFreal_Dexponent(int r)
{
    double d;
    int exponent;

    if (!initialized) {
	OFreal_D__owninit();
    }
    d = (double) i2f(r);
    if (d == 0.0) {
	SIGNAL0(SLUNDEFINED);
    } else {
	RETURN1(OFreal_D____unparse(d, decimal_digits));
    }
}


/*
 * mantissa = proc(r: real) returns(real)
 */

int OFreal_Dmantissa(int r)
{
    double d;
    int sign;
    int mantissa;
    int exponent;
    char *p;

    if (!initialized) {
	OFreal_D__owninit();
    }
    d = (double) i2f(r);
    if (d == 0.0) {
	RETURN1(f2i(0.0));
    }
    if (d < 0.0) {
	d = -d;
	sign = -1;
    } else {
	sign = 1;
    }
    OFreal_D____unparse(d, decimal_digits);
    mantissa = 0;
    exponent = 1;
    for (p = decimal_digits; *p; p++) {
	mantissa = mantissa * 10 + (*p - '0');
	--exponent;
    }
    RETURN1(f2i(sign * mantissa * pow(10.0, (double) exponent)));
}


/*
 * parse = proc(s: string) returns(real)
 *         signals(bad_format, overflow, underflow)
 */

int OFreal_Dparse(string s)
{
    char *p, *endp;
    double result;

    p = OFstring_D__s2cs(s);
    if (*p == '\0' || isspace(*p)) {
	SIGNAL0(SLBAD_FORMAT);
    }
    result = strtod(p, &endp);

    /* Signals `bad_format' if the final string is nonempty.  Since
       some implementation of `strtod' (e.g., SunOS 3.x) stores a
       pointer to the *second* character of the final string in ENDP,
       validity of ENDP must be checked.  */
    if (endp <= p + strlen(p) && *endp != '\0') {
	SIGNAL0(SLBAD_FORMAT);
    }

    if (OFreal_D__checkrange(result) == SIG) {
	return SIG;
    }
    return OFreal_D__approx(result);
}


/*
 * unparse = proc(r: real) returns(string)
 */

int OFreal_Dunparse(int r)
{
    char *p, *q;
    double d;
    int exponent;
    int i;

    if (!initialized) {
	OFreal_D__owninit();
    }
    p = unparse_buffer;
    d = (double) i2f(r);
    if (d < 0.0) {
	d = -d;
	*p++ = '-';
    }
    exponent = OFreal_D____unparse(d, decimal_digits);
    if (exponent < -1 || exponent >= max_width) {
	sprintf(p, "%c.%se%+0*d",
		decimal_digits[0],
		decimal_digits + 1,
		exp_width + 1,
		exponent);
    } else {
	q = decimal_digits;
	for (i = 0; i < exponent + 1; i++) {
	    *p++ = (*q ? *q++ : '0');
	}
	sprintf(p, ".%s", q);
    }
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(unparse_buffer)));
}


/*
 * lt = proc(r1, r2: real) returns(bool)
 */

int OFreal_Dlt(int r1, int r2)
{
    float f1, f2;

    f1 = i2f(r1);
    f2 = i2f(r2);
    RETURN1(f1 < f2);
}


/*
 * le = proc(r1, r2: real) returns(bool)
 */

int OFreal_Dle(int r1, int r2)
{
    float f1, f2;

    f1 = i2f(r1);
    f2 = i2f(r2);
    RETURN1(f1 <= f2);
}


/*
 * ge = proc(r1, r2: real) returns(bool)
 */

int OFreal_Dge(int r1, int r2)
{
    float f1, f2;

    f1 = i2f(r1);
    f2 = i2f(r2);
    RETURN1(f1 >= f2);
}


/*
 * gt = proc(r1, r2: real) returns(bool)
 */

int OFreal_Dgt(int r1, int r2)
{
    float f1, f2;

    f1 = i2f(r1);
    f2 = i2f(r2);
    RETURN1(f1 > f2);
}


/*
 * equal = proc(r1, r2: real) returns(bool)
 */

int OFreal_Dequal(int r1, int r2)
{
    float f1, f2;

    f1 = i2f(r1);
    f2 = i2f(r2);
    RETURN1(f1 == f2);
}


/*
 * similar = proc(r1, r2: real) returns(bool)
 */

int OFreal_Dsimilar(int r1, int r2)
{
    float f1, f2;

    f1 = i2f(r1);
    f2 = i2f(r2);
    RETURN1(f1 == f2);
}


/*
 * copy = proc(r: real) returns(bool)
 */

int OFreal_Dcopy(int r)
{
    RETURN1(r);
}


/*
 * print = proc(r: real, pst: pstream)
 */

int OFreal_Dprint(int r, object pst)
{
    OFreal_Dunparse(r);
    if (OFpstream_Dtext(pst, retval_area[0]) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*
 * encode = proc(r: real, ist: istream) signals(not_possible(string))
 */

int OFreal_Dencode(int r, object ist)
{
    return OFistream_Dputi(ist, (int) r);
}


/*
 * decode = proc(ist: istream) returns(real)
 *          signals(end_of_file, not_possible(string))
 */

int OFreal_Ddecode(object ist)
{
    return OFistream_Dgeti(ist);
}


/*
 * _gcd = proc(r: real, tab: gcd_tab) returns(int)
 */

int OFreal_D__gcd(int r, object tab)
{
    /* stub version */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("real$_gcd: not implemented"));
}


/*
 * _real_max = proc() returns(real)
 *	effects  Returns the maximum real object.
 */

int OFreal_D__real__max()
{
    RETURN1(f2i(FLT_MAX));
}


/*
 * _real_min = proc() returns(real)
 *	effects  Returns the minimum real object.
 */

int OFreal_D__real__min()
{
    RETURN1(f2i(FLT_MIN));
}


/*
 * _max_width = proc() returns(int)
 *	effects  Returns the maximum number of decimal digits in a mantissa
 *		 required to represent every real object accurately.
 */

int OFreal_D__max__width()
{
    if (!initialized) {
	OFreal_D__owninit();
    }
    RETURN1(max_width);
}


/*
 * _exp_width = proc() returns(int)
 *	effects  Returns the maximum number of decimal digits in an exponent
 *		 required to represent an exponent of every real object.
 */

int OFreal_D__exp__width()
{
    if (!initialized) {
	OFreal_D__owninit();
    }
    RETURN1(exp_width);
}


/*
 * _unparse = proc(r: real) returns(string, int)
 *	effects  Returns "0" and 0 if R = 0.0; otherwise returns the
 *		 mantissa without decimal point and the exponent of R
 *		 when represented in standard form.
 */

int OFreal_D__unparse(int r)
{
    static char *mantissa = 0;
    int exponent;

    if (!initialized) {
	OFreal_D__owninit();
    }
    exponent = OFreal_D____unparse(i2f(r), decimal_digits);
    RETURN2(OFstring_D__cs2s(OFstring_D__copy(decimal_digits)), exponent);
}


/*
 * Hidden operations
 */


/*
 * lit - process real literal
 */

int OFreal_Dlit(double x)
{
    return f2i((float) x);
}


/*
 * _d2r - convert C's double to CLU's real
 */

real OFreal_D__d2r(double d)
{
    return f2i(d);
}


/*
 * _r2d - convert CLU's real to C's double
 */

double OFreal_D__r2d(real r)
{
    return i2f(r);
}


/*
 * _checkrange = proc(v: [double]) signals(overflow, underflow)
 */

int OFreal_D__checkrange(double v)
{
#ifndef DJGPP_EMU387_BROKEN
    if (fabs(v) >= OFreal_D__huge__val() && errno == ERANGE) {
	SIGNAL0(SLOVERFLOW);
    } else if (v == 0.0 && errno == ERANGE) {
	SIGNAL0(SLUNDERFLOW);
    }
#endif
    RETURN0;
}


/*
 * Internal routines
 */


/*
 * _owninit - initialize own variables
 */

static int OFreal_D__owninit()
{
    initialized = TRUE;
    max_width = (int) (FLT_MANT_DIG * log10(FLT_RADIX)) + 2;
    exp_width = (int) log10(FLT_MAX_10_EXP) + 1;
    decimal_digits = (char *) malloc_atomic(max_width + 1);
    unparse_buffer = (char *) malloc_atomic(max_width + exp_width + 5);
}


/*
 * _approx
 */

static int OFreal_D__approx(double v)
{
    static double upper = 0.0;
    static double lower = 0.0;
    int sign;
    double abs;

    if (upper == 0.0) {
	upper = ((double) FLT_MAX
		 + (pow((double) FLT_RADIX,
			(double) (FLT_MAX_EXP - FLT_MANT_DIG))
		    / 2.0));
	lower = ((double) FLT_MIN
		 - (pow((double) FLT_RADIX,
			(double) (FLT_MIN_EXP - FLT_MANT_DIG - 1))
		    / 2.0));
    }
    if (v < 0.0) {
	sign = -1;
	abs = -v;
    } else {
	sign = 1;
	abs = v;
    }
    if (abs == 0.0) {
	RETURN1(f2i(0.0));
    } else if (abs < lower) {
	SIGNAL0(SLUNDERFLOW);
    } else if (abs < FLT_MIN) {
	RETURN1(f2i(sign * FLT_MIN));
    } else if (abs <= FLT_MAX) {
	RETURN1(f2i(v));
    } else if (abs <= upper) {
	RETURN1(f2i(sign * FLT_MAX));
    } else {
	SIGNAL0(SLOVERFLOW);
    }
}


/*
 * _huge_val - return HUGE_VAL
 *
 * This is a workaround for the following situation.  On Sun-3/60
 * running SunOS 3.4, HUGE is defined as 99.e999 in <math.h> (HUGE_VAL
 * is defined as HUGE in <config/math.h>).  When this literal is used
 * directly as an operand for floating-point arithmetic, GNU CC 2.7.2
 * produces an assembly with the literal as is, and GNU Assembler 2.6
 * complains of such literal, saying `cannot create floating-point
 * number'.  On the other hand, using this literal as an argument to
 * functions or an operand for `return' statements causes no problem,
 * since in this case a `double' literal is represented as a pair of
 * two integers.  This is why this function has been introduced.
 */

static double OFreal_D__huge__val()
{
    return HUGE_VAL;
}


/*
 * __unparse - auxiliary function for `unparse'
 *
 * Modifies:
 *	The string pointed to by MANTISSA.
 */

static int OFreal_D____unparse(double v, char *mantissa)
{
    /* This function uses the algorithm (FPP)^2 described in "How to
       Print Floating-Point Numbers Accurately" by Guy L. Steele
       Jr. and Jon L White (PLDI '90).  */

    static mpn_t *remainder = 0;
    static mpn_t *scale = 0;
    static mpn_t *error = 0;
    static mpn_t *t1 = 0;
    static mpn_t *t2 = 0;
    int exponent;
    double fraction;
    int i;
    int x;
    bool unequal_gap;
    int k;
    char digit;
    bool low, high;

    /* Deals with the special case.  */
    if (v == 0.0) {
	sprintf (mantissa, "0");
	return 0;
    }

    if (v < 0.0) {
	v = -v;
    }

    if (!remainder) {
	remainder = mpn_new();
	scale = mpn_new();
	error = mpn_new();
	t1 = mpn_new();
	t2 = mpn_new();
    }

#if FLT_RADIX == 2
    fraction = ldexp(frexp(v, &exponent), FLT_MANT_DIG);
#else
    exponent = 0;
    fraction = v;
    while (fraction >= 1) {
	fraction /= (double) FLT_RADIX;
	exponent++;
    }
    while (fraction < pow((double) FLT_RADIX, (double) -1)) {
	fraction *= (double) FLT_RADIX;
	--exponent;
    }
    fraction *= pow((double) FLT_RADIX, (double) FLT_MANT_DIG);
#endif

    /* Initializes REMAINDER and SCALE so that REMAINDER / SCALE is
       (mathematically) equal to V.  */
    x = exponent - FLT_MANT_DIG;
    mpn_init(remainder, fraction, (x > 0) ? x : 0);
    mpn_init(scale, 1.0, (x < 0) ? -x : 0);

    /* Initialize ERROR so that ERROR / SCALE is the distance from V
       to the successor of V, i.e., succ(V) - V = ERROR / SCALE.  In
       many cases the distance from V to the predecessor of V is the
       same.  But if V is an integral power of 2,
           V - pred(V) = (ERROR / SCALE) / 2.
       The variable UNEQUAL_GAP indicates this case.  */
    mpn_init(error, 1.0, (x > 0) ? x : 0);
    unequal_gap = (fraction == pow(FLT_RADIX, FLT_MANT_DIG - 1));

    k = 0;

    mpn_copy(t1, scale);
    mpn_div10(t1);
    while (mpn_cmp(remainder, t1) < 0) {
	--k;
	mpn_mul(remainder, 10);
	mpn_mul(error, 10);
    }
    mpn_copy(t1, remainder);
    mpn_mul(t1, 2);
    mpn_add(t1, error);
    for (;;) {
	mpn_copy(t2, scale);
	mpn_mul(t2, 2);
	if (mpn_cmp(t1, t2) < 0) {
	    break;
	}
	mpn_mul(scale, 10);
	k++;
    }

    exponent = k - 1;

    /* Generates decimal digits.  */
    for (;;) {
	mpn_mul(remainder, 10);
	digit = '0' + mpn_divmod(remainder, scale);
	mpn_mul(error, 10);
	mpn_copy(t1, remainder);
	mpn_mul(t1, 2);
	if (unequal_gap) {
	    mpn_mul(t1, FLT_RADIX);
	}
	low = (mpn_cmp(t1, error) < 0);
	mpn_copy(t1, remainder);
	mpn_mul(t1, 2);
	mpn_add(t1, error);
	mpn_copy(t2, scale);
	mpn_mul(t2, 2);
	high = mpn_cmp(t1, t2) > 0;
	if (low || high) {
	    break;
	}
	*mantissa++ = digit;
    }
    if (low && !high) {
	*mantissa++ = digit;
    } else if (high && !low) {
	*mantissa++ = digit + 1;
    } else {
	mpn_copy(t1, remainder);
	mpn_mul(t1, 2);
	if (mpn_cmp(t1, scale) <= 0) {
	    *mantissa++ = digit;
	} else {
	    *mantissa++ = digit + 1;
	}
    }

    *mantissa = '\0';
    return exponent;
}


/*
 * mpn_new - create new multiple-precision number
 *
 * Effects:
 *   	Returns a pointer to newly created number zero.  If error
 *	occurs, returns a null pointer.
 */

static mpn_t *mpn_new()
{
    mpn_t *v;

    v = (mpn_t *) malloc(sizeof(mpn_t));
    if (v) {
	v->size = 0;
	v->digits = 0;
    }
    return v;
}


/*
 * mpn_clear - clear multiple-precision number
 *
 * Modifies:
 *	The number pointed to by V.
 *
 * Effects:
 *   	Modifies the number pointed to by V so that it has the value
 *	of zero.
 */

static void mpn_clear(mpn_t *v)
{
    int i;

    for (i = 0; i < v->size; i++)
	v->digits[i] = 0;
}


/*
 * mpn_resize - extend multiple-precision number
 *
 * Modifies:
 *	The number pointed to by V. 
 *
 * Effects:
 *   	Extends the digits of the number pointed to by V so that it
 *	can contain SIZE digits.  Returns zero on success; otherwise
 *	returns a negative integer.
 */

static int mpn_resize(mpn_t *v, int size)
{
    unsigned *digits;		/* new digits */
    int i;			/* index for digits */

    if (size < 0)
	return -1;
    else if (size <= v->size)
	return 0;
    digits = (unsigned *) malloc(size * sizeof(unsigned));
    if (!digits)
	return -1;
    for (i = 0; i < size; i++)
	digits[i] = (i < v->size) ? v->digits[i] : 0;
    if (v->digits)
	free(v->digits);
    v->size = size;
    v->digits = digits;
    return 0;
}


/*
 * mpn_init - initialize multiple-precision number
 *
 * Requires:
 *	F is positive and integral; X is nonnegative.
 *
 * Modifies:
 *	The number pointed to by V.
 *
 * Effects:
 *	Initializes the number pointed to by V so that it has the
 *	value F * FLT_RADIX^X.
 */

static int mpn_init(mpn_t *v, double f, int x)
{
    int i;
    double quotient;

    mpn_clear(v);
    i = 0;
    while (f > (double) ((unsigned) UINT_MAX)) {
	modf(f / ((double) UINT_MAX + 1.0), &quotient);
	if (i > v->size - 1 && mpn_resize(v, i + 1) < 0)
	    return -1;
	v->digits[i++] = (unsigned) (f - quotient * ((double) UINT_MAX + 1.0));
	f = quotient;
    }
    if (f > 0.0) {
	if (i > v->size - 1 && mpn_resize(v, i + 1))
	    return -1;
	v->digits[i] = (unsigned) f;
    }
    for (i = 0; i < x; i++) {
	mpn_mul(v, FLT_RADIX);
    }
    return 0;
}


/*
 * mpn_significant_size - significant size of multiple-precision number
 *
 * Effects:
 *   	Returns the maximum integer X such that V->digits[I] is equal
 *	to zero for all I in the range [X + 1, V->size].
 */

static int mpn_significant_size(mpn_t *v)
{
    int size;

    for (size = v->size; size > 0 && v->digits[size - 1] == 0; --size)
	;
    return size;
}


/*
 * mpn_add - add multiple-precision numbers
 *
 * Modifies:
 *	The number pointed to by V1.
 *
 * Effects:
 *	Modifies the number pointed to by V1 so that it has the value
 *	of the sum of the two numbers pointed to by V1 and V2.
 */

static void mpn_add(mpn_t *v1, mpn_t *v2)
{
    int size;
    unsigned carry;
    int i;

    size = mpn_significant_size(v2);
    mpn_resize(v1, size);
    carry = 0;
    for (i = 0; i < size; i++) {
	unsigned next_carry = 0;
	if (v1->digits[i] > UINT_MAX - carry)
	    next_carry++;
	v1->digits[i] += carry;
	if (v1->digits[i] > UINT_MAX - v2->digits[i])
	    next_carry++;
	v1->digits[i] += v2->digits[i];
	carry = next_carry;
    }
    while (carry > 0 && i < v1->size) {
	unsigned next_carry = 0;
	if (v1->digits[i] > UINT_MAX - carry)
	    next_carry++;
	v1->digits[i] += carry;
	carry = next_carry;
	i++;
    }
    if (carry > 0) {
	mpn_resize(v1, v1->size + 1);
	v1->digits[v1->size - 1] = carry;
    }
}


/*
 * mpn_sub - subtract a multiple-precision number from another
 *
 * Requires:
 *	The numver pointed to by V1 is greater than or equal to the
 *	number pointed to by V2.
 *
 * Modifies:
 *	The numver pointed to by V1.
 *
 * Effects:
 * 	Modifies the numver pointed to by V1 so that it has the value
 *	resulting from subtracting the number pointed to by V2 from
 *	the number pointed to by V1.
 */

static void mpn_sub(mpn_t *v1, mpn_t *v2)
{
    int size;
    unsigned borrow;
    int i;

    size = mpn_significant_size(v2);
    borrow = 0;
    for (i = 0; i < size; i++) {
	unsigned next_borrow = 0;
	if (v1->digits[i] < borrow)
	    next_borrow++;
	v1->digits[i] -= borrow;
	if (v1->digits[i] < v2->digits[i])
	    next_borrow++;
	v1->digits[i] -= v2->digits[i];
	borrow = next_borrow;
    }
    while (borrow > 0 && i < v1->size) {
	unsigned next_borrow = 0;
	if (v1->digits[i] < borrow)
	    next_borrow++;
	v1->digits[i] -= borrow;
	borrow = next_borrow;
	i++;
    }
}


/*
 * mpn_mul - multiply a multiple-precision number by an integer
 *
 * Requires:
 *	N is positive and less than or equal to (UINT_MAX + 1) / 2.
 *
 * Modifies:
 *	The number pointed to by V.
 *
 * Effects:
 *   	Modifies the number pointed to by V so that it has the value
 *	resulting from multiplying the number pointed to by V by N.
 */

static void mpn_mul(mpn_t *v, unsigned n)
{
    int size;
    unsigned limit;
    unsigned carry;
    int i;

    if (n == 0) {
	mpn_clear(v);
	return;
    } else if (n == 1) {
	return;
    }
    size = mpn_significant_size(v);
    limit = UINT_MAX / n;
    carry = 0;
    for (i = 0; i < size; i++) {
	unsigned next_carry = 0;
	unsigned digit = v->digits[i];
	if (digit > limit) {
	    next_carry = UINT_HIGH(UINT_HIGH(digit) * n
				   + UINT_HIGH(UINT_LOW(digit) * n));
	}
	v->digits[i] = digit * n;
	if (v->digits[i] > UINT_MAX - carry)
	    next_carry++;
	v->digits[i] += carry;
	carry = next_carry;
    }
    if (carry > 0) {
	if (i > v->size - 1)
	    mpn_resize(v, i + 1);
	v->digits[i] = carry;
    }
}


/*
 * mpn_div10 - divide a multiple-precision number by 10
 *
 * Modifies:
 *	The number pointed to by V.
 *
 * Effects:
 *   	Modifies the number pointed to by V so that it has the value
 *	resulting from dividing the number pointed to by V by 10, with
 *	a franction part (if any) being rounded up.
 */

static void mpn_div10(mpn_t *v)
{
    static unsigned one_digits[] = {1};
    static mpn_t one= {1, one_digits};
    unsigned remainder;
    int i;

    remainder = 0;
    for (i = mpn_significant_size(v) - 1; i >= 0; --i) {
	unsigned u;
	unsigned high;
	unsigned low;
	u = (remainder << UINT_HALF_BIT) + (v->digits[i] >> UINT_HALF_BIT);
	high = u / 10;
	remainder = u % 10;
	u = (remainder << UINT_HALF_BIT) + (v->digits[i] & UINT_HALF_MAX);
	low = u / 10;
	remainder = u % 10;
	v->digits[i] = (high << UINT_HALF_BIT) + low;
    }
    if (remainder > 0) {
	mpn_add(v, &one);
    }
}


/*
 * mpn_divmod - divide a multiple-precision number by another
 *
 * Modifies:
 *	The number pointed to by V1.
 *
 * Effects:
 *   	Divides the number pointed to by V1 by the number pointed to
 *	by V2 and stores the remainder in the number pointed to by V1
 *	and returns the quotient.
 */

static int mpn_divmod(mpn_t *v1, mpn_t *v2)
{
    int q;

    q = 0;
    while (mpn_cmp(v1, v2) >= 0) {
	mpn_sub(v1, v2);
	q++;
    }
    return q;
}


/*
 * mpn_copy - copy a multiple-precision number
 *
 * Modifies:
 *	The number pointed to by V1.
 *
 * Effects:
 *   	Copies the value of the number pointed to by V2 to the number
 *	pointed to by V1.
 */

static void mpn_copy(mpn_t *v1, mpn_t *v2)
{
    int size;
    int i;

    size = mpn_significant_size(v2);
    if (v1->size < size)
	mpn_resize(v1, size);
    for (i = 0; i < size; i++) {
	v1->digits[i] = v2->digits[i];
    }
    while (i < v1->size)
	v1->digits[i++] = 0;
}


/*
 * mpn_cmp - compare multiple-precision numbers
 *
 * Effects:
 *	Returns an integer greater than, equal to, or less than zero
 *	accodingly as the number pointed to by V1 is greater than,
 *	equal to, or less than the number pointed to by V2.
 */

static int mpn_cmp(mpn_t *v1, mpn_t *v2)
{
    int size1, size2;
    int i;

    size1 = mpn_significant_size(v1);
    size2 = mpn_significant_size(v2);
    if (size1 != size2)
	return size1 - size2;
    for (i = size1 - 1; i >= 0; --i) {
	if (v1->digits[i] > v2->digits[i]) {
	    return 1;
	} else if (v1->digits[i] < v2->digits[i]) {
	    return -1;
	}
    }
    return 0;
}
