#include "include/window.h"

Celsius_Window* Celsius_CreateWindow(Celsius_Renderer *renderer, SDL_Window *SDLwindow) {
  Celsius_Window* window = malloc(sizeof(Celsius_Window));
  window->renderer = renderer;
  window->SDLWindow = SDLwindow;
  window->surface = SDL_GetWindowSurface(SDLwindow);
  return window;
}

void Celsius_UpdateWindow(Celsius_Window* window) {
  SDL_UpdateWindowSurface(window->SDLWindow);
}
