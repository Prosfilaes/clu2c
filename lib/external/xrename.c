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
     * $B!ZCm0U!*!]!](BMS-DOS $B$G$O!"(Bto $B$G;XDj$5$l$k%U%!%$%k$,4{$KB8:_$9$k(B
     * $B>l9g$K$O!"$^$:$=$l$r>C5n$7$J$1$l$P$J$i$J$$$i$7$$!#$3$N%3!<%I$O(B
     * $B$^$@$=$N=hM}$r9T$J$C$F$$$J$$!#![(B
     */

    if (rename(OFstring_D__s2cs(from), OFstring_D__s2cs(to)) < 0) {
	syserror();
	return SIG;
    }
    RETURN0;
}
