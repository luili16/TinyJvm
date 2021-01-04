//
// Created by 刘立新 on 2020/12/28.
//

#include "gtest/gtest.h"
#include "../classpath/ClassPath.h"
#include "../rtda/heap/RunTimeConstantPool.h"
#include <iostream>
#include <locale>
#include <codecvt>

using namespace std;
using namespace rtda::heap;
using namespace class_path;

TEST(RunTimeConstantPool,getClassTest) {
    string jreOption;
    string cpOption = "/Users/liulixin/CLionProjects/jvmcpp/ch01/test/testResource";
    shared_ptr<ClassPath> classPathPtr = make_shared<ClassPath>(jreOption, cpOption);
    RunTimeConstantPool::globalInit(classPathPtr);
    std::u16string className = u"jvmgo/book/ch03/ClassFileTest1";
    auto javaClass = RunTimeConstantPool::getInstance()->getClass(className);
    ASSERT_EQ(true,u"jvmgo/book/ch03/ClassFileTest" == *javaClass->name);
    ASSERT_EQ(true,*javaClass->superClassName == u"java/lang/Object");
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;

    for (int i = 0; i < javaClass->methodsLen; i++) {
        std::string  a = convert.to_bytes(*javaClass->methods[i]->name);
        std::cout << "method name: " << a << std::endl;
    }
    ASSERT_EQ(2,javaClass->methodsLen);
    RunTimeConstantPool::globalDestroy();
}