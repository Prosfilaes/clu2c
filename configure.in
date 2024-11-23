dnl configure.in - input file for autoconf
dnl
dnl Copyright (c) 1996
dnl	Department of Mathematical and Computing Sciences,
dnl	Tokyo Institute of Technology.  All rights reserved.
dnl
dnl $Id: configure.in,v 2.0 1996/06/10 08:58:01 ushijima Exp $
dnl
AC_REVISION($Revision: 2.0 $)
AC_INIT(configure)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADER(config.h:configh.in)
# Initialize variables specific to this package
SHELL='/bin/sh'
bindir='$(exec_prefix)/bin'
libdir='$(exec_prefix)/lib'
infodir='$(prefix)/info'
clu2c_rootdir='$(libdir)/clu2c'
clu2c_bindir='$(clu2c_rootdir)/bin'
clu2c_libdir='$(clu2c_rootdir)/lib'
clu2c_includedir='$(clu2c_rootdir)/include'
CLU2C=${CLU2C-'$(FAKE_CLU2C)'}
CLU2CFLAGS=${CLU2CFLAGS-'--optimize'}
PLINK=${PLINK-'$(clu2c_bindir)/plink'}
PLINKFLAGS=${PLINKFLAGS-''}
PLINK_METHOD=${PLINK_METHOD-'$(FAKE_PLINK)'}
LIBDIR=${LIBDIR-'$(topdir)/lib'}
AS=${AS-'as'}
AR=${AR-'ar'}
ARFLAGS=${ARFLAGS-'ru'}
INSTALLFLAGS=${INSTALLFLAGS-''}
COFF2EXE=${COFF2EXE-':'}
COMMAND=${COMMAND-'command'}
COMMANDFLAGS=${COMMANDFLAGS-''}
M4=${M4-'m4'}
M4FLAGS=${M4FLAGS-''}
GC_VERSION=${GC_VERSION-'4.4'}
FS_TYPE=${FS_TYPE-'unix'}
distname=${distname-'clu2c-$(VERSION)'}
dos_distname=${dos_distname-'clu$(ABRIDGED_VERSION)s'}
AC_SUBST(SHELL)
AC_SUBST(bindir)
AC_SUBST(libdir)
AC_SUBST(infodir)
AC_SUBST(clu2c_rootdir)
AC_SUBST(clu2c_bindir)
AC_SUBST(clu2c_libdir)
AC_SUBST(clu2c_includedir)
AC_SUBST(CLU2C)
AC_SUBST(CLU2CFLAGS)
AC_SUBST(PLINK)
AC_SUBST(PLINKFLAGS)
AC_SUBST(PLINK_METHOD)
AC_SUBST(LIBDIR)
AC_SUBST(AS)
AC_SUBST(AR)
AC_SUBST(ARFLAGS)
AC_SUBST(INSTALLFLAGS)
AC_SUBST(COFF2EXE)
AC_SUBST(COMMAND)
AC_SUBST(COMMANDFLAGS)
AC_SUBST(M4)
AC_SUBST(M4FLAGS)
AC_SUBST(GC_VERSION)
AC_SUBST(FS_TYPE)
AC_SUBST(distname)
AC_SUBST(dos_distname)
AC_ARG_ENABLE(dynamic-loading,
 [  --enable-dynamic-loading
                          allow the garbage collector to scan data segments
                          associated with dynamic libraries [yes]],
 [test "$enableval" = no && AC_DEFINE(DISABLE_DYNAMIC_LOADING)])
AC_ARG_WITH(bsd-byte-operations,
 [  --with-bsd-byte-operations
                          use BSD byte operations such as bcopy and bcmp,
                          even if standard memory operations such as memcpy
                          and memcmp are available [no]],
 [AC_DEFINE(WITH_BSD_BYTE_OPERATIONS)])
AC_ARG_WITH(clu2c,
 [  --with-clu2c            use installed clu2c to compile CLU sources [no]],
 [CLU2C=clu2c
  PLINK_METHOD='$(REAL_PLINK)'
  LIBDIR='$(clu2c_libdir)'])
AC_ARG_WITH(getwd,
 [  --with-getwd            use getwd to get current working directory even if
                          getcwd is available [no]],
 [AC_DEFINE(WITH_GETWD)])
