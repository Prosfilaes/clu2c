# c2o.m4
#
# $Id: c2o.m4,v 2.0 1996/06/10 09:06:22 ushijima Exp $


MK_PROVIDE(`c2o')

MK_DEFINE_VARIABLE(`ALL_CFLAGS', `$(DEFAULT_CFLAGS) $(CFLAGS)')
MK_DEFINE_VARIABLE(`DEFAULT_CFLAGS', `-I$(top_srcdir)/include')
ifdef(`_MK_SUFFIXES',
	`define(`_MK_SUFFIXES', _MK_SUFFIXES `.o .c')',
	`define(`_MK_SUFFIXES', `.o .c')')
MK_DEFINE_RULE(`c2o',
	`.c.o',
	`',
	`$(CC) $(ALL_CFLAGS) -c $<')

m4wrap(`
MK_SPECIFIC_VARIABLES
MK_VARIABLE_DEFINITION(`DEFAULT_CFLAGS', `Default flags to the C compiler')
MK_VARIABLE_DEFINITION(`ALL_CFLAGS', `All the flags to the C compiler')
MK_END
MK_SUFFIX_RULES
MK_RULE_DEFINITION(`c2o', `Compiles C file to get object file')
MK_END
')
