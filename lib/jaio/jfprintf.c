/*
 * jfprintf.c - implementation of ja_fprintf
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfprintf.c,v 2.0 1996/06/10 08:59:30 ushijima Exp $
 */

#include <config/stdarg.h>
#include <jaio.h>


/*
 * ja_fprintf - print to stream
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 */

int ja_fprintf VA_ARGS((stream, format, va_alist),
ja_FILE *stream VA_AND
ja_char *format VA_AND
VA_DCL)
{
    VA_LIST list;
    int result;

    VA_START(list, format);
    result = ja_vfprintf(stream, format, list);
    VA_END(list);
    return result;
}
