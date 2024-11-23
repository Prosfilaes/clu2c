/*
 * record.c - implementation of record
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: record.c,v 2.9 1996/10/07 05:01:06 ushijima Exp $
 */

#include <clu2c.h>


/*
 * Evaluates to the number of the components of R
 */

#define NR_COMPONENTS(r)	((r)[0] - 1)


/*
 * Internal routine declarations
 */

static int OFrecord_D__similar();


/*
 * Operations
 */


/*
 * get_Ni = proc(r: record[N1: T1, ..., Nn: Tn]) returns(Ti)
 */

int OFrecord_Dget(i, r)
int i;				/* selector number */
record r;			/* target */
{
    RETURN1(OMrecord_Dget(i, r));
}


/*
 * set_Ni = proc(r: record[N1: T1, ..., Nn: Tn], e: Ti)
 */

int OFrecord_Dset(i, r, e)
int i;				/* selector number */
record r;			/* target */
object e;			/* component to be set */
{
    OMrecord_Dset(i, r, e);
    RETURN0;
}


/*
 * r_gets_r = proc(r1, r2: record[N1: T1, ..., Nn: Tn])
 */

int OFrecord_Dr__gets__r(r1, r2)
record r1;
record r2;
{
    int nr_components;		/* number of components */
    int i;			/* selector number of each component */

    nr_components  = NR_COMPONENTS(r2);
    for(i = 1; i <= nr_components; i++) {
	OMrecord_Dset(i, r1, OMrecord_Dget(i, r2));
    }
    RETURN0;
}


/*
 * r_gets_s = proc(r: record[N1: T1, ..., Nn: Tn],
 *                 s: struct[N1: T1, ..., Nn: Tn])
 */

int OFrecord_Dr__gets__s(r, s)
record r;			/* target */
struct_ s;
{
    int nr_components;		/* number of components */
    int i;			/* index for each component */

    nr_components  = NR_COMPONENTS(r);
    for(i = 1; i <= nr_components; i++) {
	OMrecord_Dset(i, r, OMstruct_Dget(i, s));
    }
    RETURN0;
}


/*
 * equal = proc(r1, r2: record[N1: T1, ..., Nn: Tn]) returns(bool)
 */

int OFrecord_Dequal(r1, r2)
record r1;			/* left hand side */
record r2;			/* right hand side */
{
    RETURN1(r1 == r2);
}


/*
 * similar = proc(r1, r2: record[N1: T1, ..., Nn: Tn]) returns(bool)
 *           where each Ti has similar: proctype(Ti, Ti) returns(bool)
 */

int OFrecord_Dsimilar(op_list, r1, r2)
oplist_t op_list;		/* list of parameter-dependent operations */
record r1;			/* left hand side */
record r2;			/* right hand side */
{
    return OFrecord_D__similar(op_list, r1, r2);
}


/*
 * similar1 = proc(r1, r2: record[N1: T1, ..., Nn: Tn]) returns(bool)
 *            where each Ti has equal: proctype(Ti, Ti) returns(bool)
 */

int OFrecord_Dsimilar1(op_list, r1, r2)
oplist_t op_list;		/* list of parameter-dependent operations */
record r1;			/* left hand side */
record r2;			/* right hand side */
{
    return OFrecord_D__similar(op_list, r1, r2);
}


/*
 * copy1 = proc(r: record[N1: T1, ..., Nn: Tn])
 *         returns(record[N1: T1, ..., Nn: Tn])
 */

int OFrecord_Dcopy1(r)
record r;			/* target */
{
    int nr_components;		/* number of the components */
    record res;			/* result */
    int i;			/* selector number of each component */
    
    nr_components = NR_COMPONENTS(r);
    res = OFrecord_D__alloc(nr_components);
    for (i = 1; i <= nr_components; i++) {
	OMrecord_Dset(i, res, OMrecord_Dget(i, r));
    }
    RETURN1(res);
}


/*
 * copy = proc(r: record[N1: T1, ..., Nn: Tn])
 *        returns(record[N1: T1, ..., Nn: Tn])
 *        where each Ti has copy: proctype(Ti) returns(bool)
 */

int OFrecord_Dcopy(op_list, r)
oplist_t op_list;		/* list of parameter-dependent operations */
record r;			/* target */
{
    int nr_components;		/* number of the components */
    record res;			/* result */
    int i;			/* selector number of each component */
  
