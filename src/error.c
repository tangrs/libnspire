#include <stddef.h>

#include "error.h"

static const char *error_msg[NSPIRE_ERR_MAX] = {
	[NSPIRE_ERR_SUCCESS]	= "No error",
	[NSPIRE_ERR_TIMEOUT]	= "Timeout",
	[NSPIRE_ERR_NOMEM]	= "Out of memory",
	[NSPIRE_ERR_LIBUSB]	= "Libusb error",
	[NSPIRE_ERR_NODEVICE]	= "No device found",
	[NSPIRE_ERR_INVALPKT]	= "Invalid packet received",
	[NSPIRE_ERR_NACK]	= "NACK received",
	[NSPIRE_ERR_BUSY]	= "Busy",
	[NSPIRE_ERR_INVALID]	= "Invalid input",
	[NSPIRE_ERR_EXISTS]	= "Already exists",
	[NSPIRE_ERR_NONEXIST]	= "Path does not exist",

};

static const char* unknown_err = "Unknown error";

const char *nspire_strerror(int error) {
	if (error > 0)
		return unknown_err;

	if (error < -(sizeof(error_msg) / sizeof(const char*)))
		return unknown_err;

	return error_msg[-error];
}
