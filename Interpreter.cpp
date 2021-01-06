//
// Created by 刘立新 on 2020/12/16.
//

#include "Interpreter.h"
#include "../classfile/CodeAttribute.h"
#include "../rtda/Thread.h"
#include "../instructions/base/BytecodeReader.h"
#include "../instructions/InstructionFactory.h"


void Interpreter::interpret(rtda::heap::Method*method) {

    auto thread = new rtda::Thread();
    auto frame = new rtda::Frame(method, thread);
    thread->pushFrame(frame);
    auto bytecodeReader = new instructions::base::BytecodeReader();
    auto factory = new instructions::InstructionFactory();
    while (!thread->isJvmStackIsEmpty()) {
        auto curFrame = thread->currentFrame();
        thread->pc = curFrame->nextPc;

        // deocde opcode
        bytecodeReader->restore(curFrame->nextPc);
        uint8_t opcode = bytecodeReader->readUInt8();
        auto instruction = factory->newInstruction(opcode);
        instruction->fetchOperands(*bytecodeReader);
        curFrame->nextPc = bytecodeReader->getPc();


        // execute opcode
        instruction->execute(*curFrame);
    }
    delete thread;
}
