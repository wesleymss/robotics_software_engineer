# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/luqman/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/luqman/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/build

# Include any dependencies generated for this target.
include CMakeFiles/pointer_r.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pointer_r.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pointer_r.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pointer_r.dir/flags.make

CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o: CMakeFiles/pointer_r.dir/flags.make
CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o: /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/src/pointers_robot_location.cpp
CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o: CMakeFiles/pointer_r.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o -MF CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o.d -o CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o -c /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/src/pointers_robot_location.cpp

CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/src/pointers_robot_location.cpp > CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.i

CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/src/pointers_robot_location.cpp -o CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.s

# Object files for target pointer_r
pointer_r_OBJECTS = \
"CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o"

# External object files for target pointer_r
pointer_r_EXTERNAL_OBJECTS =

pointer_r: CMakeFiles/pointer_r.dir/src/pointers_robot_location.cpp.o
pointer_r: CMakeFiles/pointer_r.dir/build.make
pointer_r: CMakeFiles/pointer_r.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pointer_r"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pointer_r.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pointer_r.dir/build: pointer_r
.PHONY : CMakeFiles/pointer_r.dir/build

CMakeFiles/pointer_r.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pointer_r.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pointer_r.dir/clean

CMakeFiles/pointer_r.dir/depend:
	cd /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/build /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/build /home/luqman/robotisim_ws/src/dev_robotisim/cpp_fundamentals/build/CMakeFiles/pointer_r.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pointer_r.dir/depend

