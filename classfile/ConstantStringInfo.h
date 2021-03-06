//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTSTRINGINFO_H
#define CH01_CONSTANTSTRINGINFO_H
#include "ConstantPoolInfo.h"
namespace class_file {
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
        ~ConstantStringInfo() override = default;
    };
}



#endif //CH01_CONSTANTSTRINGINFO_H
