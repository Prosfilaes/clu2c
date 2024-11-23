# wclusrc.m4
#
# $Id: wclusrc.m4,v 2.0 1996/06/10 09:06:28 ushijima Exp $


ifelse(OSTYPE, `go32',
	`MK_MAP_VARGROUP(`MK_PREPARE_VARIABLE', `CLU_INT')',
	`MK_APPEND_ACTION(`translate_using_pretranslated_files', `MK_PREPARE(`$(CLU_INT)')')')

MK_APPEND_VARIABLE(`NON_SRC', `fakeclu.bat')
MK_APPEND_VARIABLE(`ALL_SRC', `$(CLU_SRC)')
ifelse(MK_VARIABLE_DEFINED(`EQU_SRC'), `1',
	`MK_APPEND_VARIABLE(`ALL_SRC', `$(EQU_SRC)')')
MK_CLEAN_VARGROUP(`CLU_INT')
MK_MOSTLYCLEAN_VARGROUP(`CLU_OBJ')

MK_SPECIFIC_VARIABLES
MK_VARIABLE_DEFINITION(`DEFAULT_PLINKFLAGS', `Default flags to plink')
MK_VARIABLE_DEFINITION(`ALL_PLINKFLAGS', `All the flags to plink')
MK_VARIABLE_DEFINITION(`FAKE_CLU2C', `Command line to fake clu2c execution')
MK_VARIABLE_DEFINITION(`REAL_PLINK', `Command line to execute plink')
MK_VARIABLE_DEFINITION(`FAKE_PLINK', `Command line to fake plink execution')
MK_END

MK_SOURCE_FILES
MK_VARGROUP_DEFINITION(`CLU_SRC', `CLU source files')
ifelse(MK_VARIABLE_DEFINED(`EQU_SRC'), `1',
`MK_VARIABLE_DEFINITION(`EQU_SRC', `Equate files')',
`dnl')
MK_END

MK_CREATED_FILES
MK_VARGROUP_DEFINITION(`CLU_INT', `Intermediate C files translated from CLU files')
MK_VARGROUP_DEFINITION(`CLU_OBJ', `Object files compiled from intermediate C files')
MK_VARIABLE_DEFINITION(`POUT', `Base name of output file of plink')
MK_VARIABLE_DEFINITION(`PRE', `Pre-translated C files')
MK_END

MK_SPECIFIC_RULES
MK_RULE_DEFINITION(`cfiles', `Creates all the C files')
MK_RULE_DEFINITION(`clu2c_time', `Translates all the CLU source files to C files')
MK_RULE_DEFINITION(`POUT_C', `Pre-link')
MK_END

MK_SUFFIX_RULES
MK_RULE_DEFINITION(`clu2c', `Compiles CLU files')
MK_END

MK_MAINTENANCE_RULES
MK_RULE_DEFINITION(`fakeclu_bat', `Creates fakeclu.bat')
MK_RULE_DEFINITION(`cfiles_clean', `Deletes all files created by making cfiles')
MK_END
