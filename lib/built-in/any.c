/*
 * any.c - implementation of any
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: any.c,v 2.6 1996/10/07 05:01:18 ushijima Exp $
 */

#include <clu2c.h>


/*
 * anyize
 */

any anyize(tid, obj)
int tid;			/* type ID */
object obj;			/* object to be anyized */
{
    any res;			/* result */

    res = (any) malloc(sizeof(struct any_rep));
    res->tid = tid;
    res->object = obj;
    return res;
}


/*
 * force = proc[t: type](x: any) returns(t) signals(wrong_type)
 */

int AFforce(tid, x)
int tid;
any x;
{
    if (x->tid != tid) {
	SIGNAL0(SLWRONG_TYPE);
    } else {
	RETURN1(x->object);
    }
}
