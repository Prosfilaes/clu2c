/*
 * mkdfltrt.c - create dfltroot.h
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: mkdfltrt.c,v 2.0 1996/06/10 09:02:28 ushijima Exp $
 */

#include <stdio.h>

#define OUTPUT "dfltroot.h"

main(argc, argv)
int argc;
char *argv[];
{
    char clu2c_rootdir[256], *p, *q;
    FILE *fp;

    if (argc != 2) {
	fprintf(stderr, "usage: mkdfltrt CLU2C-ROOTDIR\n");
	exit(2);
    }
    printf("creating %s\n", OUTPUT);
    for (p = argv[1], q = clu2c_rootdir; *p != '\0'; p++) {
	switch (*p) {
	case '\\':
	    *q++ = *p;
	    *q++ = *p;
	    break;
	default:
	    *q++ = *p;
	}
    }
    *q = '\0';
    fp = fopen(OUTPUT, "w");
    if (fp == NULL) {
	perror("Can't open dfltroot.h");
	exit(1);
    }
    fprintf(fp, "#define CLU2C_ROOTDIR \"%s\"\n", clu2c_rootdir);
    fclose(fp);
    exit(0);
}
