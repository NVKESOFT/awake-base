#ifndef EVENTS_H
#define EVENTS_H

#include <stdbool.h>
#include <SDL3/SDL.h>

#include "structs.h"

void process_events(SDL_Event event, struct program *game, bool *running);

#endif
