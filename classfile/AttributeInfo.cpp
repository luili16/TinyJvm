//
// Created by 刘立新 on 2020/11/27.
//

#include "AttributeInfo.h"
#include "ConstantUtf8Info.h"
#include "Attributes.h"
#include "../common/ErrorCode.h"
#include "../util/CUtil.h"
#include <iostream>

uint16_t class_file::AttributeInfo::getAttributeNameIndex() const {
    return this->attributeNameIndex;
}

class_file::AttributeInfo::AttributeInfo(uint16_t attributeNameIndex,
                                         uint32_t attributeLength):
                                         attributeNameIndex(attributeNameIndex),
                                         attributeLength(attributeLength)
                                         {
}

uint32_t class_file::AttributeInfo::getAttributeLength() const {
    return this->attributeLength;
}

class_file::AttributeInfo::~AttributeInfo() = default;

class_file::AttributeInfo *class_file::AttributeInfo::newAttributeInfoByName(const class_file::ConstantPool *constantPool,
                                                                             class_file::ClassReader &reader) {

    uint16_t attributeNameIndex = reader.readUint16();
    uint32_t attributeLength = reader.readUint32();
    auto utf8Info = dynamic_cast<const ConstantUtf8Info*>(constantPool->getConstantInfo(attributeNameIndex));
    if (utf8Info == nullptr) {
        std::cerr << "invalid attributeNameIndex:"<< attributeNameIndex << std::endl;
        exit(common::ErrorCode::NullPointerError);
    }

    if (CUtil::isU16StringEqual(const_cast<std::u16string&>(Attributes::ConstantValue),
                                const_cast<std::u16string&>(*(utf8Info)->decodeMUTF8()))) {

    }

    return nullptr;
}
