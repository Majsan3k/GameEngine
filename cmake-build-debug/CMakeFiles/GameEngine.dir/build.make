# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/majal/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/majal/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GameEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GameEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameEngine.dir/flags.make

CMakeFiles/GameEngine.dir/game/main.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/game/main.cpp.o: ../game/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameEngine.dir/game/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/game/main.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/game/main.cpp

CMakeFiles/GameEngine.dir/game/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/game/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/game/main.cpp > CMakeFiles/GameEngine.dir/game/main.cpp.i

CMakeFiles/GameEngine.dir/game/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/game/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/game/main.cpp -o CMakeFiles/GameEngine.dir/game/main.cpp.s

CMakeFiles/GameEngine.dir/game/main.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/game/main.cpp.o.requires

CMakeFiles/GameEngine.dir/game/main.cpp.o.provides: CMakeFiles/GameEngine.dir/game/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/game/main.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/game/main.cpp.o.provides

CMakeFiles/GameEngine.dir/game/main.cpp.o.provides.build: CMakeFiles/GameEngine.dir/game/main.cpp.o


CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o: ../engine/GameEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/engine/GameEngine.cpp

CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/engine/GameEngine.cpp > CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.i

CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/engine/GameEngine.cpp -o CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.s

CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o.requires

CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o.provides: CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o.provides

CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o.provides.build: CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o


CMakeFiles/GameEngine.dir/components/Sprite.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/components/Sprite.cpp.o: ../components/Sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GameEngine.dir/components/Sprite.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/components/Sprite.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Sprite.cpp

CMakeFiles/GameEngine.dir/components/Sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/components/Sprite.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Sprite.cpp > CMakeFiles/GameEngine.dir/components/Sprite.cpp.i

CMakeFiles/GameEngine.dir/components/Sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/components/Sprite.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Sprite.cpp -o CMakeFiles/GameEngine.dir/components/Sprite.cpp.s

CMakeFiles/GameEngine.dir/components/Sprite.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/components/Sprite.cpp.o.requires

CMakeFiles/GameEngine.dir/components/Sprite.cpp.o.provides: CMakeFiles/GameEngine.dir/components/Sprite.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/components/Sprite.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/components/Sprite.cpp.o.provides

CMakeFiles/GameEngine.dir/components/Sprite.cpp.o.provides.build: CMakeFiles/GameEngine.dir/components/Sprite.cpp.o


CMakeFiles/GameEngine.dir/frame/Frame.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/frame/Frame.cpp.o: ../frame/Frame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GameEngine.dir/frame/Frame.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/frame/Frame.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/frame/Frame.cpp

CMakeFiles/GameEngine.dir/frame/Frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/frame/Frame.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/frame/Frame.cpp > CMakeFiles/GameEngine.dir/frame/Frame.cpp.i

CMakeFiles/GameEngine.dir/frame/Frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/frame/Frame.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/frame/Frame.cpp -o CMakeFiles/GameEngine.dir/frame/Frame.cpp.s

CMakeFiles/GameEngine.dir/frame/Frame.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/frame/Frame.cpp.o.requires

CMakeFiles/GameEngine.dir/frame/Frame.cpp.o.provides: CMakeFiles/GameEngine.dir/frame/Frame.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/frame/Frame.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/frame/Frame.cpp.o.provides

CMakeFiles/GameEngine.dir/frame/Frame.cpp.o.provides.build: CMakeFiles/GameEngine.dir/frame/Frame.cpp.o


CMakeFiles/GameEngine.dir/components/Item.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/components/Item.cpp.o: ../components/Item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GameEngine.dir/components/Item.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/components/Item.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Item.cpp

CMakeFiles/GameEngine.dir/components/Item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/components/Item.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Item.cpp > CMakeFiles/GameEngine.dir/components/Item.cpp.i

CMakeFiles/GameEngine.dir/components/Item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/components/Item.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Item.cpp -o CMakeFiles/GameEngine.dir/components/Item.cpp.s

CMakeFiles/GameEngine.dir/components/Item.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/components/Item.cpp.o.requires

CMakeFiles/GameEngine.dir/components/Item.cpp.o.provides: CMakeFiles/GameEngine.dir/components/Item.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/components/Item.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/components/Item.cpp.o.provides

CMakeFiles/GameEngine.dir/components/Item.cpp.o.provides.build: CMakeFiles/GameEngine.dir/components/Item.cpp.o


CMakeFiles/GameEngine.dir/components/Button.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/components/Button.cpp.o: ../components/Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GameEngine.dir/components/Button.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/components/Button.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Button.cpp

CMakeFiles/GameEngine.dir/components/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/components/Button.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Button.cpp > CMakeFiles/GameEngine.dir/components/Button.cpp.i

CMakeFiles/GameEngine.dir/components/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/components/Button.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Button.cpp -o CMakeFiles/GameEngine.dir/components/Button.cpp.s

CMakeFiles/GameEngine.dir/components/Button.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/components/Button.cpp.o.requires

CMakeFiles/GameEngine.dir/components/Button.cpp.o.provides: CMakeFiles/GameEngine.dir/components/Button.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/components/Button.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/components/Button.cpp.o.provides

CMakeFiles/GameEngine.dir/components/Button.cpp.o.provides.build: CMakeFiles/GameEngine.dir/components/Button.cpp.o


