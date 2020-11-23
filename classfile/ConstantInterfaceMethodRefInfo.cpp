//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantInterfaceMethodRefInfo.h"

ConstantInterfaceMethodRefInfo::ConstantInterfaceMethodRefInfo(uint8_t tag, uint16_t classIndex,uint16_t nameAndTypeIndex):ConstantPoolInfo(tag),classIndex(classIndex),nameAndTypeIndex(nameAndTypeIndex) {
}
