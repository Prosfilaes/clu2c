# spcsrc.m4
#
# $Id: spcsrc.m4,v 2.1 1996/06/20 12:31:53 ushijima Exp $


MK_PROVIDE(`spcsrc')


# MK_SPC_SOURCES(FILE-1 ... FILE-N)

define(`MK_SPC_SOURCES',
	`MK_APPEND_VARGROUP(`SPC_SRC', $1)')

MK_CLEAR_VARGROUP(`SPC_SRC')


# MK_SPC_DIRECTORY(DIRECTORY)

define(`MK_SPC_DIRECTORY',
	`define(`_MK_SPC_DIRECTORY', `$1')')


MK_APPEND_PREREQ(`install',
	`installdirs')
MK_APPEND_ACTION(`install',
	`ifelse(OSTYPE, `unix',
	`@for i in $(SPC_SRC); do \
		echo MK_INSTALL_SOURCE_DATA(`$$i', _MK_SPC_DIRECTORY); \
		MK_INSTALL_SOURCE_DATA(`$$i', _MK_SPC_DIRECTORY); \
	done',
	`copy *.spc _MK_SPC_DIRECTORY')')

MK_DEFINE_RULE(`installdirs',
	`installdirs',
	`',
	`MK_INSTALL_DIRECTORY(`$(clu2c_rootdir)')
	MK_INSTALL_DIRECTORY(`$(clu2c_libdir)')
	MK_INSTALL_DIRECTORY(_MK_SPC_DIRECTORY)')

m4wrap(`
MK_APPEND_VARIABLE(`ALL_SRC', `$(SPC_SRC)')

MK_SOURCE_FILES
MK_VARGROUP_DEFINITION(`SPC_SRC', `Interface specification files')
MK_END

MK_SPECIFIC_RULES
MK_RULE_DEFINITION(`installdirs', `Prepares installation directory')
MK_END
')
