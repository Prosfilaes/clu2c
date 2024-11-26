/*
 * struct.c - implementation of struct
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: struct.c,v 2.13 1996/10/07 05:01:01 ushijima Exp $
 */

#include <config/string.h>

#include <clu2c.h>
#include "struct.h"

/*
 * Evaluates to the number of the components of S
 */

#define NR_COMPONENTS(s)	((s)[0] - 1)


/*
 * Internal routine declarations
 */

static int OFstruct_D__equal();


/*
 * Operations
 */


/*
 * get_Ni = proc(s: struct[N1: T1, ..., Nn: Tn]) returns(Ti)
 */

int OFstruct_Dget(int i, struct_ s)
{
    RETURN1(OMstruct_Dget(i, s));
}


/*
 * replace_Ni = proc(s: struct[N1: T1, ..., Nn: Tn], e: Ti)
 *              returns(struct[N1: T1, ..., Nn: Tn])
 */

int OFstruct_Dreplace(int i, struct_ s, object e)
{
    int nr_components;		/* number of the components */
    struct_ res;		/* result */

    nr_components = NR_COMPONENTS(s);
    res = OFstruct_D__alloc(nr_components);
    memcpy((char *) (res + 1),
	   (char *) (s + 1),
	   nr_components * sizeof(object));
    OMstruct_D__set(i, res, e);
    RETURN1(res);
}


/*
 * s2r = proc(s: struct[N1: T1, ..., Nn: Tn])
 *       returns(record[N1: T1, ..., Nn: Tn])
 */

int OFstruct_Ds2r(struct_ s)
{
    int nr_components;		/* number of the components */
    record res;			/* result */
    int i;			/* selector number of each component */

    nr_components = NR_COMPONENTS(s);
    res = OFrecord_D__alloc(nr_components);
    for (i = 1; i <= nr_components; i++) {
	OMrecord_Dset(i, res, OMstruct_Dget(i, s));
    }
    RETURN1(res);
}


/*
 * r2s = proc(r: record[N1: T1, ..., Nn: Tn])
 *       returns(struct[N1: T1, ..., Nn: Tn])
 */

int OFstruct_Dr2s(record r)
{
    int nr_components;		/* number of the components */
    struct_ res;		/* result */
    int i;			/* selector number of each component */
    
    nr_components = NR_COMPONENTS(r);
    res = OFstruct_D__alloc(nr_components);
    for (i = 1; i <= nr_components; i++) {
	OMstruct_D__set(i, res, OMrecord_Dget(i, r));
    }
    RETURN1(res);
}


/*
 * equal = proc(s1, s2: struct[N1: T1, ..., Nn: Tn]) returns(bool)
 *         where each Ti has equal: proctype(Ti, Ti) returns(bool)
 */

int OFstruct_Dequal(oplist_t op_list, struct_ s1, struct_ s2)
{
    return OFstruct_D__equal(op_list, s1, s2);
}


/*
 * similar = proc(s1, s2: struct[N1: T1, ..., Nn: Tn]) returns(bool)
 *           where each Ti has similar: proctype(Ti, Ti) returns(bool)
 */

int OFstruct_Dsimilar(oplist_t op_list, struct_ s1, struct_ s2)
{
    return OFstruct_D__equal(op_list, s1, s2);
}


/*
 * copy = proc(s: struct[N1: T1, ..., Nn: Tn])
 *        returns(struct[N1: T1, ..., Nn: Tn])
 *        where each Ti has copy: proctype(Ti) returns(bool)
 */

