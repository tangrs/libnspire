#ifndef NSP_ERROR_H
#define NSP_ERROR_H

enum {
	NSPIRE_ERR_SUCCESS,

	/* Generic */
	NSPIRE_ERR_TIMEOUT,
	NSPIRE_ERR_NOMEM,
	NSPIRE_ERR_INVALID,

	/* USB */
	NSPIRE_ERR_LIBUSB,
	NSPIRE_ERR_NODEVICE,

	/* Packet */
	NSPIRE_ERR_INVALPKT,
	NSPIRE_ERR_NACK,

	/* Service */
	NSPIRE_ERR_BUSY,

	/* File/Dir services */
	NSPIRE_ERR_EXISTS,
	NSPIRE_ERR_NONEXIST,

	/* OS install */
	NSPIRE_ERR_OSFAILED,

	/* Number of errors */
	NSPIRE_ERR_MAX
};

const char *nspire_strerror(int error);

#endif
