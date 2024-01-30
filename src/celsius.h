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
} Celsius_Renderer; 

Celsius_Renderer* Celsius_CreateRenderer(SDL_Window* window, Celsius_Camera* camera, int width, int height) {
    Celsius_Renderer* renderer = malloc(sizeof(Celsius_Renderer));
    renderer->surface = SDL_GetWindowSurface(window);
    renderer->camera = camera; 

    renderer->width = width;
    renderer->height = height;

    return renderer;
}

void Celsius_Clear(Celsius_Renderer* renderer) {
    memset(renderer->surface->pixels, 0, (renderer->width)*(renderer->height)*sizeof(u32)); 
}
