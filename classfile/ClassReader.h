//
// Created by 刘立新 on 2020/11/19.
//

#ifndef CH01_CLASSREADER_H
#define CH01_CLASSREADER_H

#include "vector"
#include <cstdint>

namespace class_file {
    struct Uint16Array {
        uint16_t* data;
        size_t len;
    };

    class ClassReader {
    public:
        explicit ClassReader(std::vector<uint8_t>& classData);
        uint8_t readUint8();
        uint8_t peekUint8();
        uint16_t readUint16();
        uint16_t peekUint16();
        uint32_t readUint32();
        uint32_t peekUint32();
        uint64_t readUint64();
        uint64_t peekUint64();
        Uint16Array* readUint16s();
        uint16_t readBytes(uint8_t * data, uint16_t len);
    private:
        std::vector<uint8_t>& classData;
        std::size_t index = 0;
    };
}




#endif //CH01_CLASSREADER_H
