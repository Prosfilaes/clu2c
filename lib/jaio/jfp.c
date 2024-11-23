/*
 * jfp.c - file pointer manager
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: jfp.c,v 2.0 1996/06/10 08:59:29 ushijima Exp $
 */

#include <config/stdlib.h>
#include <jaio.h>
#include <local.h>


/*
 * Macro definitions
 */

#define MKJFILE(fp, flags, csd)			\
    {						\
	fp, 			/* fp       */	\
	NULL,			/* base     */	\
	NULL,			/* ptr      */	\
	0,			/* cnt      */	\
	flags,			/* flags    */	\
	csd,			/* csd      */	\
	NULL,			/* flush    */	\
	CSET_ASCII,		/* charset  */	\
	FC_ASCII,		/* fc_ascii */	\
	FC_JISX0208_83,		/* fc_jis   */	\
	NULL,			/* decoder  */	\
	-1,			/* tty      */	\
	NULL			/* bytes    */	\
    }


/*
 * Internal functions declarations
 */

static void ja_cleanup();


/*
 * External variables
 */

/* The three primitive streams */

ja_FILE ja_stdio[] = {
    MKJFILE(stdin, ja_READING, DEFAULT_INPUT_CODING_SYSTEM),
    MKJFILE(stdout, ja_WRITING, DEFAULT_OUTPUT_CODING_SYSTEM),
    MKJFILE(stderr, ja_WRITING | ja_UNBUFFERED, DEFAULT_OUTPUT_CODING_SYSTEM)
};

/* Initializatoin flag */

int ja_initialized = 0;


/*
 * Internal variables
 */

/* Table of pointers to streams */

static ja_FILE *ja_streams[ja_FOPEN_MAX] = {
    ja_stdin, 
    ja_stdout, 
    ja_stderr
};

/* Table of terminal entries */

static struct ja_ttyent *ja_ttys[ja_FOPEN_MAX];


/*
 * ja_flookup - find a free stream
 *
 * Effects:
 *	Returns a pointer to a free stream if such a stream exists;
 *	otherwise returns a null pointer.  This function has no
 *	concern in the contents of the resulting stream: the invoker
 *	of this function (e.g., the JFOPEN function) must explicitly
 *	initialize it.
 */

ja_FILE *ja_flookup()
{
    int i;

    for (i = 0; i < ja_FOPEN_MAX; i++) {
	ja_FILE *stream = ja_streams[i];
	if (stream == NULL) {
	    stream = (ja_FILE *) malloc(sizeof(ja_FILE));
	    ja_streams[i] = stream;
	    return stream;
	} else if (stream->flags == 0) {
	    return stream;
	}
    }
    return NULL;
}


/*
 * ja_forall - apply a function to all active streams
 */

int ja_forall(function)
int (*function)();
{
    int i;
    int status;

    status = 0;
    for (i = 0; i < ja_FOPEN_MAX; i++) {
	ja_FILE *stream = ja_streams[i];
	if (stream != NULL && stream->flags != 0) {
	    status |= (*function)(stream);
	}
    }
    return status;
}


/*
 * ja_init - ensure flushing at program termination
 *
 * Effects:
 *	The invocation of this function ensures that for all active
 *	output or update streams any unwritten buffer contents will be
 *	written to the associated files when the program is about to
 *	terminate.
 *
 * Usage:
 *	This function should be invoked whenever an output buffer is
 *	allocated for a stream unless not yet invoked.
 */

void ja_init()
{
    if (ja_initialized) {
	return;
    }
    ja_initialized = 1;
    atexit(ja_cleanup);
}


/*
 * ja_cleanup
 */

static void ja_cleanup()
{
    ja_forall(ja_fclose);
}


/*
 * ja_tty_lookup
 */

int ja_tty_lookup(name, stream)
char *name;
ja_FILE *stream;
{
    int i;
    struct ja_ttyent *ent;

    for (i = 0; ja_ttys[i] != NULL; i++) {
	if (strcmp(ja_ttys[i]->name, name) == 0) {
	    return i;
	}
    }
    ent = (struct ja_ttyent *) malloc(sizeof(struct ja_ttyent));
    ent->name = (char *) malloc(strlen(name) + 1);
    strcpy(ent->name, name);
    ent->fd = -1;
    ent->charset = CSET_ASCII;
    ent->fp = stream;
    ja_ttys[i] = ent;
    return i;
}


/*
 * ja_tty_sync
 */

int ja_tty_sync(stream)
ja_FILE *stream;
{
    struct ja_ttyent *ent;

    if (stream->tty < 0) {
	return -1;
    }

    ent = ja_ttys[stream->tty];
    if (ent->fd >= 0
	&& ent->fd != ja_fileno(stream)
	&& ent->charset != stream->charset)
    {
	/*
	 * Synchronization is needed.
	 */
	if (ent->fp == NULL) {
	    ent->fp = ja_fopen(ent->name, "w");
	    if (ent->fp == NULL) {
		return -1;
	    }
	}
	ja_setcset(stream->charset, ent->fp);
	ja_tty_set(stream);
    }
    return 0;
}


/*
 * ja_tty_set
 */

int ja_tty_set(stream)
ja_FILE *stream;
{
    struct ja_ttyent *ent;

    if (stream->tty < 0) {
	return -1;
    }

    ent = ja_ttys[stream->tty];
    ent->fd = ja_fileno(stream);
    ent->charset = stream->charset;
    return 0;
}
