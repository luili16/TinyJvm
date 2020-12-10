//
// Created by 刘立新 on 2020/12/9.
//

#include "OperandStack.h"

rtda::OperandStack::OperandStack(uint32_t maxStack): maxSize(maxStack) {
    this->slots = new Slot*[maxStack];
}

rtda::OperandStack::~OperandStack() {
    delete [] slots;
}
