/*
 * jsprintf.c - implementation of ja_sprintf
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jsprintf.c,v 2.0 1996/06/10 08:59:50 ushijima Exp $
 */

#include <config/stdarg.h>
#include <jaio.h>


/*
 * ja_sprintf - print to string
 *
 * Modifies:
 *	The array pointed to by STRING.
 */

int ja_sprintf VA_ARGS((string, format, va_alist),
ja_char *string VA_AND
ja_char *format VA_AND
VA_DCL)
{
    VA_LIST list;
    int result;

    VA_START(list, format);
    result = ja_vsprintf(string, format, list);
    VA_END(list);
    return result;
}
