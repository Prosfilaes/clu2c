/*
 * $Id: variant.h,v 2.6 1997/02/05 09:55:49 ushijima Exp $
 *
 * Copyright (c) 1992, 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Representation */

struct variant_rep {
    int tag;
    object value;
};

typedef struct variant_rep *variant;

/* Macros for inline expansion */

#define OMvariant_Dis(n,x)	(((variant) (x))->tag == n)
#define OMvariant_Dequal(x,y)	((x) == (y))
#define OMvariant_D__tag(x)	(((variant) (x))->tag)
#define OMvariant_D__value(x)	(((variant) (x))->value)
