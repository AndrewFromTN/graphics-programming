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
include tests/CMakeFiles/vulkan.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/vulkan.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/vulkan.dir/flags.make

tests/CMakeFiles/vulkan.dir/vulkan.c.obj: tests/CMakeFiles/vulkan.dir/flags.make
tests/CMakeFiles/vulkan.dir/vulkan.c.obj: tests/CMakeFiles/vulkan.dir/includes_C.rsp
tests/CMakeFiles/vulkan.dir/vulkan.c.obj: tests/vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andrew\Downloads\glfw-3.2.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/vulkan.dir/vulkan.c.obj"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\vulkan.dir\vulkan.c.obj   -c C:\Users\Andrew\Downloads\glfw-3.2.1\tests\vulkan.c

tests/CMakeFiles/vulkan.dir/vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vulkan.dir/vulkan.c.i"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Andrew\Downloads\glfw-3.2.1\tests\vulkan.c > CMakeFiles\vulkan.dir\vulkan.c.i

tests/CMakeFiles/vulkan.dir/vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vulkan.dir/vulkan.c.s"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Andrew\Downloads\glfw-3.2.1\tests\vulkan.c -o CMakeFiles\vulkan.dir\vulkan.c.s

# Object files for target vulkan
vulkan_OBJECTS = \
"CMakeFiles/vulkan.dir/vulkan.c.obj"

# External object files for target vulkan
vulkan_EXTERNAL_OBJECTS =

tests/vulkan.exe: tests/CMakeFiles/vulkan.dir/vulkan.c.obj
tests/vulkan.exe: tests/CMakeFiles/vulkan.dir/build.make
tests/vulkan.exe: src/libglfw3.a
tests/vulkan.exe: C:/Windows/System32/vulkan-1.dll
tests/vulkan.exe: tests/CMakeFiles/vulkan.dir/linklibs.rsp
tests/vulkan.exe: tests/CMakeFiles/vulkan.dir/objects1.rsp
tests/vulkan.exe: tests/CMakeFiles/vulkan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Andrew\Downloads\glfw-3.2.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable vulkan.exe"
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\vulkan.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/vulkan.dir/build: tests/vulkan.exe

.PHONY : tests/CMakeFiles/vulkan.dir/build

tests/CMakeFiles/vulkan.dir/clean:
	cd /d C:\Users\Andrew\Downloads\glfw-3.2.1\tests && $(CMAKE_COMMAND) -P CMakeFiles\vulkan.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/vulkan.dir/clean

tests/CMakeFiles/vulkan.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Andrew\Downloads\glfw-3.2.1 C:\Users\Andrew\Downloads\glfw-3.2.1\tests C:\Users\Andrew\Downloads\glfw-3.2.1 C:\Users\Andrew\Downloads\glfw-3.2.1\tests C:\Users\Andrew\Downloads\glfw-3.2.1\tests\CMakeFiles\vulkan.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/vulkan.dir/depend
