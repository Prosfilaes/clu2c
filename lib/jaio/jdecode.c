/*
 * jdecode.c - input decoder
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jdecode.c,v 2.0 1996/06/10 08:59:16 ushijima Exp $
 */

#include <config/stdlib.h>
#include <jaio.h>
#include <local.h>


/*
 * Symbolic constants
 */

/* Entries for ja_ctype */

#define CT_GL		0x01	/* graphic character (left) */
#define CT_GR		0x02	/* graphic character (right) */
#define CT_SJIS1	0x04	/* Shift-JIS first byte */
#define CT_SJIS2	0x08	/* Shift-JIS second byte */
#define CT_FCA		0x40	/* final char for ASCII/JIS X 0201-Roman */
#define CT_FCJ		0x80	/* final char for JIS X 0208  */

#define L		CT_GL
#define R		CT_GR
#define S1		CT_SJIS1
#define S2		CT_SJIS2
#define IS		CT_IC_SINGLE
#define IM		CT_IC_MULTI
#define FA		CT_FCA
#define FJ		CT_FCJ

#define CT_GR_SJIS1 (CT_GR | CT_SJIS1)
#define CT_GR_SJIS2 (CT_GR | CT_SJIS2)

/* Transition states */

#define ST_INI	0		/* initial state */
#define ST_GR1	1		/* after GR first byte */
#define ST_SS2	2		/* after single shift to G2 */
#define ST_SJ1	3		/* after Shift-JIS first byte */
#define ST_ESA	4		/* after ESC (from ASCII) */
#define ST_ISA	5		/* after ESC 2/8 (from ASCII) */
#define ST_IMA	6		/* after ESC 2/4 (from ASCII) */
#define ST_JIS	7		/* JIS X 0208 is designated to G0 */
#define ST_GL1	8		/* after GL first byte */
#define ST_ESJ	9		/* after ESC (from JIS) */
#define ST_ISJ	10		/* after ESC 2/8 (from JIS) */
#define ST_IMJ	11		/* after ESC 2/4 (from JIS) */
#define ST_RS1	12		/* after GR or Shift-JIS first byte */


/*
 * Inline functions
 */

/* character type */

#define IN_GL(c)	(ja_ctype[c] & CT_GL)
#define IN_GR(c)	(ja_ctype[c] & CT_GR)
#define IN_SJIS1(c)	(ja_ctype[c] & CT_SJIS1)
#define IN_SJIS2(c)	(ja_ctype[c] & CT_SJIS2)
#define IN_GR_SJIS1(c)	((ja_ctype[c] & CT_GR_SJIS1) == CT_GR_SJIS1)
#define IN_GR_SJIS2(c)	((ja_ctype[c] & CT_GR_SJIS2) == CT_GR_SJIS2)
#define IN_FCA(c)	(ja_ctype[c] & (CT_FCA))
#define IN_FCJ(c)	(ja_ctype[c] & (CT_FCJ))

/* create multibyte character */

#define GL2CHAR(c1, c2)		(((c1) << 8) | (c2))
#define GR2CHAR(c1, c2)		((((c1) & 0x7f) << 8) | ((c2) & 0x7f))
#define SJISCHAR(c1, c2)	ja_sjis2jis(((c1) << 8) | (c2))

/* */

#define PUT1(x)				\
    do {				\
	if (bytes) {			\
	    bytes[n] = i - start;	\
	    start = i;			\
	}				\
	output[n++] = (x);		\
    } while (0)

#define PUT2(x, y)			\
    do {				\
	if (bytes) {			\
	    bytes[n] = i - start - 1;	\
	    bytes[n + 1] = 1;		\
	    start = i;			\
	}				\
	output[n++] = (x);		\
	output[n++] = (y);		\
    } while (0)

#define PUT3(x, y, z)			\
    do {				\
	if (bytes) {			\
	    bytes[n] = i - start - 2;	\
	    bytes[n + 1] = 1;		\
	    bytes[n + 2] = 1;		\
	    start = i;			\
	}				\
	output[n++] = (x);		\
	output[n++] = (y);		\
	output[n++] = (z);		\
    } while (0)

/*
 * Internal function declarations
 */

static int ja_decode_autoconv();
static int ja_decode_iso2022jp();
static int ja_decode_eucjp();
static int ja_decode_sjis();
static int ja_decode_noconv();


/*
 * Internal variables
 */

/* table of character type */

