#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

#include "block.h"
#include "meth.h"

struct solid_body {
	mth_vec2f position;
	SDL_Texture *texture;
	SDL_FRect frame;
};

solid_body *sb_create(float x, float y, float w, float h)
{
	solid_body *sb = calloc(1, sizeof(solid_body));

	if (!sb) {
		fprintf(stderr, "Failed to allocate solid_body!");
		exit(1);
	}
	sb -> frame.x = sb -> position.x = x;
	sb -> frame.y = sb -> position.y = y;
	sb -> frame.w = w;
	sb -> frame.h = h;
	return sb;
}

void sb_destroy(solid_body **sb)
{
	free(*sb);
	*sb = NULL;
}

SDL_FRect *sb_get_frame(solid_body *sb)
{
	return &sb -> frame;
}
