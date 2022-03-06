#include "keys.h"
#include "render_buffer.h"
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct key keys[] = {
	{
    .name = "Esc",
    .code = {0x54, 0x00, 0x00},
    .pos = {
      .x = .019,
      .y = .072,
    },
    .dirty = 0,
  },
	{
    .name = "F1",
    .code = {0x57, 0x03, 0x00},
    .pos = {
      .x = 0.130,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F2",
    .code = {0x5a, 0x06, 0x00},
    .pos = {
      .x = 0.186,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F3",
    .code = {0x5d, 0x09, 0x00},
    .pos = {
      .x = 0.241,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F4",
    .code = {0x60, 0x0c, 0x00},
    .pos = {
      .x = 0.297,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F5",
    .code = {0x63, 0x0f, 0x00},
    .pos = {
      .x = 0.382,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F6",
    .code = {0x66, 0x12, 0x00},
    .pos = {
      .x = 0.434,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F7",
    .code = {0x69, 0x15, 0x00},
    .pos = {
      .x = 0.494,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F8",
    .code = {0x6c, 0x18, 0x00},
    .pos = {
      .x = 0.548,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F9",
    .code = {0x6f, 0x1b, 0x00},
    .pos = {
      .x = 0.629,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F10",
    .code = {0x72, 0x1e, 0x00},
    .pos = {
      .x = 0.688,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F11",
    .code = {0x75, 0x21, 0x00},
    .pos = {
      .x = 0.744,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "F12",
    .code = {0x78, 0x24, 0x00},
    .pos = {
      .x = 0.800,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "PrtSc",
    .code = {0x7e, 0x2a, 0x00},
    .pos = {
      .x = 0.873,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "ScrLk",
    .code = {0x81, 0x2d, 0x00},
    .pos = {
      .x = 0.928,
      .y = 0.072,
    },
    .dirty = 0,
  },
	{
    .name = "Pause",
    .code = {0x84, 0x30, 0x00},
    .pos = {
      .x = 0.984,
      .y = 0.072,
    },
    .dirty = 0,
  },

	{
    .name = "Tilde",
    .code = {0x93, 0x3f, 0x00},
    .pos = {
      .x = 0.017,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "1",
    .code = {0x96, 0x42, 0x00},
    .pos = {
      .x = 0.076,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "2",
    .code = {0x99, 0x45, 0x00},
    .pos = {
      .x = 0.131,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "3",
    .code = {0x9c, 0x48, 0x00},
    .pos = {
      .x = 0.186,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "4",
    .code = {0x8f, 0x4b, 0x00},
    .pos = {
      .x = 0.242,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "5",
    .code = {0xa2, 0x4e, 0x00},
    .pos = {
      .x = 0.297,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "6",
    .code = {0xa5, 0x51, 0x00},
    .pos = {
      .x = 0.354,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "7",
    .code = {0xa8, 0x54, 0x00},
    .pos = {
      .x = 0.408,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "8",
    .code = {0xab, 0x57, 0x00},
    .pos = {
      .x = 0.466,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "9",
    .code = {0xae, 0x5a, 0x00},
    .pos = {
      .x = 0.524,
      .y = 0.266,
    },
    .dirty = 0,
  },
  {
    .name = "0",
    .code = {0xb1, 0x5d, 0x00},
    .pos = {
      .x = 0.578,
      .y = 0.266,
    },
    .dirty = 0,
  },
	{
    .name = "Minus",
    .code = {0xb4, 0x60, 0x00},
    .pos = {
      .x = 0.636,
      .y = 0.266,
    },
    .dirty = 0,
  },
	{
    .name = "Equals",
    .code = {0xb7, 0x63, 0x00},
    .pos = {
      .x = 0.692,
      .y = 0.266,
    },
    .dirty = 0,
  },
	{
    .name = "Backspace",
    .code = {0xba, 0x66, 0x00},
    .pos = {
      .x = 0.774,
      .y = 0.266,
    },
    .dirty = 0,
  },
	{
    .name = "Insert",
    .code = {0xbd, 0x69, 0x00},
    .pos = {
      .x = 0.873,
      .y = 0.266,
    },
    .dirty = 0,
  },
	{
    .name = "Home",
    .code = {0xc0, 0x6c, 0x00},
    .pos = {
      .x = 0.931,
      .y = 0.266,
    },
    .dirty = 0,
  },
	{
    .name = "PgUp",
    .code = {0xc3, 0x6f, 0x00},
    .pos = {
      .x = 0.987,
      .y = 0.266,
    },
    .dirty = 0,
  },

	{
    .name = "Tab",
    .code = {0xd2, 0x7e, 0x00},
    .pos = {
      .x = 0.034,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "q",
    .code = {0xd5, 0x81, 0x00},
    .pos = {
      .x = 0.103,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "w",
    .code = {0xd8, 0x84, 0x00},
    .pos = {
      .x = 0.159,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "e",
    .code = {0xdb, 0x87, 0x00},
    .pos = {
      .x = 0.215,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "r",
    .code = {0xde, 0x8a, 0x00},
    .pos = {
      .x = 0.270,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "t",
    .code = {0xe1, 0x8d, 0x00},
    .pos = {
      .x = 0.326,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "y",
    .code = {0xe4, 0x90, 0x00},
    .pos = {
      .x = 0.384,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "u",
    .code = {0xe7, 0x93, 0x00},
    .pos = {
      .x = 0.437,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "i",
    .code = {0xea, 0x96, 0x00},
    .pos = {
      .x = 0.495,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "o",
    .code = {0xed, 0x99, 0x00},
    .pos = {
      .x = 0.548,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "p",
    .code = {0xf0, 0x9c, 0x00},
    .pos = {
      .x = 0.604,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "Bracket_l",
    .code = {0xf6, 0xa2, 0x00},
    .pos = {
      .x = 0.660,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "Bracket_r",
    .code = {0x35, 0xe1, 0x00},
    .pos = {
      .x = 0.716,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "Backslash",
    .code = {0x53, 0xff, 0x00},
    //.code = {0x2f, 0xdb, 0x00},
    .pos = {
      .x = 0.785,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "Delete",
    .code = {0xfc, 0xa8, 0x00},
    .pos = {
      .x = 0.867,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "End",
    .code = {0xff, 0xab, 0x00},
    .pos = {
      .x = 0.931,
      .y = 0.433,
    },
    .dirty = 0,
  },
	{
    .name = "PgDn",
    .code = {0x02, 0xae, 0x00},
    .pos = {
      .x = 0.984,
      .y = 0.433,
    },
    .dirty = 0,
  },

	{
    .name = "Caps_Lock",
    .code = {0x11, 0xbd, 0x00},
    .pos = {
      .x = 0.042,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "a",
    .code = {0x14, 0xc0, 0x00},
    .pos = {
      .x = 0.118,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "s",
    .code = {0x17, 0xc3, 0x00},
    .pos = {
      .x = 0.173,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "d",
    .code = {0x1a, 0xc6, 0x00},
    .pos = {
      .x = 0.228,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "f",
    .code = {0x1d, 0xc9, 0x00},
    .pos = {
      .x = 0.286,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "g",
    .code = {0x20, 0xcc, 0x00},
    .pos = {
      .x = 0.340,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "h",
    .code = {0x23, 0xcf, 0x00},
    .pos = {
      .x = 0.396,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "j",
    .code = {0x26, 0xd2, 0x00},
    .pos = {
      .x = 0.451,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "k",
    .code = {0x29, 0xd5, 0x00},
    .pos = {
      .x = 0.508,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "l",
    .code = {0x2c, 0xd8, 0x00},
    .pos = {
      .x = 0.563,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "Semicolon",
    .code = {0x72, 0x1d, 0x01},
    .pos = {
      .x = 0.621,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "Apostrophe",
    .code = {0x32, 0xde, 0x00},
    .pos = {
      .x = 0.676,
      .y = 0.6,
    },
    .dirty = 0,
  },
	{
    .name = "Return",
    .code = {0x38, 0xe4, 0x00},
    .pos = {
      .x = 0.768,
      .y = 0.6,
    },
    .dirty = 0,
  },

	{
    .name = "Shift_l",
    .code = {0x50, 0xfc, 0x00},
    .pos = {
      .x = 0.057,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "z",
    .code = {0x57, 0x02, 0x01},
    .pos = {
      .x = 0.145,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "x",
    .code = {0x5a, 0x05, 0x01},
    .pos = {
      .x = 0.202,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "c",
    .code = {0x5d, 0x08, 0x01},
    .pos = {
      .x = 0.256,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "v",
    .code = {0x60, 0x0b, 0x01},
    .pos = {
      .x = 0.311,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "b",
    .code = {0x63, 0x0e, 0x01},
    .pos = {
      .x = 0.369,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "n",
    .code = {0x66, 0x11, 0x01},
    .pos = {
      .x = 0.424,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "m",
    .code = {0x69, 0x14, 0x01},
    .pos = {
      .x = 0.478,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "Comma",
    .code = {0x6c, 0x17, 0x01},
    .pos = {
      .x = 0.537,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "Period",
    .code = {0x6f, 0x1a, 0x01},
    .pos = {
      .x = 589,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "Slash",
    .code = {0x75, 0x20, 0x01},
    .pos = {
      .x = 0.647,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "Shift_r",
    .code = {0x78, 0x23, 0x01},
    .pos = {
      .x = 0.752,
      .y = 0.674,
    },
    .dirty = 0,
  },
	{
    .name = "Up",
    .code = {0x7e, 0x29, 0x01},
    .pos = {
      .x = 0.924,
      .y = 0.674,
    },
    .dirty = 0,
  },

	{
    .name = "Ctrl_l",
    .code = {0x4f, 0x3b, 0x01},
    .pos = {
      .x = 0.027,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Super_l",
    .code = {0x93, 0x3e, 0x01},
    .pos = {
      .x = 0.099,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Alt_l",
    .code = {0x96, 0x41, 0x01},
    .pos = {
      .x = 0.165,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Space",
    .code = {0x99, 0x44, 0x01},
    .pos = {
      .x = 0.376,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Alt_r",
    .code = {0x9c, 0x47, 0x01},
    .pos = {
      .x = 0.584,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Fn",
    .code = {0x9f, 0x4a, 0x01},
    .pos = {
      .x = 0.652,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Menu",
    .code = {0xa2, 0x4d, 0x01},
    .pos = {
      .x = 0.721,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Ctrl_r",
    .code = {0xa8, 0x53, 0x01},
    .pos = {
      .x = 0.793,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Left",
    .code = {0xba, 0x65, 0x01},
    .pos = {
      .x = 0.866,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Down",
    .code = {0xbd, 0x68, 0x01},
    .pos = {
      .x = 0.924,
      .y = 0.933,
    },
    .dirty = 0,
  },
	{
    .name = "Right",
    .code = {0xc0, 0x6b, 0x01},
    .pos = {
      .x = 0.978,
      .y = 0.933,
    },
    .dirty = 0,
  },
};

void keys_init(struct key *keys, uint32_t *pixel_buf) {
  static uint32_t *near_pixels_buf[999];
  static float near_pixel_weights_buf[999];
  float key_h = 0.17;
  float key_w = key_h * RENDER_BUF_H/RENDER_BUF_W;

  for (int i = 0; i < NUM_KEYS; ++i) {
    int num_near_pixels = 0;
    for (int row = 0; row < RENDER_BUF_H; ++row) {
      for (int col = 0; col < RENDER_BUF_W; ++col) {
        float normalized_x = (float)col / RENDER_BUF_W;
        float normalized_y = (float)row / RENDER_BUF_H;

        if (fabs(normalized_x - keys[i].pos.x) < key_w/4 && fabs(normalized_y - keys[i].pos.y) < key_h/4) {
          //float dist = sqrt(pow(normalized_x - keys[i].pos.x, 2) + pow(normalized_y - keys[i].pos.y, 2));
          near_pixels_buf[num_near_pixels] = &pixel_buf[row * RENDER_BUF_W + col];
          //near_pixel_weights_buf[num_near_pixels] = (key_h - dist) / key_h;
          num_near_pixels++;
        }
      }
    }
    keys[i].num_near_pixels = num_near_pixels;
    keys[i].near_pixels = malloc(sizeof(uint32_t *) * num_near_pixels);
    memcpy(keys[i].near_pixels, near_pixels_buf, sizeof(uint32_t *) * num_near_pixels);
    keys[i].near_pixel_weights = malloc(sizeof(float) * num_near_pixels);
    //memcpy(keys[i].near_pixel_weights, near_pixel_weights_buf, sizeof(float) * num_near_pixels);

    keys[i].color = malloc(sizeof(struct color));

    keys[i].color->r = 0x00;
    keys[i].color->g = 0x00;
    keys[i].color->b = 0xFF;
  }
}

void keys_set_color(struct key *keys, uint32_t *pixel_buf) {
  for (int i = 0; i < NUM_KEYS; ++i) {
    uint16_t r = 0;
    uint16_t g = 0;
    uint16_t b = 0;
    for (int j = 0; j < keys[i].num_near_pixels; ++j) {
      uint32_t pixel = *keys[i].near_pixels[j];
      r += ((pixel & 0xFF0000) >> 16);
      g += ((pixel & 0x00FF00) >> 8);
      b += (pixel & 0x0000FF);
    }

    if (keys[i].num_near_pixels > 0) {
      keys[i].color->r = r / keys[i].num_near_pixels;
      keys[i].color->g = g / keys[i].num_near_pixels;
      keys[i].color->b = b / keys[i].num_near_pixels;
      keys[i].dirty = 1;
    }
      /*
      uint8_t rr = r / keys[i].num_near_pixels;
      uint8_t gg = g / keys[i].num_near_pixels;
      uint8_t bb = b / keys[i].num_near_pixels;
      if (keys[i].color->r != rr || keys[i].color->g != gg || keys[i].color->b != bb) {
        keys[i].color->r = rr;
        keys[i].color->g = gg;
        keys[i].color->b = bb;
        keys[i].dirty = 1;
      }
      */
  }
}

