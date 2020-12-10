//
// Created by 刘立新 on 2020/12/9.
//

#ifndef CH01_OPERANDSTACK_H
#define CH01_OPERANDSTACK_H
#include <cstdint>
#include "Slot.h"
namespace rtda {
    class OperandStack {
    public:
        explicit OperandStack(uint32_t maxStack);
        ~OperandStack();
    private:
        const uint32_t maxSize;
        uint32_t size = 0;
        Slot** slots;
    };
}
#endif //CH01_OPERANDSTACK_H
