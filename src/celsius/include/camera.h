#pragma once
#include<SDL2/SDL.h>
#include<cglm/cglm.h>

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

typedef struct  {
  int WIDTH;
  int HEIGHT;
  vec3 position;
  vec3* pixelRays;
} Celsius_Camera;

Celsius_Camera* Celsius_CreateCamera(int width, int height, vec3 position);
void Celsius_CalculateNormalizedRayVectors(Celsius_Camera* camera);
