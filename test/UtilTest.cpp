//
// Created by 刘立新 on 2020/11/27.
//

#include "UtilTest.h"
#include "../classfile/ClassReader.h"
#include "../classpath/ClassPath.h"

class_file::ClassReader *UtilTest::createClassReader() {
    std::string xJre = std::string ("");
    std::string cp = std::string ("/Users/liulixin/CLionProjects/jvmcpp/ch01/test/testResource");
    auto classPath = class_path::ClassPath(xJre,cp);
    auto className = std::string ("jvmgo/book/ch03/ClassFileTest");
    auto data = classPath.readClass(className);
    return new class_file::ClassReader(*data);
}

class_path::ClassPath *UtilTest::createClassPath() {
    return nullptr;
}
