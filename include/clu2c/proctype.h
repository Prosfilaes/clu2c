/*
 * $Id: proctype.h,v 2.3 1996/05/12 06:46:26 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Representation */

typedef int (*proctype)();

/* Macros for inline expansion */

#define OMproctype_Dequal(x,y)		((x) == (y))
#define OMproctype_Dsimilar(x,y)	((x) == (y))
#define OMproctype_Dcopy(x)		(x)
