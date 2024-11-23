/*
 * jvprintf.c - implementation of ja_vprintf
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jvprintf.c,v 2.0 1996/06/10 08:59:55 ushijima Exp $
 */

#include <config/stdarg.h>
#include <jaio.h>


/*
 * ja_vprintf - print to standard output
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 */

int ja_vprintf(format, list)
ja_char *format;
VA_LIST list;
{
    return ja_vfprintf(ja_stdout, format, list);
}
