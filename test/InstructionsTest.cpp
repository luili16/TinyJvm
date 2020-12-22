//
// Created by 刘立新 on 2020/12/22.
//

#include "gtest/gtest.h"
#include "../instructions/InstructionFactory.h"
#include "../instructions/base/BytecodeReader.h"
#include "../instructions/constants/Const.h"

TEST(Instruction,opcodeConstantTest) {
    uint8_t opcodes[] = {
        0x12,
        0x15,
        0x16
    };
    auto byteCodeReader = instructions::base::BytecodeReader(opcodes,3,0);
    auto factory = new instructions::InstructionFactory();
    auto instruction = factory->newInstruction(byteCodeReader.readUInt8());
    auto isLdc = typeid(*instruction) == typeid(instructions::constants::Ldc);
    ASSERT_EQ(1,isLdc);
    auto ldc = dynamic_cast<const instructions::constants::Ldc*>(instruction);
    ASSERT_NE(nullptr,ldc);
    ASSERT_EQ(0x1516,ldc->index);
}