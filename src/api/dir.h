#ifndef NSP_DIR_H
#define NSP_DIR_H

#include "file.h"

enum nspire_dir_type {
	NSPIRE_FILE	= 0,
	NSPIRE_DIR	= 1
};

struct nspire_dir_item {
	char name[240];
	unsigned long size;
	enum nspire_dir_type type;
};

struct nspire_dir_info {
	unsigned long num;
	struct nspire_dir_item items[];
};

int nspire_dirlist(nspire_handle_t *, const char *, struct nspire_dir_info **);
void nspire_dirlist_free(struct nspire_dir_info *d);
int nspire_dir_create(nspire_handle_t *handle, const char *path);
int nspire_dir_delete(nspire_handle_t *handle, const char *path);

#define nspire_dir_move		nspire_file_move
#define nspire_dir_rename	nspire_file_move

#endif
