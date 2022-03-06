#ifndef KEYS_H
#define KEYS_H

#include "color.h"
#include <stdint.h>
#include <stddef.h>

#define NUM_KEYS 87

typedef struct s_xy_coord_f {
  float x;
  float y;
} xy_coord_f;

typedef struct s_xy_coord_i {
  unsigned x;
  unsigned y;
} xy_coord_i;

struct key {
  char name[20];
  uint8_t code[3];
  xy_coord_f pos;
  uint32_t **near_pixels;
  float *near_pixel_weights;
  unsigned num_near_pixels;
  struct color *color;
  int dirty;
};

void keys_init(struct key *keys, uint32_t *pixel_buf);

void keys_set_color(struct key *keys, uint32_t *pixel_buf);

#endif
