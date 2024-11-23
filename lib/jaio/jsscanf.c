/*
 * jsscanf.c - implementation of ja_sscanf
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jsscanf.c,v 2.0 1996/06/10 08:59:51 ushijima Exp $
 */

#include <config/stdarg.h>
#include <jaio.h>
#include <local.h>


static int ja_string_getc();
static int ja_string_ungetc();


/*
 * ja_sscanf
 */

int ja_sscanf VA_ARGS((string, format, va_alist),
ja_char *string VA_AND
ja_char *format VA_AND
VA_DCL)
{
    struct source s;
    VA_LIST list;
    int result;

    s.body.string = string;
    s.getc = ja_string_getc;
    s.ungetc = ja_string_ungetc;
    VA_START(list, format);
    result = ja_v_scanf(&s, format, list);
    VA_END(list);
    return result;
}


/*
 * ja_string_getc
 */

static int ja_string_getc(s)
struct source *s;
{
    if (*s->body.string) {
	return *s->body.string++;
    } else {
	return EOF;
    }
}


/*
 * ja_string_ungetc
 */

static int ja_string_ungetc(s, c)
struct source *s;
int c;
{
    --s->body.string;
    return c;
}
