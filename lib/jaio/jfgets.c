/*
 * jfgets.c - implementation of ja_fgets
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfgets.c,v 2.0 1996/06/10 08:59:24 ushijima Exp $
 */

#include <config/string.h>
#include <jaio.h>
#include <local.h>


/*
 * ja_fgets - get a line from stream
 *
 * Requires:
 * 	The stream pointed to by STREAM is an input or update stream.
 *
 * Modifies:
 *	The array pointed to by CHARS.
 *	The stream pointed to by STREAM.
 *
 * Effects:
 */

ja_char *ja_fgets(chars, size, stream)
ja_char *chars;
int size;
ja_FILE *stream;
{
    ja_char *cursor;		/* points to a character in CHARS */

    /* Checks if the value of SIZE is valid.  */
    if (size <= 1) {
	return NULL;
    }

    /* Rules out output streams and update streams in which the most
       recent operation was output.  */
    if (WRITING(stream)) {
	return NULL;
    }

    cursor = chars;

    for (;;) {

	int last;		/* nonzero for the last iteration */
	int count;		/* number of characters copied in this iter. */

	/* Fills in the internal buffer of STREAM, if necessary.  In
           fact, this is necessary in most cases.  The only exception
           is the case that the buffer contains some characters at the
           first iteration.  */
	if (stream->cnt == 0 || stream->base == NULL) {
	    int c;
	    c = ja_fill(stream);
	    if (c == EOF && !ja_ferror(stream) && cursor > chars) {
		/* End-of-file is encounted but at least one character
                   have been read. */
		*cursor = 0;
		return chars;
	    } else if (c == EOF) {
		return NULL;
	    }
	    *cursor++ = c;
	    --size;
	    if (c == '\n') {
		*cursor = 0;
		return chars;
	    }
	}

	/* Figures out the number of characters copied in this
           iteration, checking if this iteration is the last one.  */
	last = 0;
	for (count = 0; count < stream->cnt; count++) {
	    if (stream->ptr[count] == '\n') {
		last = 1;
		count++;
		break;
	    } else if (count == size - 1) {
		last = 1;
		break;
	    }
	}

	/* Copies COUNT characters from the buffer into CHARS, and
           adjusts relevant variables.  */
	memcpy((char *) cursor,
	       (char *) stream->ptr,
	       count * sizeof(ja_char));
	cursor += count;
	size -= count;
	stream->ptr += count;
	stream->cnt -= count;

	if (last) {
	    *cursor = 0;
	    return chars;
	}
    }
}
