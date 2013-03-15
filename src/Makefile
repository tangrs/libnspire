CC ?= gcc
LD := gcc
CFLAGS += -O3 -Wall -Werror -g -I./ #-DDEBUG
CFLAGS += $(shell pkg-config libusb-1.0 --cflags)
LDFLAGS += $(shell pkg-config libusb-1.0 --libs)

OBJS := data.o error.o packet.o init.o usb.o service.o
OBJS += services/devinfo.o
OBJS += services/dir.o
OBJS += services/file.o
OBJS += services/os.o
OBJS += services/screenshot.o

test: $(OBJS) test.o
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
