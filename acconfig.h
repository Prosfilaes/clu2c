
#ifndef CLU2C_CONFIG_H
#define CLU2C_CONFIG_H

@TOP@

/*
 * acconfig.h - additional symbols for config.h
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: acconfig.h,v 2.0 1996/06/10 08:58:00 ushijima Exp $
 */


/* Define to `long' if <time.h> doesn't define.  */
#undef clock_t

/* Define to `long' if <sys/types.h> doesn't define.  */
#undef time_t

/* Define if GNU assembler is used.  */
#undef WITH_GNU_AS

/* Define to default input coding system.  */
#undef DEFAULT_INPUT_CODING_SYSTEM

/* Define to default output coding system.  */
#undef DEFAULT_OUTPUT_CODING_SYSTEM

/* Define if MS-DOS text format is used.  */
#undef MSDOS_TEXT

/* Define if BSD byte operations are preferred.  */
#undef WITH_BSD_BYTE_OPERATIONS

/* Define if getwd is preferred to getcwd.  */
#undef WITH_GETWD

/* Define if emu387 that comes with djgpp is broken.  */
#undef DJGPP_EMU387_BROKEN

/* Define if you do not want the garbage collector to scan data
   segments associated with dynamic libraries.  */
#undef DISABLE_DYNAMIC_LOADING

@BOTTOM@


#endif /* not CLU2C_CONFIG_H */
