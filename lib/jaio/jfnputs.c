/*
 * jfnputs.c
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfnputs.c,v 2.0 1996/06/10 08:59:27 ushijima Exp $
 */

#include <config/string.h>
#include <jaio.h>
#include <local.h>


/*
 * ja_fnputs - put explicitly sized string on stream
 *
 * Modifies:
 *	The stream ponted to by STREAM.
 *
 * Effects:
 * 	Puts the first N characters of S on the stream pointed to by
 *	STREAM.  Returns zero on success; otherwise returns `EOF'.
 */

int ja_fnputs(s, n, stream)
ja_char *s;
int n;
ja_FILE *stream;
{
    int i;			/* index for S */
    int rest;			/* number of rest of characters */
    ja_char *p;		/* pointer for S */
    int m;			/* number of characters written in a mass */

    rest = n;
    p = s;

    /* If the buffer is not set up for output, the first character is
       written using `ja_putc', which causes that the buffer is
       allocated and flags are properly set.  */
    if (rest > 0 && (stream->base == NULL || stream->cnt == 0)) {
	if (ja_putc(*p, stream) == EOF) {
	    return EOF;
	}
	p++;
	--rest;
    }

    if (UNBUFFERED(stream) || LINE_BUFFERED(stream)) {

	/* If the stream pointed to by STREAM is unbuffered or line
	   buffered, efficiency is not a serious issue.  So a string
	   is written character-by-character using `ja_putc'.  This
	   also ensures that the buffer is flushed on appropriate
	   condition.  */
	for (i = 0; i < rest; i++) {
	    if (ja_putc(*p, stream) == EOF) {
		return EOF;
	    }
	    p++;
	}

    } else {

	/* Here the stream is fully buffered.  Characters in S are
	   transfered in a mass as long as the buffer has a room for
	   them. */
	while (rest > 0) {
	    m = (stream->cnt < rest) ? stream->cnt : rest;
	    if (m > 0) {
		memcpy((char *) stream->ptr, (char *) p, m * sizeof(ja_char));
		stream->ptr += m;
		stream->cnt -= m;
		p += m;
		rest -= m;
	    }
	    if (rest > 0 && ja_fflush(stream) == EOF) {
		return EOF;
	    }
	}

    }
    return 0;
}


/*
 * fnputs - non-Japanized version of ja_fnputs
 *
 * Modifies:
 *	The stdio stream pointed to by P.
 *
 * Effects:
 *	Every invocation of this function is equivalent to the
 *	invocation of the `fwrite' function with `sizeof(char)' as the
 *	second argument.  That is, if an invocation of the `fnputs'
 *	function is:
 *		fnputs(S, N, P)
 *	it is equivalent to:
 *		fwrite(S, sizeof(char), N, P)
 *	except for the return value.  This function returns zero on
 *	success (i.e., `fwrite' returns non-zero); otherwise returns
 *	`EOF'.
 */

int fnputs(s, n, p)
char *s;
int n;
FILE *p;
{
    int status;

    if (n <= 0) {
	status = 0;
    } else if (fwrite(s, sizeof(char), n, p) == 0) {
	status = EOF;
    } else {
	status = 0;
    }
    return status;
}
