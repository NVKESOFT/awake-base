#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL3/SDL.h>

/*
struct your_mom {
	long double fat[9999];
	short brain;
	float tits[2];
};
*/

struct dimensions {
	int x;
	int y;
};

struct entity {
	struct dimensions velocity;
	float position[2];
	float movement_speed;
	SDL_Texture *texture;
	SDL_FRect frame;
};

struct program {
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif
