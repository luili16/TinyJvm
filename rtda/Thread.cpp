//
// Created by 刘立新 on 2020/12/9.
//

#include "Thread.h"


void rtda::Thread::pushFrame(rtda::Frame *frame) {
    this->stack->push(frame);
}

rtda::Frame *rtda::Thread::popFrame() {
    auto f =  this->stack->pop();
    return f;
}

rtda::Frame *rtda::Thread::currentFrame() {
    return this->stack->getTop();
}

bool rtda::Thread::isJvmStackIsEmpty() {
    return this->stack->isEmpty();
}

rtda::Frame::Frame(heap::Method*method, Thread*jvmThread) {
    this->methodInfo = method;
    this->lower = nullptr;
    this->localVars = new LocalVars(method->maxLocals);
    this->operandStack = new OperandStack(method->maxStack);
    this->thread = jvmThread;
    this->nextPc = (uint64_t)this->methodInfo->code;
}

rtda::Frame::~Frame() {
    delete lower;
    delete localVars;
    delete operandStack;
}

rtda::LocalVars *rtda::Frame::getLocalVars() {
    return this->localVars;
}

rtda::OperandStack *rtda::Frame::getOperandStack() {
    return this->operandStack;
}

void rtda::Stack::push(Frame *frame) {
    if (size >= this->maxSize) {
        exit(common::ErrorCode::StackOverflowError);
    }

    if (this->top != nullptr) {
        frame->lower = this->top;
    }
    this->top = frame;
    this->size++;
}

rtda::Frame * rtda::Stack::pop() {
    if (this->top == nullptr) {
        exit(common::ErrorCode::JvmStackIsEmptyError);
    }

    Frame* f = this->top;
    this->top = f->lower;
    f->lower = nullptr;
    this->size--;
    return f;
}

rtda::Stack::Stack(uint32_t maxSize): maxSize(maxSize) {
}

rtda::Frame *rtda::Stack::getTop() {
    return this->top;
}

bool rtda::Stack::isEmpty() {
    return this->top == nullptr;
}

