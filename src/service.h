#ifndef _SERVICE_H
#define _SERVICE_H

#include <inttypes.h>
#include "handle.h"

int service_connect(nspire_handle_t *handle, uint16_t sid);
int service_disconnect(nspire_handle_t *handle);

#endif
