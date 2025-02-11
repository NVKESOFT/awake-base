#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

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

	SDL_Surface *buffer = SDL_LoadBMP("media/test.bmp");
	if (!buffer) {
		printf("Error loading image: %s\n", SDL_GetError());
		return false;
	}
	
	texture = SDL_CreateTextureFromSurface(renderer, buffer);
	SDL_FreeSurface(buffer);
	buffer = NULL;
	if (!texture) {
		printf("Error creating texture: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

bool event_loop()
{
	const unsigned char *keys = SDL_GetKeyboardState(NULL);
	static int mx = -1, my = -1;
	static double rot = 0;
	
	SDL_Event event;
	SDL_Rect dest;
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	while (SDL_PollEvent(&event) != 0)
		switch (event.type) {
		case SDL_QUIT:
			return false;
		case SDL_MOUSEMOTION:
			mx = event.button.x;
			my = event.button.y;
			break;
		}
	
	if (mx != -1) {
		float wpercent = mx / 640.0f;
		float hpercent = my / 480.0f;

		unsigned char r = round(wpercent * 255);
		unsigned char g = round(hpercent * 255);

		SDL_SetTextureColorMod(texture, r, g, 0);

		mx -= 320;
		my -= 240;
		rot = atan((float) my / (float) mx) * (180.0f, 3.14f);
		if (mx < 0)
			rot -= 180;
	}
	mx = my = -1;

	dest.x = 240;
	dest.y = 180;
	dest.w = 160;
	dest.h = 240;
	SDL_RenderCopyEx(renderer, texture, NULL, &dest, rot, NULL,
	                 keys[SDL_SCANCODE_F] ?
			 SDL_FLIP_VERTICAL : SDL_FLIP_NONE);
	
	SDL_RenderPresent(renderer);
	return true;
}

void kill()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	texture = NULL;
	renderer = NULL;
	window = NULL;
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
