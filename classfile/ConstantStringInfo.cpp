//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantStringInfo.h"

class_file::ConstantStringInfo::ConstantStringInfo(uint8_t tag, uint16_t stringIndex):ConstantPoolInfo(tag),stringIndex(stringIndex) {
}
