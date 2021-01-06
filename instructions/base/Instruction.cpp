//
// Created by 刘立新 on 2020/12/21.
//

#include "Instruction.h"

const uint8_t instructions::base::Instruction::nop;
const uint8_t instructions::base::Instruction::aconst_null;
const uint8_t instructions::base::Instruction::iconst_m1;
const uint8_t instructions::base::Instruction::iconst_0;
const uint8_t instructions::base::Instruction::ldc;
const uint8_t instructions::base::Instruction::getstatic;

void instructions::base::Index8Instruction::fetchOperands(instructions::base::BytecodeReader &reader) {
    this->index = reader.readUInt8();
}

void instructions::base::Index16Instruction::fetchOperands(instructions::base::BytecodeReader &reader) {
    this->index = reader.readUInt16();
}
