/*
 * Copyright (c) 2019 Andri Yngvason
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#include <GLES2/gl2.h>
#include <EGL/egl.h>

struct dmabuf_frame;

struct renderer {
	EGLDisplay display;
	EGLSurface surface;
	EGLContext context;
	GLuint dmabuf_shader_program;
	GLuint texture_shader_program;
	uint32_t width;
	uint32_t height;
	GLint read_format;
	GLint read_type;
};

int renderer_init(struct renderer* self, uint32_t width, uint32_t height);
void renderer_destroy(struct renderer* self);

int render_dmabuf_frame(struct renderer* self, struct dmabuf_frame* frame);
int render_framebuffer(struct renderer* self, const void* addr, uint32_t format,
		       uint32_t width, uint32_t height, uint32_t stride);

/* Copy a horizontal stripe from the GL frame into a pixel buffer */
void render_copy_pixels(struct renderer* self, void* dst, uint32_t y,
                        uint32_t height);
