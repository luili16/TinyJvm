//
// Created by 刘立新 on 2020/12/10.
//

#ifndef CH01_CODEATTRIBUTE_H
#define CH01_CODEATTRIBUTE_H

#include "AttributeInfo.h"
#include "Attributes.h"

namespace class_file {

    class ExceptionTable;
    class CodeAttribute: public AttributeInfo {
    public:
        const uint16_t maxStack;
        const uint16_t maxLocals;
        const uint32_t codeLength;
        const uint8_t *code;
        const ExceptionTable *exceptionTable;
        const Attributes* attributes;
        explicit CodeAttribute(uint16_t attributeNameIndex,
                               uint32_t attributeLength,
                               uint16_t maxStack,
                               uint16_t maxLocals,
                               uint32_t codeLength,
                               const uint8_t *code,
                               const ExceptionTable *exceptionTable,
                               const Attributes* attributes
                               );
    };

    class Exception;
    class ExceptionTable {
    private:
        const uint16_t exceptionTableLength;
        Exception** exceptions;
    public:
        static const ExceptionTable* newExceptionTable(const ConstantPool* constantPool,ClassReader&reader);
        explicit ExceptionTable(uint16_t exceptionTableLength,Exception** exceptions);
        [[nodiscard]] uint16_t getExceptionTableLength() const;
        [[nodiscard]] const Exception* getException(uint16_t index) const;
    };

    class Exception {
    public:
        const uint16_t startPc;
        const uint16_t endPc;
        const uint16_t handlerPc;
        const uint16_t catchType;
        explicit Exception(uint16_t startPc,uint16_t endPc,uint16_t handlerPc,uint16_t catchType);
    };
}




#endif //CH01_CODEATTRIBUTE_H
