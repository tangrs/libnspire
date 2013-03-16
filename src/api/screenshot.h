#ifndef NSP_SCREENSHOT_H
#define NSP_SCREENSHOT_H

#include <inttypes.h>
#include "handle.h"

struct nspire_image {
	uint16_t width, height;
	uint8_t bbp;

	unsigned char data[];
};

int nspire_screenshot(nspire_handle_t *handle, struct nspire_image **ptr);

#endif
