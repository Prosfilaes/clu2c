echo off
rem fakeclu.bat.  Generated automatically by make.
echo preparing clulink.c
if not exist clulink.c copy pretrans\clulink.c clulink.c >nul
echo preparing default.c
if not exist default.c copy pretrans\default.c default.c >nul
echo preparing logger.c
if not exist logger.c copy pretrans\logger.c logger.c >nul
echo preparing objects.c
if not exist objects.c copy pretrans\objects.c objects.c >nul
echo preparing output.c
if not exist output.c copy pretrans\output.c output.c >nul
echo preparing primary.c
if not exist primary.c copy pretrans\primary.c primary.c >nul
echo preparing sources.c
if not exist sources.c copy pretrans\sources.c sources.c >nul
echo preparing start_up.c
if not exist start_up.c copy pretrans\start_up.c start_up.c >nul
echo preparing target.c
if not exist target.c copy pretrans\target.c target.c >nul
echo preparing user.c
if not exist user.c copy pretrans\user.c user.c >nul
echo preparing version.c
if not exist version.c copy pretrans\version.c version.c >nul
