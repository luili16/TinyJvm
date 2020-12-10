//
// Created by 刘立新 on 2020/12/9.
//

#include "JvmStack.h"
#include "../common/ErrorCode.h"
#include <cstdlib>

void rtda::JvmStack::push(Frame *frame) {
    if (this->maxSize > size) {
        exit(common::ErrorCode::StackOverflowError);
    }

    if (this->top != nullptr) {
        frame->lower = this->top;
    }
    this->top = frame;
    this->size++;
}

rtda::Frame * rtda::JvmStack::pop() {
    if (this->top == nullptr) {
        exit(common::ErrorCode::JvmStackIsEmptyError);
    }

    Frame* f = this->top;
    this->top = f->lower;
    f->lower = nullptr;
    this->size--;
    return f;
}

rtda::JvmStack::JvmStack(uint32_t maxSize):maxSize(maxSize) {
}

rtda::Frame *rtda::JvmStack::getTop() {
    return this->top;
}
