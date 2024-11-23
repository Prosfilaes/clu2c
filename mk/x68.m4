# x68.m4 - definitions for X68000
#
# Copyright (c) 1996
#	Department of Mathematical and Computing Sciences,
#	Tokyo Institute of Technology.  All rights reserved.
#
# $Id: x68.m4,v 2.1 1996/06/24 11:41:44 ushijima Exp $


include(`dos.m4')


# MK_EXEEXT
#
# Expands to the standard extension to executable files.

define(`MK_EXEEXT', `.x')


# MK_LINKOUT
#
# Expands to the file name of the output file of the linker.

define(`MK_LINKOUT', `$(EXE)')


# MK_ALL_OBJ_SPEC
#
# Expands to the string

define(`MK_ALL_OBJ_SPEC', `$(ALL_OBJ)')


# MK_SHORT_COMMAND_LINES

undefine(`MK_SHORT_COMMAND_LINES')
