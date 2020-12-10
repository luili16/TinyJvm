//
// Created by 刘立新 on 2020/12/7.
//

#include "Frame.h"

rtda::Frame::Frame(uint32_t maxLocals,uint32_t maxStack) {
    this->lower = nullptr;
    this->localVars = new LocalVars(maxLocals);
    this->operandStack = new OperandStack(maxStack);
}

rtda::Frame::~Frame() {
    delete lower;
    delete localVars;
    delete operandStack;
}
