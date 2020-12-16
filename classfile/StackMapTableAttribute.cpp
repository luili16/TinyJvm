//
// Created by 刘立新 on 2020/12/11.
//

#include "StackMapTableAttribute.h"

class_file::StackMapTableAttribute::StackMapTableAttribute(uint16_t attributeNameIndex,
                                                           uint32_t attributeLength,
                                                           const ConstantPool* constantPool,
                                                           uint16_t numberOfEntries,
                                                           class_file::StackMapFrame **entries):
                                                           AttributeInfo(attributeNameIndex,attributeLength,constantPool),
                                                           numberOfEntries(numberOfEntries) {
    this->entries = entries;
}

const class_file::StackMapFrame *class_file::StackMapTableAttribute::getEntry(uint16_t index) {
    return this->entries[index];
}

const class_file::StackMapTableAttribute *
class_file::StackMapTableAttribute::newStackMapTableAttribute(class_file::ClassReader &reader) {

    uint16_t attributeNameIndex = reader.readUint16();
    uint32_t attributeLength = reader.readUint32();
    uint16_t numberOfEntries = reader.readUint16();
    auto entries = new StackMapFrame*[numberOfEntries];


    return nullptr;
}
