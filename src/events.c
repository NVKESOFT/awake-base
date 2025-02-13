#include <stdbool.h>
#include <SDL2/SDL.h>

bool process_events(SDL_Event event, bool *running)
{
	// Process event by type
	switch (event.type) {
	case SDL_QUIT:
		*running = false;
		break;
	case SDL_KEYDOWN:
		// Process keypresses
		switch (event.key.keysym.scancode) {
		case SDL_SCANCODE_ESCAPE:
			*running = false;
			break;
		}
		break;
	}
	return true;
}