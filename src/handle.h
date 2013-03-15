#ifndef _HANDLE_H
#define _HANDLE_H

#include <inttypes.h>

#include "api/handle.h"
#include "usb.h"

struct nspire_handle {
	usb_device_t device;

	uint16_t host_addr, device_addr;
	uint16_t host_sid, device_sid;
	uint8_t seq, connected;
};

#endif
