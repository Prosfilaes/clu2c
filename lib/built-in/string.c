/*
 * string.c - implementation of string
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: string.c,v 2.26 1996/10/07 07:41:30 ushijima Exp $
 */

#include <config/string.h>

#include <clu2c.h>
#include <stdio.h>
#include "array.h"
#include "string.h"

#ifdef J10N
#   error
#endif


/*
 * Own variables
 */

#ifdef J10N

static ja_decoder WVstring_Ddecoder = NULL;
static ja_char *WVstring_Dbuf = NULL;
static int WVstring_Dbufsize = ja_BUFSIZ;

#endif /* J10N */


/*
 * Internal routines implemented as macros
 */


/*
 * _setsize
 */

#if CLU2C_STRING_VERSION == 1
#   define OMstring_D__setsize(s, n)	(s)[(n)] = '\0'
#endif
#if CLU2C_STRING_VERSION == 2
#   define OMstring_D__setsize(s, n)	(s)[0] = (n)
#endif
#if CLU2C_STRING_VERSION == 3
#   define OMstring_D__setsize(s, n)	(s)->size = (n)
#endif


/*
 * _subcopy - copy characters actually
 *
 * Requires:
 *	S1 points to a (possibly incomplete) string allocated using
 *	the OFstring_D__alloc function.  S2 points to a complete
 *	string.  S1 is not the same as S2.  I1 and I2 is a positive
 *	integer.  The string pointed to by S1 can contain I1 +
 *	Size(S2) - I2 characters.
 *
 * Modifies:
 *	The string pointed to by S1.
 *
 * Effects:
 *	Changes the string pointed to by S1 so that Fetch(S1, I1 + J)
 *	is equal to Fetch(S2, I2 + J) for all J such that 0 <= J <= N -
 *	1, where Fetch(S, K) and Size(S) are the results of
 *	string$fetch(S, K) and string$size(S), respectively, viewed as
 *	S being CLU string and K being CLU int.
 */

#if CLU2C_STRING_VERSION == 1
#   define OMstring_D__subcopy(s1, i1, s2, i2, n)			\
	strncpy((s1) + (i1) - 1, (s2) + (i2) - 1, (n))
#endif
#if CLU2C_STRING_VERSION == 2
#   define OMstring_D__subcopy(s1, i1, s2, i2, n)			\
	memcpy((char *) ((s1) + (i1)),					\
	       (char *) ((s2) + (i2)),					\
	       (n) * sizeof(char_t))
#endif
#if CLU2C_STRING_VERSION == 3
#   define OMstring_D__subcopy(s1, i1, s2, i2, n)			\
	memcpy((char *) ((s1)->chars + (i1) - 1),			\
	       (char *) ((s2)->chars + (i2) - 1),			\
	       (n) * sizeof(char_t))
#endif


/*
 * _store - store character in string
 *
 * Requires:
 *	1 <= I <= string$size(S).
 *
 * Modifies:
 *	The string pointed to by S.
 *
 * Effects:
 * 	Changes the string pointed to by S so that the I'th character
 *	is equal to C.
 */

#if CLU2C_STRING_VERSION == 1
#   define OMstring_D__store(s, i, c)	(s)[(i) - 1] = (c)
#endif
#if CLU2C_STRING_VERSION == 2
#   define OMstring_D__store(s, i, c)	(s)[(i)] = (c)
#endif
#if CLU2C_STRING_VERSION == 3
#   define OMstring_D__store(s, i, c)	(s)->chars[(i) - 1] = (c)
#endif


/*
 * internal routines implemented as functions
 */


/*
 * _alloc - allocate memory for string object 
 *
 * Requires:
 *	SIZE is a positive integer.
 *
 * Effects:
 *	Returns a pointer to a new memory area that can contain at
 *	least SIZE characters.  Initialization of each component
 *	character is left to the caller.
 */

static string OFstring_D__alloc(int size)
{
    string result;

    result = (string) malloc_atomic(STRING_ALLOC_SIZE(size));
    OMstring_D__setsize(result, size);
    return result;
}


#ifdef J10N

/*
 */

