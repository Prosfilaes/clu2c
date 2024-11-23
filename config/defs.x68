# defs.x68 - configuration parameters for SHARP X68000
#
# $Id: defs.x68,v 2.0 1996/06/10 09:06:12 ushijima Exp $

# For config.h

HAVE_LONG_DOUBLE		1
RETSIGTYPE			void
size_t				undef
STDC_HEADERS			1
TIME_WITH_SYS_TIME		1
clock_t				undef
time_t				undef
WITH_GNU_AS			1
DEFAULT_INPUT_CODING_SYSTEM	CSYS_SJIS
DEFAULT_OUTPUT_CODING_SYSTEM	CSYS_SJIS
MSDOS_TEXT			1
WITH_BSD_BYTE_OPERATIONS	undef
WITH_GETWD			undef
DJGPP_EMU387_BROKEN		undef
DISABLE_DYNAMIC_LOADING		undef
HAVE_ATEXIT			1
HAVE_CLOCK			1
HAVE_GETCWD			1
HAVE_MEMCPY			1
HAVE_ON_EXIT			1
HAVE_SETVBUF			1
HAVE_SIGHOLD			undef
HAVE_STRCHR			1
HAVE_STRERROR			1
HAVE_DIRENT_H			1
HAVE_ERRNO_H			1
HAVE_ERROR_H			undef
HAVE_FLOAT_H			1
HAVE_NDIR_H			undef
HAVE_PWD_H			undef
HAVE_SIGNAL_H			1
HAVE_STAT_H			undef
HAVE_STDARG_H			1
HAVE_SYS_DIR_H			1
HAVE_SYS_NDIR_H			undef
HAVE_SYS_PARAM_H		1
HAVE_SYS_STAT_H			1
HAVE_SYS_TIME_H			1
HAVE_SYS_TYPES_H		1
HAVE_UNISTD_H			undef
HAVE_VALUES_H			undef
HAVE_LIBM			1
HAVE_LIBSUN			undef

# For config.mk

SHELL				c:\command.com
prefix				c:\usr\local
exec_prefix			$(prefix)
bindir				$(exec_prefix)\bin
libdir				$(exec_prefix)\lib
infodir				$(clu2c_rootdir)\info
clu2c_rootdir			c:\clu2c
clu2c_bindir			$(clu2c_rootdir)\bin
clu2c_libdir			$(clu2c_rootdir)\lib
clu2c_includedir		$(clu2c_rootdir)\include
SET_MAKE			MAKE = make
CLU2C				$(FAKE_CLU2C)
CLU2CFLAGS			--optimize
PLINK				$(clu2c_bindir)\plink
PLINKFLAGS
PLINK_METHOD			$(FAKE_PLINK)
CC				gcc
CFLAGS				-O
AS				as
LIBS				-lm
LDFLAGS
LIBDIR				$(topdir)/lib
AR				ar
ARFLAGS				ru
RANLIB				ranlib
INSTALL				copy
INSTALLFLAGS
INSTALL_PROGRAM			$(INSTALL)
INSTALL_DATA			$(INSTALL)
LN_S				copy
COFF2EXE
COMMAND				command
COMMANDFLAGS
M4				m4
M4FLAGS
FS_TYPE				dos
distname			clu2c-$(VERSION)
dos_distname			clu$(ABRIDGED_VERSION)s
