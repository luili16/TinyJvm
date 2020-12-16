//
// Created by 刘立新 on 2020/12/7.
//

#include "Frame.h"
#include "JvmThread.h"

rtda::Frame::Frame(uint16_t maxLocals, uint16_t maxStack) {
    this->lower = nullptr;
    this->localVars = new LocalVars(maxLocals);
    this->operandStack = new OperandStack(maxStack);
    //this->thread = nullptr;
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

uint32_t rtda::Frame::getNextPc() {
    return this->nextPc;
}

//void rtda::Frame::setJvmThread(rtda::JvmThread *t) {
//    this->thread = t;
//}
