#include <stdbool.h>
#include <SDL3/SDL.h>

#include "structs.h"
#include "defs.h"

struct solid_body create_block(float x, float y, float w, float h)
{
	struct solid_body b;
	memset(&b, 0, sizeof(struct solid_body));

	b.frame.x = b.position[X] = x;
	b.frame.y = b.position[Y] = y;
	b.frame.w = w;
	b.frame.h = h;
	return b;
}

void render_block(SDL_Renderer *rnd, struct solid_body *b)
{
	SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
	SDL_RenderRect(rnd, &b -> frame);
}
