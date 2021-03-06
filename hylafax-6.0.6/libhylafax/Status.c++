/*	$Id$ */
/*
 * Copyright (c) 2007 iFAX Solutions, Inc.
 * HylaFAX is a trademark of Silicon Graphics
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee, provided
 * that (i) the above copyright notices and this permission notice appear in
 * all copies of the software and related documentation, and (ii) the names of
 * Sam Leffler and Silicon Graphics may not be used in any advertising or
 * publicity relating to the software without the specific, prior written
 * permission of Sam Leffler and Silicon Graphics.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#include <stdarg.h>

#include "Status.h"

Status::Status (void)
  :  id(0)
{
}

Status::Status (int code, const char* fmt, ...)
 : id(code)
{
    va_list ap;
    va_start(ap, fmt);
    message = fxStr::vformat(fmt, ap);
    va_end(ap);
}

void Status::clear (void)
{
    id = 0;
    message = fxStr::null;
}

const char* Status::string (void) const
{
    return message;
}

int Status::value (void) const
{
    return id;
}

void Status::append (int code, const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    message.append("; ");
    message.append(fxStr::vformat(fmt, ap));
    va_end(ap);
    /*
     * The last error code is always the "final" one
     */
    id = code;
}
