#include "include/celsius.h"

Celsius_Window* Celsius_Init(int width, int height) {
   freopen("debug.out", "w", stdout);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	SDL_Window *window = SDL_CreateWindow("Raycast Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if (!window) {
		printf("SDL Window could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

  return Celsius_CreateWindow(Celsius_CreateRenderer(window, Celsius_CreateCamera(width, height, (vec3) {0, 0, 0}), width, height), window);

}