static unsigned char ja_ctype[] = {
    0,       0,       0,       0,       0,       0,       0,       0,
    0,       0,       0,       0,       0,       0,       0,       0,
    0,       0,       0,       0,       0,       0,       0,       0,
    0,       0,       0,       0,       0,       0,       0,       0,
    0,       L,       L,       L,       L,       L,       L,       L,
    L,       L,       L,       L,       L,       L,       L,       L,
    L,       L,       L,       L,       L,       L,       L,       L,
    L,       L,       L,       L,       L,       L,       L,       L,
    L|S2|FJ, L|S2,    L|S2|FA|FJ,L|S2,  L|S2,    L|S2,    L|S2,    L|S2,
    L|S2,    L|S2,    L|S2|FA, L|S2,    L|S2,    L|S2,    L|S2,    L|S2,
    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,
    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,
    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,
    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,
    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,
    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    L|S2,    0,
    S2,      S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,
    S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,
    S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,
    S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,   S1|S2,
    S2,      R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2,
    R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2, R|S1|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,
    R|S2,    R|S2,    R|S2,    R|S2,    R|S2,    R,       R,       0
};

/* table of decode functions */

typedef int (*ja_decode_t)();

static ja_decode_t ja_decode_table[] = {
    ja_decode_noconv,		/* CSYS_NOCONV */
    ja_decode_eucjp,		/* CSYS_EUCJP */
    ja_decode_sjis,		/* CSYS_SJIS */
    ja_decode_iso2022jp,	/* CSYS_ISO2022JP */
    ja_decode_autoconv	/* CSYS_AUTOCONV */
};


/*
 * External functions
 */


/*
 * ja_create_decoder - create input decoder
 *
 * Effects:
 *	Returns a null pointer if CSD is invalid as a coding system
 *	descriptor, or if an error ocurrs in a lower-level function;
 *	otherwise returns a pointer to a new input decoder for the
 *	coding system associated with CSD.
 */

ja_decoder ja_create_decoder(csd)
int csd;
{
    ja_decoder d;

    if (csd < 0 || csd > MAX_CSYS) {
	return NULL;
    }
    d = (ja_decoder) malloc(sizeof(struct ja_decoder_rep));
    if (d == 0) {
	return NULL;
    }
    d->csd = csd;
    d->state = ST_INI;
    d->charset = CSET_ASCII;
    d->pending_size = 0;
    return d;
}


/*
 * ja_reset_decoder - reset decoder
 *
 * Modifies:
 *	The input decoder pointed to by D.
 *
 * Effects:
 *   	Resets the input decoder pointed to by D to its initial
 *	state.
 */

int ja_reset_decoder(d)
ja_decoder d;
{
    d->state = ST_INI;
    d->charset = CSET_ASCII;
    d->pending_size = 0;
    return 0;
}



/*
 * ja_decode
 */

int ja_decode(d, input, input_size, output, output_size, bytes)
ja_decoder d;			/* decoder specific to coding system */
unsigned char *input;		/* input bytes */
int input_size;			/* size of input */
ja_char *output;		/* output characters */
int output_size;		/* maximum of size of output */
unsigned char *bytes;
{
    int n;			/* number of output characters */

    n = (*ja_decode_table[d->csd])(d, input, input_size, output, bytes);

    /*
     * Sets the current character set.
     */
    switch (d->state) {
    case ST_JIS:
    case ST_GL1:
    case ST_ESJ:
    case ST_ISJ:
    case ST_IMJ:
	d->charset = CSET_JISX0208;
	break;
    default:
	d->charset = CSET_ASCII;
    }

    return n;
}


/*
 * ja_flush_decoder
 */

int ja_flush_decoder(d, output)
ja_decoder d;
ja_char *output;
{
    int n;

    for (n = 0; n < d->pending_size; n++) {
	output[n] = d->pending[n];
    }
    d->state = ST_INI;
    d->charset = CSET_ASCII;
    return n;
}


/*
 * Internal functions
 */


/*
 * ja_decode_noconv
 */

static int ja_decode_noconv(d, input, input_size, output, bytes)
ja_decoder d;			/* decoder */
unsigned char *input;		/* input characters */
int input_size;			/* size of INPUT */
ja_char *output;		/* output characters */
unsigned char *bytes;
{
    int n;			/* number of output characters */
    int i;			/* index for INPUT */
    
    n = 0;
    for (i = 0; i < input_size; i++) {
	output[n++] = input[i];
    }
    return n;
}


/*
 * ja_decode_eucjp
 */

static int ja_decode_eucjp(d, input, input_size, output, bytes)
ja_decoder d;			/* decoder */
unsigned char *input;		/* input characters */
int input_size;			/* size of INPUT */
ja_char *output;		/* output characters */
unsigned char *bytes;
{
    unsigned char pc = '\0';	/* previous character */
    int st;			/* state */
    int n;			/* number of output characters */
    int i;			/* index for INPUT */

    if (d->pending_size > 0) {
	pc = d->pending[d->pending_size - 1];
    }
    st = d->state;
    n = 0;

    for (i = 0; i < input_size; i++) {
	unsigned char cc;	/* current character */
	cc = input[i];
	switch (st) {
	case ST_INI:		/* initial state */
	    if (IN_GL(cc)) {
		output[n++] = cc;
	    } else if (IN_GR(cc)) {
		pc = cc;
		st = ST_GR1;
	    } else if (cc == SS2) {
		st = ST_SS2;
	    } else {
		output[n++] = cc;
	    }
	    break;
	case ST_GR1:		/* after GR first byte */
	    if (IN_GR(cc)) {
		output[n++] = GR2CHAR(pc, cc);
	    } else {
		output[n++] = pc;
		output[n++] = cc;
	    }
	    st = ST_INI;
	    break;
	case ST_SS2:		/* after single shift to G2 */
	    if (IN_GR(cc)) {
		output[n++] = cc;
	    } else {
		output[n++] = SS2;
		output[n++] = cc;
	    }
	    st = ST_INI;
	    break;
	}
    }

    switch (st) {
    case ST_INI:
	d->pending_size = 0;
	break;
    case ST_GR1:
	d->pending_size = 1;
	d->pending[0] = pc;
	break;
    case ST_SS2:
	d->pending_size = 1;
	d->pending[0] = SS2;
	break;
    }
    d->state = st;
    return n;
}


/*
 * ja_decode_sjis
 */

static int ja_decode_sjis(d, input, input_size, output, bytes)
ja_decoder d;			/* decoder */
unsigned char *input;		/* input characters */
int input_size;			/* size of INPUT */
ja_char *output;		/* output characters */
unsigned char *bytes;
{
    unsigned char pc = '\0';	/* previous character */
    int st;			/* state */
    int n;			/* number of output characters */
    int i;			/* index for INPUT */

    if (d->pending_size > 0) {
	pc = d->pending[d->pending_size - 1];
    }
    st = d->state;
    n = 0;

    for (i = 0; i < input_size; i++) {
	unsigned char cc;	/* current character */
	cc = input[i];
	switch (st) {
	case ST_INI:		/* initial state */
	    if (IN_GL(cc)) {
		output[n++] = cc;
	    } else if (IN_SJIS1(cc)) {
		pc = cc;
		st = ST_SJ1;
	    } else {
		output[n++] = cc;
	    }
	    break;
	case ST_SJ1:
	    if (IN_SJIS2(cc)) {
		output[n++] = SJISCHAR(pc, cc);
	    } else {
		output[n++] = pc;
		output[n++] = cc;
	    }
	    st = ST_INI;
	    break;
	}
    }

    switch (st) {
    case ST_INI:
	d->pending_size = 0;
	break;
    case ST_SJ1:
	d->pending_size = 1;
	d->pending[0] = pc;
	break;
    }
    d->state = st;
    return n;
}


/*
 * ja_decode_iso2022jp
 */

