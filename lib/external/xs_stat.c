/*
 * xs_stat.c - interface to struct stat
 *
 * Copyright (c) 1996, 1997
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: xs_stat.c,v 2.4 1997/02/05 09:56:19 ushijima Exp $
 */

#include <config/stat.h>
#include <config/string.h>

#include <clu2c.h>


/*
 * _external_struct_stat = cluster is
 *	get_dev, get_ino, get_mode, get_nlink, get_uid, get_gid,
 *	get_rdev, get_size, get_atime, get_mtime, get_ctime,
 *	is_block_device, is_character_device, is_directory, is_fifo,
 *	is_regular, is_symbolic_link, equal, similar, copy
 */



/*
 * get_dev = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__dev(s)
struct stat *s;
{
    RETURN1(s->st_dev);
}


/*
 * get_ino = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__ino(s)
struct stat *s;
{
    RETURN1(s->st_ino);
}


/*
 * get_mode = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__mode(s)
struct stat *s;
{
    RETURN1(s->st_mode);
}


/*
 * get_nlink = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__nlink(s)
struct stat *s;
{
    RETURN1(s->st_nlink);
}


/*
 * get_uid = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__uid(s)
struct stat *s;
{
    RETURN1(s->st_uid);
}


/*
 * get_gid = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__gid(s)
struct stat *s;
{
    RETURN1(s->st_gid);
}


/*
 * get_rdev = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__rdev(s)
struct stat *s;
{
    RETURN1(s->st_rdev);
}


/*
 * get_size = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__size(s)
struct stat *s;
{
    RETURN1(s->st_size);
}


/*
 * get_atime = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__atime(s)
struct stat *s;
{
    RETURN1(s->st_atime);
}


/*
 * get_mtime = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__mtime(s)
struct stat *s;
{
    RETURN1(s->st_mtime);
}


/*
 * get_ctime = proc(s: _external_struct_stat) returns(int)
 */

int OF__external__struct__stat_Dget__ctime(s)
struct stat *s;
{
    RETURN1(s->st_ctime);
}


/*
 * is_block_device = proc(s: _external_struct_stat) returns(bool)
 */

int OF__external__struct__stat_Dis__block__device(s)
struct stat *s;
{
    RETURN1((s->st_mode & S_IFMT) == S_IFBLK);
}


/*
 * is_character_device = proc(s: _external_struct_stat) returns(bool)
 */

int OF__external__struct__stat_Dis__character__device(s)
struct stat *s;
{
    RETURN1((s->st_mode & S_IFMT) == S_IFCHR);
}


/*
 * is_directory = proc(s: _external_struct_stat) returns(bool)
 */

int OF__external__struct__stat_Dis__directory(s)
struct stat *s;
{
    RETURN1((s->st_mode & S_IFMT) == S_IFDIR);
}


/*
 * is_fifo = proc(s: _external_struct_stat) returns(bool)
 */

int OF__external__struct__stat_Dis__fifo(s)
struct stat *s;
{
    RETURN1((s->st_mode & S_IFMT) == S_IFIFO);
}


/*
 * is_regular = proc(s: _external_struct_stat) returns(bool)
 */

int OF__external__struct__stat_Dis__regular(s)
struct stat *s;
{
    RETURN1((s->st_mode & S_IFMT) == S_IFREG);
}


/*
 * is_symbolic_link = proc(s: _external_struct_stat) returns(bool)
 */

int OF__external__struct__stat_Dis__symbolic__link(s)
struct stat *s;
{
    RETURN1((s->st_mode & S_IFMT) == S_IFLNK);
}


/*
 * equal = proc(s1, s2: _external_struct_stat) returns(bool)
 */

int OF__external__struct__stat_Dequal(s1, s2)
struct stat *s1;
struct stat *s2;
{
    RETURN1(MEMEQ((char *) s1, (char *) s2, sizeof(struct stat)));
}


/*
 * similar = proc(s1, s2: _external_struct_stat) returns(bool)
 */

int OF__external__struct__stat_Dsimilar(s1, s2)
struct stat *s1;
struct stat *s2;
{
    RETURN1(MEMEQ((char *) s1, (char *) s2, sizeof(struct stat)));
}


/*
 * copy = proc(s: _external_struct_stat) returns(_external_struct_stat)
 */

int OF__external__struct__stat_Dcopy(s)
struct stat *s;
{
    struct stat *res;		/* result */

    res = (struct stat *) malloc(sizeof(struct stat));
    memcpy((char *) res, (char *) s, sizeof(struct stat));
    RETURN1(res);
}
