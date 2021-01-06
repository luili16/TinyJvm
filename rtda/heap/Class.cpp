//
// Created by 刘立新 on 2020/12/24.
//

#include "Class.h"
#include "../classfile/AttrConstantValue.h"
#include "../classfile/ConstantLongInfo.h"
#include "../classfile/ConstantIntegerInfo.h"
#include "../classfile/ConstantDoubleInfo.h"
#include "../classfile/ConstantFloatInfo.h"
#include "../classfile/AttrSignature.h"
#include "../common/ErrorCode.h"
#include "../rtda/heap/RunTimeConstantPool.h"
#include "../util/CUtil.h"
#include <iostream>

void rtda::heap::Field::resolveField() {

}

std::shared_ptr<std::u16string> findSignature(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto attriInfo = info->getAttributes()->getAttributeInfo(i);
        auto attributeName = attriInfo->getAttributeName();
        if (class_file::AttributeInfo::isSignature(*attributeName)) {
            auto signatureInfo = dynamic_cast<const class_file::AttrSignature*>(attriInfo);
            auto signatureName= constantPool->getConstantUtf8Info(signatureInfo->signatureIndex)->decodeMUTF8();
            return signatureName;
        }
    }
    return std::make_shared<std::u16string>();
}

rtda::heap::Field *
rtda::heap::Field::newField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    auto name = constantPool->getConstantUtf8Info(info->getNameIndex())->decodeMUTF8();
    auto descriptor = constantPool->getConstantUtf8Info(info->getDescriptorIndex())->decodeMUTF8();
    auto signatureName = findSignature(constantPool,info);
    Field* field = nullptr;

    if (*descriptor == u"B") {
        field = new ByteField(constantPool, info);
    } else if (*descriptor == u"C") {
        field = new CharField(constantPool, info);
    } else if (*descriptor == u"F") {
        field = new FloatField(constantPool, info);
    } else if (*descriptor == u"I") {
        field = new IntegerField(constantPool, info);
    } else if (*descriptor == u"J") {
        field = new LongField(constantPool, info);
    } else if (*descriptor == u"S") {
        field = new ShortField(constantPool, info);
    } else if (*descriptor == u"Z") {
        field = new BooleanField(constantPool, info);
    } else if(*descriptor == u"D") {
        field = new DoubleField(constantPool, info);
    } else {
        std::u16string l = u"L";
        std::u16string a = u"[";
        if (descriptor -> compare(0,l.size(),l) == 0) {
            field = new ReferenceField(constantPool, info);
        } else if (descriptor -> compare(0, a.size(), a) == 0) {
            field = new ArrayField(constantPool, info);
        } else {
            std::cerr << "unknown signature name: " << signatureName << std::endl;
            exit(common::ErrorCode::NullPointerError);
        }
    }
    field->name = name;
    field->descriptor = descriptor;
    field->signature = signatureName;

    return field;
}

rtda::heap::Method::Method(const class_file::ConstantPool *constantPool, const class_file::MethodInfo *methodInfo):codeLength() {
    auto codeAttribute = methodInfo->getCodeAttribute();
    this->name = constantPool->getConstantUtf8Info(methodInfo->getNameIndex())->decodeMUTF8();
    this->descriptor = constantPool->getConstantUtf8Info(methodInfo->getDescriptorIndex())->decodeMUTF8();
    if (codeAttribute != nullptr) {
        this->maxStack = codeAttribute->maxStack;
        this->maxLocals = codeAttribute->maxLocals;
        this->code = codeAttribute->code;
        this->codeLength = codeAttribute->codeLength;
    }
}

void rtda::heap::BaseField::resolveField() {

}

rtda::heap::BaseField::BaseField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    //this->constantValue = constantPool->getConstantInfo(info->)
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantIntegerInfo)) {
                this->constantValue = dynamic_cast<const class_file::ConstantIntegerInfo*>(constantInfo)->bytes;
            } else if (typeid(*constantInfo) == typeid(class_file::ConstantFloatInfo)) {

            }
        }
    }
}

void rtda::heap::ArrayField::resolveField() {

}

rtda::heap::ArrayField::ArrayField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {

}

void rtda::heap::ReferenceField::resolveField() {
    std::u16string resolvedClassName = this->descriptor->substr(1,this->descriptor->length() - 2);
    std::cout << "resolvedClassName: " << CUtil::toUtf8(resolvedClassName) << std::endl;
    //rtda::heap::RunTimeConstantPool::getInstance()->getClass(resolvedClassName);

}

rtda::heap::ReferenceField::ReferenceField(const class_file::ConstantPool* constantPool, const class_file::FieldInfo*info) {

}

void rtda::heap::ByteField::resolveField() {

}

