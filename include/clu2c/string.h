/*
 * string.h
 *
 * Copyright (c) 1992, 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: string.h,v 2.13 1996/10/07 07:39:58 ushijima Exp $
 */


#ifdef CLU2C_STRING_VERSION
#   if CLU2C_STRING_VERSION < 1 || CLU2C_STRING_VERSION > 3
	!!! version CLU2C_STRING_VERSION not supported !!!
#   endif
#else
#   define CLU2C_STRING_VERSION 3
#endif


/* Representation */

#if CLU2C_STRING_VERSION == 1
    typedef char *string;
    typedef char string_rep[];
#   define STRING_ALLOC_SIZE(n) ((n) + 1)
#endif
#if CLU2C_STRING_VERSION == 2
    typedef char_t *string;
    typedef char_t string_rep[];
#   define STRING_ALLOC_SIZE(n) (((n) + 1) * sizeof(char_t))
#endif
#if CLU2C_STRING_VERSION == 3
#   define STRING_REP(n) struct {int size; char_t chars[n];}
    typedef STRING_REP(1) string_rep1;
    typedef string_rep1 *string;
#   define STRING_ALLOC_SIZE(n) (sizeof(string_rep1) + ((n) - 1) * sizeof(char_t))
#endif 


/* Macros for inline expansion */

#if CLU2C_STRING_VERSION == 1
#   define OMstring_Dsize(s)	strlen((string) (s))
#endif
#if CLU2C_STRING_VERSION == 2
#   define OMstring_Dsize(s)	(((string) (s))[0])
#endif
#if CLU2C_STRING_VERSION == 3
#   define OMstring_Dsize(s)	(((string) (s))->size)
#endif

#if CLU2C_STRING_VERSION == 1
#   define OMstring_Dempty(s)	(((string) (s))[0] == '\0')
#else
#   define OMstring_Dempty(s)	(OMstring_Dsize(s) == 0)
#endif

#if CLU2C_STRING_VERSION == 1
#   define OMstring_Dfetch(s, i)	(((string) (s))[(i) - 1])
#endif
#if CLU2C_STRING_VERSION == 2
#   define OMstring_Dfetch(s, i)	(((string) (s))[(i)])
#endif
#if CLU2C_STRING_VERSION == 3
#   define OMstring_Dfetch(s, i)	(((string) (s))->chars[(i) - 1])
#endif

#define OMstring_Dlt(s1, s2)		(OFstring_D__cmp((s1), (s2)) < 0)
#define OMstring_Dle(s1, s2)		(OFstring_D__cmp((s1), (s2)) <= 0)
#define OMstring_Dge(s1, s2)		(OFstring_D__cmp((s1), (s2)) >= 0)
#define OMstring_Dgt(s1, s2)		(OFstring_D__cmp((s1), (s2)) >  0)
#define OMstring_Dequal(s1, s2)		(OFstring_D__equal((s1), (s2)))
#define OMstring_Dsimilar(s1, s2)	(OFstring_D__equal((s1), (s2)))
#define OMstring_Dcopy(s)		(s)

#if CLU2C_STRING_VERSION == 1
#   define OMstring_D__chars(s)	((string) (s))
#endif
#if CLU2C_STRING_VERSION == 2
#   define OMstring_D__chars(s)	(((string) (s)) + 1)
#endif
#if CLU2C_STRING_VERSION == 3
#   define OMstring_D__chars(s) (((string) (s))->chars)
#endif


/*
 * Flags Which catch the signal raised by Macro for inline expansion
 */

#define OMstring_Dbounds(s, i) ((i) < 1 || (i) > OMstring_Dsize(s))


/*
 * Declaration of hiddeng operations
 */

extern char *OFstring_D__copy();
extern char *OFstring_D__s2cs();
extern string OFstring_D__cs2s();
extern string OFstring_D__predict();


/*
 * for backward compatibility
 */

#define OFstring_Ds2cstr(s)	OFstring_D__s2cs(s)
#define OFstring_Dcstr2s(s)	OFstring_D__cs2s(s)


/*
 * Some commonly used string literals
 */

