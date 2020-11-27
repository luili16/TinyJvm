//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantMethodTypeInfo.h"

class_file::ConstantMethodTypeInfo::ConstantMethodTypeInfo(uint8_t tag, uint16_t descriptorIndex):ConstantPoolInfo(tag),descriptorIndex(descriptorIndex) {

}
