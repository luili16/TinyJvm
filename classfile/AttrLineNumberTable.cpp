//
// Created by 刘立新 on 2020/12/14.
//

#include "AttrLineNumberTable.h"

class_file::LineNumberTable0::LineNumberTable0(uint16_t startPc, uint16_t lineNumber):startPc(startPc),lineNumber(lineNumber) {
}

class_file::AttrLineNumberTable::AttrLineNumberTable(uint16_t attributeNameIndex,
                                                     uint32_t attributeLength,
                                                     uint16_t lineNumberTableLength,
                                                     const class_file::LineNumberTable0 **lineNumberTable)
                                                     :AttributeInfo(attributeNameIndex,attributeLength),
                                                     lineNumberTableLength(lineNumberTableLength),
                                                     lineNumberTables(lineNumberTable)
                                                     {

}

class_file::AttrLineNumberTable::~AttrLineNumberTable() {
    delete [] lineNumberTables;
    lineNumberTables = nullptr;
}

const class_file::LineNumberTable0 *class_file::AttrLineNumberTable::getLineNumberTable(uint16_t index) const {
    return this->lineNumberTables[index];
}
