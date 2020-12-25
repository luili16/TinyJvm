//
// Created by 刘立新 on 2020/12/9.
//

#include "Thread.h"


void rtda::Thread::pushFrame(rtda::Frame *frame) {
    this->stack->push(frame);
}

rtda::Frame *rtda::Thread::popFrame() {
    auto f =  this->stack->pop();
    //f->setJvmThread(nullptr);
    return f;
}

rtda::Frame *rtda::Thread::currentFrame() {
    return this->stack->getTop();
}

bool rtda::Thread::isJvmStackIsEmpty() {
    return this->stack->isEmpty();
}

const class_file::CodeAttribute* findCodeAttribute(const class_file::MethodInfo *methodInfo) {
    auto count = methodInfo->getAttributesCount();
    for (int i = 0; i < count; i++) {
        auto attributeName = methodInfo->getAttributes()->getAttributeInfo(i)->getAttributeName();
        if (class_file::AttributeInfo::isCode(*attributeName)) {
            return dynamic_cast<const class_file::CodeAttribute*>(methodInfo->getAttributes()->getAttributeInfo(i));
        }
    }
    return nullptr;
}

rtda::Frame::Frame(const class_file::MethodInfo *methodInfo, Thread*jvmThread) {
    this->methodInfo = methodInfo;
    auto codeAttr = findCodeAttribute(methodInfo);
    this->codeAttribute = const_cast<class_file::CodeAttribute*>(codeAttr);
    this->lower = nullptr;
    this->localVars = new LocalVars(codeAttr->maxLocals);
    this->operandStack = new OperandStack(codeAttr->maxStack);
    this->thread = jvmThread;
    this->nextPc = (uint64_t)this->codeAttribute->code;
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