CMakeFiles/GameEngine.dir/components/Label.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/components/Label.cpp.o: ../components/Label.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GameEngine.dir/components/Label.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/components/Label.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Label.cpp

CMakeFiles/GameEngine.dir/components/Label.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/components/Label.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Label.cpp > CMakeFiles/GameEngine.dir/components/Label.cpp.i

CMakeFiles/GameEngine.dir/components/Label.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/components/Label.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Label.cpp -o CMakeFiles/GameEngine.dir/components/Label.cpp.s

CMakeFiles/GameEngine.dir/components/Label.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/components/Label.cpp.o.requires

CMakeFiles/GameEngine.dir/components/Label.cpp.o.provides: CMakeFiles/GameEngine.dir/components/Label.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/components/Label.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/components/Label.cpp.o.provides

CMakeFiles/GameEngine.dir/components/Label.cpp.o.provides.build: CMakeFiles/GameEngine.dir/components/Label.cpp.o


CMakeFiles/GameEngine.dir/components/Movable.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/components/Movable.cpp.o: ../components/Movable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GameEngine.dir/components/Movable.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/components/Movable.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Movable.cpp

CMakeFiles/GameEngine.dir/components/Movable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/components/Movable.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Movable.cpp > CMakeFiles/GameEngine.dir/components/Movable.cpp.i

CMakeFiles/GameEngine.dir/components/Movable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/components/Movable.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/components/Movable.cpp -o CMakeFiles/GameEngine.dir/components/Movable.cpp.s

CMakeFiles/GameEngine.dir/components/Movable.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/components/Movable.cpp.o.requires

CMakeFiles/GameEngine.dir/components/Movable.cpp.o.provides: CMakeFiles/GameEngine.dir/components/Movable.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/components/Movable.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/components/Movable.cpp.o.provides

CMakeFiles/GameEngine.dir/components/Movable.cpp.o.provides.build: CMakeFiles/GameEngine.dir/components/Movable.cpp.o


CMakeFiles/GameEngine.dir/game/Player.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/game/Player.cpp.o: ../game/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/GameEngine.dir/game/Player.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/game/Player.cpp.o -c /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/game/Player.cpp

CMakeFiles/GameEngine.dir/game/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/game/Player.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/game/Player.cpp > CMakeFiles/GameEngine.dir/game/Player.cpp.i

CMakeFiles/GameEngine.dir/game/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/game/Player.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/game/Player.cpp -o CMakeFiles/GameEngine.dir/game/Player.cpp.s

CMakeFiles/GameEngine.dir/game/Player.cpp.o.requires:

.PHONY : CMakeFiles/GameEngine.dir/game/Player.cpp.o.requires

CMakeFiles/GameEngine.dir/game/Player.cpp.o.provides: CMakeFiles/GameEngine.dir/game/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/GameEngine.dir/build.make CMakeFiles/GameEngine.dir/game/Player.cpp.o.provides.build
.PHONY : CMakeFiles/GameEngine.dir/game/Player.cpp.o.provides

CMakeFiles/GameEngine.dir/game/Player.cpp.o.provides.build: CMakeFiles/GameEngine.dir/game/Player.cpp.o


# Object files for target GameEngine
GameEngine_OBJECTS = \
"CMakeFiles/GameEngine.dir/game/main.cpp.o" \
"CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o" \
"CMakeFiles/GameEngine.dir/components/Sprite.cpp.o" \
"CMakeFiles/GameEngine.dir/frame/Frame.cpp.o" \
"CMakeFiles/GameEngine.dir/components/Item.cpp.o" \
"CMakeFiles/GameEngine.dir/components/Button.cpp.o" \
"CMakeFiles/GameEngine.dir/components/Label.cpp.o" \
"CMakeFiles/GameEngine.dir/components/Movable.cpp.o" \
"CMakeFiles/GameEngine.dir/game/Player.cpp.o"

# External object files for target GameEngine
GameEngine_EXTERNAL_OBJECTS =

GameEngine.exe: CMakeFiles/GameEngine.dir/game/main.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/components/Sprite.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/frame/Frame.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/components/Item.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/components/Button.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/components/Label.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/components/Movable.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/game/Player.cpp.o
GameEngine.exe: CMakeFiles/GameEngine.dir/build.make
GameEngine.exe: CMakeFiles/GameEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable GameEngine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameEngine.dir/build: GameEngine.exe

.PHONY : CMakeFiles/GameEngine.dir/build

CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/game/main.cpp.o.requires
CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/engine/GameEngine.cpp.o.requires
CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/components/Sprite.cpp.o.requires
CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/frame/Frame.cpp.o.requires
CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/components/Item.cpp.o.requires
CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/components/Button.cpp.o.requires
CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/components/Label.cpp.o.requires
CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/components/Movable.cpp.o.requires
CMakeFiles/GameEngine.dir/requires: CMakeFiles/GameEngine.dir/game/Player.cpp.o.requires

.PHONY : CMakeFiles/GameEngine.dir/requires

CMakeFiles/GameEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameEngine.dir/clean

CMakeFiles/GameEngine.dir/depend:
	cd /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug /cygdrive/c/Users/majal/Documents/Prog3/Inlupp/GameEngine/cmake-build-debug/CMakeFiles/GameEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GameEngine.dir/depend

