#include <stdlib.h>
#include <string.h>

#include "handle.h"
#include "error.h"
#include "data.h"
#include "service.h"
#include "dir.h"

static int dir_enum(nspire_handle_t *handle, struct nspire_dir_info **d) {
	int ret;
	char *name;
	uint32_t size;
	uint8_t is_dir;
	struct nspire_dir_info *new_dir;
	struct nspire_dir_item *current;

	unsigned char buffer[254];

	if ( (ret = data_write8(handle, 0x0E)) )
		return ret;
	if ( (ret = data_read(handle, buffer, sizeof(buffer))) )
		return ret;

	if (buffer[0] == 0xFF)
		return 1;

	if ( (ret = data_scan("hbswwb0", buffer, sizeof(buffer),
			NULL, NULL, &name, &size, NULL, &is_dir)) )
		return ret;

	new_dir = realloc(*d, sizeof(struct nspire_dir_info) +
			(((*d)->num + 1) * sizeof(struct nspire_dir_item)));
	if (!new_dir)
		return -NSPIRE_ERR_NOMEM;
	current = new_dir->items + new_dir->num;
	new_dir->num++;
	*d = new_dir;

	strncpy(current->name, name, sizeof(current->name));
	current->name[sizeof(current->name)-1] = '\0';
	current->size = size;
	current->type = is_dir;

	return NSPIRE_ERR_SUCCESS;
}

int nspire_dirlist(nspire_handle_t *handle, const char *path,
		struct nspire_dir_info **info_ptr) {
	int ret;
	size_t len;
	uint8_t buffer[254], code;
	struct nspire_dir_info *d;

	if ( (ret = service_connect(handle, 0x4060)) )
		return ret;

	/* Begin dir enum */
	if ( (ret = data_build("bs", buffer, sizeof(buffer), &len,
			0x0D, path)) )
		goto end;

	if ( (ret = data_write(handle, buffer, len)) )
		goto end;

	if ( (ret = data_read(handle, buffer, 2)) )
		goto end;

	if ( (ret = data_scan("bb", buffer, sizeof(buffer),
			NULL, &code)) )
		goto end;

	switch (code) {
	case 0x0A:
		ret = -NSPIRE_ERR_NONEXIST;
		goto end;
	case 0x0F:
		ret = -NSPIRE_ERR_INVALID;
		goto end;
	}

	d = malloc(sizeof(struct nspire_dir_info));
	(d)->num = 0;
	if (!d) {
		ret = -NSPIRE_ERR_NOMEM;
		goto end;
	}

	*info_ptr = d;
	/* Start enumerating */
	while (1) {
		ret = dir_enum(handle, info_ptr);
		if (ret < 0) {
			free(*info_ptr);
			goto end;
		}

		if (ret)
			break;
	}

	ret = NSPIRE_ERR_SUCCESS;
end:
	service_disconnect(handle);
	return ret;
}

void nspire_dirlist_free(struct nspire_dir_info *d) {
	free(d);
}

int nspire_dir_create(nspire_handle_t *handle, const char *path) {
	int ret;
	size_t len;
	uint16_t result;
	uint8_t buffer[254];


	if ( (ret = service_connect(handle, 0x4060)) )
		return ret;

	if ( (ret = data_build("hs", buffer, sizeof(buffer), &len,
			0x0A03, path)) )
		goto end;

	if ( (ret = data_write(handle, &buffer, len)) )
		goto end;

	if ( (ret = data_read(handle, &buffer, 2)) )
		goto end;

	if ( (ret = data_scan("h", buffer, sizeof(buffer), &result)) )
		goto end;

	ret = (result == 0xFF00) ? NSPIRE_ERR_SUCCESS : -NSPIRE_ERR_EXISTS;
end:
	service_disconnect(handle);
	return ret;
}

int nspire_dir_delete(nspire_handle_t *handle, const char *path) {
	int ret;
	size_t len;
	uint16_t result;
	uint8_t buffer[254];


	if ( (ret = service_connect(handle, 0x4060)) )
		return ret;

	if ( (ret = data_build("hs", buffer, sizeof(buffer), &len,
			0x0B03, path)) )
		goto end;

	if ( (ret = data_write(handle, &buffer, len)) )
		goto end;

	if ( (ret = data_read(handle, &buffer, 2)) )
		goto end;

	if ( (ret = data_scan("h", buffer, sizeof(buffer), &result)) )
		goto end;

	ret = (result == 0xFF00) ? NSPIRE_ERR_SUCCESS : -NSPIRE_ERR_NONEXIST;
end:
	service_disconnect(handle);
	return ret;
}