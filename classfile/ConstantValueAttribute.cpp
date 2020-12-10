//
// Created by 刘立新 on 2020/12/10.
//

#include "ConstantValueAttribute.h"

uint16_t class_file::ConstantValueAttribute::getConstantValueIndex() const {
    return this->constantValueIndex;
}

class_file::ConstantValueAttribute::ConstantValueAttribute(uint16_t attributeNameIndex, uint32_t attributeLength,
                                                           uint16_t constantValueIndex):
                                                           AttributeInfo(attributeNameIndex,attributeLength),
                                                           constantValueIndex(constantValueIndex) {
}
