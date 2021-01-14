//
// Created by 刘立新 on 2020/12/22.
//

#ifndef CH01_CONST_H
#define CH01_CONST_H
#include "../base/Instruction.h"

namespace instructions::constants{

    class Nop: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class AConstNull: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class IConstM1: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class IConst0: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class IConst1: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class IConst2: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class IConst3: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class IConst4: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class IConst5: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class LConst0: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class LConst1: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class FConst0: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class FConst1: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class FConst2: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class DConst0: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class DConst1: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    };

    class BiPush: public instructions::base::Instruction {
    public:
        void fetchOperands(instructions::base::BytecodeReader &reader) override;
        void execute(rtda::Frame &frame) override;
    private:
        uint8_t byte = 0;
    };

    class SiPush: public instructions::base::Index8Instruction {
    public:
        void execute(rtda::Frame &frame) override;
    };

    class Ldc: public instructions::base::Index8Instruction {
    public:
        void execute(rtda::Frame &frame) override;
    };

}

#endif //CH01_CONST_H