static OFstring_D__setupbuf(int size)
{
    if (WVstring_Dbuf && WVstring_Dbufsize >= size) {
	return;
    }
    if (WVstring_Dbufsize < size) {
	WVstring_Dbufsize = size;
    }
    if (WVstring_Dbuf) {
	WVstring_Dbuf = (ja_char *)
	    realloc(WVstring_Dbuf, WVstring_Dbufsize * sizeof(ja_char));
    } else {
	WVstring_Dbuf = (ja_char *)
	    malloc_atomic(WVstring_Dbufsize * sizeof(ja_char));
    }
}

#endif /* J10N */


/*
 * Operations
 */


/*
 * size = proc(s: string) returns(int)
 */

int OFstring_Dsize(string s)
{
    RETURN1(OMstring_Dsize(s));
}


/*
 * empty = proc(s: string) returns(bool)
 */

int OFstring_Dempty(string s)
{
    RETURN1(OMstring_Dempty(s));
}


/*
 * indexs = proc(s1, s2: string) returns(int)
 */

int OFstring_Dindexs(string s1, string s2)
{
    int c, size;
    char_t *p0, *p;
#if CLU2C_STRING_VERSION > 1
    char_t *limit;
    int i;
#endif

    /*
     * The result is 1 if S1 is empty.
     */
    if (OMstring_Dempty(s1)) {
	RETURN1(1);
    }

    c = OMstring_Dfetch(s1, 1);
    size = OMstring_Dsize(s1);

    /* 
     * If C occurs in S2, makes P point to the first occurrence of C;
     * otherwise sets P to the null pointer.
     */
#if CLU2C_STRING_VERSION == 1
    p0 = s2;
    p = strchr(s2, c);
#else
    p0 = p = OMstring_D__chars(s2);
    if (p) {
	limit = p + OMstring_Dsize(s2) - size + 1;
	while (p < limit && *p != c) {
	    p++;
	}
	if (p >= limit) {
	    p = NULL;
	}
    }
#endif

    while (p != NULL) {
	int match;

#if CLU2C_STRING_VERSION == 1
	match = (strncmp(p, s1, size) == 0);
#else
	match = TRUE;
	for (i = 1; i < size; i++) {
	    if (p[i] != OMstring_Dfetch(s1, i + 1)) {
		match = FALSE;
		break;
	    }
	}
#endif
	if (match) {
	    RETURN1(p - p0 + 1);
	}

	/*
	 * Makes P to the next occurrence of C in S2 (set to the null
	 * pointer when no more occurrence is found).
	 */
#if CLU2C_STRING_VERSION == 1
	p = strchr(p + 1, c);
#else
	p++;
	while (p < limit && *p != c) {
	    p++;
	}
	if (p >= limit) {
	    p = NULL;
	}
#endif

    }

    /*
     * S1 does not occur in S2.
     */
    RETURN1(0);
}


/*
 * indexc = proc(c: char, s: string) returns(int)
 */

int OFstring_Dindexc(int c, string s)
{
#if CLU2C_STRING_VERSION == 1
    char *p;

    /*
     * Any string cannot contain a null character due to the
     * limitation of the string representation.
     */
    if (c == '\0') {
	RETURN1(0);
    }

    p = strchr(s, c);
    RETURN1(p == NULL ? 0 : p - s + 1);
#else
    int i;

    for (i = 1; i <= OMstring_Dsize(s); i++) {
	if (OMstring_Dfetch(s, i) == c) {
	    RETURN1(i);
	}
    }
    RETURN1(0);
#endif
}


/*
 * c2s = proc(c: char) returns(string)
 */

int OFstring_Dc2s(int c)
{
    string res;
  
    res = OFstring_D__alloc(1);
    OMstring_D__store(res, 1, c);
    RETURN1(res);
}


/*
 * concat = proc(s1, s2: string) returns(string)
 */

int OFstring_Dconcat(string s1, string s2)
{
    int size;			/* size of result */
    string res;			/* result */

    size = OMstring_Dsize(s1) + OMstring_Dsize(s2);
    if (size <= 0) {
	res = SLNULL;
    } else {
	res = OFstring_D__predict(size);
	OFstring_D__concat(res, s1);
	OFstring_D__concat(res, s2);
    }
    RETURN1(res);
}


/*
 * append = proc(s: string, c: char) returns(string)
 */

