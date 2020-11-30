//
// Created by 刘立新 on 2020/11/30.
//

#include "Fields.h"
#include "Attributes.h"
class_file::Fields::Fields(uint16_t fieldsCount,
                           class_file::FieldInfo **fieldInfos):
                           fieldsCount(fieldsCount),
                           fieldInfos(fieldInfos)
                           {

}

uint16_t class_file::Fields::getFieldsCount() const {
    return this->fieldsCount;
}

const class_file::FieldInfo *class_file::Fields::getFieldInfo(uint16_t index) const {
    return this->fieldInfos[index];
}

const class_file::Fields *class_file::Fields::newFields(class_file::ClassReader &reader) {

    uint16_t fieldsCount = reader.readUint16();
    auto fieldInfos = new FieldInfo*[fieldsCount];
    for (int i = 0; i < fieldsCount; i++) {
        uint16_t accessFlags = reader.readUint16();
        uint16_t nameIndex = reader.readUint16();
        uint16_t descriptorIndex = reader.readUint16();
        auto attributes = Attributes::newAttributes(reader);
        fieldInfos[i] = new FieldInfo(accessFlags,nameIndex,descriptorIndex,attributes->getAttributesCount(),attributes);
    }
    return new Fields(fieldsCount,fieldInfos);
}
