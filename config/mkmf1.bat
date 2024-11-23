echo off

rem mkmf1.bat - create make file
rem
rem Copyright (c) 1996
rem	Department of Mathematical and Computing Sciences,
rem	Tokyo Institute of Technology.  All rights reserved.
rem
rem $Id: mkmf1.bat,v 2.0 1996/06/10 09:06:18 ushijima Exp $


echo creating %2\Makefile
echo # Makefile.  generated automatically by configure.>%2\Makefile.top
echo\>>%2\Makefile.top
echo # search path for source code>>%2\Makefile.top
echo VPATH = .>>%2\Makefile.top
echo\>>%2\Makefile.top
echo # source code directory for this makefile>>%2\Makefile.top
echo srcdir = .>>%2\Makefile.top
echo\>>%2\Makefile.top
echo # top-level source code directory for this package>>%2\Makefile.top
echo top_srcdir = $(topdir)>>%2\Makefile.top
echo\>>%2\Makefile.top
echo # configuration makefile>>%2\Makefile.top
echo config_mk = %3\config.mk>>%2\Makefile.top

copy %2\Makefile.top+config.mk+%2\Makefile.%1 %2\Makefile>nul
