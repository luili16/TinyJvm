//
// Created by 刘立新 on 2020/12/9.
//

#include "JvmThread.h"

void rtda::JvmThread::pushFrame(rtda::Frame *frame) {
    //frame->setJvmThread(this);
    this->stack->push(frame);
}

rtda::Frame *rtda::JvmThread::popFrame() {
    auto f =  this->stack->pop();
    //f->setJvmThread(nullptr);
    return f;
}

rtda::Frame *rtda::JvmThread::currentFrame() {
    return this->stack->getTop();
}

