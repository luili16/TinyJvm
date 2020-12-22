//
// Created by 刘立新 on 2020/12/9.
//

#ifndef CH01_JVMSTACK_H
#define CH01_JVMSTACK_H

#include <cstdint>
#include "Frame.h"
namespace rtda {
    class JvmStack {
    public:
        void push(Frame* frame);
        Frame* pop();
        Frame* getTop();
        explicit JvmStack(uint32_t maxSize);
    private:
        const uint32_t maxSize;
        uint32_t size = 0;
        Frame* top = nullptr;
    };
}



#endif //CH01_JVMSTACK_H
