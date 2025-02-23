#include <stdbool.h>
#include <SDL3/SDL.h>

#include "structs.h"
#include "defs.h"

const float player_base_speed = 5.0f;
float player_speed_multiplier = 1.5f;

struct entity create_player(float x, float y, float w, float h)
{
	struct entity p;
	memset(&p, 0, sizeof(struct entity));

	p.frame.x = p.position[X] = x;
	p.frame.y = p.position[Y] = y;
	p.frame.w = w;
	p.frame.h = h;
	p.movement_speed = player_base_speed;
	p.collision = false;
	return p;
}

void process_player_movement(SDL_Event e, struct entity *p)
{
	if (e.type == SDL_EVENT_KEY_DOWN && !e.key.repeat)
		switch (e.key.scancode) {
		case SDL_SCANCODE_W:
			--p -> velocity.y;
			break;
		case SDL_SCANCODE_A:
			--p -> velocity.x;
			break;
		case SDL_SCANCODE_S:
			++p -> velocity.y;
			break;
		case SDL_SCANCODE_D:
			++p -> velocity.x;
			break;
		case SDL_SCANCODE_LSHIFT:
			p -> movement_speed *= player_speed_multiplier;
			break;
		default:
			break;
		}
	else if (e.type == SDL_EVENT_KEY_UP && !e.key.repeat)
		switch (e.key.scancode) {
		case SDL_SCANCODE_W:
			++p -> velocity.y;
			break;
		case SDL_SCANCODE_A:
			++p -> velocity.x;
			break;
		case SDL_SCANCODE_S:
			--p -> velocity.y;
			break;
		case SDL_SCANCODE_D:
			--p -> velocity.x;
			break;
		case SDL_SCANCODE_LSHIFT:
			p -> movement_speed = player_base_speed;
			break;
		default:
			break;
		}
}

void apply_player_movement(struct entity *p)
{
	p -> frame.x = p -> position[X] += p -> velocity.x *
		p -> movement_speed;
	p -> frame.y = p -> position[Y] += p -> velocity.y *
		p -> movement_speed;
}

void render_player(SDL_Renderer *rnd, struct entity *p)
{
	if (p -> collision)
		SDL_SetRenderDrawColor(rnd, 60, 210, 40, 255);
	else
		SDL_SetRenderDrawColor(rnd, 210, 60, 40, 255);
	SDL_RenderRect(rnd, &p -> frame);
}
