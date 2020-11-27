//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantDoubleInfo.h"

class_file::ConstantDoubleInfo::ConstantDoubleInfo(uint8_t tag, uint32_t highBytes, uint32_t lowBytes):ConstantPoolInfo(tag),highBytes(highBytes),lowBytes(lowBytes) {

}
