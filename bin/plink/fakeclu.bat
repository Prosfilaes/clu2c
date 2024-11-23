echo off
rem fakeclu.bat.  Generated automatically by make.
echo preparing appgen.c
if not exist appgen.c copy pretrans\appgen.c appgen.c >nul
echo preparing appinst.c
if not exist appinst.c copy pretrans\appinst.c appinst.c >nul
echo preparing argument.c
if not exist argument.c copy pretrans\argument.c argument.c >nul
echo preparing assoc.c
if not exist assoc.c copy pretrans\assoc.c assoc.c >nul
echo preparing clugen.c
if not exist clugen.c copy pretrans\clugen.c clugen.c >nul
echo preparing cluinst.c
if not exist cluinst.c copy pretrans\cluinst.c cluinst.c >nul
echo preparing debug.c
if not exist debug.c copy pretrans\debug.c debug.c >nul
echo preparing error.c
if not exist error.c copy pretrans\error.c error.c >nul
echo preparing formal.c
if not exist formal.c copy pretrans\formal.c formal.c >nul
echo preparing gentab.c
if not exist gentab.c copy pretrans\gentab.c gentab.c >nul
echo preparing main.c
if not exist main.c copy pretrans\main.c main.c >nul
echo preparing name.c
if not exist name.c copy pretrans\name.c name.c >nul
echo preparing nameconv.c
if not exist nameconv.c copy pretrans\nameconv.c nameconv.c >nul
echo preparing parse.c
if not exist parse.c copy pretrans\parse.c parse.c >nul
echo preparing read.c
if not exist read.c copy pretrans\read.c read.c >nul
echo preparing replace.c
if not exist replace.c copy pretrans\replace.c replace.c >nul
echo preparing selgen.c
if not exist selgen.c copy pretrans\selgen.c selgen.c >nul
echo preparing selinst.c
if not exist selinst.c copy pretrans\selinst.c selinst.c >nul
echo preparing unparse.c
if not exist unparse.c copy pretrans\unparse.c unparse.c >nul
