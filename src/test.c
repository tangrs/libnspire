#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "api/nspire.h"

#define do_or_error(x) do { \
		fprintf(stderr, "%s\n", #x); \
		int err = x; \
		if (err) { \
			fprintf(stderr, "%s\n", nspire_strerror(err)); \
			exit(-1); \
		} \
	} while (0)



int main(int arc, char *argv[]) {
	struct nspire_devinfo d;
	struct nspire_image *i;
	//struct nspire_dir_info *dir;
	//char buff[1024];
	nspire_handle_t *h;

	do_or_error(nspire_init(&h));

	do_or_error(nspire_device_info(h, &d));

	//do_or_error(nspire_dirlist(h, "/", &dir));

	do_or_error(nspire_dir_create(h, "/test_this_is_a_long_name"));

	do_or_error(nspire_dir_move(h, "/test_this_is_a_long_name", "/test1"));

	do_or_error(nspire_dir_delete(h, "/test1"));

	do_or_error(nspire_screenshot(h, &i));

	//do_or_error(nspire_file_read(h, "/ndless/ndless.cfg.tns", buff, sizeof(buff), NULL));

	//do_or_error(nspire_dir_delete(h, "/test_this_is_a_long_name"));

	/*FILE *f = fopen(argv[1], "rb");
	struct stat s;
	void *ptr = malloc(16*1024*1024);
	if (f && ptr) {
		fstat(fileno(f), &s);

		fread(ptr, 1, 16*1024*1024, f);
		do_or_error(nspire_os_send(h, ptr, s.st_size));
	}*/
}
