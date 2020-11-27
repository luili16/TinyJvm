//
// Created by 刘立新 on 2020/11/20.
//

#include "ConstantClassInfo.h"

class_file::ConstantClassInfo::ConstantClassInfo(uint8_t tag, uint16_t nameIndex) : ConstantPoolInfo(tag), nameIndex(nameIndex) {
}


