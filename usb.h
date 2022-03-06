#ifndef USB_H
#define USB_H

#include "color.h"

#include <libusb-1.0/libusb.h>

int usb_write_start(libusb_device_handle *handle);
int usb_write_end(libusb_device_handle *handle);
int usb_write_key_color(libusb_device_handle *handle);
int open_keyboard(libusb_device_handle **handle);
int close_keyboard(libusb_device_handle *handle);
int write_color(libusb_device_handle *handle, struct color *color);
int write_usb_data(libusb_device_handle *handle, unsigned char *data, int length);

#endif
