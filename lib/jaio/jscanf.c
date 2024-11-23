/*
 * jscanf.c - implementation of ja_scanf
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jscanf.c,v 2.0 1996/06/10 08:59:46 ushijima Exp $
 */

#include <config/stdarg.h>
#include <jaio.h>
#include <local.h>


static int ja_stream_getc();
static int ja_stream_ungetc();


/*
 * ja_scanf
 */

int ja_scanf VA_ARGS((format, va_alist),
ja_char *format VA_AND
VA_DCL)
{
    struct source s;
    VA_LIST list;
    int result;

    s.body.stream = ja_stdin;
    s.getc = ja_stream_getc;
    s.ungetc = ja_stream_ungetc;
    VA_START(list, format);
    result = ja_v_scanf(&s, format, list);
    VA_END(list);
    return result;
}


/*
 * ja_stream_getc
 */

static int ja_stream_getc(s)
struct source *s;
{
    return ja_getc(s->body.stream);
}


/*
 * ja_stream_ungetc
 */

static int ja_stream_ungetc(s, c)
struct source *s;
int c;
{
    return ja_ungetc(c, s->body.stream);
}
