//
// Created by 刘立新 on 2020/12/14.
//

#include "AttrEnclosingMethod.h"

class_file::AttrEnclosingMethod::AttrEnclosingMethod(uint16_t attributeNameIndex,
                                                     uint32_t attributeLength,
                                                     const ConstantPool* constantPool,
                                                     uint16_t classIndex,
                                                     uint16_t methodIndex):
                                                     AttributeInfo(attributeNameIndex,attributeLength,constantPool),
                                                     classIndex(classIndex),
                                                     methodIndex(methodIndex)
                                                     {
}
