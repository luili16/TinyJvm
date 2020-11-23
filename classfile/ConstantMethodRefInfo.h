//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTMETHODREFINFO_H
#define CH01_CONSTANTMETHODREFINFO_H

#include "ConstantPoolInfo.h"
/**
 * CONSTANT_Methodref_info {
 *      u1 tag;
 *      u2 class_index;
 *      u2 name_and_type_index;
 * }
 */
class ConstantMethodRefInfo: public ConstantPoolInfo {
public:
    const uint16_t classIndex;
    const uint16_t nameAndTypeIndex;
    explicit ConstantMethodRefInfo(uint8_t tag,uint16_t classIndex,uint16_t nameAndTypeIndex);
};


#endif //CH01_CONSTANTMETHODREFINFO_H
