#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

bool init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return false;
    }
    
    window = SDL_CreateWindow("AWAKE", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 480,
                              SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Error creating window: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool event_loop()
{
    const unsigned char *keys = SDL_GetKeyboardState(NULL);
    static int mx0 = -1, my0 = -1, mx1 = -1, my1 = -1;
    SDL_Event event;
    SDL_Rect rect;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    while (SDL_PollEvent(&event) != 0)
        switch (event.type) {
        case SDL_QUIT:
            return false;
        case SDL_MOUSEBUTTONDOWN:
            mx0 = event.button.x;
            my0 = event.button.y;
            break;
        case SDL_MOUSEMOTION:
            mx1 = event.button.x;
            my1 = event.button.y;
            break;
        case SDL_MOUSEBUTTONUP:
            mx0 = my0 = mx1 = my1 = -1;
            break;
        }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    if (keys[SDL_SCANCODE_1])
        SDL_RenderDrawPoint(renderer, 10, 10);
    if (keys[SDL_SCANCODE_2])
        SDL_RenderDrawLine(renderer, 10, 20, 10, 100);
    if (keys[SDL_SCANCODE_3]) {
        rect.x = 20;
        rect.y = 20;
        rect.w = 100;
        rect.h = 100;
        SDL_RenderFillRect(renderer, &rect);
    }

    if (mx0 != -1) {
        rect.x = mx0;
        rect.y = my0;
        rect.w = mx1 - mx0;
        rect.h = my1 - my0;
        SDL_RenderDrawRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);
    return true;
}

void kill()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    if (!init()) {
        printf("Failed to initialize!\n");
        return 1;
    }
    
    while (event_loop())
        SDL_Delay(10);

    kill();
    return 0;
}