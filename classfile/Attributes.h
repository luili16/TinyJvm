//
// Created by 刘立新 on 2020/11/30.
//

#ifndef CH01_ATTRIBUTES_H
#define CH01_ATTRIBUTES_H
#include "cstdint"
#include "AttributeInfo.h"
#include "ClassReader.h"
#include "ConstantPool.h"
#include <string>
namespace class_file {
    class Attributes {
    private:
        const uint16_t attributesCount;
        AttributeInfo* const* attributes;
    public:
        static const Attributes* newAttributes(const ConstantPool* constantPool,ClassReader&reader);
        explicit Attributes(uint16_t attributesCount, AttributeInfo**attributes);
        [[nodiscard]] uint16_t getAttributesCount() const;
        [[nodiscard]] const AttributeInfo* getAttributeInfo(uint16_t index) const;
        //const CodeAttribute* findCodeAttribute(const ConstantPool* constantPool) const;
    };
}



#endif //CH01_ATTRIBUTES_H
