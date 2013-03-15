#ifndef _ENDIAN_H
#define _ENDIAN_H

#include <inttypes.h>

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

/* No bswap16 for x86 */
#define dcpu16(x) (uint16_t)__builtin_bswap32((x)<<16)
#define dcpu32(x) __builtin_bswap32(x)
#define dcpu64(x) __builtin_bswap64(x)

#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

#define dcpu16(x)
#define dcpu32(x)
#define dcpu64(x)

#else
#error Could not determine endian. Please manually define __BYTE_ORDER__
#endif

#endif
