cmake_minimum_required(VERSION 3.16)
project(ch01)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
link_libraries(libzip.5.3.dylib)


add_executable(ch01 main.cpp Cmd.cpp Cmd.h CmdParser.cpp CmdParser.h classpath/Entry.cpp classpath/Entry.h Test.cpp Test.h util/CUtil.cpp util/CUtil.h classpath/ClassPath.cpp classpath/ClassPath.h classfile/ClassReader.cpp classfile/ClassReader.h classfile/ClassFile.cpp classfile/ClassFile.h classfile/ConstantPool.cpp classfile/ConstantPool.h classfile/ConstantPoolInfo.cpp classfile/ConstantPoolInfo.h classfile/ConstantClassInfo.cpp classfile/ConstantClassInfo.h classfile/ConstantFieldRefInfo.cpp classfile/ConstantFieldRefInfo.h classfile/ConstantMethodRefInfo.cpp classfile/ConstantMethodRefInfo.h classfile/ConstantInterfaceMethodRefInfo.cpp classfile/ConstantInterfaceMethodRefInfo.h classfile/ConstantStringInfo.cpp classfile/ConstantStringInfo.h classfile/ConstantInteger.cpp classfile/ConstantInteger.h)
target_link_libraries(ch01 libzip.5.3.dylib)
