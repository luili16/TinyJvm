//
// Created by 刘立新 on 2020/12/21.
//

#include "InstructionFactory.h"
#include "base/Instruction.h"
#include "constants/Const.h"

using namespace instructions::constants;
using namespace instructions::base;

instructions::InstructionFactory::InstructionFactory() {
    this->instructionCache = new std::unordered_map<uint8_t ,base::Instruction*>();
    // Constant
    this->instructionCache->insert({Instruction::nop, new Nop()});
    this->instructionCache->insert({Instruction::aconst_null, new AConstNull()});
    this->instructionCache->insert({Instruction::iconst_m1,new IConstM1()});
    this->instructionCache->insert({Instruction::iconst_0,new IConst0()});

    this->instructionCache->insert({Instruction::ldc,new Ldc()});

}

instructions::base::Instruction *instructions::InstructionFactory::newInstruction(uint8_t opcode) {
    return this->instructionCache->at(opcode);
}
