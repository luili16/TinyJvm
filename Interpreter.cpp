//
// Created by 刘立新 on 2020/12/16.
//

#include "Interpreter.h"
#include "../classfile/CodeAttribute.h"
#include "../rtda/JvmThread.h"
#include "../rtda/Frame.h"
#include "../instructions/base/BytecodeReader.h"
#include <iostream>


void Interpreter::interpret(const class_file::ConstantPool *constantPool, const class_file::MethodInfo *methodInfo) {

    //uint16_t maxLocals = codeAttr->maxLocals;
   // uint16_t maxStack = codeAttr->maxStack;
  //  auto byteCode = codeAttr->code;
   // auto codeLength = codeAttr->codeLength;
    auto thread = new rtda::JvmThread();
    auto frame = new rtda::Frame(methodInfo);
    thread->pushFrame(frame);

    while (thread->currentFrame() != nullptr) {
        auto curFrame = thread->popFrame();
        //curFrame->execOpcode();
        delete curFrame;
        // loop;
        //auto reader = instructions::base::BytecodeReader(byteCode,codeLength,frame->getNextPc());
        //uint8_t opcode = reader.readUInt8();
        // how to interpret opcode?
    }



}
