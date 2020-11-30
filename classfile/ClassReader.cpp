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

uint8_t class_file::ClassReader::peekUint8() {
    return this->classData[index];
}

uint16_t class_file::ClassReader::peekUint16() {
    uint8_t h = this->classData[index];
    uint8_t l = this->classData[index + 1];
    return (uint16_t)h << 8u | (uint16_t)l;
}

uint32_t class_file::ClassReader::peekUint32() {
    uint8_t h0 = this->classData[index];
    uint8_t h1 = this->classData[index + 1];
    uint16_t h = (uint16_t)h0 << 8u | (uint16_t)h1;
    uint8_t l0 = this->classData[index + 2];
    uint8_t l1 = this->classData[index + 3];
    uint16_t l = (uint16_t)l0 << 8u | (uint16_t)l1;
    return (uint32_t)h << 16u | (uint32_t)l;
}

uint64_t class_file::ClassReader::peekUint64() {

    uint8_t h0 = this->classData[index];
    uint8_t h1 = this->classData[index + 1];
    uint16_t dh0 = (uint16_t)h0 << 8u | (uint16_t)h1;
    uint8_t h2 = this->classData[index + 2];
    uint8_t h3 = this->classData[index + 3];
    uint16_t dh1 = (uint16_t)h2 << 8u | (uint16_t)h3;
    uint32_t dh = (uint32_t)dh0 << 16u | (uint32_t)dh1;

    uint8_t l0 = this->classData[index + 4];
    uint8_t l1 = this->classData[index + 5];
    uint16_t dl0 = (uint16_t)l0 << 8u | (uint16_t)l1;
    uint8_t l2 = this->classData[index + 6];
    uint8_t l3 = this->classData[index + 7];
    uint16_t dl1 = (uint16_t)l2 << 8u | (uint16_t)l3;
    uint32_t dl = (uint32_t)dl0 << 16u | (uint32_t)dl1;

    uint64_t d = (uint64_t)dh << 32u | (uint64_t)dl;
    return d;
}
