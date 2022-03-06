#ifndef RENDER_BUFFER_H
#define RENDER_BUFFER_H

#include <stdint.h>

#define RENDER_BUF_W 250
#define RENDER_BUF_H 100

void render_buffer_init(uint32_t *render_buf);

void render_buffer_clear(uint32_t *render_buf, uint32_t color);

#endif
