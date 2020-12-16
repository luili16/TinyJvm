//
// Created by 刘立新 on 2020/12/14.
//

#ifndef CH01_ATTRLOCALVARIABLETABLE_H
#define CH01_ATTRLOCALVARIABLETABLE_H

#include "AttributeInfo.h"

namespace class_file {

    class LocalVariableTable {
    public:
        const uint16_t startPc;
        const uint16_t length;
        const uint16_t nameIndex;
        const uint16_t descriptorIndex;
        const uint16_t index;
        explicit LocalVariableTable(uint16_t startPc,uint16_t length,uint16_t nameIndex,uint16_t descriptorIndex,uint16_t index);
    };

    class AttrLocalVariableTable: public AttributeInfo {
    public:
        const uint16_t localVariableTableLength;
        const LocalVariableTable** localVariableTable;
        explicit AttrLocalVariableTable(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t localVariableTableLength,const LocalVariableTable** localVariableTable);
        ~AttrLocalVariableTable() override;
    };
}

#endif //CH01_ATTRLOCALVARIABLETABLE_H
