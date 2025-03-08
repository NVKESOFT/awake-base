#include <stdbool.h>
#include <SDL3/SDL.h>

void process_events(SDL_Event *e, bool *running)
{
	if (e -> type == SDL_EVENT_QUIT || (e -> type == SDL_EVENT_KEY_DOWN &&
	                                    e -> key.scancode ==
	                                    SDL_SCANCODE_ESCAPE))
		*running = false;
}
