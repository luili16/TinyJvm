//
// Created by 刘立新 on 2020/11/27.
//

#include "gtest/gtest.h"
#include "../classfile/ClassReader.h"
#include "../classpath/ClassPath.h"

class ClassReaderTest: public::testing::Test {
protected:
    ClassReaderTest() {
        std::string xJre = std::string ("");
        std::string cp = std::string ("/Users/liulixin/CLionProjects/jvmcpp/ch01/test/testResource");
        auto classPath = class_path::ClassPath(xJre,cp);
        auto className = std::string ("jvmgo/book/ch03/ClassFileTest");
        auto data = classPath.readClass(className);
        this->reader = new class_file::ClassReader(*data);
    }
    class_file::ClassReader *reader;
};

TEST_F(ClassReaderTest, readTest){
    auto uint8 = reader->readUint8();
    EXPECT_EQ(0xca,uint8);
    auto uint16 = reader->readUint16();
    EXPECT_EQ(0xfeba,uint16);
    auto uint32 = reader->readUint32();
    EXPECT_EQ(0xbe000000,uint32);
    auto readUint64 = reader->readUint64();
    EXPECT_EQ(0x3400400a00060031, readUint64);
    uint8_t data[10];
    auto len = reader->readBytes(data,10);
    EXPECT_EQ(10,len);
    uint8_t expected[10] = {
            0x09,
            0x00,
            0x32,
            0x00,
            0x33,
            0x08,
            0x00,
            0x34,
            0x0a,
            0x00
    };
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(expected[i],data[i]);
    }
}

TEST_F(ClassReaderTest,readUint16s) {
    uint8_t data[11];
    reader->readBytes(data,11);
    auto holder = reader->readUint16s();
    EXPECT_EQ(holder->len,6);
    uint16_t h[6] = {
            0x0031,
            0x0900,
            0x3200,
            0x3308,
            0x0034,
            0x0a00
    };
    for (int i = 0; i < holder->len; i++) {
        EXPECT_EQ(h[i],holder->data[i]);
    }
}
