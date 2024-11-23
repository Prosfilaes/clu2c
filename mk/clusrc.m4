# clusrc.m4
#
# $Id: clusrc.m4,v 2.1 1997/01/24 08:29:12 ushijima Exp $


MK_REQUIRE(`c2o')
MK_PROVIDE(`clusrc')

define(`MK_CLU_SOURCES',
	`MK_APPEND_VARGROUP(`CLU_SRC', $1)
	 MK_APPEND_VARGROUP(`CLU_INT', patsubst($1, `\.clu', `.c'))
	 MK_APPEND_VARGROUP(`CLU_OBJ', patsubst($1, `\.clu', `.o'))')

define(`MK_EQU_SOURCES',
	`MK_DEFINE_VARIABLE(`EQU_SRC', `$1')')

MK_DEFINE_VARIABLE(`ALL_PLINKFLAGS', `$(DEFAULT_PLINKFLAGS) $(PLINKFLAGS)')
ifelse(MK_VARIABLE_DEFINED(`DEFAULT_PLINKFLAGS'), `1', `',
`MK_DEFINE_VARIABLE(`DEFAULT_PLINKFLAGS', `')')
MK_APPEND_VARIABLE(`DEFAULT_CFLAGS', `-w')

MK_DEFINE_VARIABLE(`POUT', `op-table')
MK_APPEND_VARIABLE(`ALL_OBJ', `$(CLU_OBJ)')
MK_DEFINE_VARIABLE(`PRE', `$(CLU_INT) $(POUT).c')

MK_CLEAR_VARGROUP(`CLU_SRC')
MK_CLEAR_VARGROUP(`CLU_INT')
MK_CLEAR_VARGROUP(`CLU_OBJ')

MK_DEFINE_VARIABLE(`FAKE_CLU2C', MK_FAKE_CLU2C)
MK_DEFINE_VARIABLE(`REAL_PLINK', `$(PLINK) $(ALL_PLINKFLAGS) -o $(POUT).c $(CLU_INT)')
MK_DEFINE_VARIABLE(`FAKE_PLINK', `$(LN_S) MK_PATH_NAME(`$(srcdir)', `pretrans', `$(POUT).c') $(POUT).c')

MK_CLEAN_FILES(`SPC.lib clu2c.time $(POUT).c')

MK_APPEND_PREREQ(`dist', `$(PRE)')
MK_APPEND_ACTION(`dist',
	`@$(top_srcdir)/config/makedist -p $(distname) $(curdir) $(PRE)')

MK_APPEND_PREREQ(`dosdist', `$(PRE)')
MK_APPEND_ACTION(`dosdist',
	`@$(top_srcdir)/config/makedist -d -p $(dos_distname) $(curdir) $(PRE)')

MK_DEFINE_RULE(`cfiles',
	`cfiles', `clu2c.time $(POUT).c')

MK_DEFINE_RULE(`clu2c_time',
	`clu2c.time', `$(CLU_SRC)',
	`$(CLU2C) $(CLU2CFLAGS) --make
	echo clu2c.time > clu2c.time')

MK_DEFINE_RULE(`POUT_C',
	`$(POUT).c',
	`$(CLU_INT)',
	`$(PLINK_METHOD)')

MK_DEFINE_RULE(`fakeclu_bat',
	`fakeclu.bat',
	`Makefile',
	`@echo creating fakeclu.bat
	@echo echo off > fakeclu.bat
	@echo rem fakeclu.bat.\  Generated automatically by make. >> fakeclu.bat
	@for i in $(CLU_INT); do \
		echo echo preparing $$i >>fakeclu.bat; \
		echo "if not exist $$i copy pretrans\\$$i $$i >nul" >> fakeclu.bat; \
	done')

MK_DEFINE_RULE(`cfiles_clean',
	`cfiles-clean',
	`',
	`MK_REMOVE(`$(CLU_INT) $(POUT).c SPC.lib clu2c.time')')

define(`_MK_SUFFIXES', `.o .c .clu')

MK_DEFINE_RULE(`clu2c',
	`.clu.c', `',
	`MK_REMOVE(`clu2c.time')
	$(MAKE) clu2c.time')

m4wrap(`include(`wclusrc.m4')')
