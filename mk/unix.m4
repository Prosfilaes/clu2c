# unix.m4
#
# $Id: unix.m4,v 2.1 1996/06/24 11:45:12 ushijima Exp $


# MK_PATH_DELIM
#
# Expands to the path delimiter.

define(`MK_PATH_DELIM',
	`/')


# MK_CAT_FILES(OUT-FILE, IN-FILE-1, ..., IN-FILE-N)

define(`MK_CAT_FILES',
	`cat MK_CAT_FILES_AUX(shift($@)) > $1')

define(`MK_CAT_FILES_AUX',
	`ifelse(`$#', `1', `$1', `$1 MK_CAT_FILES_AUX(shift($@))')')

# MK_REMOVE(FILE-1 ... FILE-N)

define(`MK_REMOVE',
	`rm -f $@')


# MK_MAKE_IN_SUBDIRS(RULE-NAME, SUBDIR-1 ... SUBDIR-N)

define(`MK_MAKE_IN_SUBDIRS',
	`for d in $2; do (cd $$d && $(MAKE) _MK_TARGET_$1); done')


# MK_PREPARE(FILE-NAME-1 ... FILE-NAME-N)

define(`MK_PREPARE',
	`@for f in $1; do \
		test -f $$f && continue; \
		echo preparing $$f; \
		$(LN_S) $(srcdir)/pretrans/$$f $$f; \
	done')

# MK_EXEEXT
#
# Expands to the standard extension to executable files.

define(`MK_EXEEXT', `')


# MK_LINKOUT
#
# Expands to the file name of the output file of the linker.

define(`MK_LINKOUT', `$(EXE)')


# MK_ALL_OBJ_SPEC
#
# Expands to the string

define(`MK_ALL_OBJ_SPEC', `$(ALL_OBJ)')


# MK_FAKE_CLU2C

define(`MK_FAKE_CLU2C', `sh $(top_srcdir)/fakeclu.sh')


# MK_INSTALL_DIRECTORY(DIRECTORY)

define(`MK_INSTALL_DIRECTORY',
	`test -d $1 || mkdir $1')


# MK_NULL_DEVICE
#
# Expands to the name of the null device.

define(`MK_NULL_DEVICE', `/dev/null')
