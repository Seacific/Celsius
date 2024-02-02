#include<SDL2/SDL.h>
#include<cglm/cglm.h>
#include "include/renderer.h"
#include "include/camera.h"
#include "include/math.h"

Celsius_Renderer* Celsius_createRenderer(SDL_Window* window, Celsius_Camera* camera, int width, int height) {
  Celsius_Renderer* renderer = malloc(sizeof(Celsius_Renderer));
  renderer->surface = SDL_GetWindowSurface(window);
  renderer->camera = camera; 

  renderer->width = width;
  renderer->height = height;

  renderer->buffer = malloc(sizeof(u32) * renderer->width * renderer->height);
  renderer->pitch = 4*width;

  return renderer;
}

void Celsius_Clear(Celsius_Renderer* renderer) {
    memset(renderer->surface->pixels, 0, (renderer->width)*(renderer->height)*sizeof(u32)); 
}

void Celsius_swapBuffer(Celsius_Renderer* renderer) {
  u32* temp = renderer->surface->pixels;
  renderer->surface->pixels = renderer->buffer;
  renderer->buffer = temp;
}

float Celsius_isIntersectingTriangle(Celsius_Renderer* renderer, vec3* vertices, int X, int Y) {
   vec3 AB, AC, BC, CA, n, cross;

   glm_vec3_sub(vertices[1], vertices[0], AB);
   glm_vec3_sub(vertices[2], vertices[0], AC);
   glm_vec3_sub(vertices[2], vertices[1], BC);
   glm_vec3_sub(vertices[0], vertices[2], CA);

   glm_vec3_crossn(AB, AC, n);

   vec3 D, Q;

   memcpy(&D, renderer->camera->pixelRays[Y*renderer->width+X], sizeof(vec3));

   float d = glm_vec3_dot(n, vertices[0]);
   float t = (d-(glm_vec3_dot(n, renderer->camera->position)))/(glm_vec3_dot(n, D));

   vec3 td;
   glm_vec3_scale(D, t, td);
   glm_vec3_add(renderer->camera->position, td, Q);

   vec3 AQ, BQ, CQ;
   vec3 testVector;
   glm_vec3_sub(Q, vertices[0], AQ);
   glm_vec3_sub(Q, vertices[2], CQ);
   glm_vec3_sub(Q, vertices[1], BQ);
   
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


   return clamp((invsqrt((glm_vec3_distance(Q, renderer->camera->position)/10))), 0, 255);
}

void Celsius_drawPixel(Celsius_Renderer* renderer, ivec2 A, float whiteBalance) {
		((u8*)renderer->buffer)[(A[0]+ renderer->width*A[1])*4] = (u8)whiteBalance;
		((u8*)renderer->buffer)[(A[0]+ renderer->width*A[1])*4 + 1] = (u8)whiteBalance;
		((u8*)renderer->buffer)[(A[0]+ renderer->width*A[1])*4 + 2] = (u8)whiteBalance;
}

u32* Surface_getPixel(SDL_Surface* surface, ivec2 A) {
    return ((u32*)surface->pixels + (A[0]+surface->w*A[1]));
}

void printVector(vec3 vector) {
    for (int i = 0; i < 3; i++) {
      printf("%f \n",vector[i]);
    }
}

void Celsius_tracePixels(Celsius_Renderer * renderer, vec3 * vertices) {
	for (int X = 0; X < renderer->width; X++) {
		for (int Y = 0; Y < renderer->height; Y++) {
			Celsius_drawPixel(renderer, (ivec2) {X, Y}, Celsius_isIntersectingTriangle(renderer, vertices, X, Y));
		}
	}
}
