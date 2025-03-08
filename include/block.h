#ifndef BLOCK_H
#define BLOCK_H

#include <SDL3/SDL.h>

typedef struct solid_body solid_body;

solid_body *sb_create(float x, float y, float w, float h);
void sb_destroy(solid_body **sb);

SDL_FRect *sb_get_frame(solid_body *sb);
void sb_render(SDL_Renderer *rnd, solid_body *b);

#endif
