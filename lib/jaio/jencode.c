/*
 * jencode.c - output encoder
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jencode.c,v 2.0 1996/06/10 08:59:18 ushijima Exp $
 */

#include <config/stdlib.h>
#include <jaio.h>
#include "local.h"


/*
 * Internal function declarations
 */

static int ja_getsize_noconv();
static int ja_encode_noconv();
static int ja_getsize_eucjp();
static int ja_encode_eucjp();
static int ja_getsize_sjis();
static int ja_encode_sjis();
static int ja_getsize_iso2022jp();
static int ja_encode_iso2022jp();


/*
 * Table of coding-system-specific functions
 */

typedef int (*ja_getsize_t)();
typedef int (*ja_encode_t)();

static ja_getsize_t ja_getsize_table[] = {
    ja_getsize_noconv,	/* CSYS_NOCONV */
    ja_getsize_eucjp,		/* CSYS_EUCJP */
    ja_getsize_sjis,		/* CSYS_SJIS */
    ja_getsize_iso2022jp	/* CSYS_ISO2022JP */
};

static ja_encode_t ja_encode_table[] = {
    ja_encode_noconv,		/* CSYS_NOCONV */
    ja_encode_eucjp,		/* CSYS_EUCJP */
    ja_encode_sjis,		/* CSYS_SJIS */
    ja_encode_iso2022jp	/* CSYS_ISO2022JP */
};


/*
 * ja_encode
 *
 * Requires:
 * 	ISIZE is the sizes of INPUT.
 *
 * Effects:
 *   	Returns NULL if CSD has a invalid value or memory allocation
 *	is failed during conversion; otherwise returns a pointer to
 *	the null-terminated character string that is the result of
 *	encoding characters in INPUT with the conding system that
 *	corresponds to CSD.  The resulting string is allocated in a
 *	static area.
 */

char *ja_encode(csd, input, isize)
int csd;			/* coding system descriptor */
ja_char *input;		/* input buffer */
int isize;			/* size of input buffer */
{
    static char *result = NULL;	/* result */
    static int maxresult = 0;	/* maximum size of the result */

    int size;

    if (csd < 0 || csd > MAX_CSYS || csd == CSYS_AUTOCONV) {
	return NULL;
    }
    size = (*ja_getsize_table[csd])(input, isize);
    if (size > maxresult) {
	if (result) {
	    free(result);
	}
	result = (char *) malloc(size);
	if (result == NULL) {
	    return NULL;
	}
	maxresult = size;
    }
    (*ja_encode_table[csd])(input, isize, result);
    return result;
}


/*
 * ja_getsize_noconv
 */

static int ja_getsize_noconv(input, isize)
ja_char *input;
int isize;
{
    return isize + 1;
}


/*
 * ja_encode_noconv - encoding function for CSYS_NOCONV
 */

static int ja_encode_noconv(input, isize, result)
ja_char *input;
int isize;
char *result;
{
    int i, j;

    j = 0;
    for (i = 0; i < isize; i++) {
	result[j++] = input[i];
    }
    result[j] = '\0';
    return 0;
}


/*
 * ja_getsize_eucjp
 */

static int ja_getsize_eucjp(input, isize)
ja_char *input;
int isize;
{
    int size;
    int i;

    size = 0;
    for (i = 0; i < isize; i++) {
	size += (input[i] < 0x80) ? 1 : 2;
    }    
    return size + 1;
}


/*
 * ja_encode_eucjp - encoding function for CSYS_EUCJP
 */

static int ja_encode_eucjp(input, isize, result)
ja_char *input;
int isize;
char *result;
{
    int i, j;
    ja_char c;

    j = 0;
    for (i = 0; i < isize; i++) {
	c = input[i];
	if (c < 0x80) {
	    result[j++] = c;
	} else if (IS_GR(c)) {
	    result[j++] = SS2;
	    result[j++] = GR2GL(c);
	} else {
	    result[j++] = GL2GR(GET_HIGH(c));
	    result[j++] = GL2GR(GET_LOW(c));
	}
    }
    result[j] = '\0';
    return 0;
}


/*
 * ja_getsize_sjis
 */

static int ja_getsize_sjis(input, isize)
ja_char *input;
int isize;
{
    int size;
    int i;

    size = 0;
    for (i = 0; i < isize; i++) {
	size += (input[i] < 0x100) ? 1 : 2;
    }
    return size + 1;
}


/*
 * ja_encode_sjis - encoding function for CSYS_SJIS
 */

static int ja_encode_sjis(input, isize, result)
ja_char *input;
int isize;
char *result;
{
    int i, j;
    ja_char c;

    j = 0;
    for (i = 0; i < isize; i++) {
	c = input[i];
	if (c < 0x100) {
	    result[j++] = c;
	} else {
	    c = ja_jis2sjis(c);
	    result[j++] = GET_HIGH(c);
	    result[j++] = GET_LOW(c);
	}
    }
    result[j] = '\0';
    return 0;
}


/*
 * ja_getsize_iso2022jp
 */

static int ja_getsize_iso2022jp(input, isize)
ja_char *input;
int isize;
{
    int charset;
    int size;
    int i;

    charset = CSET_ASCII;
    size = 0;
    for (i = 0; i < isize; i++) {
	if (input[i] < 0x100) {
	    if (charset != CSET_ASCII) {
		size += 3;
		charset = CSET_ASCII;
	    }
	    size++;
	} else {
	    if (charset != CSET_JISX0208) {
		size += 3;
		charset = CSET_JISX0208;
	    }
	    size += 2;
	}
    }
    if (charset != CSET_ASCII) {
	size += 3;
    }
    return size + 1;
}


/*
 * ja_encode_iso2022jp - encoding function for CSYS_ISO2022JP
 */

static int ja_encode_iso2022jp(input, isize, result)
ja_char *input;
int isize;
char *result;
{
    int charset;
    int i, j;
    ja_char c;

    charset = CSET_ASCII;
    j = 0;
    for (i = 0; i < isize; i++) {
	c = input[i];
	if (c < 0x100) {
	    if (charset != CSET_ASCII) {
		result[j++] = '\033';
		result[j++] = '(';
		result[j++] = FC_ASCII;
		charset = CSET_ASCII;
	    }
	    result[j++] = c;
	} else {
	    if (charset != CSET_JISX0208) {
		result[j++] = '\033';
		result[j++] = '$';
		result[j++] = FC_JISX0208_83;
		charset = CSET_JISX0208;
	    }
	    result[j++] = GET_HIGH(c);
	    result[j++] = GET_LOW(c);
	}
    }
    if (charset != CSET_ASCII) {
	result[j++] = '\033';
	result[j++] = '(';
	result[j++] = FC_ASCII;
    }
    result[j] = '\0';
    return 0;
}
