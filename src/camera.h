#pragma once

#include<stdio.h>
#include<SDL2/SDL.h>
#include<cglm/cglm.h>
typedef struct  {
    int WIDTH;
    int HEIGHT;
    vec3 position;
    vec3* pixelRays;
} Celsius_Camera;

Celsius_Camera* Celsius_CreateCamera(int width, int height, vec3 position, vec3* pixelRays) {
    Celsius_Camera* camera = malloc(sizeof(Celsius_Camera));
    camera->WIDTH = width;
    camera->HEIGHT = height;
    camera->position[0] = position[0];
    camera->position[1] = position[1];
    camera->position[2] = position[2];
    camera->pixelRays = pixelRays;

    return camera;
};
