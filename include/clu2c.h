/*
 * clu2c.h
 *
 * Copyright (c) 1996
 * 	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: clu2c.h,v 1.1 1996/10/07 02:34:01 ushijima Exp $
 */

#ifndef CLU2C_H
#define CLU2C_H

#include <gc.h>
#include <stdio.h>

/* Return values of C functions that corresponds to CLU routines.  */
/* XXX: Taking compatibility with `SIG' and `RET' into account, `YLD'
   may be more appropriate than `YIELD'.  -- TU */
#define SIG 0			/* a routine terminated exceptionally */
#define RET 1			/* a routine terminated normally */
#define YIELD 2			/* an iterator yielded an item */

/* Place holder for labeled statements.  The compiler generates code
   of the form `label: NO_OPERATION;' when it puts a label.  */
/* XXX: Why not use just a null statement?  -- TU */
#define NO_OPERATION (0)

/* Impose the use of GC versions of memory management functions.  */
/* XXX: Sometimes standard memory management functions need to be
   used, especially in writing interface to other system in C.  I
   think GC versions of these function should be explicitly named as
   `GC_*' in source code.  -- TU */
#define free GC_free
#define malloc GC_malloc
#define malloc_atomic GC_malloc_atomic
#define realloc GC_realloc

/* Indicate that the object to be encoded/decoded is NOT YET seen in
   the istream so far.  */
/* XXX: Probably it is not a right place to define this.  -- TU */
#define NOT_YET 0

/* Some specific CLU return/signal/yield statements.  */
/* XXX: The code generated by the compiler never uses these macros.  I
   think these definitions should be moved to a separate header file.
   -- TU */
#define RETURN0\
	return RET
#define RETURN1(res1)\
	retval_area[0] = (object) (res1);\
	return RET
#define RETURN2(res1,res2)\
	retval_area[0] = (object) (res1);\
	retval_area[1] = (object) (res2);\
	return RET
#define RETURN3(res1,res2,res3)\
	retval_area[0] = (object) (res1);\
	retval_area[1] = (object) (res2);\
	retval_area[2] = (object) (res3);\
	return RET
#define SIGNAL0(except)\
	signame = (except);\
	return SIG
#define SIGNAL1(except,res1)\
	signame = (except);\
	sigarg_area[0] = (object) (res1);\
	return SIG
#define SIGNAL2(except,res1,res2)\
	signame = (except);\
	sigarg_area[0] = (object) (res1);\
	sigarg_area[1] = (object) (res2);\
	return SIG
#define SIGNAL3(except,res1,res2,res3)\
	signame = (except);\
	sigarg_area[0] = (object) (res1);\
	sigarg_area[1] = (object) (res2);\
	sigarg_area[2] = (object) (res3);\
	return SIG
#define YIELD1(res1)\
	retval_area[0] = (object) (res1);\
	return YIELD

/* Generic CLU object descriptor.  */
typedef int object;
typedef object elt;		/* XXX: OBSOLETE */

/* Built-in types and type generators. */
#include <clu2c/bool.h>
#include <clu2c/null.h>
#include <clu2c/int.h>
#include <clu2c/real.h>
#include <clu2c/char.h>
#include <clu2c/string.h>
#include <clu2c/array.h>
#include <clu2c/sequence.h>
#include <clu2c/record.h>
#include <clu2c/struct.h>
#include <clu2c/oneof.h>
#include <clu2c/variant.h>
#include <clu2c/proctype.h>
#include <clu2c/itertype.h>
#include <clu2c/any.h>

/* Support for parameterized modules.  */
typedef proctype oplist_t[];	/* operation list */
typedef struct {
    proctype *oplist;		/* parameter-specific routines */
    int local_own_id;		/* ID of routine own variables */
    int clus_own_id;		/* ID of cluster own variables */
    object *vparms;		/* value parameters */
} param_info;

/* Global variables.  */
extern object retval_area[];
extern string signame;
extern object sigarg_area[];
extern string ivk_name;			/* for debugger */
extern int ivk_line;			/* for debugger */


#endif /* not CLU2C_H */