int OFstruct_Dcopy(oplist_t op_list, struct_ s)
{
    int nr_components;		/* number of the components */
    struct_ res;		/* result */
    int i;			/* selector number of each component */
    
    /*
     * Allocates a new struct object.
     */
    nr_components = NR_COMPONENTS(s);
    res = OFstruct_D__alloc(nr_components);

    /*
     * Copies each component.
     */
    for (i = 1; i <= nr_components; i++) {
	if ((*op_list[i - 1])(OMstruct_Dget(i, s)) == SIG) {
	    out_handler();
	    return(SIG);
	}
	OMstruct_D__set(i, res, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * encode = proc(s: struct[N1: T1, ..., Nn: Tn], ist: istream)
 *          signals(not_possible(string))
 *          where each Ti has encode: proctype(Ti, istream)
 *                                    signals(not_possible(stirng))
 */

int OFstruct_Dencode(oplist_t op_list, struct_ s, object ist)
{
    int id;			/* identification number for S */
    int nr_components;		/* number of components */
    int i;			/* loop counter */
    
    /*
     * Checks if S has been already encoded.
     */
    OFistream_Dcheck__history(ist, s);
    id = (int) retval_area[0];
    if (OFistream_Dputi(ist, id) == SIG) {
	return SIG;
    }
    if (id != NOT_YET) {
	return RET;
    }
    
    /*
     * Encodes the number of components.
     */
    nr_components = NR_COMPONENTS(s);
    if (OFistream_Dputi(ist, nr_components) == SIG) {
	return SIG;
    }
    
    /*
     * Encodes each component.
     */
    for (i = 1; i <= nr_components; i++) {
	if ((*op_list[i - 1])(OMstruct_Dget(i, s), ist) == SIG) {
	    return SIG;
	}
    }
    RETURN0;
}


/*
 * decode = proc(ist: istream) returns(struct[N1: T1, ..., Nn: Tn])
 *          signals(end_of_file, not_possible(string))
 *          where each Ti has decode: proctype(istream) returns(Ti)
 *                                    signals(end_of_file,
 *                                            not_possible(string))
 */

int OFstruct_Ddecode(oplist_t op_list, object ist)
{
    int id;			/* identification number for the result */
    int nr_components;		/* number of the components */
    struct_ res;		/* result */
    int i;			/* selector number of each component */
  
    /*
     * Checks if this struct has been already decoded.
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
     * Gets the number of components.
     */
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    nr_components = (int) retval_area[0];
    if (nr_components <= 0) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    }
  
    /*
     * Creates a struct object, and adds it to history.
     */
    res = OFstruct_D__alloc(nr_components);
    OFistream_Dadd__history(ist, res);
  
    /*
     * Decodes each component.
     */
    for (i = 1; i <= nr_components; i++) {
	if ((*op_list[i - 1])(ist) == SIG) {
	    return SIG;
	}
	OMstruct_D__set(i, res, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * print = proc(s: struct[N1: T1, ... Nn: Tn], pst: pstream)
 *         where each Ti has print: proctype(Ti, pstream)
 */

int OFstruct_Dprint(oplist_t op_list, struct_ s, object pst)
{
    static string lbrace = 0;
    static string rbrace = 0;
    static string comma = 0;

    int i;			/* selector number of each component */

    if (!lbrace) {
	lbrace = OFstring_D__cs2s("{");
	rbrace = OFstring_D__cs2s("}");
	comma = OFstring_D__cs2s(", ");
    }

    if (OFpstream_Dstart(pst, lbrace) == SIG) {
	out_handler();
	return SIG;
    }
    for (i = 1; i <= NR_COMPONENTS(s); i++) {
	if (i > 1) {
	    if (OFpstream_Dpause(pst, comma) == SIG) {
		out_handler();
		return SIG;
	    }
	    if (retval_area[0] == FALSE) {
		break;
	    }
	}
	if ((*op_list[i - 1])(OMstruct_Dget(i, s), pst) == SIG) {
	    out_handler();
	    return SIG;
	}
    }
    if (OFpstream_Dstop(pst, rbrace) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*
 * _gcd = proc(s: struct[N1: T1, ..., Nn: Tn], tab: gcd_tab) returns(int)
 *        where each Ti has _gcd: proctype(Ti, gcd_tab) returns(int)
 */

int OFstruct_D__gcd(oplist_t op_list, struct_ s, object tab)
{
    /* Stub version. */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("struct$_gcd: not implemented"));
}


/*
 * Hidden operations
 */


/*
 * _alloc - allocate struct object
 *
 * Effects:
 *   	Returns a pointer to a newly allocated struct object such that
 *	the number of components is NR_COMPONENTS.
 *
 * Note:
 *	Components are not initialized.
 */

struct_ OFstruct_D__alloc(int nr_components)
{
    int size;			/* size of the result */
    struct_ res;		/* result */

    size = nr_components + 1;
    res = (struct_) malloc(size * sizeof(object));
    res[0] = size;
    return res;
}


/*
 * Internal routines
 */


/*
 * _equal - comman task for equal/similar
 */

static int OFstruct_D__equal(oplist_t op_list, struct_ s1, struct_ s2)
{
    int i, com_sz;
    
    com_sz = s1[0] - 1;
    
    for (i = 1; i <= com_sz; i++) {
	/* calling t$equal */
	if ((*(op_list[i-1]))(s1[i], s2[i]) == SIG) {
	    /* exception handling  */
	    out_handler();
	    return SIG;
	}
	if (retval_area[0] == FALSE) {
	    return RET;
	}
    }
    RETURN1(TRUE);
}
