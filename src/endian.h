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
