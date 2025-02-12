#include <stdio.h>
#include <stdbool.h>

#include "common.h"
#include "defs.h"
#include "structs.h"

bool init(program *game)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return false;
	}

	game -> window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED,
	                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
	                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!game -> window) {
		printf("Error creating window: %s\n", SDL_GetError());
		return false;
	}
	
	game -> renderer = SDL_CreateRenderer(game -> window, -1,
	                                      SDL_RENDERER_ACCELERATED);
	if (!game -> renderer) {
		printf("Error creating renderer: %s\n", SDL_GetError());
		return false;
	}
	return true;
}