static int ja_decode_iso2022jp(d, input, input_size, output, bytes)
ja_decoder d;			/* decoder */
unsigned char *input;		/* input characters */
int input_size;			/* size of INPUT */
ja_char *output;		/* output characters */
unsigned char *bytes;
{
    unsigned char pc = '\0';	/* previous character */
    int st;			/* state */
    int n;			/* number of output characters */
    int start, i;		/* index for INPUT */

    if (d->pending_size > 0) {
	pc = d->pending[d->pending_size - 1];
    }
    st = d->state;
    n = 0;
    start = i = 0;

    while (i < input_size) {
	unsigned char cc;	/* current character */
	cc = input[i++];
	switch (st) {
	case ST_INI:		/* initial state */
	    if (IN_GL(cc)) {
		PUT1(cc);
	    } else if (cc == ESC) {
		st = ST_ESA;
	    } else {
		PUT1(cc);
	    }
	    break;
	case ST_JIS:		/* JIS X 0208 is designated to G0 */
	    if (IN_GL(cc)) {
		pc = cc;
		st = ST_GL1;
	    } else if (cc == ESC) {
		st = ST_ESJ;
	    } else {
		PUT1(cc);
		st = ST_JIS;
	    }
	    break;
	case ST_GL1:		/* after GL first byte */
	    if (IN_GL(cc)) {
		PUT1(GL2CHAR(pc, cc));
	    } else {
		PUT2(pc, cc);
	    }
	    st = ST_JIS;
	    break;
	case ST_ESA:		/* after ESC (from ASCII) */
	    if (cc == ICM) {
		st = ST_IMA;
	    } else if (cc == ICS) {
		st = ST_ISA;
	    } else {
		PUT2(ESC, cc);
		st = ST_INI;
	    }
	    break;
	case ST_IMA:		/* after ESC 02/04 (from ASCII) */
	    if (IN_FCJ(cc)) {
		st = ST_JIS;
	    } else {
		PUT3(ESC, ICM, cc);
		st = ST_INI;
	    }
	    break;
	case ST_ESJ:		/* after ESC (from JIS) */
	    if (cc == ICS) {
		st = ST_ISJ;
	    } else if (cc == ICM) {
		st = ST_IMJ;
	    } else {
		PUT2(ESC, cc);
		st = ST_JIS;
	    }
	    break;
	case ST_ISJ:		/* after ESC 2/8 (from JIS) */
	    if (IN_FCA(cc)) {
		st = ST_INI;
	    } else {
		PUT3(ESC, ICS, cc);
		st = ST_JIS;
	    }
	    break;
	case ST_ISA:		/* after ESC 02/08 (from ASCII) */
	    if (!IN_FCA(cc)) {
		PUT3(ESC, ICS, cc);
	    }
	    st = ST_INI;
	    break;
	case ST_IMJ:		/* after ESC 2/4 (from JIS) */
	    if (!IN_FCJ(cc)) {
		PUT3(ESC, ICM, cc);
	    }
	    st = ST_JIS;
	    break;
	}
    }

    switch (st) {
    case ST_INI:
    case ST_JIS:
	d->pending_size = 0;
	break;
    case ST_GL1:
	d->pending_size = 1;
	d->pending[0] = pc;
	break;
    case ST_ESA:
    case ST_ESJ:
	d->pending_size = 1;
	d->pending[0] = ESC;
	break;
    case ST_IMA:
    case ST_IMJ:
	d->pending_size = 2;
	d->pending[0] = ESC;
	d->pending[1] = ICM;
	break;
    case ST_ISA:
    case ST_ISJ:
	d->pending_size = 2;
	d->pending[0] = ESC;
	d->pending[1] = ICS;
	break;
    }
    d->state = st;
    return n;
}


/* ja_decode_autoconv */

