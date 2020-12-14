//
// Created by 刘立新 on 2020/12/14.
//

#include "AttrEnclosingMethod.h"

class_file::AttrEnclosingMethod::AttrEnclosingMethod(uint16_t attributeNameIndex,
                                                     uint32_t attributeLength,
                                                     uint16_t classIndex,
                                                     uint16_t methodIndex):
                                                     AttributeInfo(attributeNameIndex,attributeLength),
                                                     classIndex(classIndex),
                                                     methodIndex(methodIndex)
                                                     {
}
