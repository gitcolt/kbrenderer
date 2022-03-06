#ifndef LETTER_H
#define LETTER_H

#include <stdint.h>

typedef uint16_t letter_row;

void letter_print(uint32_t *render_buf, char ch, int x, int y, int w, int h);

struct text_opts {
  int x;
  int y;
  int ch_width;
  int ch_height;
  int spacing;
};

void text_print(uint32_t *render_buf, char *text, struct text_opts *opts);

#endif
