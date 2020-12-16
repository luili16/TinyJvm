//
// Created by 刘立新 on 2020/12/14.
//

#include "AttrLocalVariableTable.h"

class_file::LocalVariableTable::LocalVariableTable(uint16_t startPc,
                                                   uint16_t length,
                                                   uint16_t nameIndex,
                                                   uint16_t descriptorIndex,
                                                   uint16_t index):
                                                   startPc(startPc),
                                                   length(length),
                                                   nameIndex(nameIndex),
                                                   descriptorIndex(descriptorIndex),
                                                   index(index)
                                                   {
}

class_file::AttrLocalVariableTable::AttrLocalVariableTable(uint16_t attributeNameIndex,
                                                           uint32_t attributeLength,
                                                           const ConstantPool* constantPool,
                                                           uint16_t localVariableTableLength,
                                                           const class_file::LocalVariableTable **localVariableTable):
                                                           AttributeInfo(attributeNameIndex,attributeLength,constantPool),
                                                           localVariableTableLength(localVariableTableLength),
                                                           localVariableTable(localVariableTable)
                                                           {

}

class_file::AttrLocalVariableTable::~AttrLocalVariableTable() {
    delete [] localVariableTable;
    localVariableTable = nullptr;
}
