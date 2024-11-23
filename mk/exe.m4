# exe.m4
#
# $Id: exe.m4,v 2.0 1996/06/10 09:06:25 ushijima Exp $


MK_PROVIDE(`exe.m4')

define(`MK_EXE_NAME',
	`MK_DEFINE_VARIABLE(`EXEBASE', `$1')')


# Libraries

MK_DEFINE_VARIABLE(`DEFAULT_LIBS',
	`-L$(LIBDIR) -lclu2c')
MK_DEFINE_VARIABLE(`ALL_LIBS',
	`$(DEFAULT_LIBS) $(LIBS)')


# Executables

MK_DEFINE_VARIABLE(`EXEBASE', `a.out')
MK_DEFINE_VARIABLE(`EXEEXT', MK_EXEEXT)
MK_DEFINE_VARIABLE(`EXE', `$(EXEBASE)$(EXEEXT)')


# Object files

MK_APPEND_VARIABLE(`ALL_OBJ', `$(POUT).o')


# Standard targets

MK_DEFINE_PREREQ(`all', `$(EXE)')
MK_DEFINE_PREREQ(`install', `$(EXE) installdirs')
MK_APPEND_ACTION(`install',
	`MK_INSTALL_PROGRAM(`$(EXE)', `$(clu2c_bindir)')')

MK_MOSTLYCLEAN_FILES(ifelse(MK_LINKOUT, `$(EXE)',
				`$(EXE) $(POUT).o',
				`$(EXEBASE) $(EXE) $(POUT).o'))


# Specific rules

MK_DEFINE_RULE(`link',
	`$(EXE)',
	`$(ALL_OBJ) $(LIBDIR)/libclu2c.a',
	`$(CC) $(ALL_CFLAGS) MK_ALL_OBJ_SPEC $(ALL_LIBS) $(LDFLAGS) -o MK_LINKOUT')

ifelse(MK_LINKOUT, `$(EXEBASE)',
	`ifelse(DJGPP, 1,
		`MK_APPEND_ACTION(`link', `$(COFF2EXE) $(EXEBASE)')')')

MK_DEFINE_RULE(`objects',
	`objects',
	`always',
	`echo $(ALL_OBJ) > objects')

MK_DEFINE_RULE(`installdirs',
	`installdirs',
	`',
	`MK_INSTALL_DIRECTORY(`$(clu2c_rootdir)')
	MK_INSTALL_DIRECTORY(`$(clu2c_bindir)')')


m4wrap(`
MK_APPEND_VARIABLE(`NON_SRC', `objects')

MK_SPECIFIC_VARIABLES
MK_VARIABLE_DEFINITION(`DEFAULT_LIBS', `Default libraries')
MK_VARIABLE_DEFINITION(`ALL_LIBS', `All the libraries')
MK_END

MK_CREATED_FILES
MK_VARIABLE_DEFINITION(`EXEBASE', `Base name for the executable file')
MK_VARIABLE_DEFINITION(`EXEEXT', `Executable file extension (can be empty)')
MK_VARIABLE_DEFINITION(`EXE', `Executable file')
MK_VARIABLE_DEFINITION(`ALL_OBJ', `All the object files')
MK_END

MK_SPECIFIC_RULES
MK_RULE_DEFINITION(`link', `Links all the object files')
MK_RULE_DEFINITION(`installdirs', `Prepares installation directories')
MK_END

MK_MAINTENANCE_RULES
MK_RULE_DEFINITION(`objects', `Creates a list of all the objects')
MK_END
')
