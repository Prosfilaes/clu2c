/*
 * $Id: array.h,v 2.5 1996/05/12 06:45:41 ushijima Exp $
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 */

/* Representation */

struct array_rep {
    object *buf_bottom;
    object *buf_top;
    object *low;
    object *high;
    object *zero;
};

typedef struct array_rep *array;

/*
 * Rep Invariant
 *
 * a->buf_bottom <= a->low & a->high <= a->buf_top &
 * a->buf_bottom < a->buf_top & a->low - 1 <= a->high
 *
 */

/* Macros for inline expansion */

/* Bodies of Macro for inline expansion */

#define OMarray_Dlow(x)		((int)(((array)(x))->low-((array)(x))->zero))
#define OMarray_Dsize(x)	((int)(((array)(x))->high-((array)(x))->low+1))
#define OMarray_Dhigh(x)	((int) (((array)(x))->high-((array)(x))->zero))
#define OMarray_Dempty(x)	((bool) (((array)(x))->high<((array)(x))->low))
#define OMarray_Dequal(x,y)	((bool) ((x) == (y)))
#define OMarray_Dset__low(x,l)	(((array)(x))->zero=(object*)(((array)(x))->low-(l)))

#define OMarray_Dfetch(x,i)	((object) (((array) (x))->zero[(i)]))
#define OMarray_Dstore(x,i,e)	(((array) (x))->zero[(i)] = (object) (e))
#define OMarray_Dremh(x)	((object) (*(((array) (x))->high)--))
#define OMarray_Dreml(x)	((object) (*(((array) (x))->low)++))
#define OMarray_Dbottom(x)	((object) (*(((array) (x))->low)))
#define OMarray_Dtop(x)		((object) (*(((array) (x))->high)))

#define OMarray_Daddh(x,e)				\
    ((((array) (x))->high < ((array) (x))->buf_top)	\
     ? (*++((array) (x))->high = (object) (e))		\
     : (OFarray_Daddh(x, e)))
#define OMarray_Daddl(x,e)				\
    ((((array) (x))->buf_bottom < ((array) (x))->low)	\
     ? (*--((array) (x))->low = (object) (e))		\
     : (OFarray_Daddl(x, e)))

/* Flags Which catch the signal raised by Macro for inline expansion */

#define OMarray_Dbounds(x,i)	(((i) < OMarray_Dlow(x))||(OMarray_Dhigh(x) < (i)))

/*
 * Operation declarations
 */

extern array OFarray_D__alloc();
