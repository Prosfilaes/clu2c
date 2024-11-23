/*-
 * sequence.h
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: sequence.h,v 2.4 1996/05/12 06:46:33 ushijima Exp $
 */


#ifdef CLU2C_SEQUENCE_VERSION
#   if CLU2C_SEQUENCE_VERSION < 1 || CLU2C_SEQUENCE_VERSION > 2
	!!! version CLU2C_SEQUENCE_VERSION not supported !!!
#   endif
#else
#   define CLU2C_SEQUENCE_VERSION 2
#endif


/* Representation */

#if CLU2C_SEQUENCE_VERSION == 1
    struct sequence_rep {
	int size;
	object *buf;
    };
    typedef struct sequence_rep *sequence;
#endif
#if CLU2C_SEQUENCE_VERSION == 2
    typedef object *sequence;
#endif


/* Macros for inline expansion */

/* Bodies of Macro for inline expansion */

#if CLU2C_SEQUENCE_VERSION == 1
#   define OMsequence_Dsize(x) (((sequence) (x))->size)
#   define OMsequence_Dfetch(x, i) (((sequence) (x))->buf[(i) - 1])
#endif
#if CLU2C_SEQUENCE_VERSION == 2
#   define OMsequence_Dsize(x) (((sequence) (x))[0])
#   define OMsequence_Dfetch(x, i) (((sequence) (x))[i])
#endif

#define OMsequence_Dempty(x) (OMsequence_Dsize(x) <= 0)
#define OMsequence_Dbottom(x) OMsequence_Dfetch((x), 1)
#define OMsequence_Dtop(x) OMsequence_Dfetch((x), OMsequence_Dsize(x))
#define OMsequence_D__store(x,i,e) (OMsequence_Dfetch((x), (i)) = (object) (e))


/* Flags Which catch the signal raised by Macro for inline expansion */

#define OMsequence_Dbounds(x,i)	((i) < 1 || OMsequence_Dsize(x) < (i))

/* Declaration of non-int result functions */

extern sequence OFsequence_D__alloc();
