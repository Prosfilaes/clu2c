/*
 * xdir.c - implementation of _external_dir
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xdir.c,v 2.5 1997/02/05 09:56:08 ushijima Exp $
 */

#include <clu2c.h>

#include <config/dirent.h>


/*
 * _external_dir = cluster is open, read, close
 */


/*
 * open = proc(dir: string) returns(_external_dir) signals(not_possible(string))
 */

int OF__external__dir_Dopen(dir)
string dir;
{
    DIR *dst;

    dst = opendir(OFstring_D__s2cs(dir));
    if (!dst) {
	syserror();
	return SIG;
    }
    RETURN1(dst);
}


/*
 * read = proc(dst: _external_dir) returns(string) signals(end_of_file)
 */

int OF__external__dir_Dread(dst)
DIR *dst;
{
    struct dirent *ent;

    ent = readdir(dst);
    if (!ent) {
	SIGNAL0(SLEND_OF_FILE);
    }
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(ent->d_name)));
}


/*
 * close = proc(dst: _external_dir)
 */

int OF__external__dir_Dclose(dst)
DIR *dst;
{
    closedir(dst);
    RETURN0;
}
