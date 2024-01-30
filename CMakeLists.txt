cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(SDLRaycaster)


add_executable(
    SDLRaycaster
    src/main.c
    src/renderer/camera.c
    src/renderer/renderer.c
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

find_package(SDL2 REQUIRED)

target_link_libraries(SDLRaycaster SDL2::SDL2 SDL2::SDL2-static cglm)
