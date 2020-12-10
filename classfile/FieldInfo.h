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
        const static uint16_t ACC_PUBLIC = 0x0001;
        const static uint16_t ACC_PRIVATE = 0x0002;
        const static uint16_t ACC_PROTECTED = 0x0004;
        const static uint16_t ACC_STATIC = 0x0008;
        const static uint16_t ACC_FINAL = 0x0010;
        const static uint16_t ACC_TRANSIENT = 0x0080;
        const static uint16_t ACC_SYNTHETIC = 0x1000;
        const static uint16_t ACC_ENUM = 0x4000;

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
