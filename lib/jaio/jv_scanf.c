/*
 * jv_scanf.c
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jv_scanf.c,v 2.0 1996/06/10 08:59:53 ushijima Exp $
 */

#include <config/stdarg.h>
#include <config/stdlib.h>
#include <config/string.h>
#include <ctype.h>
#include <jaio.h>
#include <local.h>


#define IS_ASCII(c) ((c) >= 0 && (c) < 0x80)
#define IS_DIGIT(c) (IS_ASCII(c) && isdigit(c))
#define IS_LOWER(c) (IS_ASCII(c) && islower(c))
#define IS_SPACE(c) (IS_ASCII(c) && isspace(c))
#define IS_UPPER(c) (IS_ASCII(c) && isupper(c))

#define SUCCESS			0
#define INPUT_FAILURE		1
#define MATCHING_FAILURE	2

#define NO_ASSIGN	0x01
#define FIELD_WIDTH	0x02
#define SHORT_INT	0x04
#define LONG_INT	0x08
#define DOUBLE		0x08
#define LONG_DOUBLE	0x10
#define UNSIGNED	0x20
#define VOID_POINTER	0x40

struct conversion {
    VA_LIST list;
    int flags;
    int field_width;
};


static int ja_scan_int();
static int ja_scan_float();
static int ja_scan_string();
static int ja_scan_chars();
static int ja_scan_set();
static int ja_scan_space();


/*
 * ja_v_scanf
 */

int ja_v_scanf(s, format, list)
struct source *s;
ja_char *format;
VA_LIST list;
{
    ja_char *cp;
    struct conversion conv;
    int matches;		/* the number of input items assigned */
    int c;			/* input character from source */
    ja_char specifier;	/* conversion specifier */
    int status;

    cp = format;
    matches = 0;

    conv.list = list;

    while (*cp) {

	/* Executes the directive of one or more white-space
           characters.  */
	if (IS_SPACE(*cp)) {
	    while (IS_SPACE(*cp)) {
		cp++;
	    }
	    ja_scan_space(s);
	    continue;
	}

	/* Executes the directive of an ordinary character.  */
	if (*cp != '%') {
	    c = (*s->getc)(s);
	    if (c == EOF) {
		return EOF;
	    } else if (c != *cp) {
		(*s->ungetc)(s, c);
		break;
	    }
	    cp++;
	    continue;
	}

	/* Executes the directive of a conversion specification.  */
	cp++;			/* Skips `%'.  */
	conv.flags = 0;

	if (*cp == '*') {
	    cp++;
	    conv.flags |= NO_ASSIGN;
	}

	if (IS_DIGIT(*cp)) {
	    conv.flags |= FIELD_WIDTH;
	    conv.field_width = 0;
	    while (IS_DIGIT(*cp)) {
		conv.field_width = conv.field_width * 10 + (*cp - '0');
		cp++;
	    }
	}

	switch (*cp) {
	case 'h':
	    conv.flags |= SHORT_INT;
	    cp++;
	    break;
	case 'l':
	    conv.flags |= LONG_INT;
	    cp++;
	    break;
	case 'L':
#ifdef HAVE_LONG_DOUBLE
	    conv.flags |= LONG_DOUBLE;
#endif
	    cp++;
	    break;
	}
	    
	specifier = *cp++;

	switch (specifier) {

	case 'd':
	    status = ja_scan_int(s, &conv, 10);
	    break;

	case 'i':
	    status = ja_scan_int(s, &conv, 0);
	    break;

	case 'o':
	    conv.flags |= UNSIGNED;
	    status = ja_scan_int(s, &conv, 8);
	    break;

	case 'u':
	    conv.flags |= UNSIGNED;
	    status = ja_scan_int(s, &conv, 10);
	    break;

	case 'X':
	case 'x':
	    conv.flags |= UNSIGNED;
	    status = ja_scan_int(s, &conv, 16);
	    break;

	case 'E':
	case 'G':
	case 'e':
	case 'f':
	case 'g':
	    status = ja_scan_float(s, &conv);
	    break;

	case 's':
	    status = ja_scan_string(s, &conv);
	    break;

	case '[':
	    status = ja_scan_set(s, &conv, &cp);
	    break;

	case 'c':
	    status = ja_scan_chars(s, &conv);
	    break;

	case 'p':
	    /* May not work...  */
	    conv.flags |= VOID_POINTER;
	    status = ja_scan_int(s, &conv, 16);
	    break;

	case 'n':
	    if (conv.flags & SHORT_INT) {
		*VA_ARG(conv.list, short *) = (short) matches;
	    } else if (conv.flags & LONG_INT) {
		*VA_ARG(conv.list, long *) = (long) matches;
	    } else {
		*VA_ARG(conv.list, int *) = matches;
	    }
	    status = SUCCESS;
	    break;

	case '%':
	    ja_scan_space(s);
	    c = (*s->getc)(s);
	    if (c == EOF) {
		status = INPUT_FAILURE;
	    } else if (c != '%') {
		(*s->ungetc)(s, c);
		status = MATCHING_FAILURE;
	    } else {
		status = SUCCESS;
	    }
	    break;

	default:
	    return EOF;
	}

	if (status == INPUT_FAILURE) {
	    return EOF;
	} else if (status == MATCHING_FAILURE) {
	    return matches;
	} else if (specifier != 'n') {
	    matches++;
	}

    }

    return matches;
}


