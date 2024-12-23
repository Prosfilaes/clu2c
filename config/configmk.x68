

######################################################################
#
# configmk.x68.  Generated from configmk.in
#
# Identification for configmk.in is:
#	$Id: configmk.in,v 2.1 1997/02/06 04:21:15 ushijima Exp $
#

# Avoids SHELL from inherited from the environment
SHELL = c:\command.com

# Common prefix
prefix = c:\usr\local
exec_prefix = $(prefix)

# The directory where executable commands are installed
bindir = $(exec_prefix)\bin

# The directory where libraries are installed
libdir = $(exec_prefix)\lib

# The directory where info files are installed
infodir = $(clu2c_rootdir)\info

# CLU2C system root directory
clu2c_rootdir = c:\clu2c

# The directory where CLU2C executable commands are installed
clu2c_bindir = $(clu2c_rootdir)\bin

# The directory where CLU2C libraries are installed
clu2c_libdir = $(clu2c_rootdir)\lib

# The directory where CLU2C header files are installed
clu2c_includedir = $(clu2c_rootdir)\include

# Support for make (may be null)
MAKE = make

# CLU compiler and related things
CLU2C = $(FAKE_CLU2C)
CLU2CFLAGS = --optimize
PLINK = $(clu2c_bindir)\plink
PLINKFLAGS = 
PLINK_METHOD = $(FAKE_PLINK)

# C compiler and its flags
CC = gcc
CFLAGS = -O

# Assembler
AS = as

# Flags to linker
LIBS = -lm
LDFLAGS = 

# Library directory for linking executable commands
LIBDIR = $(topdir)/lib

# Commands for archive
AR = ar
ARFLAGS = ru
RANLIB = ranlib

# Commands for installation
INSTALL = copy
INSTALLFLAGS = 
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL)

# Command for preparation of file
LN_S = copy

# Support for DJGPP
COFF2EXE = 

# Command interpreter (MS-DOS and its variants only)
COMMAND = command
COMMANDFLAGS = 

# M4 macro processor (maintainers only)
M4 = m4
M4FLAGS = 

# File system type
FS_TYPE = dos

# Names for distribution
distname = clu2c-$(VERSION)
dos_distname = clu$(ABRIDGED_VERSION)s

# Version of the distribution
VERSION = 1.99.3
ABRIDGED_VERSION = 193