AC_ARG_WITH(gnu-as,
 [  --with-gnu-as           use GNU assembler [no]],
 [AC_DEFINE(WITH_GNU_AS)])
AC_ARG_WITH(input-code,
 [  --with-input-code=CODING-SYSTEM
                          specify default coding system for input [autoconv]],
 [case "$withval" in
  noconv|no)	AC_DEFINE(DEFAULT_INPUT_CODING_SYSTEM, CSYS_NOCONV);;
  euc-japan)	AC_DEFINE(DEFAULT_INPUT_CODING_SYSTEM, CSYS_EUCJP);;
  sjis)		AC_DEFINE(DEFAULT_INPUT_CODING_SYSTEM, CSYS_SJIS);;
  iso-2022-jp)	AC_DEFINE(DEFAULT_INPUT_CODING_SYSTEM, CSYS_ISO2022JP);;
  autoconv|yes)	AC_DEFINE(DEFAULT_INPUT_CODING_SYSTEM, CSYS_AUTOCONV);;
  *)		AC_MSG_ERROR(--with-input-code: $withval: invalid argument);;
  esac],
 [AC_DEFINE(DEFAULT_INPUT_CODING_SYSTEM, CSYS_AUTOCONV)])
AC_ARG_WITH(output-code,
 [  --with-output-code=CODING-SYSTEM
                          specify default coding system for output
                          [iso-2022-jp]],
 [case "$withval" in
  noconv|no)		AC_DEFINE(DEFAULT_OUTPUT_CODING_SYSTEM, CSYS_NOCONV);;
  euc-japan)		AC_DEFINE(DEFAULT_OUTPUT_CODING_SYSTEM, CSYS_EUCJP);;
  sjis)			AC_DEFINE(DEFAULT_OUTPUT_CODING_SYSTEM, CSYS_SJIS);;
  iso-2022-jp|yes)	AC_DEFINE(DEFAULT_OUTPUT_CODING_SYSTEM, CSYS_ISO2022JP);;
  *)			AC_MSG_ERROR(--with-output-code: $withval: invalid argument);;
  esac],
 [AC_DEFINE(DEFAULT_OUTPUT_CODING_SYSTEM, CSYS_ISO2022JP)])
AC_ARG_WITH(_help_,
[Coding systems recognized:
  noconv                  no conversion
  euc-japan               Japanese EUC
  sjis                    Shift JIS
  iso-2022-jp             ISO-2022-JP (see RFC 1468)
  autoconv                automatic conversion (input only)])
AC_PROG_MAKE_SET
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
case "$ac_cv_path_install" in
/*)  ;;
*)   ac_cv_path_install='$(topdir)/'"$ac_cv_path_install"
     INSTALL="$ac_cv_path_install"
     ;;
esac
AC_PROG_LN_S
AC_PROG_RANLIB
AC_CHECK_LIB(sun, getpwnam)
AC_CHECK_LIB(m, main)
AC_HEADER_STDC
AC_HEADER_DIRENT
AC_HEADER_TIME
AC_CHECK_HEADERS(errno.h error.h float.h pwd.h signal.h stat.h stdarg.h unistd.h values.h)
AC_CHECK_HEADERS(sys/param.h sys/stat.h sys/time.h sys/types.h)
AC_TYPE_SIGNAL
AC_TYPE_SIZE_T
AC_CHECK_TYPE(time_t, long)
AC_MSG_CHECKING(whether time.h defines clock_t)
AC_CACHE_VAL(ac_cv_type_clock_t,
[AC_EGREP_HEADER(clock_t, time.h, ac_cv_type_clock_t=yes, ac_cv_type_clock_t=no)])
AC_MSG_RESULT($ac_cv_type_clock_t)
if test $ac_cv_type_clock_t = no; then
  AC_DEFINE(clock_t, long)
fi
AC_CHECK_FUNCS(atexit clock getcwd memcpy on_exit setvbuf sighold strchr strerror)
AC_C_LONG_DOUBLE
if false; then
  AC_DEFINE(MSDOS_TEXT)
  AC_DEFINE(DJGPP_EMU387_BROKEN)
fi
AC_OUTPUT(config.mk:config/configmk.in fakeclu.sh:config/fakeclush.in,
[sh $srcdir/config/mkmf.sh $srcdir])
