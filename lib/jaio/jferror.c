/*
 * jferror.c - implementation of ja_ferror
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jferror.c,v 2.0 1996/06/10 08:59:21 ushijima Exp $
 */

#include <jaio.h>
#undef ja_ferror


/*
 * ja_ferror
 */

int ja_ferror(stream)
ja_FILE *stream;
{
    return ja_mferror(stream);
}
