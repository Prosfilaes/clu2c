/*
 * $Id: int.h,v 2.6 1996/06/21 13:54:06 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Macros for inline expansion */

/* Bodies of Macro for inline expansion */

#define OMint_Dadd(x,y)		(((int) (x)) + ((int) (y)))
#define OMint_Dsub(x,y)		(((int) (x)) - ((int) (y)))
#define OMint_Dmul(x,y)		(((int) (x)) * ((int) (y)))
#define OMint_Dminus(x)		(-((int) (x)))
#define OMint_Dabs(x)		((((int) (x)) > 0) ? ((int) (x)) : -((int) (x)))
#define OMint_Dmax(x,y)		((((int) (x)) > ((int) (y))) ? ((int) (x)) : ((int) (y)))
#define OMint_Dmin(x,y)		((((int) (x)) < ((int) (y))) ? ((int) (x)) : ((int) (y)))
#define OMint_Dlt(x,y)		(((int) (x)) <  ((int) (y)))
#define OMint_Dle(x,y)		(((int) (x)) <= ((int) (y)))
#define OMint_Dge(x,y)		(((int) (x)) >= ((int) (y)))
#define OMint_Dgt(x,y)		(((int) (x)) >  ((int) (y)))
#define OMint_Dequal(x,y)	(((int) (x)) == ((int) (y)))
#define OMint_Dsimilar(x,y)	(((int) (x)) == ((int) (y)))
#define OMint_Dcopy(x)		((int) (x))
#define OMint_Ddiv(x,y)		(((((int) (x)) >= 0) & (((int) (y)) > 0))\
				 ? (((int) (x)) / ((int) (y)))\
				 : OFint_D__div((x), (y)))
#define OMint_Dmod(x,y)		(((((int) (x)) >= 0) & (((int) (y)) > 0))\
				 ? (((int) (x)) % ((int) (y)))\
				 : OFint_D__mod((x), (y)))

/* Flags Which catch the signal raised by Macro for inline expansion */

#define OMint_Dzero__divide(x)	(((int) (x)) == 0)
