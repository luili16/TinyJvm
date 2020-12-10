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

    static void assertU16stringEquals(std::u16string& expected, std::u16string& actual) {
        EXPECT_EQ(expected.length(),actual.length());
        for (size_t i = 0;i<actual.length();i++) {
            EXPECT_EQ(actual.at(i),expected.at(i));
        }
    }

    class_file::ClassReader *reader;
    ~ClassFileTest() override {
        delete this->reader;
    }
};

TEST_F(ClassFileTest, readTest) {
    auto classFile = class_file::ClassFile::read(*(this->reader));
    auto constantPool = classFile->getConstantPool();
    auto supperClassInfo = constantPool->getConstantInfo(classFile->getSuperClass());
    EXPECT_EQ(class_file::ConstantPoolInfo::CONSTANT_Class, supperClassInfo->tag);
    const auto* p2 = dynamic_cast<const class_file::ConstantClassInfo*>(supperClassInfo);
    EXPECT_NE(nullptr,p2);
    auto constantUtf8Info = dynamic_cast<const class_file::ConstantUtf8Info*>(constantPool->getConstantInfo(p2->nameIndex));
    EXPECT_EQ(class_file::ConstantPoolInfo::CONSTANT_Utf8, constantUtf8Info->tag);
    auto superClassStrPtr = constantUtf8Info->decodeMUTF8();
    auto expectedStr = std::u16string (u"java/lang/Object");
    ClassFileTest::assertU16stringEquals(expectedStr,*superClassStrPtr);

    auto thisClassInfo = constantPool->getConstantInfo(classFile->getThisClass());
    const auto thisClassInfoPtr = dynamic_cast<const class_file::ConstantClassInfo*>(thisClassInfo);
    EXPECT_NE(nullptr,thisClassInfoPtr);
    const auto thisClassInfoStrPtr = dynamic_cast<const class_file::ConstantUtf8Info*>(constantPool->getConstantInfo(thisClassInfoPtr->nameIndex));
    expectedStr = std::u16string (u"jvmgo/book/ch03/ClassFileTest");
    ClassFileTest::assertU16stringEquals(expectedStr,*thisClassInfoStrPtr->decodeMUTF8());

    auto fieldInfo0 = classFile->getFields()->getFieldInfo(0);
    auto fieldInfo0Name = ((class_file::ConstantUtf8Info*)constantPool->getConstantInfo(fieldInfo0->getNameIndex()))->decodeMUTF8();
    ClassFileTest::assertU16stringEquals(*(new std::u16string(u"FLAG")),*fieldInfo0Name);
    fieldInfo0->getAttributes()->getAttributeInfo(0);

    EXPECT_EQ(1,1);
}