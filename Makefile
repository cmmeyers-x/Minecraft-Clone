# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/snap/cmake/992/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/cmake/1000/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cmmeyers/Dropbox/Graphics/Minecraft/Minecraft-Clone/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named mp

# Build rule for target.
mp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mp
.PHONY : mp

# fast build rule for target.
mp/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/build
.PHONY : mp/fast

ArcBallCam.o: ArcBallCam.cpp.o
.PHONY : ArcBallCam.o

# target to build an object file
ArcBallCam.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/ArcBallCam.cpp.o
.PHONY : ArcBallCam.cpp.o

ArcBallCam.i: ArcBallCam.cpp.i
.PHONY : ArcBallCam.i

# target to preprocess a source file
ArcBallCam.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/ArcBallCam.cpp.i
.PHONY : ArcBallCam.cpp.i

ArcBallCam.s: ArcBallCam.cpp.s
.PHONY : ArcBallCam.s

# target to generate assembly for a file
ArcBallCam.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/ArcBallCam.cpp.s
.PHONY : ArcBallCam.cpp.s

Block.o: Block.cpp.o
.PHONY : Block.o

# target to build an object file
Block.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Block.cpp.o
.PHONY : Block.cpp.o

Block.i: Block.cpp.i
.PHONY : Block.i

# target to preprocess a source file
Block.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Block.cpp.i
.PHONY : Block.cpp.i

Block.s: Block.cpp.s
.PHONY : Block.s

# target to generate assembly for a file
Block.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Block.cpp.s
.PHONY : Block.cpp.s

CameraManager.o: CameraManager.cpp.o
.PHONY : CameraManager.o

# target to build an object file
CameraManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/CameraManager.cpp.o
.PHONY : CameraManager.cpp.o

CameraManager.i: CameraManager.cpp.i
.PHONY : CameraManager.i

# target to preprocess a source file
CameraManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/CameraManager.cpp.i
.PHONY : CameraManager.cpp.i

CameraManager.s: CameraManager.cpp.s
.PHONY : CameraManager.s

# target to generate assembly for a file
CameraManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/CameraManager.cpp.s
.PHONY : CameraManager.cpp.s

Chunk.o: Chunk.cpp.o
.PHONY : Chunk.o

# target to build an object file
Chunk.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Chunk.cpp.o
.PHONY : Chunk.cpp.o

Chunk.i: Chunk.cpp.i
.PHONY : Chunk.i

# target to preprocess a source file
Chunk.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Chunk.cpp.i
.PHONY : Chunk.cpp.i

Chunk.s: Chunk.cpp.s
.PHONY : Chunk.s

# target to generate assembly for a file
Chunk.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Chunk.cpp.s
.PHONY : Chunk.cpp.s

Deimos.o: Deimos.cpp.o
.PHONY : Deimos.o

# target to build an object file
Deimos.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Deimos.cpp.o
.PHONY : Deimos.cpp.o

Deimos.i: Deimos.cpp.i
.PHONY : Deimos.i

# target to preprocess a source file
Deimos.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Deimos.cpp.i
.PHONY : Deimos.cpp.i

Deimos.s: Deimos.cpp.s
.PHONY : Deimos.s

# target to generate assembly for a file
Deimos.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Deimos.cpp.s
.PHONY : Deimos.cpp.s

Flashlight.o: Flashlight.cpp.o
.PHONY : Flashlight.o

# target to build an object file
Flashlight.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Flashlight.cpp.o
.PHONY : Flashlight.cpp.o

Flashlight.i: Flashlight.cpp.i
.PHONY : Flashlight.i

# target to preprocess a source file
Flashlight.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Flashlight.cpp.i
.PHONY : Flashlight.cpp.i

Flashlight.s: Flashlight.cpp.s
.PHONY : Flashlight.s

# target to generate assembly for a file
Flashlight.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Flashlight.cpp.s
.PHONY : Flashlight.cpp.s

GenericCharacter.o: GenericCharacter.cpp.o
.PHONY : GenericCharacter.o

# target to build an object file
GenericCharacter.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/GenericCharacter.cpp.o
.PHONY : GenericCharacter.cpp.o

GenericCharacter.i: GenericCharacter.cpp.i
.PHONY : GenericCharacter.i

# target to preprocess a source file
GenericCharacter.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/GenericCharacter.cpp.i
.PHONY : GenericCharacter.cpp.i

GenericCharacter.s: GenericCharacter.cpp.s
.PHONY : GenericCharacter.s

# target to generate assembly for a file
GenericCharacter.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/GenericCharacter.cpp.s
.PHONY : GenericCharacter.cpp.s

MpEngine.o: MpEngine.cpp.o
.PHONY : MpEngine.o

