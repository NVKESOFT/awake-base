#ifndef BLOCK_H
#define BLOCK_H

#include <stdbool.h>
#include <SDL3/SDL.h>

#include "structs.h"

struct solid_body create_block(float x, float y, float w, float h);
bool check_collision(SDL_FRect a, SDL_FRect b);
void render_block(SDL_Renderer *rnd, struct solid_body *b);

#endif
