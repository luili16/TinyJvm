//
// Created by 刘立新 on 2020/12/7.
//

#ifndef CH01_FRAME_H
#define CH01_FRAME_H

#include "LocalVars.h"
#include "OperandStack.h"

namespace rtda {
    class Frame {
    public:
        explicit Frame(uint32_t maxLocals,uint32_t maxStack);
        ~Frame();
        Frame* lower;
    private:
        LocalVars *localVars;
        OperandStack *operandStack;
    };
}




#endif //CH01_FRAME_H
