//
// Created by 刘立新 on 2020/12/9.
//

#ifndef CH01_THREAD_H
#define CH01_THREAD_H

#include <cstdint>
#include "../classfile/CodeAttribute.h"
#include "../classfile/MethodInfo.h"
#include "../rtda/LocalVars.h"
#include "../rtda/OperandStack.h"
#include "../common/ErrorCode.h"

namespace rtda {
    class Thread;
    class Frame {
    public:
        const class_file::MethodInfo* methodInfo;
        class_file::CodeAttribute* codeAttribute = nullptr;
        explicit Frame(const class_file::MethodInfo *methodInfo, Thread*jvmThread);
        ~Frame();
        Frame* lower;

        LocalVars* getLocalVars();
        OperandStack* getOperandStack();
        // the next instruction after the call
        uint64_t nextPc = 0u;
    private:
        LocalVars *localVars;
        OperandStack *operandStack;
        Thread* thread;
    };

    class Stack {
    public:
        void push(Frame* frame);
        Frame* pop();
        Frame* getTop();
        bool isEmpty();
        explicit Stack(uint32_t maxSize);
    private:
        const uint32_t maxSize;
        uint32_t size = 0;
        Frame* top = nullptr;
    };

    class Thread {
    public:
        uint64_t pc = 0;
        void pushFrame(Frame*frame);
        Frame* popFrame();
        Frame* currentFrame();
        bool isJvmStackIsEmpty();
    private:
        Stack* stack = new Stack(1024);
    };
}




#endif //CH01_THREAD_H
