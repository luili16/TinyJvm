//
// Created by 刘立新 on 2020/11/27.
//

#ifndef CH01_ATTRIBUTEINFO_H
#define CH01_ATTRIBUTEINFO_H
#include <cstdint>
#include "ConstantPool.h"
#include <string>

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

        static const std::u16string CONSTANT_VALUE;
        static const std::u16string CODE;
        static const std::u16string STACK_MAP_TABLE;
        static const std::u16string EXCEPTIONS;
        static const std::u16string BOOTSTRAP_METHODS;
        static const std::u16string ENCLOSING_METHOD;
        static const std::u16string LINE_NUMBER_TABLE;
        static const std::u16string LOCAL_VARIABLE_TABLE;
        static const std::u16string LOCAL_VARIABLE_TYPE_TABLE;

        static AttributeInfo* newAttributeInfoByName(const ConstantPool* constantPool, class_file::ClassReader &reader);

        static bool isConstantValue(std::u16string &attributeName);

        static bool isCode(std::u16string &attributeName);

        static bool isBootstrapMethods(std::u16string&attributeName);

        static bool isEnclosingMethod(std::u16string&attributeName);

        static bool isExceptions(std::u16string&attributeName);

        static bool isLineNumberTable(std::u16string&attributeName);

        static bool isLocalVariableTable(std::u16string&attributeName);

        static bool isLocalVariableTypeTable(std::u16string&attributeName);

        AttributeInfo(uint16_t attributeNameIndex, uint32_t attributeLength);
        [[nodiscard]] uint16_t getAttributeNameIndex() const;
        [[nodiscard]] uint32_t getAttributeLength() const;
        virtual ~AttributeInfo() = 0;
    };
}



#endif //CH01_ATTRIBUTEINFO_H
