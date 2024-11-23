# dos.m4 - definitions for MS-DOS with GO32
#
# Copyright (c) 1996
#	Department of Mathematical and Computing Sciences,
#	Tokyo Institute of Technology.  All rights reserved.
#
# $Id: dos.m4,v 2.1 1996/06/24 11:45:22 ushijima Exp $


# MK_PATH_DELIM
#
# Expands to the path delimiter.

define(`MK_PATH_DELIM',
	`\')


# MK_CAT_FILES(OUT-FILE, IN-FILE-1, ..., IN-FILE-N)

define(`MK_CAT_FILES',
	`copy MK_CAT_FILES_AUX(shift($@)) $1')
	

define(`MK_CAT_FILES_AUX',
	`ifelse(`$#', `1', `$1', `$1+MK_CAT_FILES_AUX(shift($@))')')


# MK_REMOVE(FILE-1 ... FILE-N)

define(`MK_REMOVE',
	`$(COMMAND) $(COMMANDFLAGS) /c '_MK_DOS_TOPDIR`\config\remove $@')


# MK_MAKE_IN_SUBDIRS(RULE-NAME, SUBDIR-1 ... SUBDIR-N)

define(`MK_MAKE_IN_SUBDIRS',
	`ifelse(`$2', `$(subdirs)',
		`MK_MAKE_IN_SUBDIRS_AUX(`$1', patsubst(MK_VARIABLE_VALUE(`subdirs'), `  *', `, '))',
		`MK_MAKE_IN_SUBDIRS_AUX(`$1', patsubst(`$2', `  *', `, '))')')

define(`MK_MAKE_IN_SUBDIRS_AUX',
`ifelse(`$#', `2',
	`$(COMMAND) $(COMMANDFLAGS) /c '_MK_DOS_TOPDIR`\config\insubdir $2 $(MAKE) $1',
	`$(COMMAND) $(COMMANDFLAGS) /c '_MK_DOS_TOPDIR`\config\insubdir $2 $(MAKE) $1
	MK_MAKE_IN_SUBDIRS_AUX(`$1', shift(shift($@)))')')


# MK_PREPARE(FILE-NAME-1 ... FILE-NAME-N)

define(`MK_PREPARE',
	`for %%f in $1 do if not exist %f $(LN_S) pretrans\%f %f')

define(`MK_PREPARE_VARIABLE',
	`MK_APPEND_ACTION(`translate_using_pretranslated_files', `MK_PREPARE(`$($1)')')')


# MK_EXEEXT
#
# Expands to the standard extension to executable files.

define(`MK_EXEEXT', `.exe')


# MK_LINKOUT
#
# Expands to the file name of the output file of the linker.

define(`MK_LINKOUT', `$(EXEBASE)')


# MK_ALL_OBJ_SPEC
#
# Expands to the string

define(`MK_ALL_OBJ_SPEC', `@objects')


# MK_SHORT_COMMAND_LINES

define(`MK_SHORT_COMMAND_LINES', `1')


# MK_FAKE_CLU2C

define(`MK_FAKE_CLU2C', `$(COMMAND) $(COMMANDFLAGS) /c fakeclu')


# MK_INSTALL_DIRECTORY(DIRECTORY)

define(`MK_INSTALL_DIRECTORY',
	`-mkdir $1')


# MK_NULL_DEVICE
#
# Expands to the name of the null device.

define(`MK_NULL_DEVICE', `nul')
