#include <stdio.h>
#include <SDL2/SDL.h>
#include <cglm/cglm.h>
#include "celsius/include/celsius.h"

typedef float	f32;
typedef double	f64;
typedef uint8_t	u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t	i8;
typedef int16_t	i16;
typedef int32_t	i32;
typedef int64_t	i64;

#define WIDTH 640
#define HEIGHT 480

u32	framebufferArray[WIDTH * HEIGHT] = {0};

bool debugged = false;

bool quit = false;

int main(int argc, char *args[]) {
	freopen("debug.out", "w", stdout);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	SDL_Window *window = SDL_CreateWindow("Raycast Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

	if (!window) {
		printf("SDL Window could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	Celsius_Renderer *renderer = Celsius_createRenderer(
		window,
		Celsius_CreateCamera(WIDTH, HEIGHT, (vec3) {0, 0, 0}),
		WIDTH,
		HEIGHT
	);

	vec3 vertices[3] = {
		{-2.0f, -1.0f, 3.0f},
		{2.0f, -1.0f, 3.0f},
		{0.0f, 1.0f, 3.0f}
	};


	while (!quit) {
		SDL_UpdateWindowSurface(window);
		SDL_Event	e;
		Celsius_tracePixels(renderer, vertices);
    Celsius_swapBuffer(renderer);
		while (SDL_PollEvent(&e) > 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					renderer->camera->position[2] += 0.1;
					break;
				case SDLK_DOWN:
					renderer->camera->position[2] -= 0.1;
					break;
				}
			}
		}
	}

}


