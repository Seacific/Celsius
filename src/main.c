#include <stdio.h>
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

  Celsius_Window* window = Celsius_Init(WIDTH, HEIGHT);
  Celsius_Renderer* renderer = window->renderer;

	vec3 vertices[3] = {
		{-2.0f, -1.0f, 3.0f},
		{2.0f, -1.0f, 3.0f},
		{0.0f, 1.0f, 3.0f}
	};


	while (!quit) {
    Celsius_UpdateWindow(window);
		SDL_Event	e;
		Celsius_TracePixels(renderer, vertices);
    Celsius_SwapBuffer(renderer);
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
