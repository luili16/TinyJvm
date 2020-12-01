//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTINVOKEDYNAMICINFO_H
#define CH01_CONSTANTINVOKEDYNAMICINFO_H

#include "ConstantPoolInfo.h"
namespace class_file {
    class ConstantInvokeDynamicInfo: public ConstantPoolInfo {
    public:
        const uint16_t bootstrapMethodAttrIndex;
        const uint16_t nameAndTypeIndex;
        explicit ConstantInvokeDynamicInfo(uint8_t tag,uint16_t bootstrapMethodAttrIndex,uint16_t nameAndTypeIndex);
        ~ConstantInvokeDynamicInfo() override = default;
    };
}



#endif //CH01_CONSTANTINVOKEDYNAMICINFO_H
