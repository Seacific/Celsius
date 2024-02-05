#pragma once
#include "renderer.h"
#include "SDL.h"

typedef struct {
  Celsius_Renderer* renderer;
  SDL_Window* SDLWindow; 
  SDL_Surface* surface;
} Celsius_Window;

Celsius_Window* Celsius_CreateWindow(Celsius_Renderer* renderer, SDL_Window* window);
void Celsius_UpdateWindow(Celsius_Window* window);
