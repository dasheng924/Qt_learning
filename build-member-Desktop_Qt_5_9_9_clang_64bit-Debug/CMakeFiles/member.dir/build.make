# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sunguosheng/Code/reQt/member

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sunguosheng/Code/reQt/build-member-Desktop_Qt_5_9_9_clang_64bit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/member.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/member.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/member.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/member.dir/flags.make

CMakeFiles/member.dir/main.cpp.o: CMakeFiles/member.dir/flags.make
CMakeFiles/member.dir/main.cpp.o: /Users/sunguosheng/Code/reQt/member/main.cpp
CMakeFiles/member.dir/main.cpp.o: CMakeFiles/member.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunguosheng/Code/reQt/build-member-Desktop_Qt_5_9_9_clang_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/member.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/member.dir/main.cpp.o -MF CMakeFiles/member.dir/main.cpp.o.d -o CMakeFiles/member.dir/main.cpp.o -c /Users/sunguosheng/Code/reQt/member/main.cpp

CMakeFiles/member.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/member.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sunguosheng/Code/reQt/member/main.cpp > CMakeFiles/member.dir/main.cpp.i

CMakeFiles/member.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/member.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sunguosheng/Code/reQt/member/main.cpp -o CMakeFiles/member.dir/main.cpp.s

# Object files for target member
member_OBJECTS = \
"CMakeFiles/member.dir/main.cpp.o"

# External object files for target member
member_EXTERNAL_OBJECTS =

member: CMakeFiles/member.dir/main.cpp.o
member: CMakeFiles/member.dir/build.make
member: CMakeFiles/member.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunguosheng/Code/reQt/build-member-Desktop_Qt_5_9_9_clang_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable member"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/member.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/member.dir/build: member
.PHONY : CMakeFiles/member.dir/build

CMakeFiles/member.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/member.dir/cmake_clean.cmake
.PHONY : CMakeFiles/member.dir/clean

CMakeFiles/member.dir/depend:
	cd /Users/sunguosheng/Code/reQt/build-member-Desktop_Qt_5_9_9_clang_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunguosheng/Code/reQt/member /Users/sunguosheng/Code/reQt/member /Users/sunguosheng/Code/reQt/build-member-Desktop_Qt_5_9_9_clang_64bit-Debug /Users/sunguosheng/Code/reQt/build-member-Desktop_Qt_5_9_9_clang_64bit-Debug /Users/sunguosheng/Code/reQt/build-member-Desktop_Qt_5_9_9_clang_64bit-Debug/CMakeFiles/member.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/member.dir/depend

