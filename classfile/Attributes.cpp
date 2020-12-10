
//
// Created by 刘立新 on 2020/11/30.
//

#include "Attributes.h"

const std::u16string class_file::Attributes::ConstantValue = u"ConstantValue";
const std::u16string class_file::Attributes::Code = u"Code";
const std::u16string class_file::Attributes::StackMapTable = u"StackMapTable";
const std::u16string class_file::Attributes::Exceptions = u"Exceptions";



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
//            uint16_t attributeNameIndex = reader.readUint16();
//            uint32_t attributeLength = reader.readUint32();
//            uint8_t *info;
//            if (attributeLength == 0) {
//                info = nullptr;
//            } else {
//                info = new uint8_t [attributeLength];
//                for (int j = 0; j < attributeLength; j++) {
//                    info[j] = reader.readUint8();
//                }
//            }
//            auto* attributeInfo = new AttributeInfo(attributeNameIndex,attributeLength,info);
//            attributes[i] = attributeInfo;

            attributes[i] = AttributeInfo::newAttributeInfoByName(constantPool,reader);
        }
    }

    return new Attributes(attributesCount,attributes);
}