//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTINTERFACEMETHODREFINFO_H
#define CH01_CONSTANTINTERFACEMETHODREFINFO_H

#include "ConstantPoolInfo.h"
namespace class_file {
    class ConstantInterfaceMethodRefInfo: public ConstantPoolInfo {
    public:
        const uint16_t classIndex;
        const uint16_t nameAndTypeIndex;
        explicit ConstantInterfaceMethodRefInfo(uint8_t tag, uint16_t classIndex,uint16_t nameAndTypeIndex);
        ~ConstantInterfaceMethodRefInfo() override = default;
    };
}



#endif //CH01_CONSTANTINTERFACEMETHODREFINFO_H