int OFstring_Dappend(string s, int c)
{
    int size;			/* size of S */
    string result;		/* result */

    size = OMstring_Dsize(s);
    result = OFstring_D__alloc(size + 1);
    OMstring_D__subcopy(result, 1, s, 1, size);
    OMstring_D__store(result, size + 1, c);
    RETURN1(result);
}


/*
 * fetch = proc(s: string, i: int) returns(char)
 */

int OFstring_Dfetch(string s, int i)
{
    if (OMstring_Dbounds(s, i)) {
	SIGNAL0(SLBOUNDS);
    }
    RETURN1(OMstring_Dfetch(s, i));
}


/*
 * rest = proc(s: string, i: int) returns(string) signals(bounds)
 */

int OFstring_Drest(string s, int i)
{
    string result;
    int size;

    size = OMstring_Dsize(s);
    if (i < 1 || size + 1 < i) {
	SIGNAL0(SLBOUNDS);
    } else if (i == 1) {
	RETURN1(s);
    } else if (i == size + 1) {
	RETURN1(SLNULL);
    }
    size = size - i + 1;
    result = OFstring_D__alloc(size);
    OMstring_D__subcopy(result, 1, s, i, size);
    RETURN1(result);
}


/*
 * substr = proc(s: string, at, cnt: int) returns(string)
 *          signals(bounds, negative_size)
 */

int OFstring_Dsubstr(string s, int at, int cnt)
{
    int size;			/* size of S */
    int rsize;			/* size of result */
    string res;			/* result */

    size = OMstring_Dsize(s);

    /*
     * Checks against exceptional conditions.
     */
    if (cnt < 0) {
	SIGNAL0(SLNEGATIVE_SIZE);
    } else if (at < 1 || size + 1 < at) {
	SIGNAL0(SLBOUNDS);
    }

    rsize = (size - at + 1 < cnt) ? (size - at + 1) : cnt;
    if (rsize == 0) {
	RETURN1(SLNULL);
    }
    res = OFstring_D__alloc(rsize);
    OMstring_D__subcopy(res, 1, s, at, rsize);
    RETURN1(res);
}	


/*
 * s2ac = proc(s: string) returns(array[char])
 */

int OFstring_Ds2ac(string s)
{
    int size;			/* size of S */
    array res;
    int i;
    
    size = OMstring_Dsize(s);
    OFarray_Dpredict(1, size);
    res = (array) retval_area[0];
    for (i = 1; i <= size; i++) {
	OFarray_Daddh(res, OMstring_Dfetch(s, i));
    }
    RETURN1(res);
}


/*
 * ac2s = proc(a: array[char]) returns(string)
 */

int OFstring_Dac2s(array a)
{
    int low;			/* low bound of A */
    int size;			/* size of A and result */
    string res;			/* result */
    int i;

    low = OMarray_Dlow(a);
    size = OMarray_Dsize(a);
    if (size == 0) {
	RETURN1(SLNULL);
    }
    res = OFstring_D__alloc(size);
    for (i = 0; i < size; i++) {
	OMstring_D__store(res, 1 + i, OMarray_Dfetch(a, low + i));
    }
    RETURN1(res);
}


/*
 * s2sc = proc(s: string) returns(sequence[char])
 */

int OFstring_Ds2sc(string s)
{
    int size;			/* size of S and result */
    sequence res;		/* result */
    int i;			/* index */

    size = OMstring_Dsize(s);
    res = OFsequence_D__alloc(size);
    for (i = 1; i <= size; i++) {
	OMsequence_D__store(res, i, OMstring_Dfetch(s, i));
    }
    RETURN1(res);
}


/*
 * sc2s = proc(s: sequence[char]) returns(string)
 */

int OFstring_Dsc2s(sequence s)
{
    int size;			/* size of S and result */
    string res;			/* result */
    int i;			/* index */

    size = OMsequence_Dsize(s);
    if (size == 0) {
	RETURN1(SLNULL);
    }
    res = OFstring_D__alloc(size);
    for (i = 1; i <= size; i++) {
	OMstring_D__store(res, i, OMsequence_Dfetch(s, i));
    }
    RETURN1(res);
}


/*
 * chars = iter(s: string) yields(char)
 */

#define ARSIZE	3
#define LVs	((*ivarp)[0])
#define LVsize	((*ivarp)[1])
#define LVi	((*ivarp)[2])

