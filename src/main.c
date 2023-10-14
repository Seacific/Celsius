#include <stdio.h>
#include <SDL2/SDL.h>
#include <cglm/cglm.h>

typedef float    f32;
typedef double   f64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;

#define WIDTH 640
#define HEIGHT 480

u32 framebufferArray[WIDTH * HEIGHT] = {0};

bool quit = false;

void drawRectangle(SDL_Surface* surface, vec2 pos, u32 width, u32 height);

void drawPixel(SDL_Surface* surface, ivec2 A);
void drawTriangle(SDL_Surface* surface, vec3* vertices, int X, int Y);
void tracePixels(SDL_Surface* surface);

vec3* calculateNormalizedRayVectors();

vec3* normVectors;

int main(int argc, char* args[]){

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    	{
        	printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    	}

	SDL_Window* window = SDL_CreateWindow("Raycast Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

	if (!window) {
		printf("SDL Window could not initialize! SDL_Error: %s\n", SDL_GetError());
	}



	SDL_Surface* surface = SDL_GetWindowSurface(window);

	vec3 vertices[3] = {
		{-0.5f, -0.5f, 3.0f},
		{0.0f, 0.5f, 3.0f},
		{0.5f, -0.5f, 3.0f}
	};

    vec3* normVectors = calculateNormalizedRayVectors();

	while (!quit) {
		
        tracePixels(surface);

		SDL_UpdateWindowSurface(window); SDL_Event e;
		
		while(SDL_PollEvent(&e) > 0){
			switch (e.type) {
				case SDL_QUIT:
					quit = true;
					break;
			}
		}
	}

}

void tracePixels(SDL_Surface* surface) {
    for (int X = 0; X < WIDTH; X++) {
        for (int Y = 0; Y < HEIGHT; Y++) {
            
        }
    }
}
void drawTriangle(SDL_Surface* surface, vec3* vertices, int X, int Y) {
   vec3 AB, AC, n;
   glm_vec3_sub(vertices[0], vertices[1], AB);
   glm_vec3_sub(vertices[0], vertices[2], AC);

   glm_vec3_crossn(AB, AC, n);
   
   int d = glm_vec3_dot(n, vertices[0]);

   vec3 D;

   memcpy(&D, normVectors[X*Y], sizeof(vec3));

}

void drawPixel(SDL_Surface* surface, ivec2 A) {

		((u32*)surface->pixels)[A[0]+ WIDTH*A[1]] = 0xFFFFFFFF;
}

u32* getPixel(SDL_Surface* surface, ivec2 A) {
    return ((u32*)surface->pixels + (A[0]+WIDTH*A[1]));
}

vec3* calculateNormalizedRayVectors() {
     vec3* table = malloc(sizeof(vec3)*WIDTH*HEIGHT);
     for (int Y = 0; Y < HEIGHT; Y++) {
        for (int X = 0; X < WIDTH; X++) {
            table[X+Y][0] = X-(WIDTH/2);
            table[X+Y][1] = Y-(HEIGHT/2);
            table[X+Y][2] = 1;
        }
     }
     for (int i = 0; i < WIDTH*HEIGHT; i++) {
        glm_normalize(table[i]);
     }
     return table;
}
