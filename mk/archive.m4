# archive.m4
#
# $Id: archive.m4,v 2.0 1996/06/10 09:06:22 ushijima Exp $


MK_PROVIDE(`archive')

define(`MK_ARCHIVE_NAME',
	`MK_DEFINE_VARIABLE(`ARCHIVE', `$1')')

define(`MK_ARCHIVE_FILES',
	`MK_APPEND_ACTION(`archive', `$(AR) $(ARFLAGS) $(ARCHIVE) $1')')

define(`MK_ARCHIVE_VARIABLE',
	`ifelse(MK_VARIABLE_DEFINED(`$1'), `1', `MK_ARCHIVE_FILES(`$($1)')')')

define(`MK_ARCHIVE_VARGROUP',
	`ifdef(`MK_SHORT_COMMAND_LINES',
		`MK_MAP_VARGROUP(`MK_ARCHIVE_VARIABLE', `$1')',
		`MK_ARCHIVE_VARIABLE(`$1')')')

MK_DEFINE_VARIABLE(`DEFAULT_PLINKFLAGS', `-x')

MK_DEFINE_PREREQ(`all', `archive')
MK_MOSTLYCLEAN_FILES(`archive')

MK_DEFINE_RULE(`archive', `archive', `$(ALL_OBJ)')

m4wrap(`
ifelse(MK_VARIABLE_DEFINED(`CLU_OBJ'), `1', `MK_ARCHIVE_VARGROUP(`CLU_OBJ')')
ifelse(MK_VARIABLE_DEFINED(`C_OBJ'), `1', `MK_ARCHIVE_VARGROUP(`C_OBJ')')
MK_APPEND_ACTION(`archive', `$(RANLIB) $(ARCHIVE)')
MK_APPEND_ACTION(`archive', `echo archive > archive')

MK_SPECIFIC_VARIABLES
MK_VARIABLE_DEFINITION(`ARCHIVE', `Archive file')
MK_END

MK_CREATED_FILES
MK_VARIABLE_DEFINITION(`ALL_OBJ', `All the object files')
MK_END

MK_SPECIFIC_RULES
MK_RULE_DEFINITION(`archive', `Archives object files in this directory')
MK_END
')