int OFstring_Dchars(bool init, object **ivarp, string s)
{
    /*
     * Iterator prologue.
     */
    if (init) {
	/* initial iterator call */
	*ivarp = (object *) malloc(ARSIZE * sizeof(object));
	LVs = (object) s;
    } else {
	goto resume1;
    }

    /*
     * Iterator body.
     */
    LVsize = OMstring_Dsize(LVs);
    for (LVi = 1; LVi <= LVsize; LVi++) {
	retval_area[0] = OMstring_Dfetch(LVs, LVi);
	return YIELD;
    resume1:
	NO_OPERATION;
    }
    return RET;
}

#undef ARSIZE
#undef LVs
#undef LVsize
#undef LVi


/*
 * lt = proc(s1, s2: string) returns(bool)
 */

int OFstring_Dlt(string s1, string s2)
{
    RETURN1(OMstring_Dlt(s1, s2));
}


/*
 * le = proc(s1, s2: string) returns(bool)
 */

int OFstring_Dle(string s1, string s2)
{
    RETURN1(OMstring_Dle(s1, s2));
}


/*
 * ge = proc(s1, s2: string) returns(bool)
 */

int OFstring_Dge(string s1, string s2)
{
    RETURN1(OMstring_Dge(s1, s2));
}


/*
 * gt = proc(s1, s2: string) returns(bool)
 */

int OFstring_Dgt(string s1, string s2)
{
    RETURN1(OMstring_Dgt(s1, s2));
}


/*
 * equal = proc(s1, s2: string) returns(bool)
 */

int OFstring_Dequal(string s1, string s2)
{
    RETURN1(OMstring_Dequal(s1, s2));
}


/*
 * similar = proc(s1, s2: string)returns(bool)
 */

int OFstring_Dsimilar(string s1, string s2)
{
    RETURN1(OMstring_Dsimilar(s1, s2));
}


/*
 * copy = proc(s: string) returns(string)
 */

int OFstring_Dcopy(string s)
{
    RETURN1(OMstring_Dcopy(s));
}


/*
 * print = proc(s: string, pst: pstream)
 */

int OFstring_Dprint(string s, object pst)
{
    static string ldots = NULL;
    static string bhat = NULL;
    static string bexclamation = NULL;
    static string bampersand= NULL;
    static string backslash= NULL;

    int lim, count;

    if (ldots == NULL) {
	ldots = OFstring_D__cs2s("...");
	bhat = OFstring_D__cs2s("\\^");
	bexclamation = OFstring_D__cs2s("\\!");
	bampersand= OFstring_D__cs2s("\\&");
	backslash= OFstring_D__cs2s("\\");
    }

    if (OFpstream_Dget__max__width(pst) == SIG) {
	out_handler();
	return(SIG);
    }
    lim = (int) retval_area[0];
    lim = lim * 16 + 4;		/* ??? */
    if (OFpstream_Dtextc(pst, '"') == SIG) {
	out_handler();
	return(SIG);
    }
    count = OMstring_Dsize(s);
    if (count > 0) {
	int i;
	for (i = 1; i <= count; i++) {
	    int nthch, lowch, outch;
	    string prefix;
	    bool meta;
	    if (i >= lim) {
		if ( OFpstream_Dtext(pst, ldots) == SIG ) { /* "..." */
		    out_handler();
		    return(SIG);
		}
		break;
	    }
	    nthch = OMstring_Dfetch(s, i);
	    prefix = SLNULL;
	    meta = FALSE;
	    if (nthch >= 0x100) {
		char *form = (char *) malloc_atomic(7);
		sprintf(form, "\\x%04x", nthch);
		if (OFpstream_Dtext(pst, OFstring_D__cs2s(form)) == SIG) {
		    out_handler();
		    return SIG;
		}
		continue;
	    }
	    if (nthch & 0x80) {
		meta = TRUE;
	    }
	    lowch = nthch & 0x7f;
	    outch = lowch;
	    if (lowch == '\177') {
		prefix = bhat;	/* "\\^" */
		if (meta) {
		    prefix = bexclamation; /* "\\!" */
		}
		outch = '?';
	    } else if (lowch == '"' || lowch == '\\') {
		if (meta) {
		    prefix = bampersand; /* "\\&" */
		} else {
		    prefix = backslash;	/* "\\" */
		}
	    } else if (lowch >= ' ') {
		if (meta) {
		    prefix = bampersand; /* "\\&" */
		}
	    } else if (meta) {
		prefix = bampersand; /* "\\!" */
		outch += 0x40;
	    } else if (outch == '\n') {
		prefix = backslash;	/* "\\" */
		outch = 'n';
	    } else if (outch == '\t') {
		prefix = backslash;	/* "\\" */
		outch = 't';
	    } else if (outch == '\f') {
		prefix = backslash;	/* "\\" */
		outch = 'p';
	    } else if (outch == '\b') {
		prefix = backslash;	/* "\\" */
		outch = 'b';
	    } else if (outch == '\r') {
		prefix = backslash;	/* "\\" */
		outch = 'r';
	    } else if (outch == '\v') {
		prefix = backslash;	/* "\\" */
		outch = 'v';
	    } else {
		prefix = bhat;	/* "\\^" */
		outch += 0x40;
	    }
	    if (OFpstream_Dtext(pst, prefix) == SIG) {
		out_handler();
		return SIG;
	    }
	    if (OFpstream_Dtextc(pst, outch) == SIG) {
		out_handler();
		return SIG;
	    }
	}
    }
    if (OFpstream_Dtextc(pst, '"') == SIG) {
	out_handler();
	return SIG;
    }
    return RET;
}

 
/*
 * encode = proc(s: string, ist: istream) signals(not_possible(string))
 */

