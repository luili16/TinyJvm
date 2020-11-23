//
// Created by 刘立新 on 2020/11/19.
//

#ifndef CH01_CLASSREADER_H
#define CH01_CLASSREADER_H

#include "vector"
#include <cstdint>

struct Uint16ArrayHolder {
    uint16_t* data;
    size_t len;
};

class ClassReader {
public:
    explicit ClassReader(std::vector<uint8_t>& classData);
    uint8_t readUint8();
    uint16_t readUint16();
    uint32_t readUint32();
    uint64_t readUint64();
    Uint16ArrayHolder* readUint16s();
    size_t readBytes(uint8_t * data, size_t len);
private:
    std::vector<uint8_t>& classData;
    std::size_t index = 0;
};


#endif //CH01_CLASSREADER_H
