//
// Created by 刘立新 on 2020/12/23.
//

#include "GetStatic.h"
#include <iostream>
#include "../rtda/heap/RunTimeConstantPool.h"
#include "../classfile/ConstantFieldRefInfo.h"

void instructions::references::GetStatic::execute(rtda::Frame &frame) {
    //Index16Instruction::execute(frame);
    std::cout << "call getStatic instruction" << std::endl;
    auto info = frame.method->thisClass->constantPool->getConstantInfo(this->index);
    std::cout << "info: " << info->tag << std::endl;
    auto fieldRef = dynamic_cast<const class_file::ConstantFieldRefInfo*>(info);
    std::cout << "fieldInfo: classIndex-> " << fieldRef->classIndex << std::endl;
    std::cout << "fieldInfo: nameAndTypeIndex-> " << fieldRef->nameAndTypeIndex << std::endl;
}
