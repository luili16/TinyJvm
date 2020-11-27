//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantMethodHandleInfo.h"

class_file::ConstantMethodHandleInfo::ConstantMethodHandleInfo(uint8_t tag, uint8_t referenceKind, uint16_t referenceIndex):ConstantPoolInfo(tag),referenceKind(referenceKind),referenceIndex(referenceIndex) {

}
