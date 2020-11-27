//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTMETHODTYPEINFO_H
#define CH01_CONSTANTMETHODTYPEINFO_H
#include "ConstantPoolInfo.h"
namespace class_file {
    class ConstantMethodTypeInfo: public ConstantPoolInfo {
    public:
        const uint16_t descriptorIndex;
        explicit ConstantMethodTypeInfo(uint8_t tag,uint16_t descriptorIndex);
    };
}



#endif //CH01_CONSTANTMETHODTYPEINFO_H