rtda::heap::ByteField::ByteField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantIntegerInfo)) {
                auto intInfo = dynamic_cast<const class_file::ConstantIntegerInfo*>(constantInfo);
                this->constantValue = (int8_t)((uint8_t)intInfo->bytes);
            } else {
                std::cerr << "fill ByteField value fail. expected class_file::ConstantIntegerInfo tag:" << constantInfo->tag << std::endl;
                exit(common::ErrorCode::UnExpectedAttributeInfoError);
            }
        }
    }
}


rtda::heap::CharField::CharField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantIntegerInfo)) {
                auto intInfo = dynamic_cast<const class_file::ConstantIntegerInfo*>(constantInfo);
                this->constantValue = (int16_t)((uint16_t)intInfo->bytes);
            } else {
                std::cerr << "fill CharField value fail. expected class_file::ConstantIntegerInfo tag:" << constantInfo->tag << std::endl;
                exit(common::ErrorCode::UnExpectedAttributeInfoError);
            }
        }
    }
}

void rtda::heap::CharField::resolveField() {

}

rtda::heap::DoubleField::DoubleField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantDoubleInfo)) {
                auto intInfo = dynamic_cast<const class_file::ConstantDoubleInfo*>(constantInfo);
                this->constantValue = (double )intInfo->bytes;
            } else {
                std::cerr << "fill DoubleField value fail. expected class_file::ConstantIntegerInfo tag:" << constantInfo->tag << std::endl;
                exit(common::ErrorCode::UnExpectedAttributeInfoError);
            }
        }
    }
}

void rtda::heap::DoubleField::resolveField() {

}

rtda::heap::FloatField::FloatField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantFloatInfo)) {
                auto intInfo = dynamic_cast<const class_file::ConstantFloatInfo*>(constantInfo);
                this->constantValue = (float )intInfo->bytes;
            } else {
                std::cerr << "fill FloatField value fail. expected class_file::ConstantIntegerInfo tag: " << constantInfo->tag << std::endl;
                exit(common::ErrorCode::UnExpectedAttributeInfoError);
            }
        }
    }
}

void rtda::heap::FloatField::resolveField() {

}

rtda::heap::IntegerField::IntegerField(const class_file::ConstantPool *constantPool,
                                       const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantIntegerInfo)) {
                auto intInfo = dynamic_cast<const class_file::ConstantIntegerInfo*>(constantInfo);
                this->constantValue = (int32_t )intInfo->bytes;
            } else {
                std::cerr << "fill IntegerField value fail. expected class_file::ConstantIntegerInfo tag: " << constantInfo->tag << std::endl;
                exit(common::ErrorCode::UnExpectedAttributeInfoError);
            }
        }
    }
}

void rtda::heap::IntegerField::resolveField() {

}

rtda::heap::LongField::LongField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantLongInfo)) {
                auto intInfo = dynamic_cast<const class_file::ConstantLongInfo*>(constantInfo);
                this->constantValue = (int64_t )((uint64_t)intInfo->bytes);
            } else {
                std::cerr << "fill LongField value fail. expected class_file::ConstantIntegerInfo tag: " << constantInfo->tag << std::endl;
                exit(common::ErrorCode::UnExpectedAttributeInfoError);
            }
        }
    }
}

void rtda::heap::LongField::resolveField() {

}

rtda::heap::BooleanField::BooleanField(const class_file::ConstantPool *constantPool,
                                       const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantIntegerInfo)) {
                auto intInfo = dynamic_cast<const class_file::ConstantIntegerInfo*>(constantInfo);
                this->constantValue = intInfo->bytes != 0u;
            } else {
                std::cerr << "fill BooleanField value fail. expected class_file::ConstantIntegerInfo tag: " << constantInfo->tag << std::endl;
                exit(common::ErrorCode::UnExpectedAttributeInfoError);
            }
        }
    }
}

void rtda::heap::BooleanField::resolveField() {

}

rtda::heap::ShortField::ShortField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto a = info->getAttributes()->getAttributeInfo(i);
        if (typeid(*a) == typeid(class_file::AttrConstantValue)) {
            auto index = dynamic_cast<const class_file::AttrConstantValue*>(a)->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);
            if (typeid(*constantInfo) == typeid(class_file::ConstantIntegerInfo)) {
                auto intInfo = dynamic_cast<const class_file::ConstantIntegerInfo*>(constantInfo);
                this->constantValue = (int16_t)((uint16_t)intInfo->bytes);
            } else {
                std::cerr << "fill BooleanField value fail. expected class_file::ConstantIntegerInfo tag: " << constantInfo->tag << std::endl;
                exit(common::ErrorCode::UnExpectedAttributeInfoError);
            }
        }
    }
}

void rtda::heap::ShortField::resolveField() {

}
