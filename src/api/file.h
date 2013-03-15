#ifndef NSP_FILE_H
#define NSP_FILE_H

int nspire_file_write(nspire_handle_t *, const char *, void*, size_t);
int nspire_file_read(nspire_handle_t *handle, const char *path,
		void* data, size_t size, size_t *read_bytes);
int nspire_file_move(nspire_handle_t *handle, const char *src, const char *dst);
int nspire_file_copy(nspire_handle_t *handle, const char *src, const char *dst);
int nspire_file_delete(nspire_handle_t *handle, const char *path);

#define nspire_file_touch(h,p)	nspire_file_write((h), (p), NULL, 0);
#define nspire_file_rename	nspire_file_move

#endif
