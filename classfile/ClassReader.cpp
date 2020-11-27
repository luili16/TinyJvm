//
// Created by 刘立新 on 2020/11/19.
//

#include "ClassReader.h"

class_file::ClassReader::ClassReader(std::vector<uint8_t> &classData):classData(classData) {
}

// u1
uint8_t class_file::ClassReader::readUint8() {
    uint8_t d = this->classData[index++];
    return d;
}

// u2
uint16_t class_file::ClassReader::readUint16() {
    // 大端
    uint16_t d0 = readUint8();
    uint16_t d1 = readUint8();
    uint16_t u = d0 << 8u | d1;
    return u;
}

// u4
uint32_t class_file::ClassReader::readUint32() {
    uint32_t d0 = readUint16();
    uint32_t d1 = readUint16();
    uint32_t u = d0 << 16u | d1;
    return u;
}

// u8
uint64_t class_file::ClassReader::readUint64() {
    uint64_t d0 = readUint32();
    uint64_t d1 = readUint32();
    uint64_t u = d0 << 32u | d1;
    return u;
}

class_file::Uint16ArrayHolder *class_file::ClassReader::readUint16s() {
    uint16_t n = readUint16();
    auto h = new Uint16ArrayHolder();
    h->data = new uint16_t [n];
    h->len = n;
    for (int i = 0; i != n; i++) {
        h->data[i] = readUint16();
    }
    return h;
}

uint16_t class_file::ClassReader::readBytes(uint8_t *data, uint16_t len) {
    if (index == this->classData.size()) {
        return 0;
    }
    size_t r = 0;
    for (int i = 0;i < len; i++) {
        if (index != this->classData.size()) {
            r = i + 1;
            data[i] = readUint8();
        }
    }
    return r;
}