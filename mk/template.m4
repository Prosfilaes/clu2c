# template.m4 - makefile template
#
# Copyright (c) 1996
#	Department of Mathematical and Computing Sciences,
#	Tokyo Institute of Technology.  All rights reserved.
#
# $Id: template.m4,v 2.0 1996/06/10 09:06:27 ushijima Exp $


divert(0)

######################################################################
#
`#' Makefile.OSTYPE.  Generated automatically from Makefile.in by m4.
#
ifdef(`_MK_SPECIFIC_VARIABLES',
`

#### Variables specific to this directory ####
undivert(_MK_DIV_SPECIFIC_VARIABLES)dnl',
`dnl')
ifdef(`_MK_SOURCE_FILES',
`

#### Source files ####
undivert(_MK_DIV_SOURCE_FILES)dnl',
`dnl')
ifdef(`_MK_CREATED_FILES',
`

#### Created files ####
undivert(_MK_DIV_CREATED_FILES)dnl',
`dnl')
ifdef(`_MK_MAINTENANCE_VARIABLES',
`

#### Variables for source code maintenance ####
undivert(_MK_DIV_MAINTENANCE_VARIABLES)dnl',
`dnl')


#### Rules for standard targets ####
MK_RULE_DEFINITION(`all', `Compiles the entire program')
MK_RULE_DEFINITION(`install', `Copies all the products')
MK_RULE_DEFINITION(`uninstall', `Removes installed files')
MK_RULE_DEFINITION(`mostlyclean', `Makes mostly clean')
MK_RULE_DEFINITION(`clean', `Makes clean')
MK_RULE_DEFINITION(`distclean', `Makes clean as disributed')
MK_RULE_DEFINITION(`realclean', `Makes really clean')
MK_RULE_DEFINITION(`TAGS', `Creates tag file')
MK_RULE_DEFINITION(`info', `Creates info file')
MK_RULE_DEFINITION(`dist', `Creates distribution')
MK_RULE_DEFINITION(`check', `Does some check')
ifdef(`_MK_SPECIFIC_RULES',
`

#### Rules specific to this directory ####
undivert(_MK_DIV_SPECIFIC_RULES)dnl',
`dnl')
ifdef(`_MK_SUFFIX_RULES',
`

#### Suffix rules ####

.SUFFIXES:
.SUFFIXES: _MK_SUFFIXES
undivert(_MK_DIV_SUFFIX_RULES)dnl',
`dnl')
ifdef(`_MK_MAINTENANCE_RULES',
`

#### Rules for source code maintenance ####
undivert(_MK_DIV_MAINTENANCE_RULES)dnl',
`dnl')
