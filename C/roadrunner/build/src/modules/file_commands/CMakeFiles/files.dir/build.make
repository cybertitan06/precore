# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/student/CNODP_share/precore-students-2025/C/roadrunner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/CNODP_share/precore-students-2025/C/roadrunner/build

# Include any dependencies generated for this target.
include src/modules/file_commands/CMakeFiles/files.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/modules/file_commands/CMakeFiles/files.dir/compiler_depend.make

# Include the progress variables for this target.
include src/modules/file_commands/CMakeFiles/files.dir/progress.make

# Include the compile flags for this target's objects.
include src/modules/file_commands/CMakeFiles/files.dir/flags.make

src/modules/file_commands/CMakeFiles/files.dir/files.c.o: src/modules/file_commands/CMakeFiles/files.dir/flags.make
src/modules/file_commands/CMakeFiles/files.dir/files.c.o: /home/student/CNODP_share/precore-students-2025/C/roadrunner/src/modules/file_commands/files.c
src/modules/file_commands/CMakeFiles/files.dir/files.c.o: src/modules/file_commands/CMakeFiles/files.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CNODP_share/precore-students-2025/C/roadrunner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/modules/file_commands/CMakeFiles/files.dir/files.c.o"
	cd /home/student/CNODP_share/precore-students-2025/C/roadrunner/build/src/modules/file_commands && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/modules/file_commands/CMakeFiles/files.dir/files.c.o -MF CMakeFiles/files.dir/files.c.o.d -o CMakeFiles/files.dir/files.c.o -c /home/student/CNODP_share/precore-students-2025/C/roadrunner/src/modules/file_commands/files.c

src/modules/file_commands/CMakeFiles/files.dir/files.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/files.dir/files.c.i"
	cd /home/student/CNODP_share/precore-students-2025/C/roadrunner/build/src/modules/file_commands && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CNODP_share/precore-students-2025/C/roadrunner/src/modules/file_commands/files.c > CMakeFiles/files.dir/files.c.i

src/modules/file_commands/CMakeFiles/files.dir/files.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/files.dir/files.c.s"
	cd /home/student/CNODP_share/precore-students-2025/C/roadrunner/build/src/modules/file_commands && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CNODP_share/precore-students-2025/C/roadrunner/src/modules/file_commands/files.c -o CMakeFiles/files.dir/files.c.s

# Object files for target files
files_OBJECTS = \
"CMakeFiles/files.dir/files.c.o"

# External object files for target files
files_EXTERNAL_OBJECTS =

src/modules/file_commands/libfiles.a: src/modules/file_commands/CMakeFiles/files.dir/files.c.o
src/modules/file_commands/libfiles.a: src/modules/file_commands/CMakeFiles/files.dir/build.make
src/modules/file_commands/libfiles.a: src/modules/file_commands/CMakeFiles/files.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/CNODP_share/precore-students-2025/C/roadrunner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libfiles.a"
	cd /home/student/CNODP_share/precore-students-2025/C/roadrunner/build/src/modules/file_commands && $(CMAKE_COMMAND) -P CMakeFiles/files.dir/cmake_clean_target.cmake
	cd /home/student/CNODP_share/precore-students-2025/C/roadrunner/build/src/modules/file_commands && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/files.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/modules/file_commands/CMakeFiles/files.dir/build: src/modules/file_commands/libfiles.a
.PHONY : src/modules/file_commands/CMakeFiles/files.dir/build

src/modules/file_commands/CMakeFiles/files.dir/clean:
	cd /home/student/CNODP_share/precore-students-2025/C/roadrunner/build/src/modules/file_commands && $(CMAKE_COMMAND) -P CMakeFiles/files.dir/cmake_clean.cmake
.PHONY : src/modules/file_commands/CMakeFiles/files.dir/clean

src/modules/file_commands/CMakeFiles/files.dir/depend:
	cd /home/student/CNODP_share/precore-students-2025/C/roadrunner/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/CNODP_share/precore-students-2025/C/roadrunner /home/student/CNODP_share/precore-students-2025/C/roadrunner/src/modules/file_commands /home/student/CNODP_share/precore-students-2025/C/roadrunner/build /home/student/CNODP_share/precore-students-2025/C/roadrunner/build/src/modules/file_commands /home/student/CNODP_share/precore-students-2025/C/roadrunner/build/src/modules/file_commands/CMakeFiles/files.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/modules/file_commands/CMakeFiles/files.dir/depend

