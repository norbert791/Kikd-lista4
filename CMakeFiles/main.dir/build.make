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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/189/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/189/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.c.o: main.c
CMakeFiles/main.dir/main.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/main.c.o -MF CMakeFiles/main.dir/main.c.o.d -o CMakeFiles/main.dir/main.c.o -c /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/main.c

CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/main.c > CMakeFiles/main.dir/main.c.i

CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/main.c -o CMakeFiles/main.dir/main.c.s

CMakeFiles/main.dir/predictors.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/predictors.c.o: predictors.c
CMakeFiles/main.dir/predictors.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/predictors.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/predictors.c.o -MF CMakeFiles/main.dir/predictors.c.o.d -o CMakeFiles/main.dir/predictors.c.o -c /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/predictors.c

CMakeFiles/main.dir/predictors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/predictors.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/predictors.c > CMakeFiles/main.dir/predictors.c.i

CMakeFiles/main.dir/predictors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/predictors.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/predictors.c -o CMakeFiles/main.dir/predictors.c.s

CMakeFiles/main.dir/utilities.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/utilities.c.o: utilities.c
CMakeFiles/main.dir/utilities.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/utilities.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/utilities.c.o -MF CMakeFiles/main.dir/utilities.c.o.d -o CMakeFiles/main.dir/utilities.c.o -c /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/utilities.c

CMakeFiles/main.dir/utilities.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/utilities.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/utilities.c > CMakeFiles/main.dir/utilities.c.i

CMakeFiles/main.dir/utilities.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/utilities.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/utilities.c -o CMakeFiles/main.dir/utilities.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.c.o" \
"CMakeFiles/main.dir/predictors.c.o" \
"CMakeFiles/main.dir/utilities.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.c.o
main: CMakeFiles/main.dir/predictors.c.o
main: CMakeFiles/main.dir/utilities.c.o
main: CMakeFiles/main.dir/build.make
main: libtga-master/src/libtga.a
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4 /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4 /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4 /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4 /home/norbert/Dokumenty/wppt/semestr4/kodowanie/lista4/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

