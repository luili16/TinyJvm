# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liulixin/CLionProjects/jvmcpp/ch01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ch01_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ch01_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ch01_test.dir/flags.make

CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.o: CMakeFiles/ch01_test.dir/flags.make
CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.o: ../test/ClassFileTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.o -c /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassFileTest.cpp

CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassFileTest.cpp > CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.i

CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassFileTest.cpp -o CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.s

CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.o: CMakeFiles/ch01_test.dir/flags.make
CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.o: ../test/ClassPathTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.o -c /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassPathTest.cpp

CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassPathTest.cpp > CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.i

CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassPathTest.cpp -o CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.s

CMakeFiles/ch01_test.dir/test/UtilTest.cpp.o: CMakeFiles/ch01_test.dir/flags.make
CMakeFiles/ch01_test.dir/test/UtilTest.cpp.o: ../test/UtilTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ch01_test.dir/test/UtilTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch01_test.dir/test/UtilTest.cpp.o -c /Users/liulixin/CLionProjects/jvmcpp/ch01/test/UtilTest.cpp

CMakeFiles/ch01_test.dir/test/UtilTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch01_test.dir/test/UtilTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liulixin/CLionProjects/jvmcpp/ch01/test/UtilTest.cpp > CMakeFiles/ch01_test.dir/test/UtilTest.cpp.i

CMakeFiles/ch01_test.dir/test/UtilTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch01_test.dir/test/UtilTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liulixin/CLionProjects/jvmcpp/ch01/test/UtilTest.cpp -o CMakeFiles/ch01_test.dir/test/UtilTest.cpp.s

CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.o: CMakeFiles/ch01_test.dir/flags.make
CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.o: ../test/ClassReaderTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.o -c /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassReaderTest.cpp

CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassReaderTest.cpp > CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.i

CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liulixin/CLionProjects/jvmcpp/ch01/test/ClassReaderTest.cpp -o CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.s

# Object files for target ch01_test
ch01_test_OBJECTS = \
"CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.o" \
"CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.o" \
"CMakeFiles/ch01_test.dir/test/UtilTest.cpp.o" \
"CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.o"

# External object files for target ch01_test
ch01_test_EXTERNAL_OBJECTS =

ch01_test: CMakeFiles/ch01_test.dir/test/ClassFileTest.cpp.o
ch01_test: CMakeFiles/ch01_test.dir/test/ClassPathTest.cpp.o
ch01_test: CMakeFiles/ch01_test.dir/test/UtilTest.cpp.o
ch01_test: CMakeFiles/ch01_test.dir/test/ClassReaderTest.cpp.o
ch01_test: CMakeFiles/ch01_test.dir/build.make
ch01_test: lib/libgtestd.a
ch01_test: lib/libgtest_maind.a
ch01_test: libch01_lib.a
ch01_test: lib/libgtestd.a
ch01_test: CMakeFiles/ch01_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ch01_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch01_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ch01_test.dir/build: ch01_test

.PHONY : CMakeFiles/ch01_test.dir/build

CMakeFiles/ch01_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ch01_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ch01_test.dir/clean

CMakeFiles/ch01_test.dir/depend:
	cd /Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liulixin/CLionProjects/jvmcpp/ch01 /Users/liulixin/CLionProjects/jvmcpp/ch01 /Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug /Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug /Users/liulixin/CLionProjects/jvmcpp/ch01/cmake-build-debug/CMakeFiles/ch01_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ch01_test.dir/depend
