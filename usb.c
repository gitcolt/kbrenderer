#include "keys.h"

#include <libusb-1.0/libusb.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

extern struct key keys[NUM_KEYS];

uint8_t data_start[64] = {
	0x04, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8_t data_end[64] = {
	0x04, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8_t data_settings[64] = {
	0x04, 0x1b, 0x02, 0x11, 0x03, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

int write_usb_data(libusb_device_handle *handle, unsigned char *data, int length) {
  int res = 0;
  int transferred = 0;
  uint8_t buffer[64];

  // write data packet to endpoint 0
  res += libusb_control_transfer(
      handle, // dev_handle
      0x21,
      0x09,
      0x0204,
      0x0001,
      data,
      length,
      500 // timeout
      );
  if (res < 0) {
    fprintf(stderr, "Failed to write to endpoint 0\n");
    return res;
  }

  // read from endpoint 2
  res += libusb_interrupt_transfer(
      handle,
      0x82, // endpoint
      buffer,
      64,
      &transferred,
      500 // timeout
      );
  if (res < 0) {
    fprintf(stderr, "Failed to read from endpoint 2\n");
    return res;
  }
  return res;
}

int usb_write_start(libusb_device_handle *handle) {
  int res = 0;
  res += write_usb_data(handle, data_start, 64);
  if (res < 0) {
    fprintf(stderr, "Failed to write start segment\n");
  }
  return res;
}

int usb_write_end(libusb_device_handle *handle) {
  int res = 0;
  res += write_usb_data(handle, data_end, 64);
  if (res < 0) {
    fprintf(stderr, "Failed to write end segment\n");
    return res;
  }
  return res;
}

int usb_write_key_color(libusb_device_handle *handle) {
  int res = 0;

  res += usb_write_start(handle);

  uint8_t data_buf[64];
  memcpy(data_buf, data_settings, 64 * sizeof(uint8_t));

  for (int i = 0; i < sizeof(keys)/sizeof(struct key); i++) {
    struct key key = keys[i];
    if (!key.dirty)
      continue;

    // keycode
    data_buf[1] = key.code[0];
    data_buf[5] = key.code[1];
    data_buf[6] = key.code[2];

    data_buf[ 8] = key.color->r;
    data_buf[ 9] = key.color->g;
    data_buf[10] = key.color->b;

    key.dirty = 0;

    res += write_usb_data(handle, data_buf, 64);
    if (res < 0) {
      fprintf(stderr, "Failed to write custom data\n");
      return res;
    }

    res += usb_write_end(handle);
  }
  return res;
} 

int open_keyboard(libusb_device_handle **handle) {
  int res = 0;
  res = libusb_init(NULL);
  if (res < 0) {
    fprintf(stderr, "Failed to initialize libusb\n");
    return res;
  }

  *handle = libusb_open_device_with_vid_pid(NULL, 0x0c45, 0x5004);
  if (!*handle) {
    fprintf(stderr, "Failed to open device\n");
    res++;
    return res;
  }

  if (libusb_kernel_driver_active(*handle, 0)) {
    res += libusb_detach_kernel_driver(*handle, 0);
    if (res) {
      fprintf(stderr, "Failed to detach kernel driver from interface 0\n");
      return res;
    }
  }

  // detach kernel driver on interface 1
  if (libusb_kernel_driver_active(*handle, 1)) {
    res += libusb_detach_kernel_driver(*handle, 1);
    if (res) {
      fprintf(stderr, "Failed to detach kernel driver from interface 1\n");
      return res;
    }
  }

  res += libusb_claim_interface(*handle, 0);
  if (res) {
    fprintf(stderr, "Failed to claim interface 0\n");
    return res;
  }

  // claim interface 1
  res += libusb_claim_interface(*handle, 1);
  if (res) {
    fprintf(stderr, "Failed to claim interface 1\n");
    return res;
  }

  return res;
}

int close_keyboard(libusb_device_handle *handle) {
  libusb_release_interface(handle, 1);
  libusb_attach_kernel_driver(handle, 1);

  libusb_exit(NULL);
  return 0;
}


int write_color(libusb_device_handle *handle, struct color *color) {
  int res = 0;

  uint8_t data_settings_1[64];
  memcpy(data_settings_1, data_settings, 64 * sizeof(uint8_t));
  uint8_t data_settings_2[64];
  memcpy(data_settings_2, data_settings, 64 * sizeof(uint8_t));

  data_settings_1[1] = 0x0b;
  data_settings_1[5] = 0x04;
  data_settings_2[2] = 0x02;
  data_settings_2[4] = 0x03;
  data_settings_2[5] = 0x05;

  data_settings_2[ 8] = color->r;
  data_settings_2[ 9] = color->g;
  data_settings_2[10] = color->b;

  res += write_usb_data(handle, data_start, 64);
  if (res < 0) {
    fprintf(stderr, "Failed to write start segment\n");
    return res;
  }
  res += write_usb_data(handle, data_settings_1, 64);
  if (res < 0) {
    fprintf(stderr, "Failed to write keycode data\n");
    return res;
  }
  res += write_usb_data(handle, data_settings_2, 64);
  if (res < 0) {
    fprintf(stderr, "Failed to write color data\n");
    return res;
  }
  res += write_usb_data(handle, data_end, 64);
  if (res < 0) {
    fprintf(stderr, "Failed to write end segment\n");
    return res;
  }

  return res;
}
