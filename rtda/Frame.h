//
// Created by 刘立新 on 2020/12/7.
//

#ifndef CH01_FRAME_H
#define CH01_FRAME_H

#include "LocalVars.h"
#include "OperandStack.h"
#include "../classfile/MethodInfo.h"
#include "../classfile/CodeAttribute.h"
#include "../classfile/ConstantPool.h"

namespace rtda {
    class Frame {
    public:
        const class_file::MethodInfo* methodInfo;
        explicit Frame(const class_file::MethodInfo *methodInfo);
        ~Frame();
        Frame* lower;

        LocalVars* getLocalVars();
        OperandStack* getOperandStack();
        uint32_t getNextPc();
        //void setJvmThread(JvmThread*t);
        //const class_file::MethodInfo* getMethodInfo();
    private:
        const class_file::CodeAttribute* codeAttribute;
        LocalVars *localVars;
        OperandStack *operandStack;
        //JvmThread* thread;
        // the next instruction after the call
        uint32_t nextPc = 0;
    };
}




#endif //CH01_FRAME_H
