//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantUtf8Info.h"

class_file::ConstantUtf8Info::ConstantUtf8Info(uint8_t tag,
                                               uint16_t length,
                                               const uint8_t *bytes):
                                               ConstantPoolInfo(tag),
                                               length(length),
                                               bytes(bytes) {

}
