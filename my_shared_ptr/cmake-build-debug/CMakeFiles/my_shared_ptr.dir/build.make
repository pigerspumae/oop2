# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Documents\Projects\oop2\my_shared_ptr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\Projects\oop2\my_shared_ptr\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_shared_ptr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_shared_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_shared_ptr.dir/flags.make

CMakeFiles/my_shared_ptr.dir/main.cpp.obj: CMakeFiles/my_shared_ptr.dir/flags.make
CMakeFiles/my_shared_ptr.dir/main.cpp.obj: CMakeFiles/my_shared_ptr.dir/includes_CXX.rsp
CMakeFiles/my_shared_ptr.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\Projects\oop2\my_shared_ptr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_shared_ptr.dir/main.cpp.obj"
	C:\Users\User\Desktop\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\my_shared_ptr.dir\main.cpp.obj -c C:\Users\User\Documents\Projects\oop2\my_shared_ptr\main.cpp

CMakeFiles/my_shared_ptr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_shared_ptr.dir/main.cpp.i"
	C:\Users\User\Desktop\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Documents\Projects\oop2\my_shared_ptr\main.cpp > CMakeFiles\my_shared_ptr.dir\main.cpp.i

CMakeFiles/my_shared_ptr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_shared_ptr.dir/main.cpp.s"
	C:\Users\User\Desktop\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Documents\Projects\oop2\my_shared_ptr\main.cpp -o CMakeFiles\my_shared_ptr.dir\main.cpp.s

# Object files for target my_shared_ptr
my_shared_ptr_OBJECTS = \
"CMakeFiles/my_shared_ptr.dir/main.cpp.obj"

# External object files for target my_shared_ptr
my_shared_ptr_EXTERNAL_OBJECTS =

my_shared_ptr.exe: CMakeFiles/my_shared_ptr.dir/main.cpp.obj
my_shared_ptr.exe: CMakeFiles/my_shared_ptr.dir/build.make
my_shared_ptr.exe: CMakeFiles/my_shared_ptr.dir/linklibs.rsp
my_shared_ptr.exe: CMakeFiles/my_shared_ptr.dir/objects1.rsp
my_shared_ptr.exe: CMakeFiles/my_shared_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\Projects\oop2\my_shared_ptr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_shared_ptr.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\my_shared_ptr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_shared_ptr.dir/build: my_shared_ptr.exe

.PHONY : CMakeFiles/my_shared_ptr.dir/build

CMakeFiles/my_shared_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\my_shared_ptr.dir\cmake_clean.cmake
.PHONY : CMakeFiles/my_shared_ptr.dir/clean

CMakeFiles/my_shared_ptr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\Projects\oop2\my_shared_ptr C:\Users\User\Documents\Projects\oop2\my_shared_ptr C:\Users\User\Documents\Projects\oop2\my_shared_ptr\cmake-build-debug C:\Users\User\Documents\Projects\oop2\my_shared_ptr\cmake-build-debug C:\Users\User\Documents\Projects\oop2\my_shared_ptr\cmake-build-debug\CMakeFiles\my_shared_ptr.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_shared_ptr.dir/depend

