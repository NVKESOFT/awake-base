#include <stdio.h>                                // Jason Hall is a cuck
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "structs.h"
#include "init.h"
#include "events.h"

void kill(program *game)
{
	// Completely destroy EVERYTHING
	SDL_DestroyRenderer(game -> renderer);
	SDL_DestroyWindow(game -> window);
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	// Define the program structure
	program game = {
		.window = NULL,
		.renderer = NULL
	};

	// Check if the program has successfully initialized
	if (!init(&game)) {
		printf("Failed to initialize!\n");
		return 1;
	}

	// Update the renderer
	SDL_RenderClear(game.renderer);
	SDL_RenderPresent(game.renderer);

	// Create a game loop
	bool is_running = true;

	while (is_running) {
		SDL_Event event;

		while (SDL_PollEvent(&event))
			process_events(event, &is_running);
	}
	
	// Exit the game
	kill(&game);
	return 0;
}