#!/bin/sh

# mkmf.sh - create all make files
#
# Copyright (c) 1996
#	Department of Mathematical and Computing Sciences,
#	Tokyo Institute of Technology.  All rights reserved.
#
# $Id: mkmf.sh,v 2.0 1996/06/10 09:06:17 ushijima Exp $


case "$#" in
0)
	TOP_SRCDIR=.
	;;
*)
	TOP_SRCDIR=$1
	;;
esac

for dir in `sed '/^#/d' $TOP_SRCDIR/config/ALLDIRS`; do
	echo creating $dir/Makefile
	topdir=`echo $dir | sed 's:[^./][^/]*:..:g'`
	top_srcdir=`echo $topdir/$TOP_SRCDIR | sed -e 's:^.*//:/:' -e 's:^\./::' -e 's:/\.$::'`
	if test $top_srcdir = $topdir; then
		srcdir=.
	else
		srcdir=`echo $top_srcdir/$dir | sed 's:/\.$::'`
	fi
	test -d $dir || mkdir $dir
	cat <<EOT >$dir/Makefile.top
# Makefile.  Generated automatically by configure.

# Search path for source code
VPATH = $srcdir

# Source code directory for this makefile
srcdir = $srcdir

# Top-level source code directory for this package
top_srcdir = $top_srcdir
EOT
	cat $dir/Makefile.top config.mk $TOP_SRCDIR/$dir/Makefile.unix >$dir/Makefile
done