int OFstring_Dencode(string s, object ist)
{
    int size;			/* size of S */
    int i;			/* index */

    size = OMstring_Dsize(s);
    if (OFistream_Dputi(ist, size) == SIG) {
	return SIG;
    }
    for (i = 1; i <= size; i++) {
	if (OFistream_Dputi(ist, OMstring_Dfetch(s, i)) == SIG) {
	    return SIG;
	}
    }
    return RET;
}


/*
 * decode = proc(ist: istream) returns(string)
 *          signals(end_of_file, not_possible(string))
 */

int OFstring_Ddecode(object ist)
{
    int size;			/* size of result */
    int i;			/* index */
    string res;			/* result */

    if (OFistream_Dgeti(ist) == SIG) {
	return SIG;
    }
    size = (int) retval_area[0];
    if (size < 0) {
	SIGNAL1(SLNOT_POSSIBLE, OFstring_D__cs2s("bad format"));
    } else if (size == 0) {
	res = SLNULL;
    } else {
	res = OFstring_D__alloc(size);
	for (i = 1; i <= size; i++) {
	    if (OFistream_Dgeti(ist) == SIG) {
		return SIG;
	    }
	    OMstring_D__store(res, i, retval_area[0]);
	}
    }
    RETURN1(res);
}


/*
 * _gcd = proc(s: string, tab: gcd_tab) returns(int)
 */

int OFstring_D__gcd(string s, object tab)
{
    SIGNAL1(SLFAILURE, OFstring_D__cs2s("string$_gcd: not implemented"));
}


/*
 * width = proc(s: string) returns(int)
 */

int OFstring_Dwidth(string s)
{
    int res;			/* result */
    int size;			/* size of S */
    int i;			/* index */

    res = 0;
    size = OMstring_Dsize(s);
    for (i = 1; i <= size; i++) {
	res += OMchar_Dwidth(OMstring_Dfetch(s, i));
    }
    RETURN1(res);
}


/*
 * Hidden operations
 */


/*
 * _cmp - compare two strings
 *
 * Requires:
 *	S1 and S2 are both pointers to valid string objects.
 *
 * Effects:
 *	Compares the two strings pointed to by S1 and S2, and returns
 *	an integer greater than, equal to, or less than 0, according
 *	as the string pointed to by S1 is lexicographically greater
 *	than, equal to, or less than the string pointed to by S2.
 *
 * Note:
 *   	This operation is for Japanized string only.  The strcmp
 *	function is sufficient for comparison of non-Japanized
 *	strings.
 */

