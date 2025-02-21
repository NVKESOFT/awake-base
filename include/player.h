#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

#include "structs.h"

void player_init(struct entity *player, float x, float y);
void process_player_movement(SDL_Event event, struct entity *player);
void apply_player_movement(struct entity *player);

#endif
