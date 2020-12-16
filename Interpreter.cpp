//
// Created by 刘立新 on 2020/12/16.
//

#include "Interpreter.h"
#include "../classfile/CodeAttribute.h"
#include "../rtda/JvmThread.h"
#include "../rtda/Frame.h"
#include "../instructions/base/BytecodeReader.h"
#include <iostream>

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


void Interpreter::interpret(const class_file::ConstantPool *constantPool, const class_file::MethodInfo *methodInfo) {
    auto codeAttr = findCodeAttribute(methodInfo);
    if (codeAttr == nullptr) {
        return;
    }

    uint16_t maxLocals = codeAttr->maxLocals;
    uint16_t maxStack = codeAttr->maxStack;
    auto byteCode = codeAttr->code;
    auto codeLength = codeAttr->codeLength;
    auto thread = new rtda::JvmThread();
    auto frame = new rtda::Frame(maxLocals,maxStack);
    thread->pushFrame(frame);

    // loop;
    auto reader = instructions::base::BytecodeReader(byteCode,codeLength,frame->getNextPc());
    uint8_t opcode = reader.readUInt8();
    // how to interpret opcode?

}
