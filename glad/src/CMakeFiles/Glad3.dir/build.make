# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\asher\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7628.27\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\asher\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7628.27\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\asher\CLionProjects\Open_Dungeoun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug

# Include any dependencies generated for this target.
include ..\glad\src\CMakeFiles\Glad3.dir\depend.make

# Include the progress variables for this target.
include ..\glad\src\CMakeFiles\Glad3.dir\progress.make

# Include the compile flags for this target's objects.
include ..\glad\src\CMakeFiles\Glad3.dir\flags.make

..\glad\src\CMakeFiles\Glad3.dir\glad.c.obj: ..\glad\src\CMakeFiles\Glad3.dir\flags.make
..\glad\src\CMakeFiles\Glad3.dir\glad.c.obj: ..\glad\src\glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ../glad/src/CMakeFiles/Glad3.dir/glad.c.obj"
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Glad3.dir\glad.c.obj /FdCMakeFiles\Glad3.dir\Glad3.pdb /FS -c C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src\glad.c
<<
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug

..\glad\src\CMakeFiles\Glad3.dir\glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Glad3.dir/glad.c.i"
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe > CMakeFiles\Glad3.dir\glad.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src\glad.c
<<
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug

..\glad\src\CMakeFiles\Glad3.dir\glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Glad3.dir/glad.c.s"
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Glad3.dir\glad.c.s /c C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src\glad.c
<<
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug

# Object files for target Glad3
Glad3_OBJECTS = \
"CMakeFiles\Glad3.dir\glad.c.obj"

# External object files for target Glad3
Glad3_EXTERNAL_OBJECTS =

..\glad\src\Glad3.lib: ..\glad\src\CMakeFiles\Glad3.dir\glad.c.obj
..\glad\src\Glad3.lib: ..\glad\src\CMakeFiles\Glad3.dir\build.make
..\glad\src\Glad3.lib: ..\glad\src\CMakeFiles\Glad3.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library Glad3.lib"
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src
	$(CMAKE_COMMAND) -P CMakeFiles\Glad3.dir\cmake_clean_target.cmake
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\lib.exe /nologo /machine:x64 /out:Glad3.lib @CMakeFiles\Glad3.dir\objects1.rsp 
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug

# Rule to build all files generated by this target.
..\glad\src\CMakeFiles\Glad3.dir\build: ..\glad\src\Glad3.lib

.PHONY : ..\glad\src\CMakeFiles\Glad3.dir\build

..\glad\src\CMakeFiles\Glad3.dir\clean:
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src
	$(CMAKE_COMMAND) -P CMakeFiles\Glad3.dir\cmake_clean.cmake
	cd C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug
.PHONY : ..\glad\src\CMakeFiles\Glad3.dir\clean

..\glad\src\CMakeFiles\Glad3.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\asher\CLionProjects\Open_Dungeoun C:\Users\asher\CLionProjects\Open_Dungeoun\glad C:\Users\asher\CLionProjects\Open_Dungeoun\cmake-build-debug C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src C:\Users\asher\CLionProjects\Open_Dungeoun\glad\src\CMakeFiles\Glad3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : ..\glad\src\CMakeFiles\Glad3.dir\depend
