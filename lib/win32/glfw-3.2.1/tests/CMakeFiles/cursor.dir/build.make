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
include tests/CMakeFiles/cursor.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/cursor.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/cursor.dir/flags.make

tests/CMakeFiles/cursor.dir/cursor.c.obj: tests/CMakeFiles/cursor.dir/flags.make
tests/CMakeFiles/cursor.dir/cursor.c.obj: tests/CMakeFiles/cursor.dir/includes_C.rsp
tests/CMakeFiles/cursor.dir/cursor.c.obj: tests/cursor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrew\Downloads\glfw-3.2.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/cursor.dir/cursor.c.obj"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cursor.dir\cursor.c.obj   -c C:\Users\Andrew\Downloads\glfw-3.2.1\tests\cursor.c

tests/CMakeFiles/cursor.dir/cursor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cursor.dir/cursor.c.i"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Andrew\Downloads\glfw-3.2.1\tests\cursor.c > CMakeFiles\cursor.dir\cursor.c.i

tests/CMakeFiles/cursor.dir/cursor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cursor.dir/cursor.c.s"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Andrew\Downloads\glfw-3.2.1\tests\cursor.c -o CMakeFiles\cursor.dir\cursor.c.s

tests/CMakeFiles/cursor.dir/__/deps/glad.c.obj: tests/CMakeFiles/cursor.dir/flags.make
tests/CMakeFiles/cursor.dir/__/deps/glad.c.obj: tests/CMakeFiles/cursor.dir/includes_C.rsp
tests/CMakeFiles/cursor.dir/__/deps/glad.c.obj: deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrew\Downloads\glfw-3.2.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/cursor.dir/__/deps/glad.c.obj"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cursor.dir\__\deps\glad.c.obj   -c C:\Users\Andrew\Downloads\glfw-3.2.1\deps\glad.c

tests/CMakeFiles/cursor.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cursor.dir/__/deps/glad.c.i"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Andrew\Downloads\glfw-3.2.1\deps\glad.c > CMakeFiles\cursor.dir\__\deps\glad.c.i

tests/CMakeFiles/cursor.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cursor.dir/__/deps/glad.c.s"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Andrew\Downloads\glfw-3.2.1\deps\glad.c -o CMakeFiles\cursor.dir\__\deps\glad.c.s

# Object files for target cursor
cursor_OBJECTS = \
"CMakeFiles/cursor.dir/cursor.c.obj" \
"CMakeFiles/cursor.dir/__/deps/glad.c.obj"

# External object files for target cursor
cursor_EXTERNAL_OBJECTS =

tests/cursor.exe: tests/CMakeFiles/cursor.dir/cursor.c.obj
tests/cursor.exe: tests/CMakeFiles/cursor.dir/__/deps/glad.c.obj
tests/cursor.exe: tests/CMakeFiles/cursor.dir/build.make
tests/cursor.exe: src/libglfw3.a
tests/cursor.exe: tests/CMakeFiles/cursor.dir/linklibs.rsp
tests/cursor.exe: tests/CMakeFiles/cursor.dir/objects1.rsp
tests/cursor.exe: tests/CMakeFiles/cursor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Andrew\Downloads\glfw-3.2.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable cursor.exe"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cursor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/cursor.dir/build: tests/cursor.exe

.PHONY : tests/CMakeFiles/cursor.dir/build

tests/CMakeFiles/cursor.dir/clean:
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && $(CMAKE_COMMAND) -P CMakeFiles\cursor.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/cursor.dir/clean

tests/CMakeFiles/cursor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Andrew\Downloads\glfw-3.2.1 C:\Users\Andrew\Downloads\glfw-3.2.1\tests C:\Users\Andrew\Downloads\glfw-3.2.1 C:\Users\Andrew\Downloads\glfw-3.2.1\tests C:\Users\Andrew\Downloads\glfw-3.2.1\tests\CMakeFiles\cursor.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/cursor.dir/depend

