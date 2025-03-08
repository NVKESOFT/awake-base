#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

typedef struct player player;

player *create_player(float x, float y, float w, float h);
void destroy_player(player **pl);

SDL_FRect *player_get_frame(player *pl);
void player_collided_with(player *pl, SDL_FRect *col);
void process_player_movement(SDL_Event *e, player *pl);
void apply_player_movement(player *pl);
void render_player(SDL_Renderer *rnd, player *pl);

#endif
