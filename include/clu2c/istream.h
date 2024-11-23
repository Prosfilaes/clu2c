/*
 * $Id: istream.h,v 2.6 1997/02/05 09:55:47 ushijima Exp $
 *
 * Copyright (c) 1992, 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

#ifndef CLU2C_ISTREAM_H
#define CLU2C_ISTREAM_H

#include <stdio.h>

/* Representation */

#define RHIST_SIZE 1000

struct bucket {
    object key;
    int val;
    struct bucket *next;
};

struct istream_rep {
    FILE *fp;
    int mode;
    object fn;			/* file_name */
    array history;
    struct bucket *rhistory[RHIST_SIZE];
};

typedef struct istream_rep *istream;

#endif /* CLU2C_ISTREAM_H */
