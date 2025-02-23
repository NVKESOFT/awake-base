#ifndef EVENTS_H
#define EVENTS_H

#include <stdbool.h>
#include <SDL3/SDL.h>

void process_events(SDL_Event e, bool *running);

#endif
