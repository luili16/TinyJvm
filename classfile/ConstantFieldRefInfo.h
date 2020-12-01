//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTFIELDREFINFO_H
#define CH01_CONSTANTFIELDREFINFO_H


#include "ConstantPoolInfo.h"
namespace class_file {
    /**
 * CONSTANT_Fieldref_info {
 *      u1 tag;
 *      u2 class_index;
 *      u2 name_and_type_index;
 * }
 */
    class ConstantFieldRefInfo: public ConstantPoolInfo {
    public:
        const uint16_t classIndex;
        const uint16_t nameAndTypeIndex;
        explicit ConstantFieldRefInfo(uint8_t tag,uint16_t classIndex,uint16_t nameAndTypeIndex);
        ~ConstantFieldRefInfo() override = default;
    };
}



#endif //CH01_CONSTANTFIELDREFINFO_H
