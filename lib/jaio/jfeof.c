/*
 * jfeof.c - implementation of ja_feof
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfeof.c,v 2.0 1996/06/10 08:59:20 ushijima Exp $
 */

#include <jaio.h>
#undef ja_feof


/*
 * ja_feof
 */

int ja_feof(stream)
ja_FILE *stream;
{
    return ja_mfeof(stream);
}
