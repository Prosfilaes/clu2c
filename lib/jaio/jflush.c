/*
 * jflush.c - low level flushing functions
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jflush.c,v 2.0 1996/06/10 08:59:26 ushijima Exp $
 */

#include <config/stdlib.h>
#include <config/unistd.h>
#include <jaio.h>
#include <local.h>


/*
 * Internal function declarations
 */

static int ja_flush_noconv();
static int ja_flush_eucjp();
static int ja_flush_sjis();
static int ja_flush_iso2022jp();


/*
 * List of flushing fuctions
 */

typedef int (*ja_flusher_t)();

static ja_flusher_t ja_flushers[] = {
    ja_flush_noconv,		/* CSYS_NOCONV */
    ja_flush_eucjp,		/* CSYS_EUCJP */
    ja_flush_sjis,		/* CSYS_SJIS */
    ja_flush_iso2022jp	/* CSYS_ISO2022JP */
};


/*
 * Intermediate buffer
 */

static char ja_buf[(ja_BUFSIZ * 9) / 2];


/*
 * ja_flush - flush output buffer
 *
 * Requires:
 *   	The stream pointed to by STREAM is an output stream or an update
 *	stream.
 *
 * Modifies:
 *	The stream pointed to by STREAM.
 *
 * Effects:
 * 	Flushes STREAM's internal output buffer.  Returns the last
 *	character in the buffer on sucess; otherwise returns EOF.
 */

int ja_flush(c, stream)
int c;
ja_FILE *stream;
{
    if (stream->base == NULL) {
	stream->base = (ja_char *) malloc(ja_BUFSIZ * sizeof(ja_char));
	if (stream->base == NULL) {
	    return EOF;
	}
	stream->flags |= ja_AUTO_BUFFER;
	if (isatty(ja_fileno(stream))) {
	    stream->flags |= ja_LINE_BUFFERED;
	    stream->tty = ja_tty_lookup(ttyname(ja_fileno(stream)), stream);
	}
	stream->ptr = stream->base;
	if (!ja_initialized) {
	    ja_init();
	}
    }

    if (stream->flush == NULL) {
	if (stream->csd == CSYS_AUTOCONV) {
	    stream->csd = DEFAULT_OUTPUT_CODING_SYSTEM;
	}
	stream->flush = ja_flushers[stream->csd];
    }

    if (ja_fflush(stream) == EOF) {
	return EOF;
    }

    --stream->cnt;
    *stream->ptr++ = c;
    stream->flags |= ja_WRITING;
    
    if (UNBUFFERED(stream) || (LINE_BUFFERED(stream) && c == '\n')) {
	if (ja_fflush(stream) == EOF) {
	    return EOF;
	}
    }

    return c;
}


/*
 * ja_flush_noconv
 */

static int ja_flush_noconv(stream)
ja_FILE *stream;
{
    int n;
    ja_char *p;

    n = 0;
    for (p = stream->base; p < stream->ptr; p++) {
	ja_buf[n++] = *p;
    }
    if (fwrite(ja_buf, sizeof(char), n, stream->fp) < n) {
	return EOF;
    }
    return 0;
}


/*
 * ja_flush_eucjp
 */

static int ja_flush_eucjp(stream)
ja_FILE *stream;
{
    int n;
    ja_char *p;

    n = 0;
    for (p = stream->base; p < stream->ptr; p++) {
	if (*p > 0x100) {
	    ja_buf[n++] = GL2GR(GET_HIGH(*p));
	    ja_buf[n++] = GL2GR(GET_LOW(*p));
	} else if (IS_GR(*p)) {
	    ja_buf[n++] = SS2;
	    ja_buf[n++] = *p;
	} else {
	    ja_buf[n++] = *p;
	}
    }
    if (fwrite(ja_buf, sizeof(char), n, stream->fp) < n) {
	return EOF;
    }
    return 0;
}


/*
 * ja_flush_sjis
 */

static int ja_flush_sjis(stream)
ja_FILE *stream;
{
    int n;
    ja_char *p;
    int c;

    n = 0;
    for (p = stream->base; p < stream->ptr; p++) {
	if (*p < 0x100) {
	    ja_buf[n++] = *p;
	} else {
	    c = ja_jis2sjis(*p);
	    ja_buf[n++] = GET_HIGH(c);
	    ja_buf[n++] = GET_LOW(c);
	}
    }
    if (fwrite(ja_buf, sizeof(char), n, stream->fp) < n) {
	return EOF;
    }
    return 0;
}


/*
 * ja_flush_iso2022jp
 */

static int ja_flush_iso2022jp(stream)
ja_FILE *stream;
{
    int charset;
    int n;
    ja_char *p;

    /*
     * Synchronizes character set.
     */
    if (stream->tty >= 0) {
	ja_tty_sync(stream);
    }

    charset = stream->charset;
    n = 0;
    for (p = stream->base; p < stream->ptr; p++) {
	ja_char c = *p;
	if (c < 0x100) {
	    if (charset != CSET_ASCII) {
		ja_buf[n++] = ESC;
		ja_buf[n++] = ICS;
		ja_buf[n++] = stream->fc_ascii;
		charset = CSET_ASCII;
	    }
	    ja_buf[n++] = c;
	} else {
	    if (charset != CSET_JISX0208) {
		ja_buf[n++] = ESC;
		ja_buf[n++] = ICM;
		ja_buf[n++] = stream->fc_jis;
		charset = CSET_JISX0208;
	    }
	    ja_buf[n++] = GET_HIGH(c);
	    ja_buf[n++] = GET_LOW(c);
	}
    }
    stream->charset = charset;
    if (fwrite(ja_buf, sizeof(char), n, stream->fp) < n) {
	return EOF;
    }
    if (stream->tty >= 0) {
	ja_tty_set(stream);
    }
    return 0;
}
