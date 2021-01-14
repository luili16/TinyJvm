//
// Created by 刘立新 on 2020/12/23.
//

#include "GetStatic.h"
#include <iostream>
#include "../rtda/heap/RunTimeConstantPool.h"
#include "../classfile/ConstantFieldRefInfo.h"
#include "../classfile/ConstantClassInfo.h"
#include "../classfile/ConstantNameAndTypeInfo.h"
#include "../util/CUtil.h"

using namespace rtda::heap;
void instructions::references::GetStatic::execute(rtda::Frame &frame) {
    //Index16Instruction::execute(frame);
    std::cout << "call getStatic instruction" << std::endl;
    auto constantPool = frame.method->thisClass->constantPool;
    auto info = constantPool->getConstantInfo(this->index);
    std::cout << "info: " << info->tag << std::endl;
    auto fieldRef = dynamic_cast<const class_file::ConstantFieldRefInfo*>(info);
    std::cout << "fieldInfo: classIndex-> " << fieldRef->classIndex << std::endl;
    std::cout << "fieldInfo: nameAndTypeIndex-> " << fieldRef->nameAndTypeIndex << std::endl;
    std::cout << "fieldInfo: nameAndTypeIndex-> " << fieldRef->nameAndTypeIndex << std::endl;
    auto ci = dynamic_cast<const class_file::ConstantClassInfo*>(constantPool->getConstantInfo(fieldRef->classIndex));
    auto className = constantPool->getConstantUtf8Info(ci->nameIndex)->decodeMUTF8();
    auto javaClass = RunTimeConstantPool::getInstance()->getClass(*className);
    auto nt = dynamic_cast<const class_file::ConstantNameAndTypeInfo*>(constantPool->getConstantInfo(fieldRef->nameAndTypeIndex));
    auto name = constantPool->getConstantUtf8Info(nt->nameIndex)->decodeMUTF8();
    auto type = constantPool->getConstantUtf8Info(nt->descriptorIndex)->decodeMUTF8();
    for (int i = 0; i < javaClass->fieldsCount; i++) {
        if (*javaClass->fields[i]->name == *name) {
            std::cout << " resolve field -> " << CUtil::toUtf8(*name) << std::endl;
            javaClass->fields[i]->resolveField();
        }
    }
}
