/*
 * sequence.c - implementation of sequence
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: sequence.c,v 2.14 1996/10/07 05:01:04 ushijima Exp $
 */

#include <config/string.h>

#include <clu2c.h>


/*
 * Internal routine declarations
 */

static int OFsequence_D__equal();


/*
 * _subcopy - copy elements actually
 *
 * Requires:
 *	S1 points to a (possibly incomplete) sequence allocated using
 *	the OFsequence_D__alloc function.  S2 points to a complete
 *	sequence.  S1 is not the same as S2.  I1 and I2 is a positive
 *	integer.  The sequence pointed to by S1 can contain I1 +
 *	Size(S2) - I2 elements.
 *
 * Modifies:
 *	The sequence pointed to by S1.
 *
 * Effects:
 *	Changes the sequence pointed to by S1 so that Fetch(S1, I1 + J)
 *	is equal to Fetch(S2, I2 + J) for all J such that 0 <= J <= N -
 *	1, where Fetch(S, K) and Size(S) are the results of
 *	sequence$fetch(S, K) and sequence$size(S), respectively, viewed as
 *	S being CLU sequence and K being CLU int.
 */

#if CLU2C_SEQUENCE_VERSION == 1
#   define OMsequence_D__subcopy(s1, i1, s2, i2, n)			\
	memcpy((char *) ((s1)->buf + (i1) - 1),				\
	       (char *) ((s2)->buf + (i2) - 1),				\
	       (n) * sizeof(object))
#endif
#if CLU2C_SEQUENCE_VERSION == 2
#   define OMsequence_D__subcopy(s1, i1, s2, i2, n)			\
	memcpy((char *) ((s1) + (i1)),					\
	       (char *) ((s2) + (i2)),					\
	       (n) * sizeof(object))
#endif


/*
 * Operations
 */


/*
 * new = proc() returns(sequence[T])
 */

int OFsequence_Dnew()
{
    RETURN1(OFsequence_D__alloc(0));
}


/*
 * size = proc(s: sequence[T]) returns(int)
 */

int OFsequence_Dsize(s)
sequence s;			/* target sequence */
{
    RETURN1(OMsequence_Dsize(s));
}


/*
 * empty = proc(s: sequence[T]) returns(bool)
 */

int OFsequence_Dempty(s)
sequence s;			/* target sequence */
{
    RETURN1(OMsequence_Dempty(s));
}


/*
 * subseq = proc(s: sequence[T], start, size: int) returns(sequence[T])
 *          signals(bounds, negative_size)
 */

int OFsequence_Dsubseq(s, start, size)
sequence s;			/* target sequence */
int start;			/* index at which the result starts */
int size;			/* request for the size of the result */
{
    int max_size;		/* max size of the result */
    sequence res;		/* result */

    /*
     * Checks for the exceptions.
     */
    if (start < 1 || OMsequence_Dsize(s) + 1 < start) {
	SIGNAL0(SLBOUNDS);
    } else if (size < 0) {
	SIGNAL0(SLNEGATIVE_SIZE);
    }

    /*
     * Modifies SIZE (if necessary) so that it becomes the ultimate
     * size of the result.
     */
    max_size = OMsequence_Dsize(s) - start + 1;
    if (size > max_size) {
	size = max_size;
    }

    /*
     * Creates and returns the result.
     */
    res = OFsequence_D__alloc(size);
    OMsequence_D__subcopy(res, 1, s, start, size);
    RETURN1(res);
}


/*
 * fill = proc(size: int, e: T) returns(sequence[T]) signals(negative_size)
 */

int OFsequence_Dfill(size, e)
int size;			/* size of the result */
object e;			/* element with which the result is filled */
{
    sequence res;		/* result */
    int i;			/* index for each element of the result */

    if (size < 0) {
	SIGNAL0(SLNEGATIVE_SIZE);
    }

    res = OFsequence_D__alloc(size);
    for (i = 1; i <= size; i++) {
	OMsequence_D__store(res, i, e);
    }
    RETURN1(res);
}


