//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTNAMEANDTYPEINFO_H
#define CH01_CONSTANTNAMEANDTYPEINFO_H

#include "ConstantPoolInfo.h"
namespace class_file {
    /**
 * CONSTANT_NameAndType_info {
 *      u1 tag;
 *      u2 name_index;
 *      u2 descriptor_index;
 * }
 */
    class ConstantNameAndTypeInfo: public ConstantPoolInfo {
    public:
        const uint16_t nameIndex;
        const uint16_t descriptorIndex;
        explicit ConstantNameAndTypeInfo(uint8_t tag,uint16_t nameIndex,uint16_t descriptorIndex);
    };
}



#endif //CH01_CONSTANTNAMEANDTYPEINFO_H
