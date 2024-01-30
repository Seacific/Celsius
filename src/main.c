#include <stdio.h>
#include <SDL2/SDL.h>
#include <cglm/cglm.h>
#include "celsius.h"

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

bool debugged = false;

bool quit = false;

void drawRectangle(SDL_Surface* surface, vec2 pos, u32 width, u32 height);

void drawPixel(SDL_Surface* surface, ivec2 A);
float isIntersectingTriangle(Celsius_Renderer* renderer, vec3* vertices, int X, int Y);
void tracePixels(Celsius_Renderer* renderer, vec3* vertices);
void printVector(vec3 vector);
void clear(Celsius_Renderer* renderer);

vec3* calculateNormalizedRayVectors();


int main(int argc, char* args[]){

    freopen("debug.out", "w", stdout);

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    	{
        	printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    	}

	SDL_Window* window = SDL_CreateWindow("Raycast Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

	if (!window) {
		printf("SDL Window could not initialize! SDL_Error: %s\n", SDL_GetError());
	}


    Celsius_Renderer* renderer = Celsius_CreateRenderer(
            window, 
            Celsius_CreateCamera(WIDTH, HEIGHT, (vec3){0, 0, 0}, calculateNormalizedRayVectors()),
            WIDTH,
            HEIGHT
            );
    

	vec3 vertices[3] = {
		{-2.0f, -1.0f, 3.0f},
		{2.0f, -1.0f, 3.0f},
		{0.0f, 1.0f, 3.0f}
	};


    /*for (int X = 0; X < WIDTH; X++) {
        for (int Y = 0; Y < HEIGHT; Y++) {
            printf("%f ", normVectors[X*Y][
        }
    }*/


	while (!quit) {

		SDL_UpdateWindowSurface(window); SDL_Event e;
        Celsius_Clear(renderer);
        tracePixels(renderer, vertices);
    printf("%f", isIntersectingTriangle(renderer, vertices, WIDTH/2, HEIGHT/2));		
		while(SDL_PollEvent(&e) > 0){
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

void tracePixels(Celsius_Renderer* renderer, vec3* vertices) {
    for (int X = 0; X < WIDTH; X++) {
        for (int Y = 0; Y < HEIGHT; Y++) {
          if (isIntersectingTriangle(renderer, vertices, X, Y)){
            drawPixel(renderer->surface, (ivec2){X, Y}); 
            debugged = true;
        }
        }
    }
}

// Most of the math is stolen from this pdf: https://courses.cs.washington.edu/courses/csep557/10au/lectures/triangle_intersection.pdf
float isIntersectingTriangle(Celsius_Renderer* renderer, vec3* vertices, int X, int Y) {
   vec3 AB, AC, BC, CA, n, cross;

   glm_vec3_sub(vertices[1], vertices[0], AB);
   glm_vec3_sub(vertices[2], vertices[0], AC);
   glm_vec3_sub(vertices[2], vertices[1], BC);
   glm_vec3_sub(vertices[0], vertices[2], CA);

   glm_vec3_crossn(AB, AC, n);

   vec3 D, Q;

   memcpy(&D, renderer->camera->pixelRays[Y*WIDTH+X], sizeof(vec3));

   float d = glm_vec3_dot(n, vertices[0]);
   float t = (d-(glm_vec3_dot(n, renderer->camera->position)))/(glm_vec3_dot(n, D));

   vec3 td;
   glm_vec3_scale(D, t, td);
   glm_vec3_add(renderer->camera->position, td, Q);

   vec3 AQ, BQ, CQ;
   vec3 testVector;
   glm_vec3_sub(Q, vertices[0], AQ);
   glm_vec3_sub(Q, vertices[1], BQ);
   glm_vec3_sub(Q, vertices[2], CQ);
   
   glm_vec3_cross(AB, AQ, testVector);

   if (glm_dot(testVector, n) < 0) {
        return 0;
   }
   glm_vec3_cross(BC, BQ, testVector);

   if (glm_dot(testVector, n) < 0) {
        return 0;
   }
   glm_vec3_cross(CA, CQ, testVector);

   if (glm_dot(testVector, n) < 0) {
        return 0;
   }

   return glm_vec3_distance(renderer->camera->position, Q);
}

void drawPixel(SDL_Surface* surface, ivec2 A) {

		((u8*)surface->pixels)[(A[0]+ WIDTH*A[1])*4] = 0xFF;
		((u8*)surface->pixels)[(A[0]+ WIDTH*A[1])*4 + 1] = 0xFF;
		((u8*)surface->pixels)[(A[0]+ WIDTH*A[1])*4 + 2] = 0xFF;
}

u32* getPixel(SDL_Surface* surface, ivec2 A) {
    return ((u32*)surface->pixels + (A[0]+WIDTH*A[1]));
}

vec3* calculateNormalizedRayVectors() {
     vec3* table = malloc(sizeof(vec3)*WIDTH*HEIGHT);
     for (int Y = 0; Y < HEIGHT; Y++) {
        for (int X = 0; X < WIDTH; X++) {
            table[Y*WIDTH+X][0] = X-(WIDTH/2);
            table[Y*WIDTH+X][1] = (HEIGHT/2)-Y;
            table[Y*WIDTH+X][2] = 100;
        }
     }
     for (int i = 0; i < WIDTH*HEIGHT; i++) {
        glm_normalize(table[i]);
     }
     return table;
}

void printVector(vec3 vector) {
    for (int i = 0; i < 3; i++) {
        printf("%f \n",vector[i]);
    }
}

void clear(Celsius_Renderer* renderer) {
    }
