#include "include/camera.h"

Celsius_Camera* Celsius_CreateCamera(int width, int height, vec3 position) {
  Celsius_Camera* camera = malloc(sizeof(Celsius_Camera));
  camera->WIDTH = width;
  camera->HEIGHT = height;
  camera->position[0] = position[0];
  camera->position[1] = position[1];
  camera->position[2] = position[2];
  Celsius_CalculateNormalizedRayVectors(camera);

  return camera;
};


void Celsius_CalculateNormalizedRayVectors(Celsius_Camera* camera) {
     vec3* table = malloc(sizeof(vec3)*(camera->WIDTH)*(camera->HEIGHT));
     for (int Y = 0; Y < camera->HEIGHT; Y++) {
        for (int X = 0; X < camera->WIDTH; X++) {
          table[Y*(camera->WIDTH)+X][0] = X-((camera->WIDTH)/2);
          table[Y*(camera->WIDTH)+X][1] = ((camera->HEIGHT)/2)-Y;
          table[Y*(camera->WIDTH)+X][2] = 100;
        }
     }
     for (int i = 0; i < (camera->WIDTH)*(camera->HEIGHT); i++) {
        glm_normalize(table[i]);
     }
     camera->pixelRays = table;
}



