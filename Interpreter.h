//
// Created by 刘立新 on 2020/12/16.
//

#ifndef CH01_INTERPRETER_H
#define CH01_INTERPRETER_H

#include "../classfile/ClassFile.h"
#include "../classfile/MethodInfo.h"
#include "../classfile/ConstantPool.h"

class Interpreter {
public:
    void interpret(const class_file::ConstantPool*constantPool, const class_file::MethodInfo*methodInfo);
};


#endif //CH01_INTERPRETER_H
