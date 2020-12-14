//
// Created by 刘立新 on 2020/12/14.
//

#ifndef CH01_ATTRLOCALVARIABLETYPETABLE_H
#define CH01_ATTRLOCALVARIABLETYPETABLE_H

#include "AttributeInfo.h"

namespace class_file {

    class LocalVariableTypeTable {
    public:
        const uint16_t startPc;
        const uint16_t length;
        const uint16_t nameIndex;
        const uint16_t signatureIndex;
        const uint16_t index;
        explicit LocalVariableTypeTable(uint16_t startPc,uint16_t length,uint16_t nameIndex,uint16_t signatureIndex,uint16_t index);
    };

    class AttrLocalVariableTypeTable: public AttributeInfo {
    public:
        const uint16_t localVariableTypeTableLength;
        const LocalVariableTypeTable** localVariableTypeTable;
        explicit AttrLocalVariableTypeTable(uint16_t attributeNameIndex, uint32_t attributeLength,uint16_t localVariableTypeTableLength,const LocalVariableTypeTable** localVariableTypeTable);
        [[nodiscard]] const LocalVariableTypeTable* getLocalVariableTypeTable(uint16_t index) const;
        ~AttrLocalVariableTypeTable() override;
    };
};




#endif //CH01_ATTRLOCALVARIABLETYPETABLE_H
