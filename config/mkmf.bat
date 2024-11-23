echo off

rem mkmf.bat.  Generated automatically by mkmkmfbat.

if not x%1==x goto else
set systype=dos
goto endif
:else
set systype=%1
:endif

command /c config\mkmf1 %systype% . .
command /c config\mkmf1 %systype% bin ..
command /c config\mkmf1 %systype% bin\clu2c ..\..
command /c config\mkmf1 %systype% bin\clulink ..\..
command /c config\mkmf1 %systype% bin\plink ..\..
command /c config\mkmf1 %systype% config ..
command /c config\mkmf1 %systype% doc ..
command /c config\mkmf1 %systype% include ..
command /c config\mkmf1 %systype% include\clu2c ..\..
command /c config\mkmf1 %systype% include\config ..\..
command /c config\mkmf1 %systype% lib ..
command /c config\mkmf1 %systype% lib\built-in ..\..
command /c config\mkmf1 %systype% lib\clu2c ..\..
command /c config\mkmf1 %systype% lib\external ..\..
command /c config\mkmf1 %systype% lib\gc ..\..
command /c config\mkmf1 %systype% lib\jaio ..\..
command /c config\mkmf1 %systype% lib\stdio ..\..
command /c config\mkmf1 %systype% mk ..

set systype=
