//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantNameAndTypeInfo.h"

class_file::ConstantNameAndTypeInfo::ConstantNameAndTypeInfo(uint8_t tag, uint16_t nameIndex, uint16_t descriptorIndex):ConstantPoolInfo(tag),nameIndex(nameIndex),descriptorIndex(descriptorIndex) {

}
