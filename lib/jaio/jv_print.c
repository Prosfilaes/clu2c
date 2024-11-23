/*
 * jv_print.c - auxiliary functions for ja_v[fs]printf functions
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jv_print.c,v 2.0 1996/06/10 08:59:52 ushijima Exp $
 */

#include <config/stdarg.h>
#include <ctype.h>
#include <jaio.h>
#include <local.h>


#define IS_DIGIT(c) ((c) >= 0 && (c) < 0x80 && isdigit(c))


/* Conversion specification.  */
struct conversion {

    /* Various flag bits.  */
    int flags;
#	define LEFT_JUSTIFIED	0x001
#	define ALWAYS_SIGNED	0x002
#	define SPACE_SIGNED	0x004
#	define ALTERNATE_FORM	0x008
#	define ZERO_PADDING	0x010
#	define SHORT_INT	0x020
#	define LONG_INT		0x040
#	define LONG_DOUBLE	0x080
#	define FIELD_WIDTH	0x100
#	define PRECISION	0x200

    /* Field width, if any.  */
    int field_width;

    /* Precision, if any.  */
    int precision;

    /* Type of the conversion (the last character of the conversion
       specification.  */
    char type;

    /* Conversion specification as a string.  */
    char spec[ja_BUFSIZ];

};


static int ja_print_char();
static int ja_print_string();


/*
 * ja_v_printf - generic print routine
 */

int ja_v_printf(d, format, list)
struct destination *d;
ja_char *format;
VA_LIST list;
{
    ja_char *cp;		/* points into FORMAT */
    struct conversion conv;	/* conversion specification */
    char buffer[BUFSIZ];	/* may be short */
    int i;			/* index */

    d->size = 0;
    cp = format;

    while (*cp) {

	/* Passes through characters that does not constitute a
           conversion specification.  */
	if (*cp != '%') {
	    if ((*d->putc)(d, *cp) == EOF) {
		return -1;
	    }
	    cp++;
	    continue;
	}

	/* Conversion specification encountered.  */
	cp++;
	conv.flags = 0;
	conv.spec[0] = '%';
	i = 1;

	/* Reads flags, if any.  Note that the `+' flag takes
           precedence over the ` ' flag.  */
	for (;;) {
	    if (*cp == '-') {
		conv.flags |= LEFT_JUSTIFIED;
	    } else if (*cp == '+') {
		conv.flags |= ALWAYS_SIGNED;
		conv.flags &= ~SPACE_SIGNED;
	    } else if (*cp == ' ') {
		if ((conv.flags & ALWAYS_SIGNED) == 0) {
		    conv.flags |= SPACE_SIGNED;
		}
	    } else if (*cp == '#') {
		conv.flags |= ALTERNATE_FORM;
	    } else if (*cp == '0') {
		conv.flags |= ZERO_PADDING;
	    } else {
		break;
	    }
	    conv.spec[i++] = *cp++;
	}

	/* Reads the field width, if any.  If the field width is
           specified as `*', the corresponding integer argument is
           taken here and the `spec' member is set up as if the field
           width were specified in the format string.  Note that a
           negative field width argument is taken as the `-' flag
           followed by a positive field width.  */
	if (IS_DIGIT(*cp)) {
	    conv.flags |= FIELD_WIDTH;
	    conv.field_width = 0;
	    while (IS_DIGIT(*cp)) {
		conv.field_width = conv.field_width * 10 + (*cp - '0');
		conv.spec[i++] = *cp++;
	    }
	} else if (*cp == '*') {
	    cp++;
	    conv.flags |= FIELD_WIDTH;
	    conv.field_width = VA_ARG(list, int);
	    sprintf(conv.spec + i, "%d", conv.field_width);
	    while (conv.spec[i]) {
		i++;
	    }
	    if (conv.field_width < 0) {
		conv.flags |= LEFT_JUSTIFIED;
		conv.field_width = -conv.field_width;
	    }
	}

	/* Reads precision, if any.  If the precision is specified as
           `*', the corresponding integer argument is taken here and
           the `spec' member is set up as if the precision were
           specified in the format string.  Note that a negative
           precision argument is taken as if the precision were
           omitted.  Note also that, if only the period is specified,
           the precision is taken as zero.  */
	if (*cp == '.') {
	    conv.flags |= PRECISION;
	    conv.precision = 0;
	    conv.spec[i++] = *cp++;
	    if (IS_DIGIT(*cp)) {
		while (IS_DIGIT(*cp)) {
		    conv.precision = conv.precision * 10 + (*cp - '0');
		    conv.spec[i++] = *cp++;
		}
	    } else if (*cp == '*') {
		cp++;
		conv.precision = VA_ARG(list, int);
		if (conv.precision < 0) {
		    conv.flags &= ~PRECISION;
		    --i;
		} else {
		    sprintf(conv.spec + i, "%d", conv.precision);
		    while (conv.spec[i]) {
			i++;
		    }
		}
	    }
	}
	
	/* Reads the size options, if any.  It seems that not every C
           implementation supports the type `long double'. */
	switch (*cp) {
	case 'h':
	    conv.flags |= SHORT_INT;
	    conv.spec[i++] = *cp++;
	    break;
	case 'l':
	    conv.flags |= LONG_INT;
	    conv.spec[i++] = *cp++;
	    break;
	case 'L':
#ifdef HAVE_LONG_DOUBLE
	    conv.flags |= LONG_DOUBLE;
	    conv.spec[i++] = *cp++;
#else
	    cp++;		/* Simply ignored.  */
#endif
	    break;
	}

	/* Reads the conversion type and completes the conversion
           specification.  */
	conv.type = *cp++;
	conv.spec[i++] = conv.type;
	conv.spec[i++] = '\0';

	/* Converts according to the specification.  */
	switch (conv.type) {

	case 'C':		/* Non-standard.  */
	    if (ja_print_char(d, &conv, VA_ARG(list, int)) < 0) {
		return -1;
	    }
	    continue;

	case 'S':		/* Non-standard.  */
	    if (ja_print_string(d, &conv, VA_ARG(list, ja_char *)) < 0) {
		return -1;
	    }
	    continue;

	case 'd':
	case 'i':
	    if (conv.flags & LONG_INT) {
		sprintf(buffer, conv.spec, VA_ARG(list, long));
	    } else {
		/* Note that any `short' argument has been converted
                   to `int' during the evaluation of arguments.  */
		sprintf(buffer, conv.spec, VA_ARG(list, int));
	    }
	    break;

	case 'o':
	case 'u':
	case 'x':
	case 'X':
	    if (conv.flags & SHORT_INT) {
		/* Note that any `unsigned short' argument has been
                   converted to `int' during the evaluation of
                   arguments.  */
		sprintf(buffer, conv.spec, VA_ARG(list, int));
	    } else if (conv.flags & LONG_INT) {
		sprintf(buffer, conv.spec, VA_ARG(list, unsigned long));
	    } else {
		sprintf(buffer, conv.spec, VA_ARG(list, unsigned int));
	    }
	    break;

	case 'e':
	case 'E':
	case 'f':
	case 'g':
	case 'G':
#ifdef HAVE_LONG_DOUBLE
	    if (conv.flags & LONG_DOUBLE) {
		sprintf(buffer, conv.spec, VA_ARG(list, long double));
	    } else {
		sprintf(buffer, conv.spec, VA_ARG(list, double));
	    }
#else
	    sprintf(buffer, conv.spec, VA_ARG(list, double));
#endif
	    break;

	case 'c':
	    sprintf(buffer, conv.spec, VA_ARG(list, int));
	    break;

	case 's':
	    sprintf(buffer, conv.spec, VA_ARG(list, char *));
	    break;

	case 'p':
	    sprintf(buffer, conv.spec, VA_ARG(list, void *));
	    break;

	case 'n':
	    if (conv.flags & SHORT_INT) {
		*VA_ARG(list, short *) = d->size;
	    } else if (conv.flags & LONG_INT) {
		*VA_ARG(list, long *) = d->size;
	    } else {
		*VA_ARG(list, int *) = d->size;
	    }
	    continue;

	case '%':
	    buffer[0] = '%';
	    buffer[1] = '\0';
	    break;

	default:
	    return -1;
	}
	for (i = 0; buffer[i]; i++) {
	    if ((*d->putc)(d, buffer[i]) == EOF) {
		return -1;
	    }
	}
    }
    
    if (d->finish) {
	(*d->finish)(d);
    }
    return d->size;
}


