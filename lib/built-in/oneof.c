/*
 * oneof.c - implementation of oneof
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: oneof.c,v 2.10 1996/10/07 05:01:09 ushijima Exp $
 */

#include <clu2c.h>

static int OFoneof_D__equal();


/*
 * Operations
 */


/*
 * make_Ni = proc(value: Ti) returns(oneof[N1: T1, ..., Nn: Tn])
 */

int OFoneof_Dmake(tag, value)
int tag;			/* tag number */
object value;			/* value */
{
    oneof res;
    
    res = (oneof) malloc(sizeof(struct oneof_rep));
    res->tag = tag;
    res->value = value;
    RETURN1(res);
}


/*
 * is_Ni = proc(o: oneof[N1: T1, ..., Nn: Tn]) returns(bool)
 */

int OFoneof_Dis(tag, o)
int tag;			/* tag number */
oneof o;			/* target */
{
    RETURN1(o->tag == tag);
}


/*
 * value_Ni = proc(o: oneof[N1: T1, ..., Nn: Tn]) returns(Ti)
 *            signals(wrong_tag)
 */

int OFoneof_Dvalue(tag, o)
int tag;			/* tag number */
oneof o;			/* target */
{
    if (o->tag == tag) {
	RETURN1(o->value);
    } else {
	SIGNAL0(SLWRONG_TAG);
    }
}


/*
 * o2v = proc(o: oneof[N1: T1, ..., Nn: Tn])
 *       returns(variant[N1: T1, ..., Nn: Tn])
 */

int OFoneof_Do2v(o)
oneof o;
{
    return OFvariant_Dmake(o->tag, o->value);
}


/*
 * v2o = proc(v: variant[N1: T1, ..., Nn: Tn])
 *       returns(oneof[N1: T1, ..., Nn: Tn])
 */

int OFoneof_Dv2o(v)
variant v;
{
    return OFoneof_Dmake(OMvariant_D__tag(v), OMvariant_D__value(v));
}


/*
 * equal = proc(o1, o2:oneof[N1: T1, ..., Nn: Tn]) returns(bool)
 *	   where each Ti has equal: proctype(Ti, Ti) returns(bool)
 */

int OFoneof_Dequal(op_list, o1, o2)
oplist_t op_list;		/* list of parameter-dependent operations */
oneof o1;			/* left hand side */
oneof o2;			/* right hand side */
{
    return OFoneof_D__equal(op_list, o1, o2);
}


/*
 * similar = proc(o1, o2:oneof[N1: T1, ..., Nn: Tn]) returns(bool)
 *	     where each Ti has similar: proctype(Ti, Ti) returns(bool)	
 */

int OFoneof_Dsimilar(op_list, o1, o2)
oplist_t op_list;		/* list of parameter-dependent operations */
oneof o1;			/* left hand side */
oneof o2;			/* right hand side */
{
    return OFoneof_D__equal(op_list, o1, o2);
}


/*
 * copy = proc(o: oneof[N1: T1, ..., Nn: Tn])
 *	  returns(oneof[N1: T1, ..., Nn: Tn]))
 *        where each Ti has copy: proctype(Ti) returns(Ti)
 */

int OFoneof_Dcopy(op_list, o)
oplist_t op_list;		/* list of parameter-dependent operations */
oneof o;			/* target */
{
    if ((*op_list[o->tag - 1])(o->value) == SIG) {
	out_handler();
	return SIG;
    }
    OFoneof_Dmake(o->tag, retval_area[0]);
    return RET;
}


/*
 * encode = proc(o: oneof[N1: T1, ..., Nn: Tn], ist: istream)
 *          signals(not_possible(string))
 *          where each Ti has encode: proctype(Ti, istream)
 *                                    signals(not_possible(stirng))
 */

int OFoneof_Dencode(op_list, o, ist)
oplist_t op_list;		/* list of parameter-dependent operations */
oneof o;			/* target */
object ist;			/* istream */
{
    int id;			/* identification number for O */
  
