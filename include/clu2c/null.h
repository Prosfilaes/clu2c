/*
 * $Id: null.h,v 2.2 1996/05/12 06:46:19 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Representation */

typedef int null;

#define NIL 0

/* Macros for inline expansion */

#define OMnull_Dequal(x,y)	TRUE
#define OMnull_Dsimilar(x,y)	TRUE
#define OMnull_Dcopy(x)		(x)
