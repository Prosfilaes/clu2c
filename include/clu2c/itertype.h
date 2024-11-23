/*
 * $Id: itertype.h,v 2.2 1996/05/12 06:46:14 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Representation */

typedef int (*itertype)();

/* Macros for inline expansion */

#define OMitertype_Dequal(x,y)		((x) == (y))
#define OMitertype_Dsimilar(x,y)	((x) == (y))
#define OMitertype_Dcopy(x)		(x)
