echo off

rem configure.bat
rem
rem Copyright (c) 1996
rem	Department of Mathematical and Computing Sciences,
rem	Tokyo Institute of Technology.  All rights reserved.
rem
rem $Id: configure.bat,v 2.0 1996/06/10 08:58:02 ushijima Exp $


if x%1==x goto djgpp
if %1==djgpp goto djgpp
if %1==djgpp109 goto djgpp109
if %1==x68k goto x68k
echo %1: unknown system type
echo\

:usage

echo Usage: configure [ djgpp / djgpp109 ]
echo Default system type is `djgpp'.
goto end

:djgpp

set configh=configh.dos
set configmk=configmk.dos
set ostype=dos
goto output

:djgpp109

set configh=configh.98
set configmk=configmk.98
set ostype=dos
goto output

:x68k

set configh=configh.x68
set configmk=configmk.x68
set ostype=x68
goto output

:output

echo creating config.h
copy config\%configh% config.h >nul

echo creating config.mk
copy config\%configmk% config.mk >nul

command /c config\mkmf %ostype%

set configh=
set configmk=
set ostype=

:epilogue

echo You should look into `config.mk' and `config.h', which may need
echo manual modification.  When you change `config.mk', you must do
echo `make mkfiles' to update all the makefiles.

:end
