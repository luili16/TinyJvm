//
// Created by 刘立新 on 2020/11/27.
//

#ifndef CH01_FIELDINFO_H
#define CH01_FIELDINFO_H
#include <cstdint>
#include "Attributes.h"
#include "ClassReader.h"
namespace class_file {
    class FieldInfo {
    private:
        const uint16_t accessFlags;
        const uint16_t nameIndex;
        const uint16_t descriptorIndex;
        const uint16_t attributesCount;
        const Attributes* attributes;
    public:
        explicit FieldInfo(uint16_t accessFlags,
                           uint16_t nameIndex,
                           uint16_t descriptorIndex,
                           uint16_t attributesCount,
                           const Attributes* attributes);
        [[nodiscard]] uint16_t getAccessFlags() const;
        [[nodiscard]] uint16_t getNameIndex() const;
        [[nodiscard]] uint16_t getDescriptorIndex() const;
        [[nodiscard]] uint16_t getAttributesCount() const;
        [[nodiscard]] const Attributes* getAttributes() const;
    };
}

#endif //CH01_FIELDINFO_H
