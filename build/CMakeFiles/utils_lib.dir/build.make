# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/beloin/Documents/hardware/pi-projs/lcd-dht11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/beloin/Documents/hardware/pi-projs/lcd-dht11/build

# Include any dependencies generated for this target.
include CMakeFiles/utils_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/utils_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/utils_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/utils_lib.dir/flags.make

CMakeFiles/utils_lib.dir/src/utils/defin.c.o: CMakeFiles/utils_lib.dir/flags.make
CMakeFiles/utils_lib.dir/src/utils/defin.c.o: /home/beloin/Documents/hardware/pi-projs/lcd-dht11/src/utils/defin.c
CMakeFiles/utils_lib.dir/src/utils/defin.c.o: CMakeFiles/utils_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/beloin/Documents/hardware/pi-projs/lcd-dht11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/utils_lib.dir/src/utils/defin.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/utils_lib.dir/src/utils/defin.c.o -MF CMakeFiles/utils_lib.dir/src/utils/defin.c.o.d -o CMakeFiles/utils_lib.dir/src/utils/defin.c.o -c /home/beloin/Documents/hardware/pi-projs/lcd-dht11/src/utils/defin.c

CMakeFiles/utils_lib.dir/src/utils/defin.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/utils_lib.dir/src/utils/defin.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/beloin/Documents/hardware/pi-projs/lcd-dht11/src/utils/defin.c > CMakeFiles/utils_lib.dir/src/utils/defin.c.i

CMakeFiles/utils_lib.dir/src/utils/defin.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/utils_lib.dir/src/utils/defin.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/beloin/Documents/hardware/pi-projs/lcd-dht11/src/utils/defin.c -o CMakeFiles/utils_lib.dir/src/utils/defin.c.s

# Object files for target utils_lib
utils_lib_OBJECTS = \
"CMakeFiles/utils_lib.dir/src/utils/defin.c.o"

# External object files for target utils_lib
utils_lib_EXTERNAL_OBJECTS =

libutils_lib.a: CMakeFiles/utils_lib.dir/src/utils/defin.c.o
libutils_lib.a: CMakeFiles/utils_lib.dir/build.make
libutils_lib.a: CMakeFiles/utils_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/beloin/Documents/hardware/pi-projs/lcd-dht11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libutils_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/utils_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/utils_lib.dir/build_sensor: libutils_lib.a
.PHONY : CMakeFiles/utils_lib.dir/build_display

CMakeFiles/utils_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/utils_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/utils_lib.dir/clean

CMakeFiles/utils_lib.dir/depend:
	cd /home/beloin/Documents/hardware/pi-projs/lcd-dht11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/beloin/Documents/hardware/pi-projs/lcd-dht11 /home/beloin/Documents/hardware/pi-projs/lcd-dht11 /home/beloin/Documents/hardware/pi-projs/lcd-dht11/build /home/beloin/Documents/hardware/pi-projs/lcd-dht11/build /home/beloin/Documents/hardware/pi-projs/lcd-dht11/build/CMakeFiles/utils_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/utils_lib.dir/depend
