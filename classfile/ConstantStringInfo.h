//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTSTRINGINFO_H
#define CH01_CONSTANTSTRINGINFO_H
#include "ConstantPoolInfo.h"

/**
 * CONSTANT_String_info {
 *      u1 tag;
 *      u2 string_index;
 * }
 */
class ConstantStringInfo: public ConstantPoolInfo {
public:
    const uint16_t stringIndex;
    explicit ConstantStringInfo(uint8_t tag,uint16_t stringIndex);
};


#endif //CH01_CONSTANTSTRINGINFO_H
