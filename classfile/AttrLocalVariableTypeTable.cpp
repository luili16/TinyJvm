//
// Created by 刘立新 on 2020/12/14.
//

#include "AttrLocalVariableTypeTable.h"

class_file::LocalVariableTypeTable::LocalVariableTypeTable(uint16_t startPc,
                                                           uint16_t length,
                                                           uint16_t nameIndex,
                                                           uint16_t signatureIndex,
                                                           uint16_t index):
                                                           startPc(startPc),
                                                           length(length),
                                                           nameIndex(nameIndex),
                                                           signatureIndex(signatureIndex),
                                                           index(index)
                                                           {
}

class_file::AttrLocalVariableTypeTable::AttrLocalVariableTypeTable(uint16_t attributeNameIndex,
                                                                   uint32_t attributeLength,
                                                                   uint16_t localVariableTypeTableLength,
                                                                   const class_file::LocalVariableTypeTable **localVariableTypeTable):
                                                                   AttributeInfo(attributeNameIndex,attributeLength),
                                                                   localVariableTypeTableLength(localVariableTypeTableLength),
                                                                   localVariableTypeTable(localVariableTypeTable)
                                                                   {
}

const class_file::LocalVariableTypeTable *
class_file::AttrLocalVariableTypeTable::getLocalVariableTypeTable(uint16_t index) const {
    return this->localVariableTypeTable[index];
}

class_file::AttrLocalVariableTypeTable::~AttrLocalVariableTypeTable() {
    delete [] localVariableTypeTable;
    localVariableTypeTable = nullptr;
}
