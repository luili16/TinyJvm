
//
// Created by 刘立新 on 2020/11/30.
//

#include "Attributes.h"





class_file::Attributes::Attributes(uint16_t attributesCount,
                                   class_file::AttributeInfo ** attributes):
                                   attributesCount(attributesCount),
                                   attributes(attributes)
                                   {

}

uint16_t class_file::Attributes::getAttributesCount() const {
    return this->attributesCount;
}

const class_file::AttributeInfo *class_file::Attributes::getAttributeInfo(uint16_t index) const {
    return this->attributes[index];
}

const class_file::Attributes *class_file::Attributes::newAttributes(const ConstantPool* constantPool,class_file::ClassReader &reader) {
    uint16_t attributesCount = reader.readUint16();
    AttributeInfo** attributes;
    if (attributesCount == 0) {
        attributes = nullptr;
    } else {
        attributes = new AttributeInfo*[attributesCount];
        for (uint16_t i = 0; i < attributesCount; i++) {
            attributes[i] = AttributeInfo::newAttributeInfoByName(constantPool,reader);
        }
    }

    return new Attributes(attributesCount,attributes);
}

//const class_file::CodeAttribute *class_file::Attributes::findCodeAttribute(const ConstantPool* constantPool) const {
//
//    for (uint16_t i = 0; i < attributesCount; i++) {
//        auto attributeName = constantPool->getConstantUtf8Info(this->attributes[i]->getAttributeNameIndex())->decodeMUTF8();
//        if (AttributeInfo::isCode(*attributeName)) {
//            return dynamic_cast<const CodeAttribute*>(this->attributes[i]);
//        }
//    }
//
//    return nullptr;
//}
