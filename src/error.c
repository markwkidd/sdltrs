/* SDLTRS version Copyright (c): 2006, Mark Grebe */

/* Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
*/
/*
 * Copyright (C) 1992 Clarendon Hill Software.
 *
 * Permission is granted to any individual or institution to use, copy,
 * or redistribute this software, provided this copyright notice is retained. 
 *
 * This software is provided "as is" without any expressed or implied
 * warranty.  If this software brings on any sort of damage -- physical,
 * monetary, emotional, or brain -- too bad.  You've got no one to blame
 * but yourself. 
 *
 * The software may be modified for your own purposes, but modified versions
 * must retain this notice.
 */

/*
   Modified by Timothy Mann, 1996 and later
   $Id: error.c,v 1.8 2008/06/26 04:39:56 mann Exp $
*/
/*
   Modified by Mark Grebe, 2006
   Last modified on Wed May 07 09:12:00 MST 2006 by markgrebe
*/

#include "z80.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#ifdef MACOSX
extern void MessagePrint(char *string);
#endif

extern char *program_name;

void debug(const char *fmt, ...)
{
  va_list args;
  char xfmt[2048];

  strcpy(xfmt, "debug: ");
  strcat(xfmt, fmt);
  /*strcat(xfmt, "\n");*/
  va_start(args, fmt);
  vfprintf(stdout, xfmt, args);
  va_end(args);
}

void error(const char *fmt, ...)
{
  va_list args;
  char xfmt[2048];
#ifdef MACOSX  
  char string[2048];
#endif
  
  strcpy(xfmt, program_name);
  strcat(xfmt, " error: ");
  strcat(xfmt, fmt);
  strcat(xfmt, "\n");
  va_start(args, fmt);
#ifdef MACOSX
  vsprintf(string, xfmt, args);
  MessagePrint(string);
#else  
  vfprintf(stdout, xfmt, args);
#endif  
  va_end(args);
}

