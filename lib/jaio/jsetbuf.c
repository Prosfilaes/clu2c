/*
 * jsetbuf.c - implementation of ja_setbuf
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jsetbuf.c,v 2.0 1996/06/10 08:59:46 ushijima Exp $
 */

#include <jaio.h>


/*
 * ja_setbuf
 */

void ja_setbuf(stream, buffer)
ja_FILE *stream;
ja_char *buffer;
{
    int mode;

    mode = (buffer ? ja_IOFBF : ja_IONBF);
    ja_setvbuf(stream, buffer, mode, ja_BUFSIZ);
}
