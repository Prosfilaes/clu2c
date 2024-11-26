/* 
 * array.c - implementation of array
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: array.c,v 2.16 1996/10/07 05:01:17 ushijima Exp $
 */

#include <config/string.h>

#include <clu2c.h>
#include "array.h"


/*
 * Data structure:
 *
 *  ------------------------- +-----+
 *   |             buf_top -> |  /  |
 *   |                        +-----+
 *   |                        :     :
 *   |                        +-----+
 *   |                        |  /  |
 *   |                        +-----+ ---------
 *   |                high -> |  O  | high   |
 *   |                        +-----+        |
 *   |                        :     :        |
 *   |                        +-----+        |
 * bsize          zero + k -> |  O  | k     size 
 *   |                        +-----+        |
 *   |                        :     :        |
 *   |                        +-----+        |
 *   |                 low -> |  O  | low    |
 *   |   -------------------- +-----+ ---------
 *   |    |                   |  /  |
 *   |    |                   +-----+
 *   |  offset                :     :
 *   |    |                   +-----+
 *   |    |     buf_bottom -> |  /  |
 *  ------------------------- +-----+
 *
 *       The world of C array         The world of CLU array
 */


/*
 * Minimum buffer size
 */

#define MIN_BSIZE	20


/*
 * The second arguments to array$_extend_buffer
 */

#define BOTH_SIDE	 0
#define BOTTOM_SIDE	-1
#define TOP_SIDE	 1


/*
 * Utility macros
 */

#define OMarray_D__offset(a)	((a)->low - (a)->buf_bottom)
#define OMarray_D__bsize(a)	((a)->buf_top - (a)->buf_bottom + 1)


/*
 * Abbreviations for frequently used operations of array.
 */

#define BOTTOM(a)	OMarray_Dbottom(a)
#define BOUNDS(a, i)	OMarray_Dbounds(a, i)
#define EMPTY(a)	OMarray_Dempty(a)
#define EQUAL(a1, a2)	OMarray_Dequal(a1, a2)
#define FETCH(a, i)	OMarray_Dfetch(a, i)
#define HIGH(a)		OMarray_Dhigh(a)
#define LOW(a)		OMarray_Dlow(a)
#define REMH(a)		OMarray_Dremh(a)
#define REML(a)		OMarray_Dreml(a)
#define SET_LOW(a, i)	OMarray_Dset__low(a, i)
#define SIZE(a)		OMarray_Dsize(a)
#define STORE(a, i, e)	OMarray_Dstore(a, i, e)
#define TOP(a)		OMarray_Dtop(a)
#define _BSIZE(a)	OMarray_D__bsize(a)
#define _OFFSET(a)	OMarray_D__offset(a)


/*
 * Internal function declarations
 */

static int OFarray_D__shift();
static int OFarray_D__extend__buffer();
static int OFarray_D__similar();
static int OFarray_D__shrink();


/*
 * Operations
 */


/*
 * create = proc(low: int) returns(array[T])
 */

int OFarray_Dcreate(int low)
// int low;			low bound of the result 
{
    RETURN1(OFarray_D__alloc(low, 0));
}


/*
 * new = proc() returns(array[T])
 */

int OFarray_Dnew(void)
{
    return OFarray_Dcreate(1);
}


/*
 * predict = proc(low, count: int) returns(array[T]) 
 */

int OFarray_Dpredict(int low, int count)
// int low;			low bound of the result
// int count;			count prediction 
{
    int predicted_low;		/* predicted low bound */
    int predicted_size;		/* predicted size */
    array res;			/* result */

    if (count >= 0) {
	predicted_low = low;
	predicted_size = count;
    } else {
	predicted_low = low + count;
	predicted_size = -count;
    }
    res = OFarray_D__alloc(predicted_low, predicted_size);
    OFarray_D__shrink(res, low, 0);
    RETURN1(res);
}


/*
 * fill = proc(low, size: int, elem: t) returns(array[T]) 
 *        signals(negative_size)
 */

