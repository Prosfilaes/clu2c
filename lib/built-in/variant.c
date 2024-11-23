/*
 * variant.c - implementation of variant
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: variant.c,v 2.10 1996/10/07 05:00:59 ushijima Exp $
 */

#include <clu2c.h>

static int OFvariant_D__similar();

/*
 * Operations
 */


/*
 * make_Ni = proc(value: Ti) returns(variant[N1: T1, ..., Nn: Tn])
 */

int OFvariant_Dmake(tag, value)
int tag;			/* tag number */
object value;			/* value */
{
    variant res;		/* result */
    
    res = (variant) malloc(sizeof(struct variant_rep));
    res->tag = tag;
    res->value = value;
    RETURN1(res);
}


/*
 * change_Ni = proc(v: variant[N1: T1, ..., Nn: Tn], value: Ti)
 */

int OFvariant_Dchange(tag, v, value)
int tag;			/* tag number */
variant v;			/* target */
object value;			/* value after changed */
{
    v->tag = tag;
    v->value = value;
    RETURN0;
}


/*
 * is_Ni = proc(v: variant[N1: T1, ..., Nn: Tn]) returns(bool)
 */

int OFvariant_Dis(tag, v)
int tag;			/* tag number */
variant v;			/* target */
{
    RETURN1(v->tag == tag);
}


/*
 * value_Ni = proc(v: variant[N1: T1, ..., Nn: Tn]) returns(Ti)
 *            signals(wrong_tag)
 */

int OFvariant_Dvalue(tag, v)
int tag;			/* tag number */
variant v;			/* target */
{
    if (v->tag == tag) {
	RETURN1(v->value);
    } else {
	SIGNAL0(SLWRONG_TAG);
    }
}


/*
 * v_gets_v = proc(v1, v2: variant[N1: T1, ..., Nn: Tn])
 */

int OFvariant_Dv__gets__v(v1, v2)
variant v1;
variant v2;
{
    v1->tag = v2->tag;
    v1->value = v2->value;
    RETURN0;
}


/*
 * v_gets_o = proc(v: variant[N1: T1, ..., Nn: Tn],
 *                 o: oneof[N1: T1, ..., Nn: Tn])
 */

int OFvariant_Dv__gets__o(v, o)
variant v;			/* target */
oneof o;
{
    v->tag = OMoneof_D__tag(o);
    v->value = OMoneof_D__value(o);
    RETURN0;
}


/*
 * equal = proc(v1, v2: variant[N1: T1, ..., Nn: Tn]) returns(bool)
 */

int OFvariant_Dequal(v1, v2)
variant v1;			/* left hand side */
variant v2;			/* right hand side */
{
    RETURN1(OMvariant_Dequal(v1, v2));
}


/*
 * similar = proc(v1, v2: variant[N1: T1, ..., Nn: Tn]) returns(bool)
 *           where each Ti has similar: proctype(Ti, Ti) returns(bool)
 */

int OFvariant_Dsimilar(op_list, v1, v2)
oplist_t op_list;		/* list of parameter-dependent operations */
variant v1;			/* left hand side */
variant v2;			/* right hand side */
{
    return OFvariant_D__similar(op_list, v1, v2);
}


/*
 * similar1 = proc(v1, v2: variant[N1: T1, ..., Nn: Tn]) returns(bool)
 *            where each Ti has equal: proctype(Ti, Ti) returns(bool)
 */

int OFvariant_Dsimilar1(op_list, v1, v2)
oplist_t op_list;		/* list of parameter-dependent operations */
variant v1;			/* left hand side */
variant v2;			/* right hand side */
{
    return OFvariant_D__similar(op_list, v1, v2);
}


/*
 * copy = proc(v: variant[N1: T1, ..., Nn: Tn])
 *	  returns(variant[N1: T1, ..., Nn: Tn])
 *	  where each Ti has copy: proctype(Ti) returns(Ti)
 */

int OFvariant_Dcopy(op_list, v)
oplist_t op_list;		/* list of parameter-dependent operations */
variant v;			/* target */
{
    if ((*op_list[v->tag - 1])(v->value) == SIG) {
	out_handler();
	return SIG;
    }
    return OFvariant_Dmake(v->tag, retval_area[0]);
}


