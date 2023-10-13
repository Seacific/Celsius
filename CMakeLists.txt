cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(RaycastEngine)

add_executable(
	RaycastEngine
	src/main.c
	)

target_include_directories(
	RaycastEngine
	PRIVATE
	include
	Dependencies/include
	)

target_link_libraries(RaycastEngine ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/lib/libSDL2.dylib)

