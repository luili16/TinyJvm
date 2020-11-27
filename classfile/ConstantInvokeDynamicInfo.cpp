//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantInvokeDynamicInfo.h"

class_file::ConstantInvokeDynamicInfo::ConstantInvokeDynamicInfo(uint8_t tag, uint16_t bootstrapMethodAttrIndex,
                                                     uint16_t nameAndTypeIndex):ConstantPoolInfo(tag),bootstrapMethodAttrIndex(bootstrapMethodAttrIndex),nameAndTypeIndex(nameAndTypeIndex) {

}
