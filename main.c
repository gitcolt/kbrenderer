#include "usb.h"
#include "render_buffer.h"
#include "key.h"
#include "color.h"
#include "letter.h"

#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

extern struct key keys[NUM_KEYS];
extern letter_row letters[][16];

uint32_t render_buffer[RENDER_BUF_W * RENDER_BUF_H];

int main() {
  static struct text_opts opts = {
    .x = 0,
    .y = 0,
    .ch_width = RENDER_BUF_W/4,
    .ch_height = RENDER_BUF_H * 0.8,
    .spacing = RENDER_BUF_W/10,
  };

  render_buffer_init(render_buffer);

  libusb_device_handle *handle;
  if (open_keyboard(&handle)) {
    fprintf(stderr, "Failed to open keyboard\n");
    exit(1);
  }

  keys_init(keys, render_buffer);

  //for (int i = 0; i < 1; ++i) {
  for (int i = 0; i > -RENDER_BUF_W*10; i -= RENDER_BUF_W/30) {
    render_buffer_clear(render_buffer, 0x000000);

    opts.x = i;
    text_print(render_buffer, "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", &opts);
    keys_set_color(keys, render_buffer);

    if (usb_write_key_color(handle) < 0) {
      fprintf(stderr, "Failed to write custom LED colors\n");
      //exit(1);
    }
  }

  free(keys->near_pixels);
  free(keys->near_pixel_weights);
  free(keys->color);
  close_keyboard(handle);
}