int OFarray_Dfill(int low, int size, object elem)
// int low;			low bound of the result 
// int size;			size of the result 
// object elem;			element to be filled 
{
    array res;			/* result */
    int i;			/* index for each element of the result */
    
    if (size < 0) {
	SIGNAL0(SLNEGATIVE_SIZE);
    }
    
    res = OFarray_D__alloc(low, size);
    for (i = low; i < low + size; i++) {
	STORE(res, i, elem);
    }
    RETURN1(res);
}


/*
 * low = proc(a: array[T]) returns(int)
 */

int OFarray_Dlow(array a)
// array a;			/* target array 
{
    RETURN1(LOW(a));
}


/*
 * high = proc(a: array[T]) returns(int)
 */

int OFarray_Dhigh(array a)
// array a;			/* target array 
{
    RETURN1(HIGH(a));
}


/*
 * size = proc(a: array[T]) returns(int)
 */

int OFarray_Dsize(array a)
// array a;			/* target array
{
    RETURN1(SIZE(a));
}


/*
 * empty = proc(a: array[T]) returns(bool)
 */

int OFarray_Dempty(array a)
// array a;			/* target array
{
    RETURN1(EMPTY(a));
}


/*
 * set_low = proc(a: array[T], low: int)
 */

int OFarray_Dset__low(array a, int low)
// array a;			/* target array
// int low;			/* low bound to be set
{
    SET_LOW(a, low);
    RETURN0;
}


/*
 * trim = proc(a: array[T], nlow, nsize: int) signals(bounds, negative_size)
 */

int OFarray_Dtrim(array a, int nlow, int nsize)
//array a;			/* target array 
//int nlow;			/* new low bound of A 
//int nsize;			/* max of new size of A 
{
    int low_incr;		/* increment of low bound */
    int high_decr;		/* decrement of high bound */

    if (OFarray_D__shrink(a, nlow, nsize) == SIG) {
	/*
	 * Resignals the BOUNDS or NEGATIVE_SIZE exception.
	 */
	return SIG;
    }
    low_incr = retval_area[0];
    high_decr = retval_area[1];

    /*
     * Clears the pointers to the removed elements.
     */
    if (low_incr > 0) {
	MEMCLR((char *) (a->low - low_incr), low_incr * sizeof(object));
    }
    if (high_decr > 0) {
	MEMCLR((char *) (a->high + 1), high_decr * sizeof(object));
    }

    RETURN0;
}


/*
 * fetch = proc(a: array[T], i: int) returns(T) signals(bounds) 
 */

