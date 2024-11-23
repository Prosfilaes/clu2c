/*
 * $Id: oneof.h,v 2.6 1997/02/05 09:55:48 ushijima Exp $
 *
 * Copyright (c) 1992, 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Representation */

struct oneof_rep {
    int tag;
    object value;
};

typedef struct oneof_rep *oneof;

/* Macros for inline expansion */

#define OMoneof_Dis(n,x)	(((oneof) (x))->tag == n)
#define OMoneof_D__tag(x)	(((oneof) (x))->tag)
#define OMoneof_D__value(x)	(((oneof) (x))->value)
