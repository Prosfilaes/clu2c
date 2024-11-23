/*
 * jvfprint.c - implementation of ja_vfprintf
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jvfprint.c,v 2.0 1996/06/10 08:59:55 ushijima Exp $
 */

#include <config/stdarg.h>
#include <jaio.h>
#include <local.h>


static int ja_stream_putc();


/*
 * ja_vfprintf - print to stream
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 */

int ja_vfprintf(stream, format, list)
ja_FILE *stream;
ja_char *format;
VA_LIST list;
{
    struct destination d;

    d.body.stream = stream;
    d.putc = ja_stream_putc;
    d.finish = NULL;
    return ja_v_printf(&d, format, list);
}


/*
 * ja_stream_putc
 *
 * Modifies:
 *	The object pointed to by D.
 */

static int ja_stream_putc(d, c)
struct destination *d;
int c;
{
    if (ja_putc(c, d->body.stream) == EOF) {
	return EOF;
    }
    d->size++;
    return c;
}