int OFstring_D__cmp(string s1, string s2)
{
    int size1, size2, min, i, cmp;
    char_t *chars1, *chars2;

#if CLU2C_STRING_VERSION == 1
    return strcmp(s1, s2);
#else
    size1 = OMstring_Dsize(s1);
    size2 = OMstring_Dsize(s2);
    min = OMint_Dmin(size1, size2);
    chars1 = OMstring_D__chars(s1);
    chars2 = OMstring_D__chars(s2);
    for (i = 0; i < min; i++) {
	cmp = chars1[i] - chars2[i];
	if (cmp != 0) {
	    return cmp;
	}
    }
    return size1 - size2;
#endif
}


/*
 * _equal
 */

int OFstring_D__equal(string s1, string s2)
{
#if CLU2C_STRING_VERSION == 1
    return strcmp(s1, s2) == 0;
#else
    if (OMstring_Dsize(s1) != OMstring_Dsize(s2)) {
	return FALSE;
    }
    return MEMEQ((char *) OMstring_D__chars(s1),
		 (char *) OMstring_D__chars(s2),
		 OMstring_Dsize(s1) * sizeof(char_t));
#endif
}


/*
 * _s2cs - convert CLU string into C string
 *
 * Effects:
 *   	Returns the C string that contains the same character sequence
 *	as S.
 */

char *OFstring_D__s2cs(string s)
{
    char *result;
#if CLU2C_STRING_VERSION != 1
    int size;			/* size of S */
    int i;			/* index */
#ifdef J10N
    char *output;		/* output from decoder */
#endif
#endif

#if CLU2C_STRING_VERSION == 1
    result = s;
#else  /* CLU2C_STRING_VERSION != 1 */
    size = OMstring_Dsize(s);
#ifdef J10N
#if CLU2C_CHAR_VERSION == 2
#   define INPUT OMstring_D__chars(s)
#else  /* CLU2C_CHAR_VERSION != 2 */
#   define INPUT WVstring_Dbuf
    OFstring_D__setupbuf(size);
    for (i = 0; i < size; i++) {
	WVstring_Dbuf[i] = OMstring_Dfetch(s, i + 1);
    }
#endif /* CLU2C_CHAR_VERSION != 2 */
    output = ja_encode(DEFAULT_OUTPUT_CODING_SYSTEM, INPUT, size);
    if (!output) {
	result = 0;
    } else {
	result = (char *) malloc_atomic(strlen(output) + 1);
	if (result) {
	    strcpy(result, output);
	}
    }
#else  /* not J10N */
    result = (char *) malloc_atomic(size + 1);
    if (result) {
#if CLU2C_CHAR_VERSION == 1
	strncpy(result, OMstring_D__chars(s), size);
#else  /* CLU2C_CHAR_VERSION != 1 */
	for (i = 0; i < size; i++) {
	    result[i] = OMstring_Dfetch(s, i + 1);
	}
#endif /* CLU2C_CHAR_VERSION != 1 */
	result[size] = '\0';
    }
#endif /* not J10N */
#endif /* CLU2C_STRING_VERSION != 1 */
    return result;
}


/*
 * _cs2s - convert C string into CLU string
 *
 * Effects:
 *   	Returns the CLU string that contains the same character
 *	sequence as S.
 */

string OFstring_D__cs2s(char *s)
{
    string result;
#if CLU2C_STRING_VERSION != 1
#ifdef J10N
    int len;			/* length of S */
#endif
    int size;			/* size of the result */
    int i;
#endif

    if (s[0] == '\0') {
	return SLNULL;
    }
#if CLU2C_STRING_VERSION == 1
    result = s;
#else  /* CLU2C_STRING_VERSION != 1 */
#ifdef J10N
    if (!WVstring_Ddecoder) {
	WVstring_Ddecoder = ja_create_decoder(DEFAULT_INPUT_CODING_SYSTEM);
    }
    len = strlen(s);
    OFstring_D__setupbuf(len + 1);
    size = ja_decode(WVstring_Ddecoder,
		       s,
		       len,
		       WVstring_Dbuf,
		       WVstring_Dbufsize,
		       NULL);
    size += ja_flush_decoder(WVstring_Ddecoder, WVstring_Dbuf + size);
    result = OFstring_D__alloc(size);
#if CLU2C_CHAR_VERSION == 2
    memcpy((char *) OMstring_D__chars(result),
	   (char *) WVstring_Dbuf,
	   size * sizeof(char_t));
#else  /* CLU2C_CHAR_VERSION != 2 */
    for (i = 0; i < size; i++) {
	OMstring_D__store(result, i + 1, WVstring_Dbuf[i]);
    }
#endif /* CLU2C_CHAR_VERSION != 2 */
#else  /* not J10N */
    size = strlen(s);
    result = OFstring_D__alloc(size);
#if CLU2C_CHAR_VERSION == 1
    strncpy(OMstring_D__chars(result), s, size);
#else  /* CLU2C_CHAR_VERSION != 1 */
    for (i = 0; i < size; i++) {
	OMstring_D__store(result, i + 1, s[i]);
    }
#endif /* CLU2C_CHAR_VERSION != 1 */
#endif /* not J10N */
#endif /* CLU2C_STRING_VERSION != 1 */
    return result;
}


