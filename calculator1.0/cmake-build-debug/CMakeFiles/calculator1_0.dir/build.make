# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/top/opt/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/top/opt/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/top/project/Qt/calculator1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/top/project/Qt/calculator1.0/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/calculator1_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/calculator1_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calculator1_0.dir/flags.make

CMakeFiles/calculator1_0.dir/button.cpp.o: CMakeFiles/calculator1_0.dir/flags.make
CMakeFiles/calculator1_0.dir/button.cpp.o: ../button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/top/project/Qt/calculator1.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calculator1_0.dir/button.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calculator1_0.dir/button.cpp.o -c /home/top/project/Qt/calculator1.0/button.cpp

CMakeFiles/calculator1_0.dir/button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator1_0.dir/button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/top/project/Qt/calculator1.0/button.cpp > CMakeFiles/calculator1_0.dir/button.cpp.i

CMakeFiles/calculator1_0.dir/button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator1_0.dir/button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/top/project/Qt/calculator1.0/button.cpp -o CMakeFiles/calculator1_0.dir/button.cpp.s

CMakeFiles/calculator1_0.dir/calculator.cpp.o: CMakeFiles/calculator1_0.dir/flags.make
CMakeFiles/calculator1_0.dir/calculator.cpp.o: ../calculator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/top/project/Qt/calculator1.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/calculator1_0.dir/calculator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calculator1_0.dir/calculator.cpp.o -c /home/top/project/Qt/calculator1.0/calculator.cpp

CMakeFiles/calculator1_0.dir/calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator1_0.dir/calculator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/top/project/Qt/calculator1.0/calculator.cpp > CMakeFiles/calculator1_0.dir/calculator.cpp.i

CMakeFiles/calculator1_0.dir/calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator1_0.dir/calculator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/top/project/Qt/calculator1.0/calculator.cpp -o CMakeFiles/calculator1_0.dir/calculator.cpp.s

CMakeFiles/calculator1_0.dir/main.cpp.o: CMakeFiles/calculator1_0.dir/flags.make
CMakeFiles/calculator1_0.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/top/project/Qt/calculator1.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/calculator1_0.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calculator1_0.dir/main.cpp.o -c /home/top/project/Qt/calculator1.0/main.cpp

CMakeFiles/calculator1_0.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator1_0.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/top/project/Qt/calculator1.0/main.cpp > CMakeFiles/calculator1_0.dir/main.cpp.i

CMakeFiles/calculator1_0.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator1_0.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/top/project/Qt/calculator1.0/main.cpp -o CMakeFiles/calculator1_0.dir/main.cpp.s

# Object files for target calculator1_0
calculator1_0_OBJECTS = \
"CMakeFiles/calculator1_0.dir/button.cpp.o" \
"CMakeFiles/calculator1_0.dir/calculator.cpp.o" \
"CMakeFiles/calculator1_0.dir/main.cpp.o"

# External object files for target calculator1_0
calculator1_0_EXTERNAL_OBJECTS =

calculator1_0: CMakeFiles/calculator1_0.dir/button.cpp.o
calculator1_0: CMakeFiles/calculator1_0.dir/calculator.cpp.o
calculator1_0: CMakeFiles/calculator1_0.dir/main.cpp.o
calculator1_0: CMakeFiles/calculator1_0.dir/build.make
calculator1_0: CMakeFiles/calculator1_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/top/project/Qt/calculator1.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable calculator1_0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calculator1_0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calculator1_0.dir/build: calculator1_0

.PHONY : CMakeFiles/calculator1_0.dir/build

CMakeFiles/calculator1_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calculator1_0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calculator1_0.dir/clean

CMakeFiles/calculator1_0.dir/depend:
	cd /home/top/project/Qt/calculator1.0/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/top/project/Qt/calculator1.0 /home/top/project/Qt/calculator1.0 /home/top/project/Qt/calculator1.0/cmake-build-debug /home/top/project/Qt/calculator1.0/cmake-build-debug /home/top/project/Qt/calculator1.0/cmake-build-debug/CMakeFiles/calculator1_0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calculator1_0.dir/depend

