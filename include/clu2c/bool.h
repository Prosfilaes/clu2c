/*
 * $Id: bool.h,v 2.2 1996/05/12 06:45:45 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

#ifndef _BOOL_
#define _BOOL_

/* Representation */

typedef int bool;

#define TRUE	1
#define FALSE	0

/* Macros for inline expansion */

#define OMbool_Dand(x,y)		((x) && (y))
#define OMbool_Dor(x,y)		((x) || (y))
#define OMbool_Dnot(x)		(! (x))
#define OMbool_Dequal(x,y)	((x) == (y))
#define OMbool_Dsimilar(x,y)	((x) == (y))
#define OMbool_Dcopy(x)		(x)

#endif /* _BOOL_ */