int OFarray_Dfetch(array a, int i)
// array a;			target array 
// int i;			index of the to-be-fetched element
{
    if (BOUNDS(a, i)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(FETCH(a, i));
}


/*
 * store = proc(a: array[T], i: int, elem: T) signals(bounds)
 */

int OFarray_Dstore(array a, int i, object elem)
// array a;			/* target array
// int i;			/* index for the to-be-stored object
// object elem;			/* element to be stored
{
    if (BOUNDS(a, i)) {
	SIGNAL0(SLBOUNDS);
    }
    STORE(a, i, elem);
    RETURN0;
}


/*
 * bottom = proc(a: array[T]) returns(T) signals(bounds)
 */

int OFarray_Dbottom(array a)
// array a;			/* target array
{
    if (EMPTY(a)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(BOTTOM(a));
}


/*
 * top = proc(a: array[T]) returns(T) signals(bounds)
 */

int OFarray_Dtop(array a)
// array a;			/* target array
{
    if (EMPTY(a)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(TOP(a));
}


/*
 * addh = proc(a: array[T], elem: T)
 */

int OFarray_Daddh(array a, object elem)
// array a;			/* target array
// object elem;			/* element to be added
{
    if (a->high >= a->buf_top) {

	/*
	 * Shifts the elements towards the bottom if there is sufficient
	 * room in the bottom side of the buffer; otherwise allocates a
	 * new buffer.
	 */

	int offset;

	offset = _OFFSET(a);
	if (SIZE(a) < offset) {
	    OFarray_D__shift(a, -(offset / 2));
	} else {
	    OFarray_D__extend__buffer(a, TOP_SIDE);
	}

    }

    *++a->high = elem;
    RETURN0;
}


/*
 * addl = proc(a: array[T], elem: T) signals(overflow)
 */

int OFarray_Daddl(array a, object elem)
// array a;			/* target array
// object elem;			/* element to be added
{
    if (a->low <= a->buf_bottom) {

	/*
	 * Shifts the elements towards the top if there is sufficient
	 * room in the top side of the buffer; otherwise allocates a
	 * new buffer.
	 */

	int room;

	room = a->buf_top - a->high;
	if (SIZE(a) < room) {
	    OFarray_D__shift(a, room / 2);
	} else {
	    OFarray_D__extend__buffer(a, BOTTOM_SIDE);
	}

    }

    *--a->low = elem;
    RETURN0;
}


/*
 * remh = proc(a: array[T]) returns(T) signals(bounds)
 */

int OFarray_Dremh(array a)
//array a;			/* target array
{
    if (EMPTY(a)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(REMH(a));
}


/*
 * reml = proc(a: array[T]) returns(T) signals(bounds)
 */

int OFarray_Dreml(array a)
//array a;			/* target array
{
    if (EMPTY(a)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(REML(a));
}


/*
 * elements = iter(a: array[T]) yields(T) 
 */

#define ARSIZE   3
#define LMa      ((*ivarp)[0])
#define LMi      ((*ivarp)[1])
#define LMhigh   ((*ivarp)[2])

int OFarray_Delements(bool init, object **ivarp, array a)
// bool init;			/* initialization flag
// object **ivarp;			/* (pointer to the)^2 activation record
// array a;			/* target array
{
    if (init) {
	*ivarp = (object *) malloc(ARSIZE * sizeof(object));
	LMa = (object) a;
    } else {
	goto resume1;
    }

    LMhigh = HIGH(LMa);
    for (LMi = LOW(LMa); LMi <= LMhigh; LMi++) {
	retval_area[0] = (object) FETCH(LMa, LMi);
	return YIELD;
    resume1:
	NO_OPERATION;
    }
    RETURN0;
}

#undef ARSIZE
#undef LMa
#undef LMi
#undef LMhigh


/*
 * indexes = iter(a: array[T]) yields(int) 
 */

#define ARSIZE	3
#define LMa	((*ivarp)[0])
#define LMhigh	((*ivarp)[1])
#define LMi	((*ivarp)[2])

int OFarray_Dindexes(bool init, object **ivarp, array a)
//bool init;			/* initialization flag
//object **ivarp;			/* (pointer to the)^2 activation record
//array a;			/* target array
{
    if (init) {
	*ivarp = (object *) malloc(ARSIZE * sizeof(object));
	LMa = (object) a;
    } else {
	goto resume1;
    }
    
    LMhigh = HIGH(LMa);
    for (LMi = LOW(LMa); LMi <= LMhigh; LMi++) {
	retval_area[0] = (object) LMi;
	return YIELD;
    resume1:
	NO_OPERATION;
    }
    RETURN0;
}

#undef ARSIZE
#undef LMa
#undef LMhigh
#undef LMi


/*
 * equal = proc(a1, a2: array[T]) returns(bool) 
 */

int OFarray_Dequal(array a1, array a2)
// array a1;			/* left hand side
// array a2;			/* right hand side
{
    RETURN1(EQUAL(a1, a2));
}


/*
 * similar = proc(a1, a2: array[T]) returns(bool)
 *           where T has similar: proctype(T, T) returns(bool)
 */

int OFarray_Dsimilar(oplist_t op_list, array a1, array a2)
// oplist_t op_list;		/* list of parameter-dependent operations
// array a1;			/* left hand side 
// array a2;			/* right hand side
{
    return(OFarray_D__similar(op_list, a1, a2));
}


/*
 * similar1 = proc(a1, a2: array[T]) returns(bool)
 *            where T has similar: proctype(T, T) returns(bool)
 */

int OFarray_Dsimilar1(oplist_t op_list, array a1, array a2)
// oplist_t op_list;		/* list of parameter-dependent operatinos 
// array a1;			/* left hand side 
// array a2;			/* right hand side 
{
    return(OFarray_D__similar(op_list, a1, a2));
}


/*
 * copy = proc(a: array[T]) returns(array[T])
 *        where T has copy: proctype(T) returns(T)
 */

int OFarray_Dcopy(oplist_t op_list, array a)
// oplist_t op_list;		/* list of parameter-dependent operations 
// array a;			/* target array 
{
    int low;			/* low bound common to A and the result */
    int size;			/* size common to A and the result */
    array res;			/* result */
    int i;			/* index for each element A and the result */
    
    low = LOW(a);
    size = SIZE(a);
    res = OFarray_D__alloc(low, size);
    for (i = low; i < low + size; i++) {
	if ((*(op_list[0]))(FETCH(a, i)) == SIG) {
	    out_handler();
	    return SIG;
	}
	STORE(res, i, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * copy1 = proc(a: array[T]) returns(array[T]) 
 */

int OFarray_Dcopy1(array a)
//array a;			/* target array
{
    int size;			/* size common to A and the result */
    array res;			/* result */

    size = SIZE(a);
    res = OFarray_D__alloc(LOW(a), size);
    memcpy((char *) (res->low), (char *) (a->low), size * sizeof(object));
    RETURN1(res);
}


/*
 * fill_copy = proc(low, size: int, elem: T) returns(array[T])
 *             signals(negative_size)
 *             where T has copy: proctype(T) returns(T)
 */

int OFarray_Dfill__copy(oplist_t op_list, int low, int size, object elem)
// oplist_t op_list;		/* list of parameter-dependent operations
// int low;			/* low bound of the result
// int size;			/* size of the result
// object elem;			/* element to be copied
{
    array res;			/* result */
    int i;			/* index for each element of the result */

    if (size < 0) {
	SIGNAL0(SLNEGATIVE_SIZE);
    }

    res = OFarray_D__alloc(low, size);
    for (i = low; i < low + size; i++) {
	if ((*(op_list[0]))(elem) == SIG) {
	    out_handler();
	    return SIG;
	}
	STORE(res, i, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * encode = proc(a: array[T], ist: istream) signals(not_possible(string))
 *          where T has encode: proctype(T, istream)
 *                              signals(not_possible(stirng))
 */

int OFarray_Dencode(oplist_t op_list, array a, object ist)
// oplist_t op_list;		/* list of parameter-dependent operations
// array a;			/* target array
// object ist;			/* istream
{
    int id;			/* identification number for A */
    int low;			/* low bound of A */
    int size;			/* size of A */
    int i;			/* index of each element of A */
    
    /*
     * Checks if this array has already been encoded.
     */
    OFistream_Dcheck__history(ist, a);
    id = (int) retval_area[0];
    if (OFistream_Dputi(ist, id) == SIG) {
	return SIG;
    }
    if (id != NOT_YET) {
	RETURN0;
    }
    
    /*
     * Encodes array.
     */
    low = LOW(a);
    size = SIZE(a);
    if (OFistream_Dputi(ist, low) == SIG) {
	return SIG;
    }
    if (OFistream_Dputi(ist, size) == SIG) {
	return SIG;
    }
    for (i = low; i <= low + size - 1; i++) {
	if ((*(op_list[0]))(FETCH(a, i), ist) == SIG) {
	    return SIG;
	}
    }	    

    RETURN0;
}


/*
 * decode = proc(ist: istream) returns(array[T])
 *          signals(end_of_file, not_possible(string))
 *          where T has decode: proctype(istream) returns(T)
 *                              signals(end_of_file, not_possible(string))
 */

int OFarray_Ddecode(oplist_t op_list, object ist)
//oplist_t op_list;		list of parameter-dependent operations
//object ist;			istream
{
    int id;			/* identification number for the result */
    int low;			/* low bound of the result */
    int size;			/* size of the result */
    array res;			/* result */
    int i;			/* index for each element of the result */
    
    /*
     * Check if the same object has already been decoded.
     */
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    id = (int) retval_area[0];
    if (id != NOT_YET) {
	if (OFistream_Dget__obj(ist, id) == RET) {
	    return RET;
	} else if (OMstring_Dequal(signame, SLBOUNDS)) {
	    SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("wrong id"));
	} else {
	    return SIG;
	}
    }
    
    /*
     * Get low bound and size (size is checked).
     */
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    low = (int) retval_area[0];
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    size = (int) retval_area[0];
    if (size < 0) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    } 
    
    /*
     * Creates array object, and add it to history.
     */
    res = OFarray_D__alloc(low, size);
    OFistream_Dadd__history(ist, res);
    
    /*
     * Decodes elements.
     */
    for (i = low; i < low + size; i++) {
	if ((*(op_list[0]))(ist) ==SIG) {
	    return SIG;
	}
	STORE(res, i, retval_area[0]);
    }
    
    RETURN1(res);
}


/*
 * Following operations are implemented in MIT version of CLU
 * compilers.  We offer these for compatibility, althogh some
 * operations are stub versions.
 */


/*
 * print = proc (a: array[T], pst: pstream)
 *         where T has print: proctype(T, pstream)
 */

int OFarray_Dprint(oplist_t op_list, array a, object pst)
// oplist_t op_list;		list of parameter-dependent operations 
// array a;			target object 
// object pst;			pstream 
{
    static string lbkt = 0;
    static string rbkt = 0;
    static string ddot = 0;
    static string colon = 0;
    static string comma = 0;

    int low;
    int high;
    int i;
    
    if (!lbkt) {
	lbkt = OFstring_D__cs2s("[");
	rbkt = OFstring_D__cs2s("]");
	ddot = OFstring_D__cs2s("..");
	colon = OFstring_D__cs2s(": ");
	comma = OFstring_D__cs2s(", ");
    }

    if (OFpstream_Dtext(pst, lbkt) == SIG) {
	out_handler();
	return SIG;
    }

    /*
     * Prints low bound.
     */
    if (OFint_Dprint(LOW(a), pst) == SIG) {
	out_handler();
	return SIG;
    }

    /*
     * Prints high bound unless all elements will be printed.
     */
    if (OFpstream_Dget__max__width(pst) == SIG) {
	out_handler();
	return SIG;
    }
    if (SIZE(a) >= (int) retval_area[0]) {
	if (OFpstream_Dtext(pst, ddot) == SIG) {
	    out_handler();
	    return SIG;
	}
	if (OFint_Dprint(SIZE(a), pst) == SIG) {
	    out_handler();
	    return SIG;
	}
    }

    if (OFpstream_Dstart(pst, colon) == SIG) {
	out_handler();
	return SIG;
    }

    /*
     * Prints elements.
     */
    low = LOW(a);
    high = HIGH(a);
    for (i = low; i <= high; i++) {
	if (i > low) {
	    if (OFpstream_Dpause(pst, comma) == SIG) {
		out_handler();
		return SIG;
	    }
	    if (!(retval_area[0])) {
		break;
	    }
	}
	(*(op_list[0]))(FETCH(a, i), pst);
    }
    
    if (OFpstream_Dstop(pst, rbkt) == SIG) {
	out_handler();
	return(SIG);
    }
    RETURN0;
}


/*
 * _gcd = proc(a: array[T], tab: gcd_tab) returns(int)
 *        where T has _gcd: proctype(T, gcd_tab) returns(int)
 */

int OFarray_D__gcd(oplist_t op_list, array a, object tab)
// oplist_t op_list;		list of parameter-dependent operations
// array a;			target array
// object tab;			gcd_tab
{
    /* stub version */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("array$_gcd: not implemented"));
}


/*
 * cons = proc(s: sequence[T]) returns(array[T])
 */

int OFarray_Dcons(sequence s)
// sequence s;			sequence of elements
{
    return OFarray_Dcons2(1, s);
}


/*
 * cons2 = proc (low: int, s: sequence[T]) returns(array[T])
 */

int OFarray_Dcons2(int low, sequence s)
// int low;			low bound of the result
// sequence s;			sequence of elements
{
    int size;			/* size of the result */
    array res;			/* result */
    int i;			/* index of each element of S */
    int j;			/* index for each element of the result */

    size = OMsequence_Dsize(s);
    res = OFarray_D__alloc(low, size);
    for (i = 1, j = low; i <= size; i++, j++) {
	STORE(res, j, OMsequence_Dfetch(s, i));
    }
    RETURN1(res);
}


/*
 * Hidden operations
 */


/*-
 * _alloc - allocate array object
 *
 * Requires:
 *	(1) SIZE, BSIZE, and OFFSET are all non-negative integers.
 *	(2) OFFSET + SIZE <= BSIZE.
 *
 * Effects:
 *   	Returns a pointer to an newly allocated array object such
 *	that:
 *	    (1) the low bounds is LOW, 
 *	    (2) the size is SIZE, 
 *	    (3) the size of underlying buffer is BSIZE, and
 *	    (4) the bottom element is stored at OFFSET'th slot in
 *		the buffer (in the sense that the 0th slot is the
 *		bottom of the buffer).
 *
 * Note:
 *   	Initialization of elements is not performed and left to the
 *	caller.
 */

array OFarray_D__alloc(int low, int size)
//int low;			low bound of the result
//int size;			size of the result
{
    int bsize;			/* buffer size of the result */
    int offset;			/* offset for the 1st element in the buffer */
    object *base;		/* base pointer to the buffer */
    object *bottom;		/* pointer to the bottom element */
    array res;			/* result */

    /*
     * Determines the buffer size and the offset.
     */
    bsize = OMint_Dmax(MIN_BSIZE, size * 2);
    offset = bsize / 4;

    /*
     * Allocates a buffer.
     */
    base = (object *) malloc(bsize * sizeof(object));
    bottom = base + offset;

    /*
     * Allocates an array object and initializes it.
     */
    res = (array) malloc(sizeof(struct array_rep));
    res->buf_bottom = base;
    res->buf_top = base + bsize - 1;
    res->zero = bottom - low;
    res->low = bottom;
    res->high = bottom + size - 1;

    return res;
}


/*
 * Internal routines
 */


/*-
 * _shift = proc(a: array[T], n: int)
 *
 * Requires:
 *   	The underlying buffer of A has sufficient room for shifting.
 *
 * Modifies:
 *	A.
 *
 * Effects:
 *	Shifts the elments |N| times towards the bottom (in the case
 *	of N < 0) or towards the top (in the case of N > 0).  No
 *	effects if N = 0.
 */

static int OFarray_D__shift(array a, int n)
{
    object *low;		/* pointer to the bottom element */
    object *high;		/* pointer to the top element */
    object *p;

    low = a->low;
    high = a->high;

    if (n > 0) {
	for (p = high; p >= low; --p) {
	    *(p + n) = *p;
	}
    } else if (n < 0) {
	for (p = low; p <= high; p++) {
	    *(p + n) = *p;
	}
    }
    a->low += n;
    a->high += n;
    a->zero += n;

    RETURN0;
}


/*-
 * _extend_buffer = proc(a: array[T], direction: int)
 *
 * Effects:
 *	Replaces the underlying buffer of A with a larger one, copying
 *	the elements of A into the new buffer.  Extends the bottom
 *	side if DIRECTION is negative; extends the top side if
 *	DIRECTION is positive; otherwise extends the both side.
 */

static int OFarray_D__extend__buffer(array a, int direction)
{
    int bsize;			/* size of the new buffer */
    object *buf;		/* new buffer */
    int offset;			/* offset of the new buffer */
    int size;			/* size of A */
    int low;			/* low bound of A */
    object *bottom;		/* pointer to the bottom element */

    /*
     * Allocates a new buffer in double size.
     */
    bsize = _BSIZE(a) * 2;
    buf = (object *) malloc(bsize * sizeof(object));

    /*
     * Determines a new offset.
     */
    if (direction > 0) {
	offset = _OFFSET(a);
    } else if (direction < 0) {
	offset = _OFFSET(a) + bsize / 2;
    } else {
	offset = _OFFSET(a) + bsize / 4;
    }

    /*
     * Copies the elements of A to the new buffer.
     */
    size = SIZE(a);
    memcpy((char *) (buf + offset), (char *) (a->low), size * sizeof(object));

    /*
     * Replaces the buffer.
     */
    low = LOW(a);
    bottom = buf + offset;
    free(a->buf_bottom);
    a->buf_bottom = buf;
    a->buf_top = buf + bsize - 1;
    a->low = bottom;
    a->high = bottom + size - 1;
    a->zero = bottom - low;

    RETURN0;
}


/*-
 * _similar - common task for similar/similar1
 */

static int OFarray_D__similar(oplist_t op_list, array a1, array a2)
// oplist_t op_list;		list of parameter-dependent operations
// array a1;			left hand side
// array a2;			right hand side
{
    int low;			/* low bound of A1 */
    int high;			/* high bound of A1 */
    int i;			/* index of each element of A1 */
    
    /*
     * Compares low and high bounds.
     */
    low = LOW(a1);
    high = HIGH(a1);
    if (low != LOW(a2) || high != HIGH(a2)) {
	RETURN1(FALSE);
    }

    /*
     * Compares each element.  Note that here LOW and HIGH are the
     * common bounds of A1 and A2.
     */
    for (i = low; i <= high; i++) {
	if ((*(op_list[0]))(FETCH(a1, i), FETCH(a2, i)) == SIG)	{
	    out_handler();
	    return SIG;
	}
	if (retval_area[0] == FALSE) {
	    return RET;
	}
    }
    
    /*
     * No difference is detected: returns true.
     */
    RETURN1(TRUE);
}


/*
 * _shrink = proc(a: array[T], nlow, nsize: int) returns(int, int)
 *           signals(bounds, negative_size)
 *
 * Effects:
 *   	The same as the trim operation, except that the pointers to
 *	the removed elements in the buffer is not cleared and that it
 *	returns the increment of low bound and the decrement of high
 *	bound, in this order.
 */

static int OFarray_D__shrink(array a, int nlow, int nsize)
// array a;			target array
// int nlow;			new low bound
// int nsize;			new size
{
    int max_size;		/* max size after shrinked */
    int low_incr;		/* increment of low bound */
    int high_decr;		/* decrement of high bound */

    /*
     * Checks for exceptions.
     */
    if (nlow < LOW(a) || HIGH(a) + 1 < nlow) {
	SIGNAL0(SLBOUNDS);
    } else if (nsize < 0) {
	SIGNAL0(SLNEGATIVE_SIZE);
    }

    /*
     * Determines the increment of low bound.
     */
    low_incr = nlow - LOW(a);

    /*
     * Determines the decrement of high bound.
     */
    max_size = HIGH(a) - nlow + 1;
    if (nsize < max_size) {
	high_decr = max_size - nsize;
    } else {
	high_decr = 0;
    }

    /*
     * Shrinks A.
     */
    a->low += low_incr;
    a->high -= high_decr;

    RETURN2(low_incr, high_decr);
}
