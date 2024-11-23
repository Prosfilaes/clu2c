/*
 * xrename.c - interface to rename
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xrename.c,v 2.4 1997/02/05 09:56:17 ushijima Exp $
 */

#include <stdio.h>

#include <clu2c.h>


/*
 * _external_rename = proc(from, to: string) signals(not_possible(string))
 */

int AF__external__rename(from, to)
string from;
string to;
{
    /*
     * 【注意！−−MS-DOS では、to で指定されるファイルが既に存在する
     * 場合には、まずそれを消去しなければならないらしい。このコードは
     * まだその処理を行なっていない。】
     */

    if (rename(OFstring_D__s2cs(from), OFstring_D__s2cs(to)) < 0) {
	syserror();
	return SIG;
    }
    RETURN0;
}
