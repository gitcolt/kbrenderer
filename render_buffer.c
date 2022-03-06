#include "render_buffer.h"
#include "color.h"
#include <stdint.h>
#include <string.h>

void render_buffer_init(uint32_t *render_buf) {
  memset(render_buf, 0, sizeof(uint32_t) * RENDER_BUF_W * RENDER_BUF_H);
}

void render_buffer_clear(uint32_t *render_buf, uint32_t color) {
  for (int i = 0; i < RENDER_BUF_H * RENDER_BUF_W; ++i)
    render_buf[i] = color;
}
