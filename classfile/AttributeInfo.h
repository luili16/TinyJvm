//
// Created by 刘立新 on 2020/11/27.
//

#ifndef CH01_ATTRIBUTEINFO_H
#define CH01_ATTRIBUTEINFO_H
#include <cstdint>
#include "ConstantPool.h"

namespace class_file {
    /**
     * attribute_info {
     *  u2 attribute_name_index;
     *  u4 attribute_length;
     *  u1 info[attribute_length];
     * }
     */
    class AttributeInfo {
    private:
        const uint16_t attributeNameIndex;
        const uint32_t attributeLength;
    public:
        static AttributeInfo* newAttributeInfoByName(const ConstantPool* constantPool, class_file::ClassReader &reader);
        AttributeInfo(uint16_t attributeNameIndex, uint32_t attributeLength);
        [[nodiscard]] uint16_t getAttributeNameIndex() const;
        [[nodiscard]] uint32_t getAttributeLength() const;
        virtual ~AttributeInfo() = 0;
    };
}



#endif //CH01_ATTRIBUTEINFO_H
