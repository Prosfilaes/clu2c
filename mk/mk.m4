divert(-1)

# mk.m4
#
# $Id: mk.m4,v 2.0 1996/06/10 09:06:26 ushijima Exp $


ifdef(`OSTYPE', `', `define(`OSTYPE', `unix')')

include(OSTYPE.m4)


####

define(`MK_REQUIRE',
	`ifdef(`_MK_PROVIDE_$1', `', `include(`$1.m4')')')

define(`MK_PROVIDE',
	`define(`_MK_PROVIDE_$1', `1')')


#### Directory configuration ####


# MK_CURRENT_DIRECTORY(ENT-1, ..., ENT-N)
#
# This macro specifies the current directory relative to the top build
# directory.  Arguments form a list of directory entries.  Defines
# `curdir' and `topdir' according to the arguments.

define(`MK_CURRENT_DIRECTORY',
	`ifelse(`$1', `.',
		`MK_DEFINE_VARIABLE(`curdir', `.')
		 MK_DEFINE_VARIABLE(`topdir', `$(curdir)')
		 define(`_MK_DOS_TOPDIR', `$(curdir)')',
		`MK_DEFINE_VARIABLE(`curdir', MK_PATH_NAME($@))
		 MK_DEFINE_VARIABLE(`topdir', MK_PARENT_DIR($#))
		 define(`_MK_DOS_TOPDIR', MK_PARENT_DIR_DOS($#))')
	 MK_CURRENT_DIRECTORY_AUX')

define(`MK_CURRENT_DIRECTORY_AUX',
`MK_SPECIFIC_VARIABLES
MK_VARIABLE_DEFINITION(`curdir', `Current directory relative to the top-level build directory')
MK_VARIABLE_DEFINITION(`topdir', `Top-level build directory')
MK_END')


# MK_PATH_NAME(ENT-1, ..., ENT-N)

define(`MK_PATH_NAME',
	`ifelse($#, 1,
		`$1',
		`$1`'MK_PATH_DELIM`'MK_PATH_NAME(shift($@))')')


# MK_PARENT_DIR(N)

define(`MK_PARENT_DIR',
	`ifelse(eval($1 <= 1), 1,
		`..',
		`../MK_PARENT_DIR(eval($1 - 1))')')


# MK_PARENT_DIR_DOS(N)

define(`MK_PARENT_DIR_DOS',
	`ifelse(eval($1 <= 1), 1,
		`..',
		`..\MK_PARENT_DIR_DOS(eval($1 - 1))')')


# MK_SUBDIRECTORIES(SUBDIR-1 ... SUBDIR-N)
#
# Equivalent to MK_DEFINE_VARIABLE(`subdirs', SUBDIR-1 ... SUBDIR-N).

define(`MK_SUBDIRECTORIES',
	`MK_DEFINE_VARIABLE(`subdirs', `$1')
	MK_SUBDIRECTORIES_AUX
	MK_APPEND_DELEGATING_ACTION(`all')
	MK_APPEND_DELEGATING_ACTION(`install')
	MK_APPEND_DELEGATING_ACTION(`mostlyclean')
	MK_APPEND_DELEGATING_ACTION(`clean')
	MK_APPEND_DELEGATING_ACTION(`distclean')
	MK_APPEND_DELEGATING_ACTION(`realclean')
	MK_APPEND_DELEGATING_ACTION(`dist')
	MK_APPEND_DELEGATING_ACTION(`mkfiles')
	MK_APPEND_DELEGATING_ACTION(`m4')
	MK_APPEND_DELEGATING_ACTION(`dosdist')
	MK_APPEND_DELEGATING_ACTION(`source_list')')

define(`MK_SUBDIRECTORIES_AUX',
`MK_SPECIFIC_VARIABLES
MK_VARIABLE_DEFINITION(`subdirs', `Subdirectories')
MK_END')


#### Variable handling ####


# MK_DEFINE_VARIABLE(VAR-NAME, VALUE)
#
# Defines the value of the makefile variable named VAR-NAME as VALUE.

define(`MK_DEFINE_VARIABLE',
	`define(`_MK_VAL_$1', `$2')')


# MK_APPEND_VARIABLE(VAR-NAME, VALUE)
#
# Appends VALUE to the value of the makefile variable named VAR-NAME.

define(`MK_APPEND_VARIABLE',
	`define(`_MK_VAL_$1', ifdef(`_MK_VAL_$1', _MK_VAL_$1 $2, $2))')


# MK_VARIABLE_DEFINITION(VAR-NAME [, DOC-STRING])
#
# Expands to the definition of the makefile variable named VAR-NAME.

define(`MK_VARIABLE_DEFINITION',
`ifelse(`$2', `',
`dnl',
`
`#' $2')
$1 =ifdef(`_MK_VAL_$1', ` '_MK_VAL_$1)')


# MK_VARIABLE_DEFINITION_LINE(VAR-NAME)
#
# Expands to the definition of the makefile variable named VAR-NAME
# and a trailing newline.

define(`MK_VARIABLE_DEFINITION_LINE',
	`MK_VARIABLE_DEFINITION(`$1')
')


# MK_VARIABLE_DEFINED(VAR-NAME)
#
# Expands to 1 if the makefile variable named VAR-NAME is defined;
# otherwise expands to 0.

define(`MK_VARIABLE_DEFINED',
	`ifdef(`_MK_VAL_$1', `1', `0')')


# MK_VARIABLE_VALUE(VAR-NAME)
#
# Expands to the current value of the makefile variable named
# VAR-NAME.

define(`MK_VARIABLE_VALUE',
	`ifdef(`_MK_VAL_$1', _MK_VAL_$1, `')')


#### Variable group handling ####


# MK_CLEAR_VARGROUP(VG-NAME)
#
# Clears the makefile variable group VG-NAMEd VG-VG-NAME.

define(`MK_CLEAR_VARGROUP',
	`define(`_MK_CNT_$1', `0')')


# MK_APPEND_VARGROUP(VG-NAME, VALUE)
#
# Appends VALUE to the value of the makefile variable group named
# VG-NAME, i.e., defines the value of a new makefile variable named
# VG-NAME_# (# is initially 1 and incremented each time) as VALUE and
# appends $(VG-NAME_#) to the value of the makefile variable named
# VG-NAME.

define(`MK_APPEND_VARGROUP',
	`define(`_MK_CNT_$1', incr(_MK_CNT_$1))
	 MK_DEFINE_VARIABLE(`$1_'_MK_CNT_$1, `$2')
	 MK_APPEND_VARIABLE(`$1', `$($1_'_MK_CNT_$1`)')')


# MK_MAP_VARGROUP(MACRO-NAME, VG-NAME)

define(`MK_MAP_VARGROUP',
	`MK_MAP_VARGROUP_AUX(`$1', `$2', 1, _MK_CNT_$2)')


# MK_MAP_VARGROUP_AUX(MACRO-NAME, VG-NAME, CNT, MAX)

define(`MK_MAP_VARGROUP_AUX',
	`ifelse(eval(`$3 > $4'), `1', `',
		`$1(`$2_$3')`'MK_MAP_VARGROUP_AUX(`$1', `$2', incr($3), $4)')')


# MK_VARGROUP_DEFINITION(VG-NAME [, DOC-STRING])

define(`MK_VARGROUP_DEFINITION',
`ifelse(`$2', `',
`dnl',
`
`#' $2')
MK_VARIABLE_DEFINITION(`$1')
MK_MAP_VARGROUP(`MK_VARIABLE_DEFINITION_LINE', `$1')dnl')


#### Rule handling ####


# MK_DEFINE_RULE(RULE-NAME, TARGET, PREREQ, ACTION)

define(`MK_DEFINE_RULE',
	`MK_DEFINE_TARGET(`$1', `$2')
	 ifelse(`$3', `', `', `MK_DEFINE_PREREQ(`$1', `$3')')
	 ifelse(`$4', `', `', `MK_DEFINE_ACTION(`$1', `$4')')')


# MK_DEFINE_TARGET(RULE-NAME, TARGET)

define(`MK_DEFINE_TARGET',
	`define(`_MK_TARGET_$1', `$2')')


# MK_DEFINE_ACTION(RULE_NAME, ACTION)

define(`MK_DEFINE_ACTION',
	`define(`_MK_ACTION_$1', `$2')')


# MK_APPEND_ACTION(RULE_NAME, ACTION)

define(`MK_APPEND_ACTION',
	`ifdef(`_MK_ACTION_$1',
		`MK_DEFINE_ACTION(`$1', _MK_ACTION_$1
	`$2')',
		`MK_DEFINE_ACTION(`$1', `$2')')')


# MK_DEFINE_PREREQ(RULE-NAME, PREREQ)

define(`MK_DEFINE_PREREQ',
	`define(`_MK_PREREQ_$1', `$2')')


# MK_APPEND_PREREQ(RULE_NAME, PREREQ)

define(`MK_APPEND_PREREQ',
	`ifdef(`_MK_PREREQ_$1',
		`MK_DEFINE_PREREQ(`$1', _MK_PREREQ_$1 `$2')',
		`MK_DEFINE_PREREQ(`$1', `$2')')')


# MK_DELEGATE_ACTION(RULE-NAME-1, ..., RULE-NAME-N)

define(`MK_DELEGATE_ACTION',
	`ifelse($1, `', `',
		`MK_APPEND_ACTION($1, MK_MAKE_IN_SUBDIRS($1))
		 MK_DELEGATE_ACTION(shift($@))')')


# MK_APPEND_DELEGATING_ACTION(RULE-NAME [, SUBDIR-1 ... SUBDIR-N ] )

define(`MK_APPEND_DELEGATING_ACTION',
	`ifelse(`$2', `',
		`MK_APPEND_ACTION(`$1', MK_MAKE_IN_SUBDIRS(`$1', `$(subdirs)'))',
		`MK_APPEND_ACTION(`$1', MK_MAKE_IN_SUBDIRS(`$1', `$2'))')')


# MK_RULE_DEFINITION(RULE-NAME [, DOC-STRING])

define(`MK_RULE_DEFINITION',
`ifelse(`$2', `',
`dnl',
`
`#' `$2'')
_MK_TARGET_$1:ifdef(`_MK_PREREQ_$1', ` '_MK_PREREQ_$1)
ifdef(`_MK_ACTION_$1', `'	_MK_ACTION_$1, `dnl')')


# MK_MOSTLYCLEAN_FILES(FILE-1 ... FILE-N)
#
# Specifies files `make mostlyclean' should delete.  Furthermore,
# `make clean', `make distclean', and `make realclean' also delete
# these files.

define(`MK_MOSTLYCLEAN_FILES',
	`MK_APPEND_ACTION(`mostlyclean', `MK_REMOVE(`$1')')
	 MK_CLEAN_FILES(`$1')')


# MK_CLEAN_FILES(FILE-1 ... FILE-N)
#
# Specifies files `make clean' should delete.  Furthermore, `make
# distclean' and `make realclean' also delete these files.

define(`MK_CLEAN_FILES',
	`MK_APPEND_ACTION(`clean', `MK_REMOVE(`$1')')
	 MK_DISTCLEAN_FILES(`$1')')


# MK_DISTCLEAN_FILES(FILE-1 ... FILE-N)
#
# Specifies files `make distclean' should delete.  Furthermore, `make
# realclean' also delete these files.

define(`MK_DISTCLEAN_FILES',
	`MK_APPEND_ACTION(`distclean', `MK_REMOVE(`$1')')
	 MK_REALCLEAN_FILES(`$1')')


# MK_REALCLEAN_FILES(FILE-1 ... FILE-N)
#
# Specifies files `make realclean' should delete.

define(`MK_REALCLEAN_FILES',
	`MK_APPEND_ACTION(`realclean', `MK_REMOVE(`$1')')')


# MK_MOSTLYCLEAN_VARIABLE(VAR-NAME)

define(`MK_MOSTLYCLEAN_VARIABLE',
	`ifelse(MK_VARIABLE_DEFINED(`$1'), `1',
		`MK_MOSTLYCLEAN_FILES(`$($1)')')')


# MK_CLEAN_VARIABLE(VAR-NAME)

define(`MK_CLEAN_VARIABLE',
	`ifelse(MK_VARIABLE_DEFINED(`$1'), `1',
		`MK_CLEAN_FILES(`$($1)')')')


# MK_DISTCLEAN_VARIABLE(VAR-NAME)

define(`MK_DISTCLEAN_VARIABLE',
	`ifelse(MK_VARIABLE_DEFINED(`$1'), `1',
		`MK_DISTCLEAN_FILES(`$($1)')')')


# MK_REALCLEAN_VARIABLE(VAR-NAME)

define(`MK_REALCLEAN_VARIABLE',
	`ifelse(MK_VARIABLE_DEFINED(`$1'), `1',
		`MK_REALCLEAN_FILES(`$($1)')')')


# MK_MOSTLYCLEAN_VARGROUP(VG-NAME)

define(`MK_MOSTLYCLEAN_VARGROUP',
	`ifdef(`MK_SHORT_COMMAND_LINES',
		`MK_MAP_VARGROUP(`MK_MOSTLYCLEAN_VARIABLE', `$1')',
		`MK_MOSTLYCLEAN_VARIABLE(`$1')')')


# MK_CLEAN_VARGROUP(VG-NAME)

define(`MK_CLEAN_VARGROUP',
	`ifdef(`MK_SHORT_COMMAND_LINES',
		`MK_MAP_VARGROUP(`MK_CLEAN_VARIABLE', `$1')',
		`MK_CLEAN_VARIABLE(`$1')')')


# MK_DISTCLEAN_VARGROUP(VG-NAME)

define(`MK_DISTCLEAN_VARGROUP',
	`ifdef(`MK_SHORT_COMMAND_LINES',
		`MK_MAP_VARGROUP(`MK_DISTCLEAN_VARIABLE', `$1')',
		`MK_DISTCLEAN_VARIABLE(`$1')')')


# MK_REALCLEAN_VARGROUP(VG-NAME)

define(`MK_REALCLEAN_VARGROUP',
	`ifdef(`MK_SHORT_COMMAND_LINES',
		`MK_MAP_VARGROUP(`MK_REALCLEAN_VARIABLE', `$1')',
		`MK_REALCLEAN_VARIABLE(`$1')')')


# MK_INSTALL_PROGRAM(FILE, DIRECTORY [, ALTNAME])

define(`MK_INSTALL_PROGRAM',
	`ifelse(`$3', `',
		`$(INSTALL_PROGRAM) $(INSTALLFLAGS) $1 MK_PATH_NAME(`$2', `$1')',
		`$(INSTALL_PROGRAM) $(INSTALLFLAGS) $1 MK_PATH_NAME(`$2', `$3')')')


# MK_INSTALL_DATA(FILE, DIRECTORY [, ALTNAME])

define(`MK_INSTALL_DATA',
	`ifelse(`$3', `',
		`$(INSTALL_DATA) $(INSTALLFLAGS) $1 MK_PATH_NAME(`$2', `$1')',
		`$(INSTALL_DATA) $(INSTALLFLAGS) $1 MK_PATH_NAME(`$2', `$3')')')


# MK_INSTALL_SOURCE_DATA(FILE, DIRECTORY)

define(`MK_INSTALL_SOURCE_DATA',
	`$(INSTALL_DATA) $(INSTALLFLAGS) MK_PATH_NAME(`$(srcdir)', `$1') MK_PATH_NAME(`$2', `$1')')


# MK_DOLLAR(SYMBOL)

define(`MK_DOLLAR', `$$1')


# MK_MISC_SOURCES(FILE-1 ... FILE-N)

define(`MK_MISC_SOURCES',
	`MK_APPEND_VARIABLE(`MISC_SRC', `$1')')


# MK_NON_SOURCES(FILE-1 ... FILE-N)

define(`MK_NON_SOURCES',
	`MK_APPEND_VARIABLE(`NON_SRC', `$1')')


#### Diversion handling ####

define(`_MK_DIV_SPECIFIC_VARIABLES', `1')
define(`_MK_DIV_SOURCE_FILES', `2')
define(`_MK_DIV_CREATED_FILES', `3')
define(`_MK_DIV_MAINTENANCE_VARIABLES', `4')
define(`_MK_DIV_SPECIFIC_RULES', `5')
define(`_MK_DIV_SUFFIX_RULES', `6')
define(`_MK_DIV_MAINTENANCE_RULES', `7')

define(`MK_SPECIFIC_VARIABLES',
	`define(`_MK_SPECIFIC_VARIABLES', `1')
	 divert(_MK_DIV_SPECIFIC_VARIABLES)dnl')

define(`MK_SOURCE_FILES',
	`define(`_MK_SOURCE_FILES', `1')
	 divert(_MK_DIV_SOURCE_FILES)dnl')

define(`MK_CREATED_FILES',
	`define(`_MK_CREATED_FILES', `1')
	 divert(_MK_DIV_CREATED_FILES)dnl')

define(`MK_MAINTENANCE_VARIABLES',
	`ifelse(OSTYPE, `unix',
		`define(`_MK_MAINTENANCE_VARIABLES', `1')
		 divert(_MK_DIV_MAINTENANCE_VARIABLES)dnl')')

define(`MK_SPECIFIC_RULES',
	`define(`_MK_SPECIFIC_RULES', `1')
	 divert(_MK_DIV_SPECIFIC_RULES)dnl')

define(`MK_SUFFIX_RULES',
	`define(`_MK_SUFFIX_RULES', `1')
	 divert(_MK_DIV_SUFFIX_RULES)dnl')

define(`MK_MAINTENANCE_RULES',
	`ifelse(OSTYPE, `unix',
		`define(`_MK_MAINTENANCE_RULES')
		 divert(_MK_DIV_MAINTENANCE_RULES)dnl')')
 
define(`MK_END',
	`divert(-1)')


#### Default settings ####


MK_DEFINE_VARIABLE(`DEFAULT_M4FLAGS',
	`-I`'MK_PATH_NAME(`$(top_srcdir)', `mk')')
MK_DEFINE_VARIABLE(`ALL_M4FLAGS',
	`$(DEFAULT_M4FLAGS) $(M4FLAGS)')
MK_DEFINE_VARIABLE(`MISC_SRC', `ChangeLog Makefile.in README')

MK_DEFINE_VARIABLE(`NON_SRC', `Makefile.dos Makefile.unix')

MK_DEFINE_VARIABLE(`DIST', `$(ALL_SRC) $(NON_SRC)')

MK_DEFINE_RULE(`all', `all')
MK_DEFINE_RULE(`install', `install')
MK_DEFINE_RULE(`uninstall', `uninstall')
MK_DEFINE_RULE(`mostlyclean', `mostlyclean')
MK_DEFINE_RULE(`clean', `clean')
MK_DEFINE_RULE(`distclean', `distclean')
MK_DEFINE_RULE(`realclean', `realclean')
MK_DEFINE_RULE(`TAGS', `TAGS')
MK_DEFINE_RULE(`info', `info')
MK_DEFINE_RULE(`dist', `dist')
MK_DEFINE_RULE(`check', `check')

MK_DISTCLEAN_FILES(`Makefile Makefile.top')

MK_DEFINE_RULE(`dist',
	`dist',
	`$(DIST)',
	`@$(top_srcdir)/config/makedist $(distname) $(curdir) $(DIST)')

MK_DEFINE_RULE(`dosdist',
	`dosdist',
	`$(DIST)',
	`@$(top_srcdir)/config/makedist -d $(dos_distname) $(curdir) $(DIST)')

MK_DEFINE_RULE(`mkfiles',
	`mkfiles', `',
	`MK_CAT_FILES(`Makefile',
		`Makefile.top',
		ifelse(OSTYPE, `unix', `MK_PATH_NAME(`$(topdir)', `config.mk')', `$(config_mk)'),
		MK_PATH_NAME(`$(srcdir)', `Makefile.OSTYPE'))')

MK_DEFINE_RULE(`m4',
	`m4', `',
	`@for os in unix dos; do					\
	    mk=Makefile.$$os;						\
	    echo creating $$mk;						\
	    $(M4) $(ALL_M4FLAGS) -DOSTYPE=$$os Makefile.in >$$mk.new;	\
	    if test ! $$?; then						\
		echo $$mk is unchanged;					\
		rm -f $$mk.new;						\
		exit 1;							\
	    elif cmp -s $$mk $$mk.new 2>/dev/null; then			\
		echo $$mk is unchanged;					\
		rm -f $$mk.new;						\
	    else							\
		rm -f $$mk;						\
		mv $$mk.new $$mk;					\
	    fi;								\
	done')

MK_DEFINE_RULE(`source_list',
	`source-list', `',
	`@if [ $(curdir) = . ]; then\
	    cp /dev/null source-list;\
	    for i in $(ALL_SRC); do\
		echo $$i >>source-list;\
	    done;\
	else\
	    for i in $(ALL_SRC); do\
		echo $(curdir)/$$i >>$(topdir)/source-list;\
	    done;\
	fi')

MK_DEFINE_RULE(`always', `always')

m4wrap(`MK_APPEND_VARIABLE(`ALL_SRC', `$(MISC_SRC)')
MK_MAINTENANCE_VARIABLES
MK_VARIABLE_DEFINITION(`NON_SRC', `Non-source files included in the distribution')
MK_VARIABLE_DEFINITION(`DIST', `All the files included in the distribution')
MK_VARIABLE_DEFINITION(`DEFAULT_M4FLAGS', `Default flags to m4')
MK_VARIABLE_DEFINITION(`ALL_M4FLAGS', `All the flags to m4')
MK_END
MK_SOURCE_FILES
MK_VARIABLE_DEFINITION(`MISC_SRC', `Miscellaneous source files')
MK_VARIABLE_DEFINITION(`ALL_SRC', `All the source files')
MK_END
MK_SPECIFIC_RULES
MK_RULE_DEFINITION(`mkfiles', `Creates makefiles for this directory and all the subdirectories')
MK_RULE_DEFINITION(`always', `Forces a particular target to be made')
MK_END
MK_MAINTENANCE_RULES
MK_RULE_DEFINITION(`m4', `Processes m4 files')
MK_RULE_DEFINITION(`dosdist', `Creates dos distribution')
MK_RULE_DEFINITION(`source_list', `Creates the list of source files')
MK_END
include(`template.m4')')
