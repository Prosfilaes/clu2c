/*
 * xerrname.c - interface to error name
 *
 * Copyright (c) 1996
 * 	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xerrname.c,v 2.1 1996/10/07 05:16:45 ushijima Exp $
 */

#include <config/errno.h>
#include <clu2c.h>


struct error {
    int no;			/* error number */
    char *name;			/* error name */
};

static struct error errlist[] = {
    /* POSIX error names */
#ifdef E2BIG
    {E2BIG, "E2BIG"},
#endif
#ifdef EACCES
    {EACCES, "EACCES"},
#endif
#ifdef EAGAIN
    {EAGAIN, "EAGAIN"},
#endif
#ifdef EBADF
    {EBADF, "EBADF"},
#endif
#ifdef EBUSY
    {EBUSY, "EBUSY"},
#endif
#ifdef ECHILD
    {ECHILD, "ECHILD"},
#endif
#ifdef EDEADLK
    {EDEADLK, "EDEADLK"},
#endif
#ifdef EDOM
    {EDOM, "EDOM"},
#endif
#ifdef EEXIST
    {EEXIST, "EEXIST"},
#endif
#ifdef EFAULT
    {EFAULT, "EFAULT"},
#endif
#ifdef EFBIG
    {EFBIG, "EFBIG"},
#endif
#ifdef EINTR
    {EINTR, "EINTR"},
#endif
#ifdef EINVAL
    {EINVAL, "EINVAL"},
#endif
#ifdef EIO
    {EIO, "EIO"},
#endif
#ifdef EISDIR
    {EISDIR, "EISDIR"},
#endif
#ifdef EMFILE
    {EMFILE, "EMFILE"},
#endif
#ifdef EMLINK
    {EMLINK, "EMLINK"},
#endif
#ifdef ENAMETOOLONG
    {ENAMETOOLONG, "ENAMETOOLONG"},
#endif
#ifdef ENFILE
    {ENFILE, "ENFILE"},
#endif
#ifdef ENODEV
    {ENODEV, "ENODEV"},
#endif
#ifdef ENOENT
    {ENOENT, "ENOENT"},
#endif
#ifdef ENOEXEC
    {ENOEXEC, "ENOEXEC"},
#endif
#ifdef ENOLCK
    {ENOLCK, "ENOLCK"},
#endif
#ifdef ENOMEM
    {ENOMEM, "ENOMEM"},
#endif
#ifdef ENOSPC
    {ENOSPC, "ENOSPC"},
#endif
#ifdef ENOSYS
    {ENOSYS, "ENOSYS"},
#endif
#ifdef ENOTDIR
    {ENOTDIR, "ENOTDIR"},
#endif
#ifdef ENOTEMPTY
    {ENOTEMPTY, "ENOTEMPTY"},
#endif
#ifdef ENOTTY
    {ENOTTY, "ENOTTY"},
#endif
#ifdef ENXIO
    {ENXIO, "ENXIO"},
#endif
#ifdef EPERM
    {EPERM, "EPERM"},
#endif
#ifdef EPIPE
    {EPIPE, "EPIPE"},
#endif
#ifdef ERANGE
    {ERANGE, "ERANGE"},
#endif
#ifdef EROFS
    {EROFS, "EROFS"},
#endif
#ifdef ESPIPE
    {ESPIPE, "ESPIPE"},
#endif
#ifdef ESRCH
    {ESRCH, "ESRCH"},
#endif
#ifdef EXDEV
    {EXDEV, "EXDEV"},
#endif
};

static string errnames[sizeof(errlist)/sizeof(struct error)];


/*
 * _external_errname = proc() returns(string)
 * 	effects  Returns the error name (such as "ENOENT") that
 *		 corresponds to the current error number.
 */

int AF__external__errname()
{
    int i;

    for (i = 0; i < sizeof(errlist) / sizeof(struct error); i++) {
	if (errlist[i].no == errno) {
	    if (!errnames[i]) {
		errnames[i] = OFstring_D__cs2s(errlist[i].name);
	    }
	    RETURN1(errnames[i]);
	}
    }
    RETURN1(SLNULL);
}
