#pragma once
#include<SDL2/SDL.h>
#include<cglm/cglm.h>
#include"camera.h"

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

typedef struct {
  SDL_Surface* surface;
  Celsius_Camera* camera;
  int width;
  int height;
  u32* buffer;
  u32 pitch;
} Celsius_Renderer; 

Celsius_Renderer* Celsius_createRenderer(SDL_Window* window, Celsius_Camera* camera, int width, int height); 
float Celsius_isIntersectingTriangle(Celsius_Renderer* renderer, vec3* vertices, int X, int Y);
void Celsius_swapBuffer(Celsius_Renderer* renderer);
void Celsius_drawPixel(Celsius_Renderer* renderer, ivec2 A, float whiteBalance);
u32* Surface_getPixel(SDL_Surface* surface, ivec2 A);
void printVector(vec3 vector);
void Celsius_clear(Celsius_Renderer* renderer);
void Celsius_tracePixels(Celsius_Renderer * renderer, vec3 * vertices);
void Celsius_updateSurface(Celsius_Renderer* renderer);

