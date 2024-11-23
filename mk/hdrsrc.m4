# hdrsrc.m4
#
# $Id: hdrsrc.m4,v 2.1 1996/06/20 12:32:09 ushijima Exp $


MK_PROVIDE(`hdrsrc')


# MK_HDR_SOURCES(FILE-1 ... FILE-N)

define(`MK_HDR_SOURCES',
	`MK_APPEND_VARGROUP(`HDR_SRC', $1)')

MK_CLEAR_VARGROUP(`HDR_SRC')


# MK_HDR_DIRECTORY(DIRECTORY)

define(`MK_HDR_DIRECTORY',
	`define(`_MK_HDR_DIRECTORY', `$1')')

MK_APPEND_PREREQ(`install',
	`installdirs')
MK_APPEND_ACTION(`install',
	`ifelse(OSTYPE, `unix',
	`@for i in $(HDR_SRC); do \
		echo MK_INSTALL_SOURCE_DATA(`$$i', _MK_HDR_DIRECTORY); \
		MK_INSTALL_SOURCE_DATA(`$$i', _MK_HDR_DIRECTORY); \
	done',
	`copy *.h _MK_HDR_DIRECTORY')')

MK_DEFINE_RULE(`installdirs',
	`installdirs',
	`',
	`MK_INSTALL_DIRECTORY(`$(clu2c_rootdir)')
	MK_INSTALL_DIRECTORY(`$(clu2c_includedir)')
	MK_INSTALL_DIRECTORY(_MK_HDR_DIRECTORY)')

m4wrap(`
MK_APPEND_VARIABLE(`ALL_SRC', `$(HDR_SRC)')

MK_SOURCE_FILES
MK_VARGROUP_DEFINITION(`HDR_SRC', `Interface specification files')
MK_END
MK_SPECIFIC_RULES
MK_RULE_DEFINITION(`installdirs', `Prepares installation directory')
MK_END
')
