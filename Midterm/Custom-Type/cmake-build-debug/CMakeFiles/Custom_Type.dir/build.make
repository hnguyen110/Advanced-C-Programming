# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/Users/rootuser/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/rootuser/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Custom_Type.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Custom_Type.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Custom_Type.dir/flags.make

CMakeFiles/Custom_Type.dir/main.cpp.o: CMakeFiles/Custom_Type.dir/flags.make
CMakeFiles/Custom_Type.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Custom_Type.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Custom_Type.dir/main.cpp.o -c /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/main.cpp

CMakeFiles/Custom_Type.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Custom_Type.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/main.cpp > CMakeFiles/Custom_Type.dir/main.cpp.i

CMakeFiles/Custom_Type.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Custom_Type.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/main.cpp -o CMakeFiles/Custom_Type.dir/main.cpp.s

CMakeFiles/Custom_Type.dir/Bouquet.cpp.o: CMakeFiles/Custom_Type.dir/flags.make
CMakeFiles/Custom_Type.dir/Bouquet.cpp.o: ../Bouquet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Custom_Type.dir/Bouquet.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Custom_Type.dir/Bouquet.cpp.o -c /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/Bouquet.cpp

CMakeFiles/Custom_Type.dir/Bouquet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Custom_Type.dir/Bouquet.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/Bouquet.cpp > CMakeFiles/Custom_Type.dir/Bouquet.cpp.i

CMakeFiles/Custom_Type.dir/Bouquet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Custom_Type.dir/Bouquet.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/Bouquet.cpp -o CMakeFiles/Custom_Type.dir/Bouquet.cpp.s

# Object files for target Custom_Type
Custom_Type_OBJECTS = \
"CMakeFiles/Custom_Type.dir/main.cpp.o" \
"CMakeFiles/Custom_Type.dir/Bouquet.cpp.o"

# External object files for target Custom_Type
Custom_Type_EXTERNAL_OBJECTS =

Custom_Type: CMakeFiles/Custom_Type.dir/main.cpp.o
Custom_Type: CMakeFiles/Custom_Type.dir/Bouquet.cpp.o
Custom_Type: CMakeFiles/Custom_Type.dir/build.make
Custom_Type: CMakeFiles/Custom_Type.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Custom_Type"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Custom_Type.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Custom_Type.dir/build: Custom_Type

.PHONY : CMakeFiles/Custom_Type.dir/build

CMakeFiles/Custom_Type.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Custom_Type.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Custom_Type.dir/clean

CMakeFiles/Custom_Type.dir/depend:
	cd /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/cmake-build-debug /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/cmake-build-debug /Users/rootuser/Desktop/OOP345NAA/Midterm/Custom-Type/cmake-build-debug/CMakeFiles/Custom_Type.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Custom_Type.dir/depend