/*
 * copy1 = proc(v: variant[N1: T1, ..., Nn: Tn)
 *         returns(variant[N1: T1, ..., Nn: Tn)
 */

int OFvariant_Dcopy1(v)
variant v;			/* target */
{
    return OFvariant_Dmake(v->tag, v->value);
}


/*
 * encode = prvc(v: variant[N1: T1, ..., Nn: Tn], ist: istream) 
 *          signals(not_possible(string))
 *          where each Ti has encode: proctype(Ti, istream)
 *                                    signals(not_possible(stirng))
 */

int OFvariant_Dencode(op_list, v, ist)
oplist_t op_list;		/* list of parameter-dependent operations */
variant v;			/* target */
object ist;			/* istream */
{
    int id;			/* identification number for V */
  
    /*
     * Checks if this variant has been already encoded.
     */
    OFistream_Dcheck__history(ist, v);
    id = (int) retval_area[0];
    if (OFistream_Dputi(ist, id) == SIG) {
	return SIG;
    }
    if (id != NOT_YET) {
	return RET;
    }

    /*
     * Encodes tag.
     */
    if (OFistream_Dputi(ist, v->tag) == SIG) {
	return SIG;
    }
  
    /*
     * Encodes value (calling t$encode).
     */
    if ((*op_list[v->tag - 1])(v->value, ist) == SIG) {
	return SIG;
    }

    RETURN0;
}


/*
 * decode = proc(ist: istream) returns(variant[N1: T1, ..., Nn: Tn])
 *          signals(end_of_file, not_possible(string))
 *          where each Ti has decode: proctype(istream) returns(Ti)
 *                                    signals(end_of_file,
 *                                            not_possible(string))
 */

int OFvariant_Ddecode(op_list, ist)
oplist_t op_list;		/* list of parameter-dependent operations */
object ist;			/* istream */
{
    int id;			/* identification number for the result */
    int tag;			/* tag number of the result */
    variant res;		/* result */
    
    /*
     * Checks if this variant has been already decoded.
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
     * Gets tag.
     */
    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    tag = (int) retval_area[0];
    if (tag < 1) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    }
  
    /*
     * Creates variant object, and add it to history.
     */
    OFvariant_Dmake(tag, 0);
    res = (variant) retval_area[0];
    OFistream_Dadd__history(ist, res);
  
    /*
     * Gets value.
     */
    if ((*op_list[tag - 1])(ist) == SIG) {
	return SIG;
    }
    res->value = retval_area[0];
    
    RETURN1(res);
}


/*
 * print = proc(v: variant[N1: T1, ..., Nn: Tn], pst: pstream)
 *         where each Ti has print: proctype(Ti, pstream)
 */

int OFvariant_Dprint(op_list, v, pst)
oplist_t op_list;		/* list of parameter-dependent operations */
variant v;			/* target */
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
    if (OFint_Dprint(v->tag, pst) == SIG) {
	out_handler();
	return SIG;
    }
    if (OFpstream_Dtext(pst, colon) == SIG) {
	out_handler();
	return SIG;
    }
    if ((*op_list[v->tag - 1])(v->value, pst) == SIG) {
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
 * _gcd = proc(v: variant[N1: T1, ..., Nn: Tn], tab: gcd_tab) returns(int)
 *        where each Ti has _gcd: proctype(Ti, gcd_tab) returns(int)
 */

int OFvariant_D__gcd(op_list, v, tab)
oplist_t op_list;		/* list of parameter-dependent operations */
variant v;			/* target */
object tab;			/* gcd_tab */
{
    /* Stub version. */
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("variant$_gcd: not implemented"));
}


/*
 * Internal routines
 */


/*
 * _similar - common task for similar/similar1
 */

static int OFvariant_D__similar(op_list, v1, v2)
oplist_t op_list;		/* list of parameter-dependent operations */
variant v1;			/* left hand side */
variant v2;			/* right hand side */
{
    /*
     * Compares tags.
     */
    if (v1->tag != v2->tag) {
	RETURN1(FALSE);
    }
    
    /*
     * Compares values.
     */
    if ((*op_list[v1->tag - 1])(v1->value, v2->value) == SIG) {
	out_handler();
	return SIG;
    }
    return RET;
}