/*
 * ja_scan_int
 */

static int ja_scan_int(s, conv, base)
struct source *s;
struct conversion *conv;
int base;			/* can be zero */
{
    static char buf[BUFSIZ];
    int i;			/* index for buf */
    int c;			/* input character */
    char sign;			/* (implicit or explicit) sign */
    int radix;			/* actual radix */
    int digits_present;		/* non-zero iff any digits are present */
    char *digits;		/* digit characters */
    unsigned long abs;		/* absolute value of the input item */

    ja_scan_space(s);
    i = 0;

    /* Reads an optional sign.  */
    c = (*s->getc)(s);
    if (c == EOF) {
	return INPUT_FAILURE;
    }
    if (c == '+' || c == '-') {
	sign = c;
	buf[i++] = c;
	c = (*s->getc)(s);
	if (c == EOF) {
	    return MATCHING_FAILURE;
	}
    } else {
	sign = '+';
    }

    if (base == 0 && !IS_DIGIT(c)) {
	return MATCHING_FAILURE;
    }

    /* Actual radix defaults to BASE.  If BASE is zero, the actual
       radix must be fixed based on the prefix.  */
    radix = base;

    /* At least one digit must be present.  */
    digits_present = 0;

    /* Reads an optinal prefix.  If BASE is zero and the actual radix
       is not 10, a prefix must be present.  If BASE is 16, a prefix
       (`0X' or `0x') may or may not be present.  If BASE is 8, a
       leading zero is treated as an octal digit rather than a prefix.  */
    if (c == '0' && (base == 0 || base == 16)) {
	buf[i++] = c;
	c = (*s->getc)(s);
	if (c == EOF) {
	    /* The previous zero turns out to be a digit rather than a
               character that begins a prefix.  */
	    digits_present = 1;
	    if (base == 0) {
		radix = 10;
	    }
	} else if (c == 'X' || c == 'x') {
	    radix = 16;
	    buf[i++] = c;
	    c = (*s->getc)(s);
	} else if (base == 0) {
	    radix = 8;
	} else /* (base == 16) */ {
	    digits_present = 1;
	}
    } else if (base == 0) {
	radix = 10;
    }

    /* Determines the set of permitted digit characters according to
       the actual radix.  */
    if (radix == 8) {
	digits = "01234567";
    } else if (radix == 10) {
	digits = "0123456789";
    } else /* (radix == 16) */ {
	digits = "0123456789ABCDEFabcdef";
    }

    /* Reads the digits.  */
    abs = 0;
    while (IS_ASCII(c) && strchr(digits, c)) {
	int digit_value;
	if (i >= BUFSIZ - 1) {
	    break;
	}
	if ((conv->flags & FIELD_WIDTH) && i >= conv->field_width) {
	    break;
	}
	digits_present = 1;
	buf[i++] = c;
	if (IS_DIGIT(c)) {
	    digit_value = c - '0';
	} else if (IS_UPPER(c)) {
	    digit_value = c - 'A' + 10;
	} else /* (IS_LOWER(c)) */ {
	    digit_value = c - 'a' + 10;
	}
	abs = abs * radix + digit_value;
	c = (*s->getc)(s);
	if (c == EOF) {
	    break;
	}
    }
    if (c != EOF) {
	(*s->ungetc)(s, c);
    }
    buf[i] = '\0';

    if (i <= 0 || !digits_present) {
	return MATCHING_FAILURE;
    }

    if (conv->flags & NO_ASSIGN) {
	return SUCCESS;
    }

    if (sign == '-') {
	abs = -abs;
    }

    if (conv->flags & VOID_POINTER) {
	*VA_ARG(conv->list, void **) = (void *) abs;
    } else if (conv->flags & UNSIGNED) {
	if (conv->flags & SHORT_INT) {
	    *VA_ARG(conv->list, unsigned short *) = (unsigned short) abs;
	} else if (conv->flags & LONG_INT) {
	    *VA_ARG(conv->list, unsigned long *) = abs;
	} else {
	    *VA_ARG(conv->list, unsigned *) = (unsigned) abs;
	}
    } else {
	long value = strtol(buf, NULL, base);
	if (conv->flags & SHORT_INT) {
	    *VA_ARG(conv->list, short *) = (short) value;
	} else if (conv->flags & LONG_INT) {
	    *VA_ARG(conv->list, long *) = value;
	} else {
	    *VA_ARG(conv->list, int *) = (int) value;
	}
    }
    return SUCCESS;
}


