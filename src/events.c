#include <stdbool.h>
#include <SDL3/SDL.h>

#include "structs.h"

void process_events(SDL_Event event, struct program *game, bool *running)
{
	if (event.type == SDL_EVENT_QUIT || (event.type ==
	                                     SDL_EVENT_KEY_DOWN &&
	                                     event.key.scancode ==
	                                     SDL_SCANCODE_ESCAPE))
		*running = false;
}
