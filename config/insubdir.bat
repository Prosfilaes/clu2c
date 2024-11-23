echo off

rem insubdir.bat - execute commands in subdirectory 
rem
rem Copyright (c) 1996
rem	Department of Mathematical and Computing Sciences,
rem	Tokyo Institute of Technology.  All rights reserved.
rem
rem $Id: insubdir.bat,v 2.0 1996/06/10 09:06:14 ushijima Exp $

cd %1
shift
%1 %2 %3 %4 %5 %6 %7 %8 %9
cd ..
