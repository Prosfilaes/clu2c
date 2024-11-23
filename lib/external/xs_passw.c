/*
 * xs_passw.c - interface to struct passwd
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xs_passw.c,v 2.4 1997/02/05 09:56:18 ushijima Exp $
 */

#include <config/pwd.h>
#include <config/string.h>

#include <clu2c.h>


/*
 * _external_struct_passwd = cluster is 
 * 	get_name, get_passwd, get_uid, get_gid, get_gecos, get_dir,
 *	get_shell, equal, similar, copy
 */


/*
 * get_name = proc(pw: _external_struct_passwd) returns(string)
 */

int OF__external__struct__passwd_Dget__name(pw)
struct passwd *pw;
{
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(pw->pw_name)));
}


/*
 * get_passwd = proc(pw: _external_struct_passwd) returns(string)
 */

int OF__external__struct__passwd_Dget__passwd(pw)
struct passwd *pw;
{
#ifdef HAVE_PW_PASSWD
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(pw->pw_passwd)));
#else
    RETURN1(SLNULL);
#endif
}


/*
 * get_uid = proc(pw: _external_struct_passwd) returns(int)
 */

int OF__external__struct__passwd_Dget__uid(pw)
struct passwd *pw;
{
    RETURN1(pw->pw_uid);
}


/*
 * get_gid = proc(pw: _external_struct_passwd) returns(int)
 */

int OF__external__struct__passwd_Dget__gid(pw)
struct passwd *pw;
{
    RETURN1(pw->pw_gid);
}


/*
 * get_gecos = proc(pw: _external_struct_passwd) returns(string)
 */

int OF__external__struct__passwd_Dget__gecos(pw)
struct passwd *pw;
{
#ifdef HAVE_PW_GECOS
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(pw->pw_gecos)));
#else
    RETURN1(SLNULL);
#endif
}


/*
 * get_dir = proc(pw: _external_struct_passwd) returns(string)
 */

int OF__external__struct__passwd_Dget__dir(pw)
struct passwd *pw;
{
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(pw->pw_dir)));
}


/*
 * get_shell = proc(pw: _external_struct_passwd) returns(string)
 */

int OF__external__struct__passwd_Dget__shell(pw)
struct passwd *pw;
{
    RETURN1(OFstring_D__cs2s(OFstring_D__copy(pw->pw_shell)));
}


/*
 * equal = proc(pw1, pw2: _external_struct_passwd) returns(string)
 */

int OF__external__struct__passwd_Dequal(pw1, pw2)
struct passwd *pw1;
struct passwd *pw2;
{
    RETURN1(MEMEQ((char *) pw1, (char *) pw2, sizeof(struct passwd)));
}


/*
 * similar = proc(pw1, pw2: _external_struct_passwd) returns(string)
 */

int OF__external__struct__passwd_Dsimilar(pw1, pw2)
struct passwd *pw1;
struct passwd *pw2;
{
    RETURN1(MEMEQ((char *) pw1, (char *) pw2, sizeof(struct passwd)));
}


/*
 * copy = proc(pw: _external_struct_passwd) returns(_external_struct_passwd)
 */

int OF__external__struct__passwd_Dcopy(pw)
struct passwd *pw;
{
    struct passwd *res;		/* result */

    res = (struct passwd *) malloc(sizeof(struct passwd));
    memcpy((char *) res, (char *) pw, sizeof(struct passwd));
    RETURN1(res);
}
