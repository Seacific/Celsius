# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sea/dev/SDLRaycaster

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sea/dev/SDLRaycaster

# Include any dependencies generated for this target.
include CMakeFiles/SDLRaycaster.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDLRaycaster.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDLRaycaster.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDLRaycaster.dir/flags.make

CMakeFiles/SDLRaycaster.dir/src/main.c.o: CMakeFiles/SDLRaycaster.dir/flags.make
CMakeFiles/SDLRaycaster.dir/src/main.c.o: src/main.c
CMakeFiles/SDLRaycaster.dir/src/main.c.o: CMakeFiles/SDLRaycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sea/dev/SDLRaycaster/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SDLRaycaster.dir/src/main.c.o"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDLRaycaster.dir/src/main.c.o -MF CMakeFiles/SDLRaycaster.dir/src/main.c.o.d -o CMakeFiles/SDLRaycaster.dir/src/main.c.o -c /Users/sea/dev/SDLRaycaster/src/main.c

CMakeFiles/SDLRaycaster.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDLRaycaster.dir/src/main.c.i"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sea/dev/SDLRaycaster/src/main.c > CMakeFiles/SDLRaycaster.dir/src/main.c.i

CMakeFiles/SDLRaycaster.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDLRaycaster.dir/src/main.c.s"
	/usr/local/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sea/dev/SDLRaycaster/src/main.c -o CMakeFiles/SDLRaycaster.dir/src/main.c.s

# Object files for target SDLRaycaster
SDLRaycaster_OBJECTS = \
"CMakeFiles/SDLRaycaster.dir/src/main.c.o"

# External object files for target SDLRaycaster
SDLRaycaster_EXTERNAL_OBJECTS =

SDLRaycaster: CMakeFiles/SDLRaycaster.dir/src/main.c.o
SDLRaycaster: CMakeFiles/SDLRaycaster.dir/build.make
SDLRaycaster: libCelsius.a
SDLRaycaster: /opt/homebrew/Cellar/sdl2/2.28.5/lib/libSDL2.dylib
SDLRaycaster: /opt/homebrew/Cellar/sdl2/2.28.5/lib/libSDL2.a
SDLRaycaster: CMakeFiles/SDLRaycaster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/sea/dev/SDLRaycaster/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SDLRaycaster"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDLRaycaster.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDLRaycaster.dir/build: SDLRaycaster
.PHONY : CMakeFiles/SDLRaycaster.dir/build

CMakeFiles/SDLRaycaster.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDLRaycaster.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDLRaycaster.dir/clean

CMakeFiles/SDLRaycaster.dir/depend:
	cd /Users/sea/dev/SDLRaycaster && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sea/dev/SDLRaycaster /Users/sea/dev/SDLRaycaster /Users/sea/dev/SDLRaycaster /Users/sea/dev/SDLRaycaster /Users/sea/dev/SDLRaycaster/CMakeFiles/SDLRaycaster.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SDLRaycaster.dir/depend

