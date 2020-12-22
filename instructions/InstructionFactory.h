//
// Created by 刘立新 on 2020/12/21.
//

#ifndef CH01_INSTRUCTIONFACTORY_H
#define CH01_INSTRUCTIONFACTORY_H
#include "base/Instruction.h"
#include <unordered_map>

namespace instructions {
    class InstructionFactory {
    public:
        explicit InstructionFactory();
        const base::Instruction* newInstruction(uint8_t opcode);
    private:
        std::unordered_map<uint8_t,base::Instruction*>* instructionCache;
    };
}


#endif //CH01_INSTRUCTIONFACTORY_H