/*
 * ja_scan_float
 */

static int ja_scan_float(s, conv)
struct source *s;
struct conversion *conv;
{
    static char buf[BUFSIZ];	/* buffer for `strtod' */
    int i;			/* index for BUF */
    int rest;			/* room left in BUF */
    int c;			/* input character */
    int no_integer;		/* non-zero iff no integer part in mantissa */
    int no_fraction;		/* non-zero iff no fraction part in mantissa */
    double value;		/* value of converted floating-point number */

    ja_scan_space(s);

    /* Initializes the buffer.  */
    i = 0;
    rest = BUFSIZ - 1;
    if ((conv->flags & FIELD_WIDTH) && rest > conv->field_width) {
	rest = conv->field_width;
    }

    /* Reads an optional sign.  */
    c = (*s->getc)(s);
    if (c == EOF) {
	return INPUT_FAILURE;
    }
    if ((c == '+' || c == '-') && rest > 0) {
	buf[i++] = c;
	--rest;
	c = (*s->getc)(s);
	if (c == EOF) {
	    return MATCHING_FAILURE;
	}
    }

    no_integer = 1;
    while (IS_DIGIT(c) && rest > 0) {
	no_integer = 0;
	buf[i++] = c;
	--rest;
	c = (*s->getc)(s);
	if (c == EOF) {
	    break;
	}
    }

    no_fraction = 1;
    if (c == '.' && rest > 0) {
	buf[i++] = c;
	--rest;
	c = (*s->getc)(s);
	while (IS_DIGIT(c) && rest > 0) {
	    no_fraction = 0;
	    buf[i++] = c;
	    --rest;
	    c = (*s->getc)(s);
	    if (c == EOF) {
		break;
	    }
	}
    }

    if (no_integer && no_fraction) {
	if (c != EOF) {
	    (*s->ungetc)(s, c);
	}
	return MATCHING_FAILURE;
    }

    if ((c == 'E' || c == 'e') && rest > 0) {
	int no_exponent_digits = 1;
	buf[i++] = c;
	--rest;
	c = (*s->getc)(s);
	if ((c == '+' || c == '-') && rest > 0) {
	    buf[i++] = c;
	    --rest;
	    c = (*s->getc)(s);
	    if (c == EOF) {
		return MATCHING_FAILURE;
	    }
	}
	while (IS_DIGIT(c) && rest > 0) {
	    no_exponent_digits = 0;
	    buf[i++] = c;
	    --rest;
	    c = (*s->getc)(s);
	    if (c == EOF) {
		break;
	    }
	}
	if (no_exponent_digits) {
	    if (c != EOF) {
		(*s->ungetc)(s, c);
	    }
	    return MATCHING_FAILURE;
	}
    }

    if (c != EOF) {
	(*s->ungetc)(s, c);
    }
    buf[i] = '\0';

    if (conv->flags & NO_ASSIGN) {
	return SUCCESS;
    }

