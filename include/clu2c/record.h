/*
 * $Id: record.h,v 2.3 1996/05/12 06:46:31 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Representation */

typedef object *record;		    /* first element is size of object */

/* Macros for inline expansion */

#define OMrecord_Dget(n,x)	(((record) (x))[n])
#define OMrecord_Dset(n,x,e)	(((record) (x))[n] = (e))


/*
 * Operation declarations
 */

extern record OFrecord_D__alloc();
