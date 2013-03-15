#ifndef _USB_H
#define _USB_H

#include <libusb.h>

typedef struct {
	libusb_device_handle *dev;
	unsigned char ep_in, ep_out;
} usb_device_t;

int usb_init();
void usb_finish();
int usb_get_device(usb_device_t *handle);
void usb_free_device(usb_device_t *handle);
int usb_write(usb_device_t *handle, void *ptr, int len);
int usb_read(usb_device_t *handle, void *ptr, int len);

#endif
