# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /snap/cmake/1000/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1000/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone

# Include any dependencies generated for this target.
include CMakeFiles/mp.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/mp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mp.dir/flags.make

CMakeFiles/mp.dir/main.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mp.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/main.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/main.cpp

CMakeFiles/mp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/main.cpp > CMakeFiles/mp.dir/main.cpp.i

CMakeFiles/mp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/main.cpp -o CMakeFiles/mp.dir/main.cpp.s

CMakeFiles/mp.dir/MpEngine.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/MpEngine.cpp.o: MpEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mp.dir/MpEngine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/MpEngine.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/MpEngine.cpp

CMakeFiles/mp.dir/MpEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/MpEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/MpEngine.cpp > CMakeFiles/mp.dir/MpEngine.cpp.i

CMakeFiles/mp.dir/MpEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/MpEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/MpEngine.cpp -o CMakeFiles/mp.dir/MpEngine.cpp.s

CMakeFiles/mp.dir/Plane.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/Plane.cpp.o: Plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mp.dir/Plane.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/Plane.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Plane.cpp

CMakeFiles/mp.dir/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/Plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Plane.cpp > CMakeFiles/mp.dir/Plane.cpp.i

CMakeFiles/mp.dir/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/Plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Plane.cpp -o CMakeFiles/mp.dir/Plane.cpp.s

CMakeFiles/mp.dir/CameraManager.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/CameraManager.cpp.o: CameraManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mp.dir/CameraManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/CameraManager.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CameraManager.cpp

CMakeFiles/mp.dir/CameraManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/CameraManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CameraManager.cpp > CMakeFiles/mp.dir/CameraManager.cpp.i

CMakeFiles/mp.dir/CameraManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/CameraManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CameraManager.cpp -o CMakeFiles/mp.dir/CameraManager.cpp.s

CMakeFiles/mp.dir/GenericCharacter.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/GenericCharacter.cpp.o: GenericCharacter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mp.dir/GenericCharacter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/GenericCharacter.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/GenericCharacter.cpp

CMakeFiles/mp.dir/GenericCharacter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/GenericCharacter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/GenericCharacter.cpp > CMakeFiles/mp.dir/GenericCharacter.cpp.i

CMakeFiles/mp.dir/GenericCharacter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/GenericCharacter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/GenericCharacter.cpp -o CMakeFiles/mp.dir/GenericCharacter.cpp.s

CMakeFiles/mp.dir/Popsickle.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/Popsickle.cpp.o: Popsickle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mp.dir/Popsickle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/Popsickle.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Popsickle.cpp

CMakeFiles/mp.dir/Popsickle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/Popsickle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Popsickle.cpp > CMakeFiles/mp.dir/Popsickle.cpp.i

CMakeFiles/mp.dir/Popsickle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/Popsickle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Popsickle.cpp -o CMakeFiles/mp.dir/Popsickle.cpp.s

CMakeFiles/mp.dir/Deimos.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/Deimos.cpp.o: Deimos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mp.dir/Deimos.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/Deimos.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Deimos.cpp

CMakeFiles/mp.dir/Deimos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/Deimos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Deimos.cpp > CMakeFiles/mp.dir/Deimos.cpp.i

CMakeFiles/mp.dir/Deimos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/Deimos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Deimos.cpp -o CMakeFiles/mp.dir/Deimos.cpp.s

CMakeFiles/mp.dir/ArcBallCam.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/ArcBallCam.cpp.o: ArcBallCam.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/mp.dir/ArcBallCam.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/ArcBallCam.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/ArcBallCam.cpp

CMakeFiles/mp.dir/ArcBallCam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/ArcBallCam.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/ArcBallCam.cpp > CMakeFiles/mp.dir/ArcBallCam.cpp.i

CMakeFiles/mp.dir/ArcBallCam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/ArcBallCam.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/ArcBallCam.cpp -o CMakeFiles/mp.dir/ArcBallCam.cpp.s

CMakeFiles/mp.dir/Flashlight.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/Flashlight.cpp.o: Flashlight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/mp.dir/Flashlight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/Flashlight.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Flashlight.cpp

CMakeFiles/mp.dir/Flashlight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/Flashlight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Flashlight.cpp > CMakeFiles/mp.dir/Flashlight.cpp.i

CMakeFiles/mp.dir/Flashlight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/Flashlight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Flashlight.cpp -o CMakeFiles/mp.dir/Flashlight.cpp.s

CMakeFiles/mp.dir/Block.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/Block.cpp.o: Block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/mp.dir/Block.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/Block.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Block.cpp

