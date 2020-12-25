//
// Created by 刘立新 on 2020/12/24.
//

#include "AttrSignature.h"

class_file::AttrSignature::AttrSignature(uint16_t attributeNameIndex, uint32_t attributeLength,
                                         const class_file::ConstantPool *constantPool, uint16_t signatureIndex):AttributeInfo(attributeNameIndex,attributeLength,constantPool),
                                         signatureIndex(signatureIndex)
                                         {

}
