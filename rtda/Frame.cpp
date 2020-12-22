//
// Created by 刘立新 on 2020/12/7.
//

#include "Frame.h"
#include "JvmThread.h"
#include "../classfile/CodeAttribute.h"

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

rtda::Frame::Frame(const class_file::MethodInfo *methodInfo) {
    this->methodInfo = methodInfo;
    auto codeAttr = findCodeAttribute(methodInfo);
    this->codeAttribute = codeAttr;
    this->lower = nullptr;
    this->localVars = new LocalVars(codeAttr->maxLocals);
    this->operandStack = new OperandStack(codeAttr->maxStack);
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
