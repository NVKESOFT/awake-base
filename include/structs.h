#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>
#include <SDL3/SDL.h>

/*
struct your_mom {
	long double fat[9999];
	short brain;
	float tits[2];
};
*/

struct coords {
	int x;
	int y;
};

struct entity {
	struct coords velocity;
	float position[2];
	float movement_speed;
	SDL_Texture *texture;
	SDL_FRect frame;
};

struct solid_body {
	float position[2];
	SDL_Texture *texture;
	SDL_FRect frame;
};

#endif