#if CLU2C_STRING_VERSION == 1
#   define SLNULL			""
#   define SLBAD_FORMAT			"bad_format"
#   define SLBOUNDS			"bounds"
#   define SLCOMPLEX_RESULT		"complex_result"
#   define SLEND_OF_FILE		"end_of_file"
#   define SLFAILURE			"failure"
#   define SLILLEGAL_CHAR		"illegal_char"
#   define SLNEGATIVE_EXPONENT		"negative_exponent"
#   define SLNEGATIVE_FIELD_WIDTH	"negative_field_width"
#   define SLNEGATIVE_SIZE		"negative_size"
#   define SLNO_LIMIT			"no_limit"
#   define SLNOT_FOUND			"not_found"
#   define SLNOT_POSSIBLE		"not_possible"
#   define SLOVERFLOW			"overflow"
#   define SLUNDEFINED			"undefined"
#   define SLUNDERFLOW			"underflow"
#   define SLWRONG_TAG			"wrong_tag"
#   define SLWRONG_TYPE			"wrong_type"
#   define SLZERO_DIVIDE		"zero_divide"
#   define SLOUT_OF_MEMORY		"out of memory"
#endif

#if CLU2C_STRING_VERSION == 2
    extern string_rep Chars;
#   define SLNULL			(&Chars[  0])
#   define SLBAD_FORMAT			(&Chars[  2])
#   define SLBOUNDS			(&Chars[ 13])
#   define SLCOMPLEX_RESULT		(&Chars[ 20])
#   define SLEND_OF_FILE		(&Chars[ 35])
#   define SLFAILURE			(&Chars[ 47])
#   define SLILLEGAL_CHAR		(&Chars[ 55])
#   define SLNEGATIVE_EXPONENT		(&Chars[ 68])
#   define SLNEGATIVE_FIELD_WIDTH	(&Chars[ 86])
#   define SLNEGATIVE_SIZE		(&Chars[107])
#   define SLNO_LIMIT			(&Chars[121])
#   define SLNOT_FOUND			(&Chars[130])
#   define SLNOT_POSSIBLE		(&Chars[140])
#   define SLOVERFLOW			(&Chars[153])
#   define SLUNDEFINED			(&Chars[162])
#   define SLUNDERFLOW			(&Chars[172])
#   define SLWRONG_TAG			(&Chars[182])
#   define SLWRONG_TYPE			(&Chars[192])
#   define SLZERO_DIVIDE		(&Chars[203])
#   define SLOUT_OF_MEMORY		(&Chars[215])
#endif

#if CLU2C_STRING_VERSION == 3
    typedef struct {
	STRING_REP( 1) null;
	STRING_REP(10) bad_format;
	STRING_REP( 6) bounds;
	STRING_REP(14) complex_result;
	STRING_REP(11) end_of_file;
	STRING_REP( 7) failure;
	STRING_REP(12) illegal_char;
	STRING_REP(17) negative_exponent;
	STRING_REP(20) negative_field_width;
	STRING_REP(13) negative_size;
	STRING_REP( 8) no_limit;
	STRING_REP( 9) not_found;
	STRING_REP(12) not_possible;
	STRING_REP( 8) overflow;
	STRING_REP( 9) undefined;
	STRING_REP( 9) underflow;
	STRING_REP( 9) wrong_tag;
	STRING_REP(10) wrong_type;
	STRING_REP(11) zero_divide;
	STRING_REP(13) out_of_memory;
    } string_default_table;
    extern string_default_table Strings;
#   define SLNULL		  ((string) (&Strings.null))
#   define SLBAD_FORMAT		  ((string) (&Strings.bad_format))
#   define SLBOUNDS		  ((string) (&Strings.bounds))
#   define SLCOMPLEX_RESULT	  ((string) (&Strings.complex_result))
#   define SLEND_OF_FILE	  ((string) (&Strings.end_of_file))
#   define SLFAILURE		  ((string) (&Strings.failure))
#   define SLILLEGAL_CHAR	  ((string) (&Strings.illegal_char))
#   define SLNEGATIVE_EXPONENT	  ((string) (&Strings.negative_exponent))
#   define SLNEGATIVE_FIELD_WIDTH ((string) (&Strings.negative_field_width))
#   define SLNEGATIVE_SIZE	  ((string) (&Strings.negative_size))
#   define SLNO_LIMIT		  ((string) (&Strings.no_limit))
#   define SLNOT_FOUND		  ((string) (&Strings.not_found))
#   define SLNOT_POSSIBLE	  ((string) (&Strings.not_possible))
#   define SLOVERFLOW		  ((string) (&Strings.overflow))
#   define SLUNDEFINED		  ((string) (&Strings.undefined))
#   define SLUNDERFLOW		  ((string) (&Strings.underflow))
#   define SLWRONG_TAG		  ((string) (&Strings.wrong_tag))
#   define SLWRONG_TYPE		  ((string) (&Strings.wrong_type))
#   define SLZERO_DIVIDE	  ((string) (&Strings.zero_divide))
#   define SLOUT_OF_MEMORY	  ((string) (&Strings.out_of_memory))
#endif /* CLU2C_STRING_VERSION == 3 */
