//
// Created by 刘立新 on 2020/12/16.
//

#ifndef CH01_INTERPRETER_H
#define CH01_INTERPRETER_H

#include "./classfile/ClassFile.h"
#include "./classfile/MethodInfo.h"
#include "./classfile/ConstantPool.h"
#include "./rtda/heap/Class.h"


class Interpreter {
public:
    void interpret(rtda::heap::Method*method);
};


#endif //CH01_INTERPRETER_H
