# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Andrew\Downloads\glfw-3.2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Andrew\Downloads\glfw-3.2.1

# Include any dependencies generated for this target.
include tests/CMakeFiles/timeout.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/timeout.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/timeout.dir/flags.make

tests/CMakeFiles/timeout.dir/timeout.c.obj: tests/CMakeFiles/timeout.dir/flags.make
tests/CMakeFiles/timeout.dir/timeout.c.obj: tests/CMakeFiles/timeout.dir/includes_C.rsp
tests/CMakeFiles/timeout.dir/timeout.c.obj: tests/timeout.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrew\Downloads\glfw-3.2.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/timeout.dir/timeout.c.obj"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\timeout.dir\timeout.c.obj   -c C:\Users\Andrew\Downloads\glfw-3.2.1\tests\timeout.c

tests/CMakeFiles/timeout.dir/timeout.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/timeout.c.i"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Andrew\Downloads\glfw-3.2.1\tests\timeout.c > CMakeFiles\timeout.dir\timeout.c.i

tests/CMakeFiles/timeout.dir/timeout.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/timeout.c.s"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Andrew\Downloads\glfw-3.2.1\tests\timeout.c -o CMakeFiles\timeout.dir\timeout.c.s

tests/CMakeFiles/timeout.dir/__/deps/glad.c.obj: tests/CMakeFiles/timeout.dir/flags.make
tests/CMakeFiles/timeout.dir/__/deps/glad.c.obj: tests/CMakeFiles/timeout.dir/includes_C.rsp
tests/CMakeFiles/timeout.dir/__/deps/glad.c.obj: deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrew\Downloads\glfw-3.2.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/timeout.dir/__/deps/glad.c.obj"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\timeout.dir\__\deps\glad.c.obj   -c C:\Users\Andrew\Downloads\glfw-3.2.1\deps\glad.c

tests/CMakeFiles/timeout.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/__/deps/glad.c.i"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Andrew\Downloads\glfw-3.2.1\deps\glad.c > CMakeFiles\timeout.dir\__\deps\glad.c.i

tests/CMakeFiles/timeout.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/__/deps/glad.c.s"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Andrew\Downloads\glfw-3.2.1\deps\glad.c -o CMakeFiles\timeout.dir\__\deps\glad.c.s

# Object files for target timeout
timeout_OBJECTS = \
"CMakeFiles/timeout.dir/timeout.c.obj" \
"CMakeFiles/timeout.dir/__/deps/glad.c.obj"

# External object files for target timeout
timeout_EXTERNAL_OBJECTS =

tests/timeout.exe: tests/CMakeFiles/timeout.dir/timeout.c.obj
tests/timeout.exe: tests/CMakeFiles/timeout.dir/__/deps/glad.c.obj
tests/timeout.exe: tests/CMakeFiles/timeout.dir/build.make
tests/timeout.exe: src/libglfw3.a
tests/timeout.exe: tests/CMakeFiles/timeout.dir/linklibs.rsp
tests/timeout.exe: tests/CMakeFiles/timeout.dir/objects1.rsp
tests/timeout.exe: tests/CMakeFiles/timeout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Andrew\Downloads\glfw-3.2.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable timeout.exe"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\timeout.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/timeout.dir/build: tests/timeout.exe

.PHONY : tests/CMakeFiles/timeout.dir/build

tests/CMakeFiles/timeout.dir/clean:
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && $(CMAKE_COMMAND) -P CMakeFiles\timeout.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/timeout.dir/clean

tests/CMakeFiles/timeout.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Andrew\Downloads\glfw-3.2.1 C:\Users\Andrew\Downloads\glfw-3.2.1\tests C:\Users\Andrew\Downloads\glfw-3.2.1 C:\Users\Andrew\Downloads\glfw-3.2.1\tests C:\Users\Andrew\Downloads\glfw-3.2.1\tests\CMakeFiles\timeout.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/timeout.dir/depend

