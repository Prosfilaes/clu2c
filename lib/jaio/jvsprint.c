/*
 * jvsprint.c - implementation of ja_vsprintf
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jvsprint.c,v 2.0 1996/06/10 08:59:56 ushijima Exp $
 */

#include <config/stdarg.h>
#include <jaio.h>
#include <local.h>


static int ja_string_putc();
static void ja_string_finish();


/*
 * ja_vsprintf - print to string
 *
 * Modifies:
 *	The array pointed to by STRING.
 */

int ja_vsprintf(string, format, list)
ja_char *string;
ja_char *format;
VA_LIST list;
{
    struct destination d;

    d.body.string = string;
    d.putc = ja_string_putc;
    d.finish = ja_string_finish;
    return ja_v_printf(&d, format, list);
}


/*
 * ja_string_putc
 *
 * Modifies:
 *	The object pointed to by D.
 */

static int ja_string_putc(d, c)
struct destination *d;
int c;
{
    *d->body.string++ = c;
    d->size++;
    return c;
}


/*
 * ja_string_finish
 *
 * Modifies:
 *	The object pointed to by D.
 */

static void ja_string_finish(d)
struct destination *d;
{
    *d->body.string = 0;
}
