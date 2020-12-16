//
// Created by 刘立新 on 2020/12/16.
//

#include "BytecodeReader.h"
#include <iostream>
#include "../common/ErrorCode.h"

instructions::base::BytecodeReader::BytecodeReader(const uint8_t *code,
                                                   uint32_t len,
                                                   uint32_t pc):
                                                   code(code),
                                                   len(len),
                                                   pc(pc) {
}

uint8_t instructions::base::BytecodeReader::getPc() {
    return this->pc;
}

int8_t instructions::base::BytecodeReader::readInt8() {
    return (int8_t)this->readUInt8();
}

uint8_t instructions::base::BytecodeReader::readUInt8() {
    uint8_t uint8 = this->code[pc];
    pc++;
    if (pc >= len) {
        std::cerr << "fetch opcode error." << std::endl;
        exit(common::ErrorCode::IndexOutOfArrayError);
    }
    return uint8;
}

int16_t instructions::base::BytecodeReader::readInt16() {
    return (int16_t)this->readUInt16();
}

uint16_t instructions::base::BytecodeReader::readUInt16() {
    uint16_t high = readUInt8();
    uint16_t low = readUInt8();
    return (high << 8u | low);
}

int32_t instructions::base::BytecodeReader::readInt32() {
    return (int32_t)this->readUInt32();
}

uint32_t instructions::base::BytecodeReader::readUInt32() {
    uint32_t high = readUInt16();
    uint32_t low = readUInt16();
    return high << 16u | low;
}

int32_t *instructions::base::BytecodeReader::readInt32s(uint32_t n) {
    return reinterpret_cast<int32_t*>(this->readUInt32s(n));
}

uint32_t *instructions::base::BytecodeReader::readUInt32s(uint32_t n) {

    auto arr = new uint32_t [n];
    for (int i = 0; i<n; i++) {
        arr[i] = readUInt8();
    }

    return arr;
}

void instructions::base::BytecodeReader::skipPadding() {
    while ((this->pc%4) != 0) {
        this->readUInt8();
    }
}
