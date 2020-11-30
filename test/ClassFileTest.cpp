//
// Created by 刘立新 on 2020/11/25.
//

#include "gtest/gtest.h"
#include "../classfile/ClassReader.h"
#include "../classpath/ClassPath.h"
#include "../classfile/ClassFile.h"
#include "UtilTest.h"

class ClassFileTest: public::testing::Test {
protected:
    ClassFileTest() {
        this->reader = UtilTest::createClassReader();
    }
    class_file::ClassReader *reader;
    ~ClassFileTest() override {
        delete this->reader;
    }
};

TEST_F(ClassFileTest, readTest) {
    auto classFile = class_file::ClassFile::read(*(this->reader));

    EXPECT_EQ(1,1);
}