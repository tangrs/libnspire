#include <stdlib.h>
#include <string.h>

#include "packet.h"
#include "error.h"
#include "usb.h"

int nspire_init(nspire_handle_t **ptr) {
	int ret;
	struct packet p;
	nspire_handle_t *h = malloc(sizeof(*h));

	if (!h)
		return -NSPIRE_ERR_NOMEM;

	if ( (ret = usb_init()) )
		goto error;

	if ( (ret = usb_get_device(&h->device)) )
		goto error;

	h->host_addr = 0x6400;
	h->device_addr = 0x6401;
	h->host_sid = 0x4003;
	h->device_sid = 0x4003;
	h->connected = 0;
	h->seq = 1;

	if ( (ret = packet_recv(h, NULL)) )
		goto error_free_usb;

	p = packet_new(h);
	packet_set_data(p, 0x64, 0x01, 0xFF, 0x00);
	if ( (ret = packet_send(h, p)) )
		goto error_free_usb;

	h->host_sid = 0x8000;

	*ptr = h;

	return NSPIRE_ERR_SUCCESS;

error_free_usb:
	usb_free_device(&h->device);
error:
	free(h);
	return ret;
}
