AM_CFLAGS = -Wall -O3
SUBDIRS = api

lib_LTLIBRARIES		= libnspire.la
libnspire_la_CPPFLAGS	= @USB_CFLAGS@
libnspire_la_LIBADD	= @USB_LIBS@
libnspire_la_LDFLAGS	= -export-symbols-regex '^nspire_'
libnspire_la_SOURCES	= *.h services/*.h \
	data.c error.c init.c packet.c service.c usb.c \
	services/devinfo.c \
	services/dir.c \
	services/file.c \
	services/os.c \
	services/screenshot.c

