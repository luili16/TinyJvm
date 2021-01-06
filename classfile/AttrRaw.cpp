//
// Created by 刘立新 on 2020/12/11.
//

#include "AttrRaw.h"

class_file::AttrRaw::AttrRaw(uint16_t attributeNameIndex,
                             uint32_t attributeLength,
                             const ConstantPool* constantPool,
                             uint8_t *info):
                                               AttributeInfo(attributeNameIndex,attributeLength,constantPool),
                                               info(info)
                                               {
}
