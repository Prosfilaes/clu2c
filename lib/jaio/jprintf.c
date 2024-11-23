/*
 * jprintf.c - implementation of ja_printf 
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jprintf.c,v 2.0 1996/06/10 08:59:42 ushijima Exp $
 */

#include <config/stdarg.h>
#include <jaio.h>


/*
 * ja_printf - print to standard output
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 */

int ja_printf VA_ARGS((format, va_alist),
ja_char *format VA_AND
VA_DCL)
{
    VA_LIST list;
    int result;

    VA_START(list, format);
    result = ja_vfprintf(ja_stdout, format, list);
    VA_END(list);
    return result;
}