/*
 * _copy - make a copy of C string
 *
 * Effects:
 *	Returns a new C string that is the same as S.
 *
 * Note:
 *	This operation is for non-Japanized string only, and needed to
 *	convert a C string located at static data area.  Since the
 *	_cs2s operation in non-Japanized string is NOP, an explicit
 *	copy is required for such a string.  The convention used for a
 *	static string is:
 *
 *		OFstring_D__cs2s(OFstring_D__copy(...))
 *
 *	This code will do for both Japanized and non-Japanized CLU2C,
 *	without creating any extra garbage.
 */

char *OFstring_D__copy(char *s)
{
    char *result;

#if CLU2C_STRING_VERSION == 1
    result = (char *) malloc_atomic(strlen(s) + 1);
    strcpy(result, s);
#else
    result = s;
#endif
    return result;
}


/*
 * _predict - predict string of particular size
 *
 * Requires:
 *	SIZE is a non-negative integer.
 *
 * Effects:
 *   	Returns a new empty string.  However, the memory area
 *	allocated for the result is large enough to contain SIZE
 *	characters.  The resulting string may later be "augmented"
 *	using the _concat operation.
 */

string OFstring_D__predict(int size)
{
    string result;

    result = OFstring_D__alloc(size);
    OMstring_D__setsize(result, 0);
    return result;
}


/*
 * _concat - concatenate two strings
 *
 * Requires:
 *   	The memory area pointed to by S1 is large enough to contain
 *	string$size(S1) + string$size(S2) characters.
 *
 * Modifies:
 *	The string pointed to by S1.
 *
 * Effects:
 *   	Modifies the string pointed to by S1 so that it becomes the
 *	same string as the result of string$concat(S1, S2).
 *
 * Note:
 *   	This operation is for Japanized string only.  The strcat
 *	function is sufficient for non-Japanized string.
 */

int OFstring_D__concat(string s1, string s2)
{
#if CLU2C_STRING_VERSION == 1
    strcat(s1, s2);
#else
    OMstring_D__subcopy(s1, OMstring_Dsize(s1) + 1, s2, 1, OMstring_Dsize(s2));
    OMstring_D__setsize(s1, OMstring_Dsize(s1) + OMstring_Dsize(s2));
#endif
}


/*
 * Some common string objects
 */

