# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/out/build/task_1

# Include any dependencies generated for this target.
include CMakeFiles/Task_0.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Task_0.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_0.dir/flags.make

CMakeFiles/Task_0.dir/Task_1.cpp.o: CMakeFiles/Task_0.dir/flags.make
CMakeFiles/Task_0.dir/Task_1.cpp.o: /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/Task_1.cpp
CMakeFiles/Task_0.dir/Task_1.cpp.o: CMakeFiles/Task_0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/out/build/task_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_0.dir/Task_1.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Task_0.dir/Task_1.cpp.o -MF CMakeFiles/Task_0.dir/Task_1.cpp.o.d -o CMakeFiles/Task_0.dir/Task_1.cpp.o -c /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/Task_1.cpp

CMakeFiles/Task_0.dir/Task_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Task_0.dir/Task_1.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/Task_1.cpp > CMakeFiles/Task_0.dir/Task_1.cpp.i

CMakeFiles/Task_0.dir/Task_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Task_0.dir/Task_1.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/Task_1.cpp -o CMakeFiles/Task_0.dir/Task_1.cpp.s

# Object files for target Task_0
Task_0_OBJECTS = \
"CMakeFiles/Task_0.dir/Task_1.cpp.o"

# External object files for target Task_0
Task_0_EXTERNAL_OBJECTS =

Task_0: CMakeFiles/Task_0.dir/Task_1.cpp.o
Task_0: CMakeFiles/Task_0.dir/build.make
Task_0: CMakeFiles/Task_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/out/build/task_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task_0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_0.dir/build: Task_0
.PHONY : CMakeFiles/Task_0.dir/build

CMakeFiles/Task_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task_0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task_0.dir/clean

CMakeFiles/Task_0.dir/depend:
	cd /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/out/build/task_1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1 /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1 /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/out/build/task_1 /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/out/build/task_1 /Users/artembelcikova/Documents/453501/ОАиП/LR_8/Task_1/out/build/task_1/CMakeFiles/Task_0.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Task_0.dir/depend

