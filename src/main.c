#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
// Jason Hall is a cuck
#include "structs.h"
#include "defs.h"
#include "events.h"
#include "player.h"

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
	struct entity player;
	memset(&player, 0, sizeof(struct entity));
	
	if (!init(&game)) {
		SDL_LogInfo(SDL_LOG_CATEGORY_ERROR, "Couldn't initialize!");
		return 1;
	}
	
	player_init(&player, 100.0f, 100.0f);
	
	bool is_running = true;
	SDL_Event event;
	
	while (is_running) {
		while (SDL_PollEvent(&event)) {
			process_events(event, &game, &is_running);
			process_player_movement(event, &player);
		}
		
		apply_player_movement(&player);
		
		SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
		SDL_RenderClear(game.renderer);
		SDL_SetRenderDrawColor(game.renderer, 210, 60, 40, 255);
		SDL_RenderRect(game.renderer, &player.frame);
		SDL_RenderPresent(game.renderer);
		
		SDL_Delay(DELAY_ONE_FRAME);
	}
	
	kill(&game);
	return 0;
}
