//
// Created by 刘立新 on 2020/11/27.
//

#ifndef CH01_METHODINFO_H
#define CH01_METHODINFO_H
#include "cstdint"
#include "Attributes.h"
#include "ConstantPool.h"
#include "CodeAttribute.h"

namespace class_file {
    class MethodInfo {
    private:
        const uint16_t accessFlags;
        const uint16_t nameIndex;
        const uint16_t descriptorIndex;
        const uint16_t attributesCount;
        const Attributes* attributes;
        const ConstantPool* constantPool;
    public:
        explicit MethodInfo(uint16_t accessFlags,
                            uint16_t nameIndex,
                            uint16_t descriptorIndex,
                            uint16_t attributesCount,
                            const Attributes* attributes,
                            const ConstantPool* constantPool
                            );
        ~MethodInfo();
        [[nodiscard]] uint16_t getAccessFlags() const;
        [[nodiscard]] uint16_t getNameIndex() const;
        [[nodiscard]] uint16_t getDescriptorIndex() const;
        [[nodiscard]] uint16_t getAttributesCount() const;
        [[nodiscard]] const Attributes* getAttributes() const;
        const CodeAttribute* getCodeAttribute() const;
    };
}



#endif //CH01_METHODINFO_H
