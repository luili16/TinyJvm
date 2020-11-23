//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantMethodRefInfo.h"

ConstantMethodRefInfo::ConstantMethodRefInfo(uint8_t tag, uint16_t classIndex, uint16_t nameAndTypeIndex):ConstantPoolInfo(tag),classIndex(classIndex),nameAndTypeIndex(nameAndTypeIndex) {
}
