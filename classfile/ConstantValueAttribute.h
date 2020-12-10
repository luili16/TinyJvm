//
// Created by 刘立新 on 2020/12/10.
//

#ifndef CH01_CONSTANTVALUEATTRIBUTE_H
#define CH01_CONSTANTVALUEATTRIBUTE_H

#include "AttributeInfo.h"
#include "cstdint"

namespace class_file {
    class ConstantValueAttribute: public AttributeInfo {
    private:
        const uint16_t constantValueIndex;
    public:
        ConstantValueAttribute(uint16_t attributeNameIndex, uint32_t attributeLength, uint16_t constantValueIndex);
        [[nodiscard]] uint16_t getConstantValueIndex() const;
    };
}


#endif //CH01_CONSTANTVALUEATTRIBUTE_H