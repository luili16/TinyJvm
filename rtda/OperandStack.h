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
        explicit OperandStack(uint16_t maxStack);
        ~OperandStack();
        void pushInt(int32_t int32);
        int32_t popInt();
        void pushFloat(float float32);
        float popFloat();
        void pushLong(int64_t int64);
        int64_t popLong();
        void pushDouble(double float64);
        double popDouble();
    private:
        const uint16_t maxStack;
        uint16_t size = -1;
        Slot** slots;
    };
}
#endif //CH01_OPERANDSTACK_H
