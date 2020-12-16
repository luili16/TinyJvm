//
// Created by 刘立新 on 2020/12/7.
//

#ifndef CH01_FRAME_H
#define CH01_FRAME_H

#include "LocalVars.h"
#include "OperandStack.h"

namespace rtda {
    class JvmThread;
    class Frame {
    public:
        explicit Frame(uint16_t maxLocals, uint16_t maxStack);
        ~Frame();
        Frame* lower;

        LocalVars* getLocalVars();
        OperandStack* getOperandStack();
        uint32_t getNextPc();
        //void setJvmThread(JvmThread*t);
    private:
        LocalVars *localVars;
        OperandStack *operandStack;
        //JvmThread* thread;
        // the next instruction after the call
        uint32_t nextPc = 0;
    };
}




#endif //CH01_FRAME_H
