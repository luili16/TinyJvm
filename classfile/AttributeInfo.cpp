//
// Created by 刘立新 on 2020/11/27.
//

#include "AttributeInfo.h"
#include "ConstantUtf8Info.h"
#include "Attributes.h"
#include "ConstantValueAttribute.h"
#include "CodeAttribute.h"
#include "../util/CUtil.h"
#include "RawAttributeInfo.h"

const std::u16string class_file::AttributeInfo::ConstantValue = u"ConstantValue";
const std::u16string class_file::AttributeInfo::Code = u"Code";
const std::u16string class_file::AttributeInfo::StackMapTable = u"StackMapTable";
const std::u16string class_file::AttributeInfo::Exceptions = u"Exceptions";

uint16_t class_file::AttributeInfo::getAttributeNameIndex() const {
    return this->attributeNameIndex;
}

class_file::AttributeInfo::AttributeInfo(uint16_t attributeNameIndex,
                                         uint32_t attributeLength) :
        attributeNameIndex(attributeNameIndex),
        attributeLength(attributeLength) {
}

uint32_t class_file::AttributeInfo::getAttributeLength() const {
    return this->attributeLength;
}

class_file::AttributeInfo::~AttributeInfo() = default;

class_file::AttributeInfo *
class_file::AttributeInfo::newAttributeInfoByName(const class_file::ConstantPool *constantPool,
                                                  class_file::ClassReader &reader) {

    uint16_t attributeNameIndex = reader.readUint16();
    uint32_t attributeLength = reader.readUint32();
    auto utf8Info = constantPool->getConstantUtf8Info(attributeNameIndex);
    auto attributeName = const_cast<std::u16string &>(*(utf8Info)->decodeMUTF8());
    if (isConstantValue(attributeName)) {
        const uint16_t constantValueIndex = reader.readUint16();
        auto constantValueAttribute = new ConstantValueAttribute(
                attributeNameIndex,
                attributeLength,
                constantValueIndex);
        return constantValueAttribute;
    } else if (isCode(attributeName)) {
        const uint16_t maxStack = reader.readUint16();
        const uint16_t maxLocals = reader.readUint16();
        const uint32_t codeLength = reader.readUint32();

        uint8_t *code;
        if (codeLength == 0) {
            code = nullptr;
        } else {
            code = new uint8_t[codeLength];
            for (int i = 0; i < codeLength; i++) {
                code[i] = reader.readUint8();
            }
        }

        const ExceptionTable *exceptionTable = ExceptionTable::newExceptionTable(constantPool, reader);
        const Attributes *attributes = Attributes::newAttributes(constantPool, reader);
        auto codeAttribute = new CodeAttribute(
                attributeNameIndex,
                attributeLength,
                maxStack,
                maxLocals,
                codeLength,
                code,
                exceptionTable,
                attributes
        );
        return codeAttribute;
    } else {
        uint8_t *info;
        if (attributeLength == 0) {
            info = nullptr;
        } else {
            info = new uint8_t[attributeLength];
            for (int j = 0; j < attributeLength; j++) {
                info[j] = reader.readUint8();
            }
        }
        auto *attributeInfo = new RawAttributeInfo(attributeNameIndex, attributeLength, info);
        return attributeInfo;
    }
}

bool class_file::AttributeInfo::isConstantValue(std::u16string &attributeName) {
    //bool eq = CUtil::isU16StringEqual(const_cast<std::u16string &>(AttributeInfo::ConstantValue), attributeName);
    return attributeName == const_cast<std::u16string &>(AttributeInfo::ConstantValue);
}

bool class_file::AttributeInfo::isCode(std::u16string &attributeName) {
    //return CUtil::isU16StringEqual(const_cast<std::u16string &>(AttributeInfo::Code), attributeName);
    return attributeName == const_cast<std::u16string &>(AttributeInfo::Code);
}
