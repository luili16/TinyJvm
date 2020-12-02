//
// Created by 刘立新 on 2020/11/25.
//

#include "gtest/gtest.h"
#include "../classfile/ClassReader.h"
#include "../classpath/ClassPath.h"
#include "../classfile/ClassFile.h"
#include "../classfile/ConstantClassInfo.h"
#include "../classfile/ConstantUtf8Info.h"
#include "UtilTest.h"

class ClassFileTest: public::testing::Test {
protected:
    ClassFileTest() {
        std::string className = "jvmgo/book/ch03/ClassFileTest0";
        this->reader = UtilTest::createClassReader(className);
    }
    class_file::ClassReader *reader;
    ~ClassFileTest() override {
        delete this->reader;
    }
};

TEST_F(ClassFileTest, readTest) {
    auto classFile = class_file::ClassFile::read(*(this->reader));
    auto constantPool = classFile->getConstantPool();
    auto info = constantPool->getConstantInfo(classFile->getSuperClass());
    EXPECT_EQ(class_file::ConstantPoolInfo::CONSTANT_Class,info->tag);
    const auto* p2 = dynamic_cast<const class_file::ConstantClassInfo*>(info);
    EXPECT_NE(nullptr,p2);
    auto constantUtf8Info = dynamic_cast<const class_file::ConstantUtf8Info*>(constantPool->getConstantInfo(p2->nameIndex));
    EXPECT_EQ(class_file::ConstantPoolInfo::CONSTANT_Utf8, constantUtf8Info->tag);
//    EXPECT_EQ("", constantUtf8Info);

    EXPECT_EQ(1,1);
}