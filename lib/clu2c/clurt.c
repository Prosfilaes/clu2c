/* 
 * clurt.c - CLU runtime support
 *
 * Copyright (c) 1992, 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: clurt.c,v 2.17 1997/02/05 09:55:50 ushijima Exp $
 */

#include <config/errno.h>
#include <config/string.h>

#include <clu2c.h>


#define MAX_RETVALS 20
#define MAX_SIGARGS 20


/**
 ** Global variables.
 **/


/*
 * Return values of routines in the normal condition.
 */

object retval_area[MAX_RETVALS];


/*
 * Exception name and return values of routines in the exceptional
 * condition.
 */

string signame;
object sigarg_area[MAX_SIGARGS];


/*
 * Argument vector.
 */

int gargc;
char **gargv;


/*
 * The name of the routine and the line number where the invocation
 * occurs.  These variables are used to locate the occurrence of an
 * exception, for debugger.
 */

string ivk_name = SLNULL;	/* for debugger */
int ivk_line = 0;		/* for debugger */


/**
 ** Run-time support routines.
 **/


/*
 * Top level driver.
 */

main(argc, argv)
int argc;
char *argv[];
{
    int status = 0;		/* exit status */
    object eo;			/* error output */

    /*
     * Saves argument vector in global variables.
     */
    gargc = argc;
    gargv = argv;

    /*
     * Initializes garbage collector.
     */
    GC_init();

    /*
     * Invokes start up routine.
     */
    if (AFstart__up() == SIG) {
	OFstream_Derror__output();
	eo = retval_area[0];
	if (OMbool_Dnot(OMstring_Dequal(signame, SLFAILURE))) {
	    OFstream_Dputs(eo, OFstring_D__cs2s("unhandled exception: "));
	    OFstream_Dputl(eo, signame);
	} else if (OMbool_Dnot(OMstring_Dempty(sigarg_area[0]))) {
	    OFstream_Dputl(eo, sigarg_area[0]);
	}
	status = 1;
    }

    /*
     * Cleans up streams and exits.
     */
    OFstream_D__close__all();
    exit(status);
}


/*
 * Does the job at the outermost exception handler in each routine.
 */

out_handler(routine)
string routine;
{
    if ( ! OMstring_Dequal(signame, SLFAILURE) ) {
	/* when signame is not "failure" */
	OFstring_Dconcat(OFstring_D__cs2s("unhandled exception: "), signame);
	if (!OMstring_Dempty(routine)) {
	    OFstring_Dconcat(retval_area[0], OFstring_D__cs2s(" in "));
	    OFstring_Dconcat(retval_area[0], routine);
	}
	sigarg_area[0] = retval_area[0];
	signame = SLFAILURE;
    }
}


/*
 * Sets the exception as `failure("no return value in ...")' for the
 * time when the control reaches to the end of the routine that has
 * some results.
 */

noretval(routine)
string routine;
{
    signame = SLFAILURE;
    retval_area[0] = OFstring_D__cs2s("no return values");
    if (!OMstring_Dempty(routine)) {
	OFstring_Dconcat(retval_area[0], OFstring_D__cs2s(" in "));
	OFstring_Dconcat(retval_area[0], routine);
    }
    sigarg_area[0] = retval_area[0];
}


/*
 * Does no operation.  Invocations of this function is inserted into
 * generated code for the debugger to set breakpoints.
 */

nop()
{
    /* no operation for debugger */
}

catch_failure(name, line)
    string name;
    int line;
{
    /* no operation */
}

catch_signal(name, line)
    string name;
    int line;
{
    /* no operation */
}

/*-
 * syserror - set up system error as an exception
 */

syserror()
{
    signame = SLNOT_POSSIBLE;
    sigarg_area[0] = (object) OFstring_D__cs2s(strerror(errno));
}
