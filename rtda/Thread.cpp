//
// Created by 刘立新 on 2020/12/9.
//

#include "Thread.h"

void rtda::Thread::pushFrame(rtda::Frame *frame) {
    this->stack->push(frame);
}

rtda::Frame *rtda::Thread::popFrame() {
    return this->stack->pop();
}

rtda::Frame *rtda::Thread::currentFrame() {
    return this->stack->getTop();
}

