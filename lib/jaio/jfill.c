/*
 * jfill.c - low level filling functions
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfill.c,v 2.0 1996/06/10 08:59:25 ushijima Exp $
 */

#include <config/stdlib.h>
#include <config/unistd.h>

#include <jaio.h>
#include <local.h>


/*
 * Intermediate buffer
 */

static unsigned char ja_buf[ja_BUFSIZ + 1];


/*
 * ja_fill - fill input buffer
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 *	Returns EOF if the end-of-file or any error is encountered;
 *	otherwise fills the buffer with at least one character, then
 *	removes the first character from the buffer, and then returns
 *	it.
 */

int ja_fill(stream)
ja_FILE *stream;
{
    int c;
    int n;

    /* Rules out an output stream and an update stream in which the
       most recent operation is output.  */
    if (WRITING(stream)) {
	return EOF;
    }

    /* Allocates the buffer if not allocated yet.  */
    if (stream->base == NULL) {
	stream->base = (ja_char *) malloc(ja_BUFSIZ * sizeof(ja_char));
	if (stream->base == NULL) {
	    return EOF;
	}
	stream->flags |= ja_AUTO_BUFFER;
    }

    if (stream->bytes == NULL
	&& (stream->csd == CSYS_ISO2022JP || stream->csd == CSYS_AUTOCONV))
    {
	stream->bytes = (unsigned char *) malloc(ja_BUFSIZ);
	if (stream->bytes == NULL) {
	    return EOF;
	}
    }

    /* Prepares the input decoder.  */
    if (stream->decoder == NULL) {
	stream->decoder = ja_create_decoder(stream->csd);
	if (stream->decoder == NULL) {
	    return EOF;
	}
    }

    if (isatty(ja_fileno(stream))) {
	stream->tty = ja_tty_lookup(ttyname(ja_fileno(stream)), NULL);
	if (!UNBUFFERED(stream)) {
	    stream->flags |= ja_LINE_BUFFERED;
	}
    }
    
    /*
     * Synchronizes character set.
     */
    if (stream->tty >= 0) {
	ja_tty_sync(stream);
    }

    /*
     * Resets the buffer.
     */
    stream->ptr = stream->base;
    stream->cnt = 0;

    while (stream->cnt == 0) {

	/*
	 * Breaks the loop if an error occurs or the end-of-file has
	 * been reached; otherwise enters the read characters in the
	 * intermediate buffer in the form of null-terminated string.
	 */
	if (LINE_BUFFERED(stream)) {		/* Line buffered */
	    n = 0;
	    while (n < ja_BUFSIZ && (c = fgetc(stream->fp)) != EOF) {
		ja_buf[n++] = c;
		if (c == '\n') {
		    break;
		}
	    }
	    if (n == 0 && c == EOF) {
		break;
	    }
	} else if (UNBUFFERED(stream)) {	/* Unbuffered. */
	    c = fgetc(stream->fp);
	    if (c == EOF) {
		break;
	    }
	    ja_buf[0] = c;
	    n = 1;
	} else {				/* Fully buffered. */
	    n = fread(ja_buf, sizeof(unsigned char), ja_BUFSIZ, stream->fp);
	    if (n == 0) {
		break;
	    }
	}

	/*
	 * Converts the contents of the intermediate buffer and enters
	 * the resulting character sequence in the buffer pointed to
	 * by STREAM->BASE.  STREAM->CNT becomes the number of characters in
	 * the buffer pointed by STREAM->BASE.
	 */
	stream->cnt = ja_decode(stream->decoder,
				  ja_buf,
				  n,
				  stream->base,
				  ja_BUFSIZ,
				  stream->bytes);
    }

    /*
     * Checks for an error.
     */
    if (ja_ferror(stream)) {
	return EOF;
    }

    /*
     * If STREAM->CNT is equal to zero at this point, the underlying
     * stream pointed to by STREAM->FP is empty, i.e., has reached
     * end-of-file.  However, the input decoder pointed to by
     * STREAM->DECODER may have input characters pending in it, so
     * flushing the decoder may cause some characters to be got.  If
     * STREAM->CNT is still zero after flushing, the actual end-of-file
     * has been reached.
     */
    if (stream->cnt == 0) {
	stream->cnt = ja_flush_decoder(stream->decoder, stream->base);
	if (stream->cnt == 0) {
	    return EOF;
	}
    }

    /* Now the buffer has some input characters.  Rules out subsequent
       output operations.  */
    stream->flags |= ja_READING;

    /*  */
    stream->charset = stream->decoder->charset;
    if (stream->tty >= 0) {
	ja_tty_set(stream);
    }

    /*
     * Removes the first character from the buffer and returns it.
     */
    --stream->cnt;
    return *(stream->ptr++);
}
