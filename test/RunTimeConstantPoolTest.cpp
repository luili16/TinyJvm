//
// Created by 刘立新 on 2020/12/28.
//

#include "gtest/gtest.h"
#include "../classpath/ClassPath.h"
#include "../rtda/heap/RunTimeConstantPool.h"

using namespace std;
using namespace rtda::heap;
using namespace class_path;

TEST(RunTimeConstantPool,getClassTest) {
    string jreOption;
    string cpOption = "/Users/liulixin/CLionProjects/jvmcpp/ch01/test/testResource";
    shared_ptr<ClassPath> classPathPtr = make_shared<ClassPath>(jreOption, cpOption);
    RunTimeConstantPool::globalInit(classPathPtr);
    std::u16string className = u"com/";
    auto javaClass = RunTimeConstantPool::getInstance()->getClass(className);

    RunTimeConstantPool::globalDestroy();
}