#include <SDL3/SDL.h>

#include "structs.h"

void player_init(struct entity *player, float x, float y)
{
	player -> position[0] = x;
	player -> position[1] = y;
	player -> movement_speed = 5.0f;
	player -> frame.w = 100;
	player -> frame.h = 100;
}

void process_player_movement(SDL_Event event, struct entity *player)
{
	if (event.type == SDL_EVENT_KEY_DOWN && !event.key.repeat)
		switch (event.key.scancode) {
		case SDL_SCANCODE_W:
			--player -> velocity.y;
			break;
		case SDL_SCANCODE_A:
			--player -> velocity.x;
			break;
		case SDL_SCANCODE_S:
			++player -> velocity.y;
			break;
		case SDL_SCANCODE_D:
			++player -> velocity.x;
			break;
		case SDL_SCANCODE_LSHIFT:
			player -> movement_speed *= 1.5f;
			break;
		default:
			break;
		}
	else if (event.type == SDL_EVENT_KEY_UP && !event.key.repeat)
		switch (event.key.scancode) {
		case SDL_SCANCODE_W:
			++player -> velocity.y;
			break;
		case SDL_SCANCODE_A:
			++player -> velocity.x;
			break;
		case SDL_SCANCODE_S:
			--player -> velocity.y;
			break;
		case SDL_SCANCODE_D:
			--player -> velocity.x;
			break;
		case SDL_SCANCODE_LSHIFT:
			player -> movement_speed = 5.0f;
			break;
		default:
			break;
		}
}

void apply_player_movement(struct entity *player)
{
	player -> position[0] += player -> velocity.x *
		player -> movement_speed;
	player -> position[1] += player -> velocity.y *
		player -> movement_speed;
	
	player -> frame.x = player -> position[0];
	player -> frame.y = player -> position[1];
}
