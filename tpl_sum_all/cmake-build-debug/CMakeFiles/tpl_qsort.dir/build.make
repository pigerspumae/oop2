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
CMAKE_SOURCE_DIR = C:\Users\User\Documents\Projects\tpl_sum_all

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\Projects\tpl_sum_all\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tpl_qsort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tpl_qsort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tpl_qsort.dir/flags.make

CMakeFiles/tpl_qsort.dir/main.cpp.obj: CMakeFiles/tpl_qsort.dir/flags.make
CMakeFiles/tpl_qsort.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\Projects\tpl_sum_all\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tpl_qsort.dir/main.cpp.obj"
	C:\Users\User\Desktop\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tpl_qsort.dir\main.cpp.obj -c C:\Users\User\Documents\Projects\tpl_sum_all\main.cpp

CMakeFiles/tpl_qsort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tpl_qsort.dir/main.cpp.i"
	C:\Users\User\Desktop\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Documents\Projects\tpl_sum_all\main.cpp > CMakeFiles\tpl_qsort.dir\main.cpp.i

CMakeFiles/tpl_qsort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tpl_qsort.dir/main.cpp.s"
	C:\Users\User\Desktop\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Documents\Projects\tpl_sum_all\main.cpp -o CMakeFiles\tpl_qsort.dir\main.cpp.s

# Object files for target tpl_qsort
tpl_qsort_OBJECTS = \
"CMakeFiles/tpl_qsort.dir/main.cpp.obj"

# External object files for target tpl_qsort
tpl_qsort_EXTERNAL_OBJECTS =

tpl_qsort.exe: CMakeFiles/tpl_qsort.dir/main.cpp.obj
tpl_qsort.exe: CMakeFiles/tpl_qsort.dir/build.make
tpl_qsort.exe: CMakeFiles/tpl_qsort.dir/linklibs.rsp
tpl_qsort.exe: CMakeFiles/tpl_qsort.dir/objects1.rsp
tpl_qsort.exe: CMakeFiles/tpl_qsort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\Projects\tpl_sum_all\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tpl_qsort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tpl_qsort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tpl_qsort.dir/build: tpl_qsort.exe

.PHONY : CMakeFiles/tpl_qsort.dir/build

CMakeFiles/tpl_qsort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tpl_qsort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tpl_qsort.dir/clean

CMakeFiles/tpl_qsort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\Projects\tpl_sum_all C:\Users\User\Documents\Projects\tpl_sum_all C:\Users\User\Documents\Projects\tpl_sum_all\cmake-build-debug C:\Users\User\Documents\Projects\tpl_sum_all\cmake-build-debug C:\Users\User\Documents\Projects\tpl_sum_all\cmake-build-debug\CMakeFiles\tpl_qsort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tpl_qsort.dir/depend

