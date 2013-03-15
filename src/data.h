#ifndef _DATA_H
#define _DATA_H

#include <stdint.h>
#include "handle.h"
#include "endian.h"
#include "packet.h"

int data_write_special(nspire_handle_t*, void*, size_t,
		void (*)(struct packet *));

int data_write(nspire_handle_t *handle, void *ptr, size_t maxlen);
int data_read(nspire_handle_t *handle, void *ptr, size_t maxlen);
int data_build(const char *, void *, size_t, size_t *, ...);
int data_scan(const char *, const void *, size_t, ...);

static inline int data_write8(nspire_handle_t *handle, uint8_t x) {
	return data_write(handle, &x, 1);
}

static inline int data_write16(nspire_handle_t *handle, uint16_t x) {
	x = dcpu16(x);
	return data_write(handle, &x, 2);
}

#endif