#if CLU2C_STRING_VERSION == 2
    string_rep Chars = {
	  0,  -1,  10, 'b', 'a',  'd', '_', 'f', 'o', 'r',	/*   0--  9 */
	'm', 'a', 't',   6, 'b',  'o', 'u', 'n', 'd', 's',	/*  10-- 19 */
	 14, 'c', 'o', 'm', 'p',  'l', 'e', 'x', '_', 'r',	/*  20-- 29 */
	'e', 's', 'u', 'l', 't',   11, 'e', 'n', 'd', '_',	/*  30-- 39 */
	'o', 'f', '_', 'f', 'i',  'l', 'e',   7, 'f', 'a',	/*  40-- 49 */
	'i', 'l', 'u', 'r', 'e',   12, 'i', 'l', 'l', 'e',	/*  50-- 59 */
	'g', 'a', 'l', '_', 'c',  'h', 'a', 'r',  17, 'n',	/*  60-- 69 */
	'e', 'g', 'a', 't', 'i',  'v', 'e', '_', 'e', 'x',	/*  70-- 79 */
	'p', 'o', 'n', 'e', 'n',  't',  20, 'n', 'e', 'g',	/*  80-- 89 */
	'a', 't', 'i', 'v', 'e',  '_', 'f', 'i', 'e', 'l',	/*  90-- 99 */
	'd', '_', 'w', 'i', 'd',  't', 'h',  13, 'n', 'e',	/* 100--109 */
	'g', 'a', 't', 'i', 'v',  'e', '_', 's', 'i', 'z',	/* 110--119 */
	'e',   8, 'n', 'o', '_',  'l', 'i', 'm', 'i', 't',	/* 120--129 */
	  9, 'n', 'o', 't', '_',  'f', 'o', 'u', 'n', 'd',	/* 130--139 */
	 12, 'n', 'o', 't', '_',  'p', 'o', 's', 's', 'i',	/* 140--149 */
	'b', 'l', 'e',   8, 'o',  'v', 'e', 'r', 'f', 'l',	/* 150--159 */
	'o', 'w',   9, 'u', 'n',  'd', 'e', 'f', 'i', 'n',	/* 160--169 */
	'e', 'd',   9, 'u', 'n',  'd', 'e', 'r', 'f', 'l',	/* 170--179 */
	'o', 'w',   9, 'w', 'r',  'o', 'n', 'g', '_', 't',	/* 180--189 */
	'a', 'g',  10, 'w', 'r',  'o', 'n', 'g', '_', 't',	/* 190--199 */
	'y', 'p', 'e',  11, 'z',  'e', 'r', 'o', '_', 'd',	/* 200--209 */
	'i', 'v', 'i', 'd', 'e',   13, 'o', 'u', 't', ' ',	/* 210--219 */
	'o', 'f', ' ', 'm', 'e',  'm', 'o', 'r', 'y'		/* 220--228 */
    };
#endif /* CLU2C_STRING_VERSION == 2 */

#if CLU2C_STRING_VERSION == 3
    string_default_table Strings = {
	{ 0, {'\0'}},
	{10, {'b', 'a', 'd', '_', 'f', 'o', 'r', 'm', 'a', 't'}},
	{ 6, {'b', 'o', 'u', 'n', 'd', 's'}},
	{14, {'c', 'o', 'm', 'p', 'l', 'e', 'x', '_', 'r', 'e', 's', 'u', 'l', 't'}},
	{11, {'e', 'n', 'd', '_', 'o', 'f', '_', 'f', 'i', 'l', 'e'}},
	{ 7, {'f', 'a', 'i', 'l', 'u', 'r', 'e'}},
	{12, {'i', 'l', 'l', 'e', 'g', 'a', 'l', '_', 'c', 'h', 'a', 'r'}},
	{17, {'n', 'e', 'g', 'a', 't', 'i', 'v', 'e', '_', 'e', 'x', 'p', 'o', 'n', 'e', 'n', 't'}},
	{20, {'n', 'e', 'g', 'a', 't', 'i', 'v', 'e', '_', 'f', 'i', 'e', 'l', 'd', '_', 'w', 'i', 'd', 't', 'h'}},
	{13, {'n', 'e', 'g', 'a', 't', 'i', 'v', 'e', '_', 's', 'i', 'z', 'e'}},
	{ 8, {'n', 'o', '_', 'l', 'i', 'm', 'i', 't'}},
	{ 9, {'n', 'o', 't', '_', 'f', 'o', 'u', 'n', 'd'}},
	{12, {'n', 'o', 't', '_', 'p', 'o', 's', 's', 'i', 'b', 'l', 'e'}},
	{ 8, {'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w'}},
	{ 9, {'u', 'n', 'd', 'e', 'f', 'i', 'n', 'e', 'd'}},
	{ 9, {'u', 'n', 'd', 'e', 'r', 'f', 'l', 'o', 'w'}},
	{ 9, {'w', 'r', 'o', 'n', 'g', '_', 't', 'a', 'g'}},
	{10, {'w', 'r', 'o', 'n', 'g', '_', 't', 'y', 'p', 'e'}},
	{11, {'z', 'e', 'r', 'o', '_', 'd', 'i', 'v', 'i', 'd', 'e'}},
	{13, {'o', 'u', 't', ' ', 'o', 'f', ' ', 'm', 'e', 'm', 'o', 'r', 'y'}}
    };
#endif /* CLU2C_STRING_VERSION == 3 */
