//
// Created by 刘立新 on 2020/12/10.
//

#include "CodeAttribute.h"

class_file::Exception::Exception(uint16_t startPc,
                                           uint16_t endPc,
                                           uint16_t handlerPc,
                                           uint16_t catchType):
                                           startPc(startPc),
                                           endPc(endPc),
                                           handlerPc(handlerPc),
                                           catchType(catchType)
                                           {

}

class_file::CodeAttribute::CodeAttribute(uint16_t attributeNameIndex,
                                         uint32_t attributeLength,
                                         uint16_t maxStack,
                                         uint16_t maxLocals,
                                         uint32_t codeLength,
                                         const uint8_t *code,
                                         const class_file::ExceptionTable *exceptionTable,
                                         const class_file::Attributes *attributes):
                                         AttributeInfo(attributeNameIndex,attributeLength),
                                         maxStack(maxStack),
                                         maxLocals(maxLocals),
                                         codeLength(codeLength),
                                         code(code),
                                         exceptionTable(exceptionTable),
                                         attributes(attributes)
                                         {
}

const class_file::ExceptionTable *
class_file::ExceptionTable::newExceptionTable(const class_file::ConstantPool *constantPool,
                                              class_file::ClassReader &reader) {
    const uint16_t exceptionTableLength = reader.readUint16();
    Exception** exceptions;
    if (exceptionTableLength == 0) {
        exceptions = nullptr;
    } else {
        exceptions = new Exception*[exceptionTableLength];
        for (int i = 0;i < exceptionTableLength; i++) {
            const uint16_t startPc = reader.readUint16();
            const uint16_t endPc = reader.readUint16();
            const uint16_t handlerPc = reader.readUint16();
            const uint16_t catchType = reader.readUint16();
            exceptions[i] = new Exception(
                    startPc,
                    endPc,
                    handlerPc,
                    catchType
            );
        }
    }

    auto exceptionTable = new ExceptionTable(
            exceptionTableLength,
            exceptions
            );
    return exceptionTable;
}

class_file::ExceptionTable::ExceptionTable(uint16_t exceptionTableLength,
                                           class_file::Exception **exceptions):
                                           exceptionTableLength(exceptionTableLength),
                                           exceptions(exceptions)
                                           {
}

uint16_t class_file::ExceptionTable::getExceptionTableLength() const {
    return this->exceptionTableLength;
}

const class_file::Exception *class_file::ExceptionTable::getException(uint16_t index) const {
    return this->exceptions[index];
}
