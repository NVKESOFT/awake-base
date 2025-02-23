#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

#include "structs.h"

struct entity create_player(float x, float y, float w, float h);
void process_player_movement(SDL_Event e, struct entity *p);
void apply_player_movement(struct entity *p);
void render_player(SDL_Renderer *rnd, struct entity *p);

#endif