# target to build an object file
MpEngine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/MpEngine.cpp.o
.PHONY : MpEngine.cpp.o

MpEngine.i: MpEngine.cpp.i
.PHONY : MpEngine.i

# target to preprocess a source file
MpEngine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/MpEngine.cpp.i
.PHONY : MpEngine.cpp.i

MpEngine.s: MpEngine.cpp.s
.PHONY : MpEngine.s

# target to generate assembly for a file
MpEngine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/MpEngine.cpp.s
.PHONY : MpEngine.cpp.s

Plane.o: Plane.cpp.o
.PHONY : Plane.o

# target to build an object file
Plane.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Plane.cpp.o
.PHONY : Plane.cpp.o

Plane.i: Plane.cpp.i
.PHONY : Plane.i

# target to preprocess a source file
Plane.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Plane.cpp.i
.PHONY : Plane.cpp.i

Plane.s: Plane.cpp.s
.PHONY : Plane.s

# target to generate assembly for a file
Plane.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Plane.cpp.s
.PHONY : Plane.cpp.s

Popsickle.o: Popsickle.cpp.o
.PHONY : Popsickle.o

# target to build an object file
Popsickle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Popsickle.cpp.o
.PHONY : Popsickle.cpp.o

Popsickle.i: Popsickle.cpp.i
.PHONY : Popsickle.i

# target to preprocess a source file
Popsickle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Popsickle.cpp.i
.PHONY : Popsickle.cpp.i

Popsickle.s: Popsickle.cpp.s
.PHONY : Popsickle.s

# target to generate assembly for a file
Popsickle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Popsickle.cpp.s
.PHONY : Popsickle.cpp.s

Skier.o: Skier.cpp.o
.PHONY : Skier.o

# target to build an object file
Skier.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Skier.cpp.o
.PHONY : Skier.cpp.o

Skier.i: Skier.cpp.i
.PHONY : Skier.i

# target to preprocess a source file
Skier.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Skier.cpp.i
.PHONY : Skier.cpp.i

Skier.s: Skier.cpp.s
.PHONY : Skier.s

# target to generate assembly for a file
Skier.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Skier.cpp.s
.PHONY : Skier.cpp.s

TextureManager.o: TextureManager.cpp.o
.PHONY : TextureManager.o

# target to build an object file
TextureManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/TextureManager.cpp.o
.PHONY : TextureManager.cpp.o

TextureManager.i: TextureManager.cpp.i
.PHONY : TextureManager.i

# target to preprocess a source file
TextureManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/TextureManager.cpp.i
.PHONY : TextureManager.cpp.i

TextureManager.s: TextureManager.cpp.s
.PHONY : TextureManager.s

# target to generate assembly for a file
TextureManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/TextureManager.cpp.s
.PHONY : TextureManager.cpp.s

Tree.o: Tree.cpp.o
.PHONY : Tree.o

# target to build an object file
Tree.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Tree.cpp.o
.PHONY : Tree.cpp.o

Tree.i: Tree.cpp.i
.PHONY : Tree.i

# target to preprocess a source file
Tree.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Tree.cpp.i
.PHONY : Tree.cpp.i

Tree.s: Tree.cpp.s
.PHONY : Tree.s

# target to generate assembly for a file
Tree.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/Tree.cpp.s
.PHONY : Tree.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mp.dir/build.make CMakeFiles/mp.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... mp"
	@echo "... ArcBallCam.o"
	@echo "... ArcBallCam.i"
	@echo "... ArcBallCam.s"
	@echo "... Block.o"
	@echo "... Block.i"
	@echo "... Block.s"
	@echo "... CameraManager.o"
	@echo "... CameraManager.i"
	@echo "... CameraManager.s"
	@echo "... Chunk.o"
	@echo "... Chunk.i"
	@echo "... Chunk.s"
	@echo "... Deimos.o"
	@echo "... Deimos.i"
	@echo "... Deimos.s"
	@echo "... Flashlight.o"
	@echo "... Flashlight.i"
	@echo "... Flashlight.s"
	@echo "... GenericCharacter.o"
	@echo "... GenericCharacter.i"
	@echo "... GenericCharacter.s"
	@echo "... MpEngine.o"
	@echo "... MpEngine.i"
	@echo "... MpEngine.s"
	@echo "... Plane.o"
	@echo "... Plane.i"
	@echo "... Plane.s"
	@echo "... Popsickle.o"
	@echo "... Popsickle.i"
	@echo "... Popsickle.s"
	@echo "... Skier.o"
	@echo "... Skier.i"
	@echo "... Skier.s"
	@echo "... TextureManager.o"
	@echo "... TextureManager.i"
	@echo "... TextureManager.s"
	@echo "... Tree.o"
	@echo "... Tree.i"
	@echo "... Tree.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

