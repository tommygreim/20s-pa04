# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\Programs\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Programs\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\Documents\College\Sophmore\Algorithms\20s-pa04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\Documents\College\Sophmore\Algorithms\20s-pa04\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P04.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P04.dir/flags.make

CMakeFiles/P04.dir/main.cpp.obj: CMakeFiles/P04.dir/flags.make
CMakeFiles/P04.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Documents\College\Sophmore\Algorithms\20s-pa04\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P04.dir/main.cpp.obj"
	G:\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\P04.dir\main.cpp.obj -c G:\Documents\College\Sophmore\Algorithms\20s-pa04\main.cpp

CMakeFiles/P04.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P04.dir/main.cpp.i"
	G:\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Documents\College\Sophmore\Algorithms\20s-pa04\main.cpp > CMakeFiles\P04.dir\main.cpp.i

CMakeFiles/P04.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P04.dir/main.cpp.s"
	G:\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Documents\College\Sophmore\Algorithms\20s-pa04\main.cpp -o CMakeFiles\P04.dir\main.cpp.s

# Object files for target P04
P04_OBJECTS = \
"CMakeFiles/P04.dir/main.cpp.obj"

# External object files for target P04
P04_EXTERNAL_OBJECTS =

P04.exe: CMakeFiles/P04.dir/main.cpp.obj
P04.exe: CMakeFiles/P04.dir/build.make
P04.exe: CMakeFiles/P04.dir/linklibs.rsp
P04.exe: CMakeFiles/P04.dir/objects1.rsp
P04.exe: CMakeFiles/P04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Documents\College\Sophmore\Algorithms\20s-pa04\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P04.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\P04.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P04.dir/build: P04.exe

.PHONY : CMakeFiles/P04.dir/build

CMakeFiles/P04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\P04.dir\cmake_clean.cmake
.PHONY : CMakeFiles/P04.dir/clean

CMakeFiles/P04.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Documents\College\Sophmore\Algorithms\20s-pa04 G:\Documents\College\Sophmore\Algorithms\20s-pa04 G:\Documents\College\Sophmore\Algorithms\20s-pa04\cmake-build-debug G:\Documents\College\Sophmore\Algorithms\20s-pa04\cmake-build-debug G:\Documents\College\Sophmore\Algorithms\20s-pa04\cmake-build-debug\CMakeFiles\P04.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P04.dir/depend

