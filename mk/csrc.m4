# csrc.m4
#
# $Id: csrc.m4,v 2.0 1996/06/10 09:06:23 ushijima Exp $


MK_REQUIRE(`c2o')
MK_PROVIDE(`csrc')


# MK_C_SOURCES(FILE-1 ... FILE-N)

define(`MK_C_SOURCES',
	`MK_APPEND_VARGROUP(`C_SRC', $1)
	 MK_APPEND_VARGROUP(`C_OBJ', patsubst($1, `\.c', `.o'))')


MK_APPEND_VARIABLE(`ALL_OBJ', `$(C_OBJ)')

MK_CLEAR_VARGROUP(`C_SRC')
MK_CLEAR_VARGROUP(`C_OBJ')

m4wrap(`
MK_APPEND_VARIABLE(`ALL_SRC', `$(C_SRC)')
MK_MOSTLYCLEAN_VARGROUP(`C_OBJ')

MK_SOURCE_FILES
MK_VARGROUP_DEFINITION(`C_SRC', `C source files')
MK_END

MK_CREATED_FILES
MK_VARGROUP_DEFINITION(`C_OBJ', `Object files compiled from C source files')
MK_END
')
