#include <stdio.h>
#include <stdbool.h>

#include "common.h"
#include "structs.h"
#include "init.h"

void kill(program *game)
{
	SDL_DestroyRenderer(game -> renderer);
	SDL_DestroyWindow(game -> window);
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	program game = {
		.window = NULL,
		.renderer = NULL
	};

	if (!init(&game)) {
		printf("Failed to initialize!\n");
		exit(1);
	}

	SDL_RenderClear(game.renderer);
	SDL_RenderPresent(game.renderer);

	SDL_Delay(5000);
	
	kill(&game);
	printf("alright");
	return 0;
}