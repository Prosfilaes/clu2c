/*
 * $Id: any.h,v 2.4 1997/02/05 09:55:46 ushijima Exp $
 *
 * Copyright (c) 1992, 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

#ifndef _ANY_
#define _ANY_

/* Representation */

struct any_rep {
    int tid;
    object object;
};

typedef struct any_rep *any;

#endif /* _ANY_ */
