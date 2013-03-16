/*
    This file is part of libnspire.

    libnspire is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libnspire is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libnspire.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _ENDIAN_H
#define _ENDIAN_H

#include "config.h"
#include <inttypes.h>

#if defined(ENDIAN_LITTLE)

/* No bswap16 for x86 */
#define dcpu16(x) (uint16_t)__builtin_bswap32((x)<<16)
#define dcpu32(x) __builtin_bswap32(x)
#define dcpu64(x) __builtin_bswap64(x)

#elif defined(ENDIAN_BIG)

#define dcpu16(x) (x)
#define dcpu32(x) (x)
#define dcpu64(x) (x)

#else
#error Could not determine endian.
#endif

#endif
