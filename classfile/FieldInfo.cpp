//
// Created by 刘立新 on 2020/11/27.
//

#include "FieldInfo.h"

class_file::FieldInfo::FieldInfo(uint16_t accessFlags,
                                 uint16_t nameIndex,
                                 uint16_t descriptorIndex,
                                 uint16_t attributesCount,
                                 const Attributes* attributes):
                                 accessFlags(accessFlags),
                                 nameIndex(nameIndex),
                                 descriptorIndex(descriptorIndex),
                                 attributesCount(attributesCount),
                                 attributes(attributes)
                                 {

}

uint16_t class_file::FieldInfo::getAccessFlags() const {
    return this->accessFlags;
}

uint16_t class_file::FieldInfo::getNameIndex() const {
    return this->nameIndex;
}

uint16_t class_file::FieldInfo::getAttributesCount() const {
    return this->attributesCount;
}

uint16_t class_file::FieldInfo::getDescriptorIndex() const {
    return this->descriptorIndex;
}

const class_file::Attributes *class_file::FieldInfo::getAttributes() const {
    return this->attributes;
}
