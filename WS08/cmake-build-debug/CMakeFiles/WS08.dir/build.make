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
CMAKE_COMMAND = "/Users/rootuser/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/rootuser/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rootuser/Desktop/OOP345NAA/WS08

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rootuser/Desktop/OOP345NAA/WS08/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WS08.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WS08.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WS08.dir/flags.make

CMakeFiles/WS08.dir/main.cpp.o: CMakeFiles/WS08.dir/flags.make
CMakeFiles/WS08.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rootuser/Desktop/OOP345NAA/WS08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WS08.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WS08.dir/main.cpp.o -c /Users/rootuser/Desktop/OOP345NAA/WS08/main.cpp

CMakeFiles/WS08.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WS08.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rootuser/Desktop/OOP345NAA/WS08/main.cpp > CMakeFiles/WS08.dir/main.cpp.i

CMakeFiles/WS08.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WS08.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rootuser/Desktop/OOP345NAA/WS08/main.cpp -o CMakeFiles/WS08.dir/main.cpp.s

CMakeFiles/WS08.dir/Utilities.cpp.o: CMakeFiles/WS08.dir/flags.make
CMakeFiles/WS08.dir/Utilities.cpp.o: ../Utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rootuser/Desktop/OOP345NAA/WS08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WS08.dir/Utilities.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WS08.dir/Utilities.cpp.o -c /Users/rootuser/Desktop/OOP345NAA/WS08/Utilities.cpp

CMakeFiles/WS08.dir/Utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WS08.dir/Utilities.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rootuser/Desktop/OOP345NAA/WS08/Utilities.cpp > CMakeFiles/WS08.dir/Utilities.cpp.i

CMakeFiles/WS08.dir/Utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WS08.dir/Utilities.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rootuser/Desktop/OOP345NAA/WS08/Utilities.cpp -o CMakeFiles/WS08.dir/Utilities.cpp.s

# Object files for target WS08
WS08_OBJECTS = \
"CMakeFiles/WS08.dir/main.cpp.o" \
"CMakeFiles/WS08.dir/Utilities.cpp.o"

# External object files for target WS08
WS08_EXTERNAL_OBJECTS =

WS08: CMakeFiles/WS08.dir/main.cpp.o
WS08: CMakeFiles/WS08.dir/Utilities.cpp.o
WS08: CMakeFiles/WS08.dir/build.make
WS08: CMakeFiles/WS08.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rootuser/Desktop/OOP345NAA/WS08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable WS08"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WS08.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WS08.dir/build: WS08

.PHONY : CMakeFiles/WS08.dir/build

CMakeFiles/WS08.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WS08.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WS08.dir/clean

CMakeFiles/WS08.dir/depend:
	cd /Users/rootuser/Desktop/OOP345NAA/WS08/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rootuser/Desktop/OOP345NAA/WS08 /Users/rootuser/Desktop/OOP345NAA/WS08 /Users/rootuser/Desktop/OOP345NAA/WS08/cmake-build-debug /Users/rootuser/Desktop/OOP345NAA/WS08/cmake-build-debug /Users/rootuser/Desktop/OOP345NAA/WS08/cmake-build-debug/CMakeFiles/WS08.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WS08.dir/depend

