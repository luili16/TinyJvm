//
// Created by 刘立新 on 2020/12/10.
//

#ifndef CH01_ATTRCONSTANTVALUE_H
#define CH01_ATTRCONSTANTVALUE_H

#include "AttributeInfo.h"
#include "cstdint"

namespace class_file {
    class AttrConstantValue: public AttributeInfo {
    private:
        const uint16_t constantValueIndex;
    public:
        AttrConstantValue(uint16_t attributeNameIndex, uint32_t attributeLength, const ConstantPool* constantPool, uint16_t constantValueIndex);
        [[nodiscard]] uint16_t getConstantValueIndex() const;
    };
}


#endif //CH01_ATTRCONSTANTVALUE_H