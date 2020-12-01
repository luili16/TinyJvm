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

const class_file::Attributes *class_file::Attributes::newAttributes(class_file::ClassReader &reader) {
    uint16_t attributesCount = reader.readUint16();
    AttributeInfo** attributes;
    if (attributesCount == 0) {
        attributes = nullptr;
    } else {
        attributes = new AttributeInfo*[attributesCount];
        for (uint16_t i = 0; i < attributesCount; i++) {
            uint16_t attributeNameIndex = reader.readUint16();
            uint32_t attributeLength = reader.readUint32();
            uint8_t *info;
            if (attributeLength == 0) {
                info = nullptr;
            } else {
                info = new uint8_t [attributeLength];
                for (int j = 0; j < attributeLength; j++) {
                    info[j] = reader.readUint8();
                }
            }
            auto* attributeInfo = new AttributeInfo(attributeNameIndex,attributeLength,info);
            attributes[i] = attributeInfo;
        }
    }

    return new Attributes(attributesCount,attributes);
}