static int ja_decode_autoconv(d, input, input_size, output, bytes)
ja_decoder d;			/* decoder */
unsigned char *input;		/* input characters */
int input_size;			/* size of INPUT */
ja_char *output;		/* output characters */
unsigned char *bytes;
{
    unsigned char pc = '\0';	/* previous character */
    int st;			/* state */
    int n;			/* number of output characters */
    int n_ambiguous;		/* number of ambiguous characters */
    int n_eucjp;		/* number of JIS char in Japanese EUC */
    int n_sjis;			/* number of JIS char in Shift-JIS */
    int start, i;		/* index for INPUT */
    unsigned char cc;		/* current character */

    if (d->pending_size > 0) {
	pc = d->pending[d->pending_size - 1];
    }
    st = d->state;
    n = 0;

    n_ambiguous = 0;
    n_eucjp = 0;
    n_sjis = 0;

    start = i = 0;

    switch (st) {
    case ST_INI:
	goto L_INI;
    case ST_JIS:
	goto L_JIS;
    case ST_GL1:
	goto L_GL1;
    case ST_GR1:
	goto L_GR1;
    case ST_SJ1:
	goto L_SJ1;
    case ST_ESA:
	goto L_ESA;
    case ST_IMA:
	goto L_IMA;
    case ST_ESJ:
	goto L_ESJ;
    case ST_ISJ:
	goto L_ISJ;
    case ST_ISA:
	goto L_ISA;
    case ST_IMJ:
	goto L_IMJ;
    case ST_RS1:
	goto L_RS1;
    }

 L_INI:				/* initial state */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_INI;
	goto L_END;
    }
    if (IN_GL(cc)) {
	PUT1(cc);
	goto L_INI;
    } else if (cc == ESC) {
	goto L_ESA;
    } else if (IN_GR_SJIS1(cc)) {
	pc = cc;
	goto L_RS1;
    } else if (IN_GR(cc)) {
	pc = cc;
	goto L_GR1;
    } else if (IN_SJIS1(cc)) {
	pc = cc;
	goto L_SJ1;
    } else {
	PUT1(cc);
	goto L_INI;
    }

 L_JIS:				/* JIS X 0208 is designated to G0 */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_JIS;
	goto L_END;
    }
    if (IN_GL(cc)) {
	pc = cc;
	goto L_GL1;
    } else if (cc == ESC) {
	goto L_ESJ;
    } else {
	PUT1(cc);
	goto L_JIS;
    }

 L_GL1:				/* after GL first byte */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_GL1;
	goto L_END;
    }
    if (IN_GL(cc)) {
	PUT1(GL2CHAR(pc, cc));
    } else {
	PUT2(pc, cc);
    }
    goto L_JIS;

 L_GR1:				/* after GR first byte */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_GR1;
	goto L_END;
    }
    if (IN_GR(cc)) {
	PUT1(GR2CHAR(pc, cc));
	n_eucjp++;
    } else {
	PUT2(pc, cc);
    }
    goto L_INI;

 L_SJ1:				/* after Shift-JIS first byte */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_SJ1;
	goto L_END;
    }
    if (IN_SJIS2(cc)) {
	PUT1(SJISCHAR(pc, cc));
	n_sjis++;
    } else {
	PUT2(pc, cc);
    }
    goto L_INI;

 L_ESA:				/* after ESC (from ASCII) */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_ESA;
	goto L_END;
    }
    if (cc == ICM) {
	goto L_IMA;
    } else if (cc == ICS) {
	goto L_ISA;
    } else {
	PUT2(ESC, cc);
	goto L_INI;
    }

 L_IMA:				/* after ESC 2/4 (from ASCII) */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_IMA;
	goto L_END;
    }
    if (IN_FCJ(cc)) {
	goto L_JIS;
    } else {
	PUT3(ESC, ICM, cc);
	goto L_INI;
    }

 L_ESJ:				/* after ESC (from JIS) */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_ESJ;
	goto L_END;
    }
    if (cc == ICS) {
	goto L_ISJ;
    } else if (cc == ICM) {
	goto L_IMJ;
    } else {
	PUT2(ESC, cc);
	goto L_JIS;
    }

 L_ISJ:				/* after ESC 2/8 (from JIS) */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_ISJ;
	goto L_END;
    }
    if (IN_FCA(cc)) {
	goto L_INI;
    } else {
	PUT3(ESC, ICS, cc);
	goto L_JIS;
    }

 L_ISA:				/* after ESC 2/8 (from ASCII) */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_ISA;
	goto L_END;
    }
    if (!IN_FCA(cc)) {
	PUT3(ESC, ICS, cc);
    }
    goto L_INI;

 L_IMJ:				/* after ESC 2/4 (from JIS) */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_IMJ;
	goto L_END;
    }
    if (!IN_FCJ(cc)) {
	PUT3(ESC, ICM, cc);
    }
    goto L_JIS;

 L_RS1:				/* after GR for Shift-JIS first byte */
    if (i < input_size) {
	cc = input[i++];
    } else {
	st = ST_RS1;
	goto L_END;
    }
    if (IN_GR_SJIS2(cc)) {
	PUT1((pc << 8) | cc);
	n_ambiguous++;
    } else if (IN_GR(cc)) {
	PUT1(GR2CHAR(pc, cc));
	n_eucjp++;
    } else if (IN_SJIS2(cc)) {
	PUT1(SJISCHAR(pc, cc));
	n_sjis++;
    } else {
	PUT2(pc, cc);
    }
    goto L_INI;

 L_END:

    /*
     * Fixes ambiguous characters, if any.
     */
    if (n_ambiguous > 0) {
	ja_char c;
	if (n_sjis > n_eucjp) {
	    for (i = 0; i < n; i++) {
		c = output[i];
		if (c < 0) {
		    output[i] = ja_sjis2jis(c & 0xffff);
		}
	    }
	} else {
	    for (i = 0; i < n; i++) {
		c = output[i];
		if (c < 0) {
		    output[i] = c & 0x7f7f;
		}
	    }
	}
    }

    switch (st) {
    case ST_INI:
    case ST_JIS:
	d->pending_size = 0;
	break;
    case ST_GL1:
    case ST_GR1:
    case ST_SJ1:
    case ST_RS1:
	d->pending_size = 1;
	d->pending[0] = pc;
	break;
    case ST_ESA:
    case ST_ESJ:
	d->pending_size = 1;
	d->pending[0] = ESC;
	break;
    case ST_IMA:
    case ST_IMJ:
	d->pending_size = 2;
	d->pending[0] = ESC;
	d->pending[1] = ICM;
	break;
    case ST_ISA:
    case ST_ISJ:
	d->pending_size = 2;
	d->pending[0] = ESC;
	d->pending[1] = ICS;
	break;
    }
    d->state = st;
    return n;
}
