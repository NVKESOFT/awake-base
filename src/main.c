#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
// Jason Hall is a cuck
#include "structs.h"
#include "defs.h"
#include "events.h"
#include "player.h"
#include "block.h"

#define WINDOW_TITLE "AWAKE"
#define IMAGE_FLAGS IMG_INIT_PNG

struct program {
	SDL_Window *window;
	SDL_Renderer *renderer;
};

bool init(struct program *game)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
		             "Couldn't initialize SDL: %s", SDL_GetError());
		return false;
	}
	
	if (!SDL_CreateWindowAndRenderer(WINDOW_TITLE, SCREEN_WIDTH,
	                                 SCREEN_HEIGHT, 0, &game -> window,
	                                 &game -> renderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
		             "Couldn't create window and renderer: %s",
		             SDL_GetError());
		return false;
	}
	return true;
}

void kill(struct program *game)
{
	SDL_DestroyRenderer(game -> renderer);
	SDL_DestroyWindow(game -> window);
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	struct program game;
	memset(&game, 0, sizeof(struct program));
	
	if (!init(&game)) {
		SDL_LogInfo(SDL_LOG_CATEGORY_ERROR, "Couldn't initialize!");
		return 1;
	}
	
	struct entity player = create_player(100.f, 100.f, 100.f, 100.f);
	struct solid_body block = create_block(300.f, 300.f, 100.f, 100.f);

	bool running = true;
	SDL_Event e;
	
	while (running) {
		while (SDL_PollEvent(&e)) {
			process_events(e, &running);
			process_player_movement(e, &player);
		}
		
		apply_player_movement(&player);

		SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
		SDL_RenderClear(game.renderer);
		render_player(game.renderer, &player);
		render_block(game.renderer, &block);
		SDL_RenderPresent(game.renderer);

		SDL_Delay(DELAY_ONE_FRAME);
	}
	
	kill(&game);
	return 0;
}
