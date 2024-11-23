/*
 * itertype.c - implementation of itertype
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: itertype.c,v 2.5 1996/10/07 05:01:12 ushijima Exp $
 */

#include <clu2c.h>


/*
 * Operations
 */


/*
 * equal = proc(i1, i2: itertype(...)) returns(bool)
 */

int OFitertype_Dequal(i1, i2)
itertype i1;			/* left hand side */
itertype i2;			/* right hand side */
{
    RETURN1(OMitertype_Dequal(i1, i2));
}


/*
 * similar = proc(i1, i2: itertype(...)) returns(bool)
 */

int OFitertype_Dsimilar(i1, i2)
itertype i1;			/* left hand side */
itertype i2;			/* right hand side */
{
    RETURN1(OMitertype_Dsimilar(i1, i2));
}


/*
 * copy = proc(i: itertype(...)) returns(itertype(...))
 */

int OFitertype_Dcopy(i)
itertype i;			/* target */
{
    RETURN1(OMitertype_Dcopy(i));
}
