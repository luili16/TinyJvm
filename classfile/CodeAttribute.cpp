//
// Created by 刘立新 on 2020/12/10.
//

#include "CodeAttribute.h"

class_file::ExceptionTable::ExceptionTable(uint16_t startPc,
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
                                         uint16_t exceptionTableLength,
                                         const class_file::ExceptionTable **exceptionTable,
                                         const class_file::Attributes *attributes):
                                         AttributeInfo(attributeNameIndex,attributeLength),
                                         maxStack(maxStack),
                                         maxLocals(maxLocals),
                                         codeLength(codeLength),
                                         code(code),
                                         exceptionTableLength(exceptionTableLength),
                                         exceptionTable(exceptionTable),
                                         attributes(attributes)
                                         {
}
