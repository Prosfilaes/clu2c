/*
 * $Id: char.h,v 2.8 1996/05/12 06:45:50 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */


#ifdef CLU2C_CHAR_VERSION
#   if CLU2C_CHAR_VERSION < 1 || CLU2C_CHAR_VERSION > 2
	!!! version CLU2C_CHAR_VERSION not supported !!!
#   endif
#else
#   ifdef J10N
#	define CLU2C_CHAR_VERSION 2
#   else
#	define CLU2C_CHAR_VERSION 1
#   endif
#endif


/*
 * Representation
 */

typedef int char_;
#if CLU2C_CHAR_VERSION == 1
    typedef char char_t;
#endif
#if CLU2C_CHAR_VERSION == 2
    typedef short char_t;
#endif


/*
 * Constants
 */

#if CLU2C_CHAR_VERSION == 1
#   define CHAR_TOP	0xff
#endif
#if CLU2C_CHAR_VERSION == 2
#   define CHAR_TOP	0x7e7e
#endif


/*
 * Macros for inline expansion
 */

#define OMchar_Di2c(x)		(x)
#define OMchar_Dc2i(x)		((int) (x))
#define OMchar_Dlt(x,y)		((x) <  (y))
#define OMchar_Dle(x,y)		((x) <= (y))
#define OMchar_Dge(x,y)		((x) >= (y))
#define OMchar_Dgt(x,y)		((x) >  (y))
#define OMchar_Dequal(x,y)	((x) == (y))
#define OMchar_Dsimilar(x,y)	((x) == (y))
#define OMchar_Dcopy(x)		(x)

#if CLU2C_CHAR_VERSION == 1
#   define OMchar_Dwidth(x)	(1)
#endif
#if CLU2C_CHAR_VERSION == 2
#   define OMchar_Dwidth(x)	((((int) (x)) < 0x100) ? 1 : 2)
#endif

#define OMchar_Dlit1(x)		(x)


/*
 * Flags which catch the signal raised by macro for inline expansion
 */

#define OMchar_Dillegal__char(x)	(((x) < 0) || (CHAR_TOP < (x)))
