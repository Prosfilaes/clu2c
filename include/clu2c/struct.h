/*
 * $Id: struct.h,v 2.3 1996/05/12 06:46:43 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Representation */

typedef object *struct_;	/* first element is size of obj */

/* Macros for inline expansion */

#define OMstruct_Dget(n,x)	(((struct_) (x))[n])
#define OMstruct_D__set(n,x,e)	(((struct_) (x))[n] = (e))

/* Operation declarations */

extern struct_ OFstruct_D__alloc();
