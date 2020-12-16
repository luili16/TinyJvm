//
// Created by 刘立新 on 2020/12/16.
//

#ifndef CH01_BYTECODEREADER_H
#define CH01_BYTECODEREADER_H

#include "cstdint"

namespace instructions::base {
    class BytecodeReader {
    public:
        BytecodeReader(const uint8_t *code, uint32_t len,uint32_t pc);
        uint8_t getPc();
        int8_t readInt8();
        uint8_t readUInt8();
        int16_t readInt16();
        uint16_t readUInt16();
        int32_t readInt32();
        uint32_t readUInt32();
        int32_t *readInt32s(uint32_t n);
        uint32_t *readUInt32s(uint32_t n);
        void skipPadding();
    private:
        const uint32_t len;
        const uint8_t *code;
        uint32_t pc = 0u;
    };
}




#endif //CH01_BYTECODEREADER_H
