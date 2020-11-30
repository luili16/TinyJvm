//
// Created by 刘立新 on 2020/11/27.
//

#include "gtest/gtest.h"
#include "../classfile/ClassReader.h"
#include "../classpath/ClassPath.h"
#include "UtilTest.h"

class ClassReaderTest: public::testing::Test {
protected:
    ClassReaderTest() {
        this->reader = UtilTest::createClassReader();
    }
    ~ClassReaderTest() override {
        delete this->reader;
    }
    class_file::ClassReader *reader;
};

TEST_F(ClassReaderTest, readTest) {
    auto readUint8 = reader->readUint8();
    EXPECT_EQ(0xca, readUint8);
    auto readUint16 = reader->readUint16();
    EXPECT_EQ(0xfeba, readUint16);
    auto readUint32 = reader->readUint32();
    EXPECT_EQ(0xbe000000, readUint32);
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

TEST_F(ClassReaderTest,peeks) {
    uint8_t peekUint8 = reader->peekUint8();
    EXPECT_EQ(0xca,peekUint8);
    uint16_t peekUint16 = reader->peekUint16();
    EXPECT_EQ(0xcafe,peekUint16);
    uint32_t peekUint32 = reader->peekUint32();
    EXPECT_EQ(0xcafebabe,peekUint32);
    uint64_t peekUint64 = reader->peekUint64();
    EXPECT_EQ(0xcafebabe00000034,peekUint64);
}
