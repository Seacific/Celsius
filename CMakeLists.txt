cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(SDLRaycaster)

add_compile_options(-g -O0)

add_library(
  Celsius
  src/celsius/camera.c
  src/celsius/renderer.c
  src/celsius/math.c
  src/celsius/window.c
  src/celsius/celsius.c
  )

add_executable(
    SDLRaycaster
    src/main.c
	)

target_include_directories(
	SDLRaycaster
	PRIVATE
    include/
    Dependencies/include
    src/
	)

target_link_directories(
    SDLRaycaster
    PRIVATE
    Dependencies/
    Dependencies/lib/
    )

target_include_directories(
  Celsius
	PRIVATE
    include/
    Dependencies/include
    src/
	)

target_link_directories(
  Celsius
    PRIVATE
    Dependencies/
    Dependencies/lib/
    )


find_package(SDL2 REQUIRED)

target_link_libraries(Celsius SDL2::SDL2 SDL2::SDL2-static cglm)

target_link_libraries(SDLRaycaster Celsius)
