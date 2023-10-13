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
void drawTriangle(SDL_Surface* surface, ivec2 A, ivec2 B, ivec2 C);

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
		{-0.5f, -0.5f, 0.0f},
		{0.0f, 0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f}
	};


	while (!quit) {
		
		drawTriangle(surface, (ivec2){200, 300}, (ivec2){400, 100}, (ivec2){450, 250});

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

void drawTriangle(SDL_Surface* surface, ivec2 A, ivec2 B, ivec2 C) {

	float w1;
	float w2;

	int Ax = A[0];
	int Ay = A[1];

	int Bx = B[0];
	int By = B[1];

	int Cx = C[0];
	int Cy = C[1];

	for (int currentPixelY = 0; currentPixelY < HEIGHT; currentPixelY++) {
		for (int currentPixelX = 0; currentPixelX < WIDTH; currentPixelX++) {

			w1 = (Ax*(Cy-Ay)+(currentPixelY-Ay)*(Cx-Ax)-currentPixelX*(Cy-Ay))/((By-Ay)*(Cx-Ax)-(Bx-Ax)*(Cy-Ay));
			w2 = (currentPixelY-Ay-w1*(By-Ay))/(Cy-Ay);
			
			printf("%f ", w1);
			printf("%f\n", w2);
			
			if (w1 > 0 && w2 > 0 && w1 + w2 < 1) {
				drawPixel(surface, (ivec2){currentPixelX, currentPixelY});
				printf("Drawing Pixel");
			}
		}
	}
}

void tracePixels(SDL_Surface* surface) {
    for (
}

/*
void DEBUG_Weight(ivec2 A, ivec2 B, ivec2 C) {

	float w1;
	float w2;

	int Ax = A[0];
	int Ay = A[1];

	int Bx = B[0];
	int By = B[1];

	int Cx = C[0];
	int Cy = C[1];

	int currentPixelX = 


	w1 = (Ax*(Cy-Ay)+(currentPixelY-Ay)*(Cx-Ax)-currentPixelX*(Cy-Ay))/((By-Ay)*(Cx-Ax)-(Bx-Ax)*(Cy-Ay));
	w2 = (currentPixelY-Ay-w1*(By-Ay))/(Cy-Ay);

	print
}
*/
void drawPixel(SDL_Surface* surface, ivec2 A) {

		((u32*)surface->pixels)[A[0]+ WIDTH*A[1]] = 0xFFFFFFFF;
}

u32* getPixel(SDL_Surface* surface, ivec2 A) {
    return ((u32*)surface->pixels + (A[0]+WIDTH*A[1]));
}


void drawRectangle(SDL_Surface* surface, vec2 pos, u32 width, u32 height) {

	if (width + (u32)(pos[0]*WIDTH) > WIDTH){
		width = WIDTH-width;
	}

	if (height - (u32)(pos[1]*HEIGHT) <= 0) {
		height = (u32)(pos[1]*HEIGHT) - HEIGHT;
	}

	for (int row  = 0; row < height; row++){
		for(int column = 0; column < width; column++){
			((u32*)surface->pixels)[column + WIDTH*row + (u32)(pos[0]*WIDTH)+(u32)(pos[1]*HEIGHT)*WIDTH] = 0xffffaaaa;
		}
	}
}


