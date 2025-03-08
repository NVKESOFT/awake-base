#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

#include "player.h"
#include "meth.h"

const float player_base_speed = 5.0f;
float player_speed_multiplier = 1.5f;

struct player {
	mth_vec2i velocity;
	mth_vec2f position;
	float movement_speed;
	SDL_Texture *texture;
	SDL_FRect frame;
	SDL_FRect *collision;
};

player *create_player(float x, float y, float w, float h)
{
	player *pl = calloc(1, sizeof(player));
	
	if (!pl) {
		fprintf(stderr, "Failed to allocate player!");
		exit(1);
	}
	pl -> position.x = x;
	pl -> position.y = y;
	pl -> frame.w = w;
	pl -> frame.h = h;
	pl -> movement_speed = player_base_speed;
	return pl;
}

void destroy_player(player **pl)
{
	free(*pl);
	*pl = NULL;
}

/*
void update_sprite(player *pl)
{
	return;
}
*/

SDL_FRect *player_get_frame(player *pl)
{
	return &pl -> frame;
}

void player_collided_with(player *pl, SDL_FRect *col)
{
	if (SDL_HasRectIntersectionFloat(&pl -> frame, col))
		pl -> collision = col;
	else
		pl -> collision = NULL;
}

void process_player_movement(SDL_Event *e, player *pl)
{
	if (e -> type == SDL_EVENT_KEY_DOWN && !e -> key.repeat)
		switch (e -> key.scancode) {
		case SDL_SCANCODE_W:
			--pl -> velocity.y;
			break;
		case SDL_SCANCODE_A:
			--pl -> velocity.x;
			break;
		case SDL_SCANCODE_S:
			++pl -> velocity.y;
			break;
		case SDL_SCANCODE_D:
			++pl -> velocity.x;
			break;
		case SDL_SCANCODE_LSHIFT:
			pl -> movement_speed *= player_speed_multiplier;
			break;
		default:
			break;
		}
	else if (e -> type == SDL_EVENT_KEY_UP && !e -> key.repeat)
		switch (e -> key.scancode) {
		case SDL_SCANCODE_W:
			++pl -> velocity.y;
			break;
		case SDL_SCANCODE_A:
			++pl -> velocity.x;
			break;
		case SDL_SCANCODE_S:
			--pl -> velocity.y;
			break;
		case SDL_SCANCODE_D:
			--pl -> velocity.x;
			break;
		case SDL_SCANCODE_LSHIFT:
			pl -> movement_speed = player_base_speed;
			break;
		default:
			break;
		}
//	update_sprite(pl);
}

void apply_player_movement(player *pl)
{
	pl -> frame.x = pl -> position.x += pl -> velocity.x *
		pl -> movement_speed;
	pl -> frame.y = pl -> position.y += pl -> velocity.y *
		pl -> movement_speed;
}

void render_player(SDL_Renderer *rnd, player *pl)
{
	if (pl -> collision)
		SDL_SetRenderDrawColor(rnd, 60, 210, 40, 255);
	else
		SDL_SetRenderDrawColor(rnd, 210, 60, 40, 255);
	SDL_RenderRect(rnd, &pl -> frame);
}