CMakeFiles/mp.dir/Block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/Block.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Block.cpp > CMakeFiles/mp.dir/Block.cpp.i

CMakeFiles/mp.dir/Block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/Block.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Block.cpp -o CMakeFiles/mp.dir/Block.cpp.s

CMakeFiles/mp.dir/Tree.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/Tree.cpp.o: Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/mp.dir/Tree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/Tree.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Tree.cpp

CMakeFiles/mp.dir/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/Tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Tree.cpp > CMakeFiles/mp.dir/Tree.cpp.i

CMakeFiles/mp.dir/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/Tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Tree.cpp -o CMakeFiles/mp.dir/Tree.cpp.s

CMakeFiles/mp.dir/Skier.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/Skier.cpp.o: Skier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/mp.dir/Skier.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/Skier.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Skier.cpp

CMakeFiles/mp.dir/Skier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/Skier.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Skier.cpp > CMakeFiles/mp.dir/Skier.cpp.i

CMakeFiles/mp.dir/Skier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/Skier.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Skier.cpp -o CMakeFiles/mp.dir/Skier.cpp.s

CMakeFiles/mp.dir/TextureManager.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/TextureManager.cpp.o: TextureManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/mp.dir/TextureManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/TextureManager.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/TextureManager.cpp

CMakeFiles/mp.dir/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/TextureManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/TextureManager.cpp > CMakeFiles/mp.dir/TextureManager.cpp.i

CMakeFiles/mp.dir/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/TextureManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/TextureManager.cpp -o CMakeFiles/mp.dir/TextureManager.cpp.s

CMakeFiles/mp.dir/Chunk.cpp.o: CMakeFiles/mp.dir/flags.make
CMakeFiles/mp.dir/Chunk.cpp.o: Chunk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/mp.dir/Chunk.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mp.dir/Chunk.cpp.o -c /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Chunk.cpp

CMakeFiles/mp.dir/Chunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mp.dir/Chunk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Chunk.cpp > CMakeFiles/mp.dir/Chunk.cpp.i

CMakeFiles/mp.dir/Chunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mp.dir/Chunk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/Chunk.cpp -o CMakeFiles/mp.dir/Chunk.cpp.s

# Object files for target mp
mp_OBJECTS = \
"CMakeFiles/mp.dir/main.cpp.o" \
"CMakeFiles/mp.dir/MpEngine.cpp.o" \
"CMakeFiles/mp.dir/Plane.cpp.o" \
"CMakeFiles/mp.dir/CameraManager.cpp.o" \
"CMakeFiles/mp.dir/GenericCharacter.cpp.o" \
"CMakeFiles/mp.dir/Popsickle.cpp.o" \
"CMakeFiles/mp.dir/Deimos.cpp.o" \
"CMakeFiles/mp.dir/ArcBallCam.cpp.o" \
"CMakeFiles/mp.dir/Flashlight.cpp.o" \
"CMakeFiles/mp.dir/Block.cpp.o" \
"CMakeFiles/mp.dir/Tree.cpp.o" \
"CMakeFiles/mp.dir/Skier.cpp.o" \
"CMakeFiles/mp.dir/TextureManager.cpp.o" \
"CMakeFiles/mp.dir/Chunk.cpp.o"

# External object files for target mp
mp_EXTERNAL_OBJECTS =

mp: CMakeFiles/mp.dir/main.cpp.o
mp: CMakeFiles/mp.dir/MpEngine.cpp.o
mp: CMakeFiles/mp.dir/Plane.cpp.o
mp: CMakeFiles/mp.dir/CameraManager.cpp.o
mp: CMakeFiles/mp.dir/GenericCharacter.cpp.o
mp: CMakeFiles/mp.dir/Popsickle.cpp.o
mp: CMakeFiles/mp.dir/Deimos.cpp.o
mp: CMakeFiles/mp.dir/ArcBallCam.cpp.o
mp: CMakeFiles/mp.dir/Flashlight.cpp.o
mp: CMakeFiles/mp.dir/Block.cpp.o
mp: CMakeFiles/mp.dir/Tree.cpp.o
mp: CMakeFiles/mp.dir/Skier.cpp.o
mp: CMakeFiles/mp.dir/TextureManager.cpp.o
mp: CMakeFiles/mp.dir/Chunk.cpp.o
mp: CMakeFiles/mp.dir/build.make
mp: CMakeFiles/mp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable mp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mp.dir/build: mp
.PHONY : CMakeFiles/mp.dir/build

CMakeFiles/mp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mp.dir/clean

CMakeFiles/mp.dir/depend:
	cd /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles/mp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mp.dir/depend

