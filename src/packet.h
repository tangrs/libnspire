#ifndef _PACKET_H
#define _PACKET_H

#include <inttypes.h>
#include "handle.h"

struct packet {
    uint16_t    magic,
                src_addr,
                src_sid,
                dst_addr,
                dst_sid,
                data_checksum;
    uint8_t     data_size,
                ack,
                seq,
                header_checksum;
    uint8_t     data[254];
};

#define packet_set_data(p, arr...) do { \
		unsigned char buffer[] = { arr }; \
		p.data_size = sizeof(buffer); \
		memcpy(p.data, buffer, p.data_size); \
	} while (0)

int packet_send(nspire_handle_t *h, struct packet p);
int packet_recv(nspire_handle_t *h, struct packet *p);
struct packet packet_new(nspire_handle_t *h);
int packet_ack(nspire_handle_t *h, struct packet p);
int packet_nack(nspire_handle_t *h, struct packet p);

#endif
