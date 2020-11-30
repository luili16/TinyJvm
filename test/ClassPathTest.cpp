//
// Created by 刘立新 on 2020/11/26.
//

#include "gtest/gtest.h"
#include "../classpath/ClassPath.h"
#include <string>

TEST(ClassPathTest,readClass) {
    std::string xJre = std::string ("");
    std::string cp = std::string ("/Users/liulixin/CLionProjects/jvmcpp/ch01/test/testResource");
    auto classPath = class_path::ClassPath(xJre,cp);
    auto className = std::string ("jvmgo/book/ch01/HelloWorld");
    auto data = classPath.readClass(className);
    EXPECT_EQ(567,data->size());
    delete data;
}