    value = strtod(buf, NULL);
    if (conv->flags & DOUBLE) {
	*VA_ARG(conv->list, double *) = value;
#ifdef HAVE_LONG_DOUBLE
    } else if (conv->flags & LONG_DOUBLE) {
	*VA_ARG(conv->list, long double *) = (long double) value;
#endif
    } else {
	*VA_ARG(conv->list, float *) = (float) value;
    }
    return SUCCESS;
}


/*
 * ja_scan_string
 */

static int ja_scan_string(s, conv)
struct source *s;
struct conversion *conv;
{
    int assign;			/* zero iff assignment is suppressed */
    ja_char *store = NULL;
    int width;
    int c;
    int w;

    ja_scan_space(s);
    assign = (conv->flags & NO_ASSIGN) ? 0 : 1;
    if (assign) {
	store = VA_ARG(conv->list, ja_char *);
    }
    width = 0;
    while ((c = (*s->getc)(s)) != EOF && !IS_SPACE(c)) {
	w = (c < 0x100) ? 1 : 2;
	if ((conv->flags & FIELD_WIDTH) && width + w > conv->field_width) {
	    break;
	}
	if (assign) {
	    *store++ = c;
	}
	width += w;
    }
    if (c != EOF) {
	(*s->ungetc)(s, c);
    }
    if (assign) {
	*store = 0;
    }
    return SUCCESS;
}


/*
 * ja_scan_chars
 */

static int ja_scan_chars(s, conv)
struct source *s;
struct conversion *conv;
{
    int assign;
    ja_char *store = NULL;
    int width;
    int c;

    assign = (conv->flags & NO_ASSIGN) ? 0 : 1;
    if (assign) {
	store = VA_ARG(conv->list, ja_char *);
    }
    width = 0;
    while ((c = (*s->getc)(s)) != EOF) {
	width += (c < 0x100) ? 1 : 2;
	if ((conv->flags & FIELD_WIDTH) && width > conv->field_width) {
	    (*s->ungetc)(s, c);
	    return SUCCESS;
	}
	if (assign) {
	    *store++ = c;
	}
	if (!(conv->flags & FIELD_WIDTH)) {
	    return SUCCESS;
	}
    }	
    return INPUT_FAILURE;
}


/*
 * ja_scan_set
 */

static int ja_scan_set(s, conv, cpp)
struct source *s;
struct conversion *conv;
ja_char **cpp;
{
    ja_char *cp;		/* points to conversion specification */
    ja_char *list;		/* beginning of scan list */
    int complement;
    ja_char c;		/* input character */
    int list_size;		/* size of scan list */
    int assign;
    ja_char *store = NULL;
    int width;
    int matched;

    /* Reads the scan list and creates the corresponding scan set.  */
    cp = *cpp;
    list = cp;
    complement = 0;
    if (*cp++ == '^') {
	cp++;
	list++;
	complement = 1;
    }
    c = *cp++;
    while (c && c != ']') {
	c = *cp++;
    }
    *cpp = c ? cp : cp - 1;
    list_size = cp - list - 1;

    assign = (conv->flags & NO_ASSIGN) ? 0 : 1;
    if (assign) {
	store = VA_ARG(conv->list, ja_char *);
    }
    width = 0;
    matched = 0;
    while ((c = (*s->getc)(s)) != EOF) {
	int w;
	int i;
	w = (c < 0x100) ? 1 : 2;
	if ((conv->flags & FIELD_WIDTH) && width + w > conv->field_width) {
	    break;
	}
	matched = complement;
	for (i = 0; i < list_size; i++) {
	    if (list[i] == c) {
		matched = !matched;
		break;
	    }
	}
	if (!matched) {
	    break;
	}
	width += w;
	if (assign) {
	    *store++ = c;
	}
    }
    if (c != EOF) {
	(*s->ungetc)(s, c);
    }
    if (assign) {
	*store = 0;
    }

    if (width > 0) {
	return SUCCESS;
    } else if (c == EOF) {
	return INPUT_FAILURE;
    } else {
	return MATCHING_FAILURE;
    }
}


/*
 * ja_scan_space
 */

static int ja_scan_space(s)
struct source *s;
{
    int c;

    for (;;) {
	c = (*s->getc)(s);
	if (!IS_SPACE(c)) {
	    break;
	}
    }
    if (c == EOF) {
	return EOF;
    }
    (*s->ungetc)(s, c);
    return 0;
}
