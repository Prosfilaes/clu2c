echo off

rem remove.bat
rem
rem Copyright (c) 1996
rem	Department of Mathematical and Computing Sciences,
rem	Tokyo Institute of Technology.  All rights reserved.
rem
rem $Id: remove.bat,v 2.0 1996/06/10 09:06:20 ushijima Exp $


rem usage: remove FILE-1 ... FILE-N

:loop
if x%1==x goto end
if exist %1 del %1
shift
goto loop
:end
