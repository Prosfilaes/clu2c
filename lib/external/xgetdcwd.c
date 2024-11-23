/*
 * xgetdcwd.c - interface to getdcwd
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xgetdcwd.c,v 2.4 1997/02/05 09:56:12 ushijima Exp $
 */

#if defined(GO32) || defined(X68000)


#include <config/param.h>

#include <clu2c.h>


/*
 * getcurdir - get current directory of the specified drive
 *
 * Requires:
 *	DRIVE is non-negative and less than or equal to 26.
 *	The array pointed to by DIRECTORY can contain at least MAXDIR
 *	characters (MAXDIR is defined in the <getcdir.h> header).
 *
 * Modifies:
 *	The array pointed to by DIRECTORY.
 *
 * Effects:
 *   	Modifies the array pointed to by DIRECTORY so that it contains
 *	a string that represents the current directory, without drive
 *	specification and leading backslash, of the drive specified by
 *	DRIVE.  0 specifies the current drive; 1 specifies the A
 *	drive; 2 specifies the B drive, and so on.  Returns 0 on
 *	success; otherwise returns -1.
 */

#ifdef GO32

#include <dos.h>

static int getcurdir(drive, directory)
int drive;
char *directory;
{
    union REGS arg, res;
    char *p;

    /*
     * Makes a DOS system call 0x47.  It seems that an erroneous
     * condition cannot be detected on GO32...
     */
    arg.h.ah = 0x47;
    arg.h.dl = (unsigned char) drive;
    arg.x.si = (unsigned long) directory;
    intdos(&arg, &res);

    /*
     * Normalization.
     */
    for (p = directory; *p != '\0'; p++) {
	if (*p == '/') {
	    *p = '\\';
	} else if ('A' <= *p && *p <= 'Z') {
	    *p = *p - 'A' + 'a';
	}
    }

    /*
     * Terminates successfully.
     */
    return 0;
}

#endif /* GO32 */

#ifdef X68000

#include <doslib.h>

static int getcurdir(drive, directory)
int drive;
char *directory;
{

    if (CURDIR(drive, directory) < 0) {
	return -1;
    }

    for (p = directory; *p != '\0'; p++) {
	if (*p == '/') {
	    *p = '\\';
	} else if ('A' <= *p && *p <= 'Z') {
	    *p = *p - 'A' + 'a';
	}
    }

    return 0;
}

#endif /* X68000 */


/*
 * getdrive - get number of current drive
 *
 * Effects:
 *   	Returns an integer that represents the current drive.  The A
 *	drive is represented by 1, B by 2, C by 3, and so on.
 */

#ifdef GO32

#include <dos.h>

static int getdrive()
{
    union REGS arg;		/* argument to DOS system call */
    union REGS res;		/* result of DOS system call */

    /*
     * Makes a DOS system call 0x19.  Note that the result of the call
     * (stored in the AL register) is 0-origin, e.g., the A drive is
     * represented by 0.
     */
    arg.h.ah = 0x19;
    intdos(&arg, &res);
 
    /*
     * Returns 1-origin number.
     */
    return res.h.al + 1;
}

#endif /* GO32 */

#ifdef X68000

#include <doslib.h>

static int getdrive()
{
    return CURDRV() + 1;
}

#endif /* X68000 */



/*
 * getdcwd - get current working directory of specified drive
 *
 * Requires:
 *   	The array pointed to by BUF can contain at least SIZE
 *	characters (including terminating null character), unless BUF
 *	is a null pointer.
 *	SIZE must be at least one greater than the length of the
 *	path name to be returned.
 *
 * Modifies:
 *   	The array pointed to by BUF (unless BUF is a null pointer).
 *
 * Effects:
 *	Returns NULL if any error is encountered; otherwise returns a
 *	pointer to the string that represents the current working
 *	directory, including the drive specification and the leading
 *	backslash.  If BUF is a null pointer, a new storage is
 *	allocated dynamically; otherwise the array pointed to by BUF
 *	is used to store the path name.
 */

static char *getdcwd(drive, buf, size)
int drive;
char *buf;
int size;
{
    char *res;			/* result */

    if (drive < 0 || drive > 26) {
	return 0;
    }
    if (buf) {
	res = buf;
    } else {
	res = (char *) malloc(size);
	if (!res) {
	    return 0;
	}
    }
    strcpy(res, "a:\\");
    getcurdir(drive, res + 3);
    if (drive == 0) {
	drive = getdrive();
    }
    res[0] = 'a' + drive - 1;
    return res;
}


/*
 * _external_getdcwd = proc(drive: int) returns(string)
 *                     signals(not_possible(string))
 */

int AF__external__getdcwd(drive)
int drive;
{
    static char prev[MAXPATHLEN] = "";
    static string res;

    char buf[MAXPATHLEN];

    if (!getdcwd(drive, buf, MAXPATHLEN)) {
	syserror();
	return SIG;
    }
    if (strcmp(buf, prev) != 0) {
	strcpy(prev, buf);
	res = OFstring_D__cs2s(OFstring_D__copy(prev));
    }
    RETURN1(res);
}


#endif /* GO32 or X68000 */
