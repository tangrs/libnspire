#include "error.h"
#include "data.h"
#include "packet.h"

int service_connect(nspire_handle_t *handle, uint16_t sid) {
	if (handle->connected)
		return -NSPIRE_ERR_BUSY;

	handle->connected = 1;
	handle->device_sid = sid;

	return NSPIRE_ERR_SUCCESS;
}

static void mod_src(struct packet *p) {
	p->src_sid = 0x40DE;
}

int service_disconnect(nspire_handle_t *handle) {
	int ret;
	struct packet p;
	uint8_t data[] = {
		(handle->host_sid>>8) & 0xFF,
		(handle->host_sid>>0) & 0xFF };

	if (!handle->connected)
		return NSPIRE_ERR_SUCCESS;

	p = packet_new(handle);
	if ( (ret = data_write_special(handle, &data, 2, mod_src)) ) {
		return ret;
	}

	handle->connected = 0;
	handle->host_sid++;

	return NSPIRE_ERR_SUCCESS;
}