/*
 * ja_print_char
 *
 * Modifies:
 *	The object pointed to by D.
 */

static int ja_print_char(d, conv, c)
struct destination *d;
struct conversion *conv;
int c;
{
    ja_char s[2];

    s[0] = c;
    s[1] = 0;
    return ja_print_string(d, conv, s);
}


/*
 * ja_print_string
 *
 * Modifies:
 *	The object pointed to by D.
 */

static int ja_print_string(d, conv, s)
struct destination *d;
struct conversion *conv;
ja_char *s;
{
    int width;
    int i;
    int c;
    int w;

    if ((conv->flags & FIELD_WIDTH) && (conv->flags & LEFT_JUSTIFIED) == 0) {
	width = 0;
	for (i = 0; s[i]; i++) {
	    w = (s[i] < 0x100) ? 1 : 2;
	    if ((conv->flags & PRECISION) && width + w > conv->precision) {
		break;
	    }
	    width += w;
	}
	while (conv->field_width > width) {
	    if ((*d->putc)(d, ' ') == EOF) {
		return -1;
	    }
	    --conv->field_width;
	}
    }

    width = 0;
    for (i = 0; s[i]; i++) {
	c = s[i];
	w = (c < 0x100) ? 1 : 2;
	if ((conv->flags & PRECISION) && width + w > conv->precision) {
	    break;
	}
	if ((*d->putc)(d, c) == EOF) {
	    return -1;
	}
	width += w;
    }

    if (conv->flags & FIELD_WIDTH) {
	while (width < conv->field_width) {
	    if ((*d->putc)(d, ' ') == EOF) {
		return -1;
	    }
	    width++;
	}

    }

    return 0;
}
