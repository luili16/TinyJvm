cmake_minimum_required(VERSION 3.16)
project(ch01)
set(GOOGLETEST_VERSION 1.10.0)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib-google-test)

include_directories(/usr/local/include ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
link_directories(/usr/local/lib)
link_libraries(libzip.5.3.dylib)

add_executable(ch01 main.cpp Cmd.cpp Cmd.h CmdParser.cpp CmdParser.h classpath/Entry.cpp classpath/Entry.h util/CUtil.cpp util/CUtil.h classpath/ClassPath.cpp classpath/ClassPath.h classfile/ClassReader.cpp classfile/ClassReader.h classfile/ClassFile.cpp classfile/ClassFile.h classfile/ConstantPool.cpp classfile/ConstantPool.h classfile/ConstantPoolInfo.cpp classfile/ConstantPoolInfo.h classfile/ConstantClassInfo.cpp classfile/ConstantClassInfo.h classfile/ConstantFieldRefInfo.cpp classfile/ConstantFieldRefInfo.h classfile/ConstantMethodRefInfo.cpp classfile/ConstantMethodRefInfo.h classfile/ConstantInterfaceMethodRefInfo.cpp classfile/ConstantInterfaceMethodRefInfo.h classfile/ConstantStringInfo.cpp classfile/ConstantStringInfo.h classfile/ConstantIntegerInfo.cpp classfile/ConstantIntegerInfo.h classfile/ConstantFloatInfo.cpp classfile/ConstantFloatInfo.h classfile/ConstantLongInfo.cpp classfile/ConstantLongInfo.h classfile/ConstantDoubleInfo.cpp classfile/ConstantDoubleInfo.h classfile/ConstantNameAndTypeInfo.cpp classfile/ConstantNameAndTypeInfo.h classfile/ConstantUtf8Info.cpp classfile/ConstantUtf8Info.h classfile/ConstantMethodHandleInfo.cpp classfile/ConstantMethodHandleInfo.h classfile/ConstantMethodTypeInfo.cpp classfile/ConstantMethodTypeInfo.h classfile/ConstantInvokeDynamicInfo.cpp classfile/ConstantInvokeDynamicInfo.h util/Abc.cpp util/Abc.h)

target_link_libraries(ch01 libzip.5.3.dylib)

add_library(ch01_lib main.cpp Cmd.cpp Cmd.h CmdParser.cpp CmdParser.h classpath/Entry.cpp classpath/Entry.h util/CUtil.cpp util/CUtil.h classpath/ClassPath.cpp classpath/ClassPath.h classfile/ClassReader.cpp classfile/ClassReader.h classfile/ClassFile.cpp classfile/ClassFile.h classfile/ConstantPool.cpp classfile/ConstantPool.h classfile/ConstantPoolInfo.cpp classfile/ConstantPoolInfo.h classfile/ConstantClassInfo.cpp classfile/ConstantClassInfo.h classfile/ConstantFieldRefInfo.cpp classfile/ConstantFieldRefInfo.h classfile/ConstantMethodRefInfo.cpp classfile/ConstantMethodRefInfo.h classfile/ConstantInterfaceMethodRefInfo.cpp classfile/ConstantInterfaceMethodRefInfo.h classfile/ConstantStringInfo.cpp classfile/ConstantStringInfo.h classfile/ConstantIntegerInfo.cpp classfile/ConstantIntegerInfo.h classfile/ConstantFloatInfo.cpp classfile/ConstantFloatInfo.h classfile/ConstantLongInfo.cpp classfile/ConstantLongInfo.h classfile/ConstantDoubleInfo.cpp classfile/ConstantDoubleInfo.h classfile/ConstantNameAndTypeInfo.cpp classfile/ConstantNameAndTypeInfo.h classfile/ConstantUtf8Info.cpp classfile/ConstantUtf8Info.h classfile/ConstantMethodHandleInfo.cpp classfile/ConstantMethodHandleInfo.h classfile/ConstantMethodTypeInfo.cpp classfile/ConstantMethodTypeInfo.h classfile/ConstantInvokeDynamicInfo.cpp classfile/ConstantInvokeDynamicInfo.h util/Abc.cpp util/Abc.h)
target_link_libraries(ch01_lib libzip.5.3.dylib)
add_executable(ch01_test test/ClassFileTest.cpp test/ClassPathTest.cpp test/UtilTest.cpp test/UtilTest.h test/ClassReaderTest.cpp)
target_link_libraries(ch01_test gtest gtest_main ch01_lib)