    /*
     * Checks if this oneof has been already encoded.
     */
    OFistream_Dcheck__history(ist, o);
    id = (int) retval_area[0];
    if (OFistream_Dputi(ist, id) == SIG) {
	return SIG;
    }
    if (id != NOT_YET) {
	return RET;
    }
  
    /*
     * Encodes O.
     */
    if (OFistream_Dputi(ist, o->tag) == SIG) {
	return SIG;
    }
    return (*op_list[o->tag -1 ])(o->value, ist);
}


/*
 * decode = proc(ist: istream) returns(oneof[N1: T1, ..., Nn: Tn])
 *          signals(end_of_file, not_possible(string))
 *          where each Ti has decode: proctype(istream) returns(Ti)
 *                                    signals(end_of_file,
 *                                            not_possible(string))
 */

int OFoneof_Ddecode(op_list, ist)
oplist_t op_list;		/* list of parameter-dependent operations */
object ist;			/* istream */
{
    int id;			/* identification number for the result */
    int tag;			/* tag of the result */
    oneof res;			/* result */
    
    /*
     * Checks if this object has been already decoded.
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
     * Decodes tag.
     */
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    tag = (int) retval_area[0];
    if (tag < 1) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    }
    
    /*
     * Creates oneof object, and add it to history.
     */
    OFoneof_Dmake(tag, 0);
    res = (oneof) retval_area[0];
    OFistream_Dadd__history(ist, res);
    
    /*
     * Decodes value.
     */
    if ((*op_list[tag - 1])(ist) == SIG) {
	return SIG;
    }
    res->value = retval_area[0];

    RETURN1(res);
}


/*
 * print = proc(o: oneof[N1: T1, ..., Nn: Tn], pst: pstream)
 *         where each Ti has print: proctype(Ti, pstream)
 */

int OFoneof_Dprint(op_list, o, pst)
oplist_t op_list;		/* list of parameter-dependent operations */
oneof o;			/* target */
object pst;			/* pstream */
{
    static string langle = 0;
    static string rangle = 0;
    static string colon = 0;

    if (!langle) {
	langle = OFstring_D__cs2s("<");
	rangle = OFstring_D__cs2s(">");
	colon = OFstring_D__cs2s(": ");
    }

    if (OFpstream_Dstart(pst, langle) == SIG) {
	out_handler();
	return SIG;
    }
    if (OFint_Dprint(o->tag, pst) == SIG) {
	out_handler();
	return SIG;
    }
    if (OFpstream_Dtext(pst, colon) == SIG) {
	out_handler();
	return SIG;
    }
    if ((*(op_list[o->tag - 1]))(o->value, pst) == SIG) {
	out_handler();
	return SIG;
    }	
    if (OFpstream_Dstop(pst, rangle) == SIG) {
	out_handler();
	return SIG;
    }
    RETURN0;
}


/*
 * _gcd = proc(o: oneof[N1: T1, ..., Nn: Tn], tab: gcd_tab) returns(int)
 *        where each Ti has _gcd: proctype(Ti, gcd_tab) returns(int)
 */

int OFoneof_D__gcd(op_list, o, tab)
oplist_t op_list;		/* list of parameter-dependent operations */
oneof o;			/* target */
object tab;			/* gcd_tab */
{
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("oneof$_gcd: not implemented"));
}


/*
 * Internal routines
 */


/*
 * _equal - common task for equal/similar
 */

static int OFoneof_D__equal(op_list, o1, o2)
oplist_t op_list;		/* list of parameter-dependent operations */
oneof o1;			/* left hand side */
oneof o2;			/* right hand side */
{
    /*
     * Compares tags.
     */
    if (o1->tag != o2->tag) {
	RETURN1(FALSE);
    }
    
    /*
     * Compares values.
     */
    if ((*op_list[o1->tag - 1])(o1->value, o2->value) == SIG) {
	out_handler();
	return SIG;
    }
    return RET;
}
