//
// Created by 刘立新 on 2020/12/9.
//

#ifndef CH01_THREAD_H
#define CH01_THREAD_H

#include <cstdint>
#include "JvmStack.h"
#include "Frame.h"

namespace rtda {
    class Thread {
    public:
        uint32_t pc = 0;
        void pushFrame(Frame*frame);
        Frame* popFrame();
        Frame* currentFrame();
    private:
        JvmStack* stack = new JvmStack(1024);
    };
}




#endif //CH01_THREAD_H