/*
 * fill_copy = proc(size: int, elem: T) returns(sequence[T])
 *             signals(negative_size)
 *             where T has copy: proctype(T) returns(T)
 */

int OFsequence_Dfill__copy(op_list, size, elem)
oplist_t op_list;		/* list of parameter-dependent operations */
int size;			/* size of the result */
object elem;
{
    sequence res;		/* result */
    int i;			/* index for each element of the result */

    /*
     * Checks for an exception.
     */
    if (size < 0) {
	SIGNAL0(SLNEGATIVE_SIZE);
    }

    /*
     * Creates the result and returns it.
     */
    res = OFsequence_D__alloc(size);
    for (i = 1; i <= size; i++) {
	if ((*(op_list[0]))(elem) == SIG) {
	    out_handler();
	    return SIG;
	}
	OMsequence_D__store(res, i, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * fetch = proc(s: sequence[T], i: int) returns(T) signals(bounds)
 */

int OFsequence_Dfetch(s, i)
sequence s;			/* target sequence */
int i;				/* index of the result */
{
    if (OMsequence_Dbounds(s, i)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(OMsequence_Dfetch(s, i));
}


/*
 * bottom = proc(s: sequence[T]) returns(T) signals(bounds)
 */

int OFsequence_Dbottom(s)
sequence s;			/* target sequence */
{
    if (OMsequence_Dempty(s)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(OMsequence_Dbottom(s));
}


/*
 * top = proc(s: sequence[T]) returns(T) signals(bounds)
 */

int OFsequence_Dtop(s)
sequence s;			/* target sequence */
{
    if (OMsequence_Dempty(s)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(OMsequence_Dtop(s));
}


/*
 * replace = proc(s: sequence[T], i: int, e: T) returns(sequence[T])
 *           signals(bounds)
 */

int OFsequence_Dreplace(s, i, e)
sequence s;			/* target sequence */
int i;				/* index at which element is replaced */
object e;			/* replacement */
{
    sequence res;		/* result */

    if (OMsequence_Dbounds(s, i)) {
	SIGNAL0(SLBOUNDS);
    }

    res = OFsequence_D__alloc(OMsequence_Dsize(s));
    OMsequence_D__subcopy(res, 1, s, 1, OMsequence_Dsize(s));
    OMsequence_D__store(res, i, e);
    RETURN1(res);
}


/*
 * addh = proc(s: sequence[T], e: T) returns(sequence[T]) signals(bounds)
 */

int OFsequence_Daddh(s, e)
sequence s;			/* target sequence */
object e;			/* element to be added */
{
    int size;			/* size of S */
    sequence res;		/* result */

    size = OMsequence_Dsize(s);
    res = OFsequence_D__alloc(size + 1);
    OMsequence_D__subcopy(res, 1, s, 1, size);
    OMsequence_D__store(res, size + 1, e);
    RETURN1(res);
}


/*
 * addl = proc(s: sequence[T], e: T) returns(sequence[T]) signals(bounds)
 */

int OFsequence_Daddl(s, e)
sequence s;			/* target sequence */
object e;			/* element to be added */
{
    int size;			/* size of S */
    sequence res;		/* result */

    size = OMsequence_Dsize(s);
    res = OFsequence_D__alloc(size + 1);
    OMsequence_D__store(res, 1, e);
    OMsequence_D__subcopy(res, 2, s, 1, size);
    RETURN1(res);
}


/*
 * remh = proc(s: sequence[T]) returns(sequence[T]) signals(bounds)
 */

int OFsequence_Dremh(s)
sequence s;			/* target sequence */
{
    int size;			/* size of result */
    sequence res;		/* result */

    size = OMsequence_Dsize(s) - 1;

    if (size < 0) {
	SIGNAL0(SLBOUNDS);
    }

    res = OFsequence_D__alloc(size);
    OMsequence_D__subcopy(res, 1, s, 1, size);
    RETURN1(res);
}


/*
 * reml = proc(s: sequence[T]) returns(sequence[T]) signals(bounds)
 */

int OFsequence_Dreml(s)
sequence s;			/* target sequence */
{
    int size;			/* size of result */
    sequence res;		/* result */

    size = OMsequence_Dsize(s) - 1;

    if (size < 0) {
	SIGNAL0(SLBOUNDS);
    }

    res = OFsequence_D__alloc(size);
    OMsequence_D__subcopy(res, 1, s, 2, size);
    RETURN1(res);
}


/*
 * e2s = proc(e: T) returns(sequence[T])
 */

int OFsequence_De2s(e)
object e;			/* element of the result */
{
    sequence res;		/* result */

    res = OFsequence_D__alloc(1);
    OMsequence_D__store(res, 1, e);
    RETURN1(res);
}


/*
 * concat = proc(s1, s2: sequence[T]) returns(sequence[T])
 */

int OFsequence_Dconcat(s1, s2)
sequence s1;			/* left hand side */
sequence s2;			/* right hand side */
{
    sequence res;		/* result */
    int size1;			/* size of S1 */
    int size2;			/* size of S2 */

    size1 = OMsequence_Dsize(s1);
    size2 = OMsequence_Dsize(s2);
    res = OFsequence_D__alloc(size1 + size2);
    OMsequence_D__subcopy(res, 1, s1, 1, size1);
    OMsequence_D__subcopy(res, size1 + 1, s2, 1, size2);
    RETURN1(res);
}


/*
 * a2s = proc(a: array[T]) returns(sequence[T])
 */

int OFsequence_Da2s(a)
array a;
{
    int size;			/* size common to A and the result */
    sequence res;		/* result */
    int i;			/* index for each element of the result */
    int j;			/* index of each element of A */

    size = OMarray_Dsize(a);
    res = OFsequence_D__alloc(size);
    for (i = 1, j = OMarray_Dlow(a); i <= size; i++, j++) {
	OMsequence_D__store(res, i, OMarray_Dfetch(a, j));
    }
    RETURN1(res);
}


/*
 * s2a = proc(s: sequence[T]) returns(array[T])
 */

int OFsequence_Ds2a(s)
sequence s;			/* target sequence */
{
    int size;			/* size common to S and the result */
    array res;			/* result */
    int i;			/* index of each element of S */
    int j;			/* index for each elment of the result */

    size = OMsequence_Dsize(s);
    res = OFarray_D__alloc(1, size);
    for (i = 1, j = OMarray_Dlow(res); i <= size; i++, j++) {
	OMarray_Dstore(res, j, OMsequence_Dfetch(s, i));
    }
    RETURN1(res);
}


/*
 * elements = iter(s: sequence[T]) yields(T)
 */

#define ARSIZE	3
#define LMs	((*ivarp)[0])
#define LMi	((*ivarp)[1])
#define LMsize	((*ivarp)[2])

int OFsequence_Delements(init, ivarp, s)
bool init;			/* initialization flag */
object **ivarp;			/* (pointer to the)^2 activation recored */
sequence s;			/* target sequence */
{
    if (init) {
	*ivarp = (object *) malloc(ARSIZE * sizeof(object));
	LMs = (object) s;
    } else {
	goto resume1;
    }

    LMsize = OMsequence_Dsize(LMs);
    for (LMi = 1; LMi <= LMsize; LMi++) {
	retval_area[0] = (object) OMsequence_Dfetch(LMs, LMi);
	return YIELD;
    resume1:
	NO_OPERATION;
    }
    RETURN0;
}

#undef ARSIZE
#undef LMs
#undef LMi
#undef LMsize


/*
 * indexes = iter(s: sequence[T]) returns(T)
 */

#define ARSIZE	3
#define LMs	((*ivarp)[0])
#define LMsize	((*ivarp)[1])
#define LMi	((*ivarp)[2])

int OFsequence_Dindexes(init, ivarp, s)
bool init;			/* initialization flag */
object **ivarp;			/* (pointer to the)^2 activation record */
sequence s;			/* target sequence */
{
    if (init) {
	*ivarp = (object *) malloc(ARSIZE * sizeof(object));
	LMs = (object) s;
    } else {
	goto resume1;
    }

    LMsize = OMsequence_Dsize(LMs);
    for (LMi = 1; LMi <= LMsize; LMi++) {
	retval_area[0] = LMi;
	return YIELD;
    resume1:
	NO_OPERATION;
    }
    RETURN0;
}

#undef ARSIZE
#undef LMs
#undef LMsize
#undef LMi


/*
 * equal = proc(s1, s2: sequence[T]) returns(bool)
 *         where T has equal: proctype(T, T) returns(bool)
 */

int OFsequence_Dequal(op_list, s1, s2)
oplist_t op_list;		/* list of parameter-dependent operations */
sequence s1;			/* left hand side */
sequence s2;			/* right hand side */
{
    return OFsequence_D__equal(op_list, s1, s2);
}


/*
 * similar = proc(s1, s2: sequence[T]) returns(bool)
 *           where T has similar: proctype(T, T) returns(bool)
 */

int OFsequence_Dsimilar(op_list, s1, s2)
oplist_t op_list;		/* list of parameter-dependent operations */
sequence s1;			/* left hand side */
sequence s2;			/* right hand side */
{
    return OFsequence_D__equal(op_list, s1, s2);
}


/*
 * copy = proc(s: sequence[T]) returns(sequence[T])
 *        where T has copy: proctype(T) returns(T)
 */

int OFsequence_Dcopy(op_list, s)
oplist_t op_list;		/* list of parameter-dependent operations */
sequence s;			/* target sequence */
{
    int size;			/* size common to S and the result */
    sequence res;		/* result */
    int i;			/* index of each element of S and the result */

    size = OMsequence_Dsize(s);
    res = OFsequence_D__alloc(size);
    for (i = 1; i <= size; i++) {
	if ((*(op_list[0]))(OMsequence_Dfetch(s, i)) == SIG) {
	    out_handler();
	    return SIG;
	}
	OMsequence_D__store(res, i, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * encode = proc(s: sequence[T], ist: istream) signals(not_possible(string))
 *          where T has encode: proctype(T, istream)
 *                              signals(not_possible(stirng))
 */

int OFsequence_Dencode(op_list, s, ist)
oplist_t op_list;		/* list of parameter-dependent operations */
sequence s;			/* target sequence */
object ist;			/* istream */
{
    int id;			/* identification number for S */
    int size;			/* size of S */
    int i;			/* index for each element of S */

    /*
     * Checks if S has been already encoded.
     */
    OFistream_Dcheck__history(ist, s);
    id = (int) retval_area[0];
    if (OFistream_Dputi(ist, id) == SIG) {
	return SIG;
    }
    if (id != NOT_YET) {
	RETURN0;
    }

    /*
     * Encodes S.
     */
    size = OMsequence_Dsize(s);
    if (OFistream_Dputi(ist, size) == SIG) {
	return SIG;
    }
    for (i = 1; i <= size; i++) {
	if ((*(op_list[0]))(OMsequence_Dfetch(s, i), ist) == SIG) {
	    return SIG;
	}
    }
    RETURN0;
}


/*
 * decode = proc(ist: istream) returns(sequence[T])
 *          signals(end_of_file, not_possible(string))
 *          where T has decode: proctype(istream) returns(T)
 *                              signals(end_of_file, not_possible(string))
 */

int OFsequence_Ddecode(op_list, ist)
oplist_t op_list;		/* list of parameter-dependent operations */
object ist;			/* istream */
{
    int id;			/* identification number for the result */
    int size;			/* size of the result */
    int i;			/* index for each element of the result */
    sequence res;		/* result */

    /*
     * Checks if this sequence has been already decoded.
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
     * Decodes size, and checks it.
     */
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    size = (int) retval_area[0];
    if (size < 0) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    }

    /*
     * Creates sequence object, and add it to history.
     */
    res = OFsequence_D__alloc(size);
    OFistream_Dadd__history(ist, res);

    /*
     * Decodes elements.
     */
    if (size == 0) {
	RETURN1(res);
    }
    for (i = 1; i <= size; i++) {
	if ((*(op_list[0]))(ist) == SIG) {
	    return SIG;
	}
	OMsequence_D__store(res, i, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * print = proc (s: sequence[T], pst: pstream)
 *         where T has print: proctype(T, pstream)
 */

int OFsequence_Dprint(op_list, s, pst)
oplist_t op_list;		/* list of parameter-dependent operations */
sequence s;			/* target sequence */
object pst;			/* pstream */
{
    static string lbkt = 0;
    static string rbkt = 0;
    static string comma = 0;

    int i;			/* index of each element of S */

    if (!lbkt) {
	lbkt = OFstring_D__cs2s("[");
	rbkt = OFstring_D__cs2s("]");
	comma = OFstring_D__cs2s(", ");
    }

    if (OFpstream_Dstart(pst, lbkt) == SIG) {
	out_handler();
	return SIG;
    }
    for (i = 1; i <= OMsequence_Dsize(s); i++) {
	if (i > 1) {
	    if (OFpstream_Dpause(pst, comma) == SIG) {
		out_handler();
		return SIG;
	    }
	    OFbool_Dnot((bool) retval_area[0]);
	    if ((bool) retval_area[0]) {
		break;
	    }
	}
	(*(op_list[0]))(OMsequence_Dfetch(s, i), pst);
    }
    if (OFpstream_Dstop(pst, rbkt) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*
 * _gcd = proc(s: sequence[T], tab: gcd_tab) returns(int)
 *        where T has _gcd: proctype(T, gcd_tab) returns(int)
 */

int OFsequence_D__gcd(op_list, s, tab)
oplist_t op_list;		/* list of parameter-dependent operations */
sequence s;			/* target sequence */
object tab;			/* gcd_tab */
{
    /* stub version */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("sequence$_gcd: not implemented"));
}


/*
 * Hidden operations
 */


/*
 * _alloc - allocate memory for sequence object
 *
 * Requires:
 *	SIZE is a non-negative integer.
 *
 * Effects:
 *	Returns a pointer to a new memory area for sequence object
 *	that will contain SIZE elements.  Initialization of each
 *	component is not done.
 */

sequence OFsequence_D__alloc(size)
int size;			/* size of the result */
{
    sequence res;		/* result */

#if CLU2C_SEQUENCE_VERSION == 1
    res = (sequence) malloc(sizeof(struct sequence_rep));
    res->size = size;
    if (size <= 0) {
	res->buf = 0;
    } else {
	res->buf = (object *) malloc(size * sizeof(object));
    }
#endif
#if CLU2C_SEQUENCE_VERSION == 2
    res = (sequence) malloc((size + 1) * sizeof(object));
    res[0] = size;
#endif
    return res;
}


/*
 * Internal routines
 */


/*
 * _equal - common task for equal/similar
 */

static int OFsequence_D__equal(op_list, s1, s2)
oplist_t op_list;		/* list of parameter-dependent operations */
sequence s1;			/* left hand side */
sequence s2;			/* right hand side */
{
    int size;			/* size of S1 (and S2) */
    int i;			/* index of each element of S1 and S2 */

    /*
     * Returns false if the sizes of two sequences differ.
     */
    size = OMsequence_Dsize(s1);
    if (size != OMsequence_Dsize(s2)) {
	RETURN1(FALSE);
    }

    /*
     * Compares each element and returns false if different elements
     * is found.
     */
    for (i = 1; i <= size; i++) {
	if ((*(op_list[0]))(OMsequence_Dfetch(s1, i),
			    OMsequence_Dfetch(s2, i)) == SIG)
	{
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