    nr_components = NR_COMPONENTS(r);
    res = OFrecord_D__alloc(nr_components);
    for (i = 1; i <= nr_components; i++) {
	if ((*(op_list[i - 1]))(OMrecord_Dget(i, r)) == SIG) {
	    out_handler();
	    return(SIG);
	}
	OMrecord_Dset(i, res, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * encode = proc(r: record[N1: T1, ..., Nn: Tn], ist: istream)
 *          signals(not_possible(string))
 *          where each Ti has encode: proctype(Ti, istream)
 *                                    signals(not_possible(stirng))
 */

int OFrecord_Dencode(op_list, r, ist)
oplist_t op_list;		/* list of parameter-dependent operations */
record r;			/* target */
object ist;			/* istream */
{
    int id;			/* identification number for R */
    int nr_components;		/* number of components */
    int i;			/* loop counter */
  
    /*
     * Checks if this record has been already encoded.
     */
    OFistream_Dcheck__history(ist, r);
    id = (int) retval_area[0];
    if (OFistream_Dputi(ist, id) == SIG) {
	return SIG;
    }
    if (id != NOT_YET) {
	RETURN0;
    }
  
    /*
     * Encodes the number of components.
     */
    nr_components = NR_COMPONENTS(r);
    if (OFistream_Dputi(ist, nr_components) == SIG) {
	return SIG;
    }
  
    /*
     * Encodes each component.
     */
    for (i = 1; i <= nr_components; i++) {
	if ((*(op_list[i - 1]))(OMrecord_Dget(i, r), ist) == SIG) {
	    return SIG;
	}
    }
    RETURN0;
}


/*
 * decode = proc(ist: istream) returns(record[N1: T1, ..., Nn: Tn])
 *          signals(end_of_file, not_possible(string))
 *          where each Ti has decode: proctype(istream) returns(Ti)
 *                                    signals(end_of_file,
 *                                            not_possible(string))
 */

int OFrecord_Ddecode(op_list, ist)
oplist_t op_list;		/* list of parameter-dependent operations */
object ist;			/* istream */
{
    int id;			/* identification number for the result */
    int nr_components;		/* number of the components */
    record res;			/* result */
    int i;			/* selector number of each component */
  
    /*
     * Checks if this record has been already decoded.
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
     * Decodes the number of the components.
     */
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    nr_components = (int) retval_area[0];
    if (nr_components <= 0) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    }
  
    /*
     * Allocates a record object, and adds it to history.
     */
    res = OFrecord_D__alloc(nr_components);
    OFistream_Dadd__history(ist, res);
  
    /*
     * Decodes each component.
     */
    for (i = 1; i <= nr_components; i++) {
	if ((*op_list[i - 1])(ist) == SIG) {
	    return SIG;
	}
	OMrecord_Dset(i, res, retval_area[0]);
    }
    RETURN1(res);
}


/*
 * print = proc(r: record[N1: T1, ... Nn: Tn], pst: pstream)
 *         where each Ti has print: proctype(Ti, pstream)
 */

int OFrecord_Dprint(op_list, r, pst)
oplist_t op_list;		/* list of parameter-dependent operations */
record r;			/* targer record */
object pst;			/* pstream */
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
    for (i = 1; i <= NR_COMPONENTS(r); i++) {
	if (i > 1) {
	    if (OFpstream_Dpause(pst, comma) == SIG) {
		out_handler();
		return SIG;
	    }
	    if (OMbool_Dnot(retval_area[0])) {
		break;
	    }
	}
	(*(op_list[i - 1]))(OMrecord_Dget(i, r), pst);
    }
    if (OFpstream_Dstop(pst, rbrace) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*
 * _gcd = proc (r: record[N1: T1, ... Nn: Tn], tab: gcd_tab) returns(int)
 *        where each Ti has _gcd: proctype(Ti, gcd_tab) returns(int)
 */

int OFrecord_D__gcd(op_list, r, tab)
oplist_t op_list;		/* list of parameter-dependent operations */
record r;			/* target */
object tab;			/* gcd_tab */
{
    /* Stub version. */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("record$_gcd: not implemented"));
}


/*
 * Hidden operations
 */


/*
 * _alloc - allocate record object
 *
 * Effects:
 *   	Returns a pointer to a newly allocated record object such that
 *	the number of components is NR_COMPONENTS.
 *
 * Note:
 *	Components are not initialized.
 */

record OFrecord_D__alloc(nr_components)
int nr_components;		/* number of components */
{
    int size;			/* size of the result */
    record res;			/* result */

    size = nr_components + 1;
    res = (record) malloc(size * sizeof(object));
    res[0] = size;
    return res;
}


/*
 * Internal routines
 */


/*
 * _similar - common task for similar/similar1
 */

static int OFrecord_D__similar(op_list, r1, r2)
oplist_t op_list;		/* list of parameter-dependent operations */
record r1;			/* left hand side */
record r2;			/* right hand side */
{
    int nr_components;		/* number of the components */
    int i;			/* selector number of each component */

    nr_components = NR_COMPONENTS(r1);
    for (i = 1; i <= nr_components; i++) {
	if ((*op_list[i - 1])(OMrecord_Dget(i, r1),
			      OMrecord_Dget(i, r2)) == SIG)
	{
	    out_handler();
	    return SIG;
	}
	if (retval_area[0] == FALSE) {
	    return RET;
	}
    }
    RETURN1(TRUE);
}
