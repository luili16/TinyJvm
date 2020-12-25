//
// Created by 刘立新 on 2020/11/27.
//

#include "MethodInfo.h"
#include "CodeAttribute.h"

class_file::MethodInfo::MethodInfo(uint16_t accessFlags,
                                   uint16_t nameIndex,
                                   uint16_t descriptorIndex,
                                   uint16_t attributesCount,
                                   const class_file::Attributes *attributes,
                                   const ConstantPool* constantPool
                                   ):
                                   accessFlags(accessFlags),
                                   nameIndex(nameIndex),
                                   descriptorIndex(descriptorIndex),
                                   attributesCount(attributesCount),
                                   attributes(attributes),
                                   constantPool(constantPool)
                                   {

}

uint16_t class_file::MethodInfo::getAccessFlags() const {
    return this->accessFlags;
}

uint16_t class_file::MethodInfo::getNameIndex() const {
    return this->nameIndex;
}

uint16_t class_file::MethodInfo::getDescriptorIndex() const {
    return this->descriptorIndex;
}

uint16_t class_file::MethodInfo::getAttributesCount() const {
    return this->attributesCount;
}

const class_file::Attributes *class_file::MethodInfo::getAttributes() const {
    return this->attributes;
}

class_file::MethodInfo::~MethodInfo() {
    delete attributes;
    attributes = nullptr;
}

const class_file::CodeAttribute *class_file::MethodInfo::getCodeAttribute() const {

    for (int i = 0; i < this->attributesCount; i++) {
        auto attribute = this->attributes->getAttributeInfo(i);
        if (typeid(CodeAttribute) == typeid(*attribute)) {
            return dynamic_cast<const CodeAttribute*>(attribute);
        }
    }

    return nullptr;
}
