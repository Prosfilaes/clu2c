/*
 * signal.h - header for signal handling routines
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: signal.h,v 2.0 1996/06/10 09:05:43 ushijima Exp $
 */

#ifndef CONFIG_SIGNAL_H
#define CONFIG_SIGNAL_H


#include <config.h>


#ifdef HAVE_SIGNAL_H
#   include <signal.h>
#   ifndef HAVE_SIGHOLD
#	define sighold(sig) sigblock(sigmask(sig))
#	define sigrelse(sig) sigsetmask(sigblock(0) & ~sigmask(sig))
#   endif
#else
#   define signal(sig, handler) 0
#   define sighold(sig) 0
#   define sigrelse(sig) 0
#endif

#ifndef NSIG
#   define NSIG 32
#endif


#endif /* not CONFIG_SIGNAL_H */
