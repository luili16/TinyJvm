//
// Created by 刘立新 on 2020/12/24.
//

#include "Class.h"
#include "../classfile/ConstantValueAttribute.h"
#include "../classfile/ConstantLongInfo.h"
#include "../classfile/ConstantIntegerInfo.h"
#include "../classfile/ConstantDoubleInfo.h"
#include "../classfile/ConstantFloatInfo.h"
#include "../classfile/ConstantStringInfo.h"
#include "../classfile/AttrSignature.h"
#include "../common/ErrorCode.h"
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

    auto accessFlags = info->getAccessFlags();
    auto name = constantPool->getConstantUtf8Info(info->getNameIndex())->decodeMUTF8();
    auto descriptor = constantPool->getConstantUtf8Info(info->getDescriptorIndex())->decodeMUTF8();
    auto signatureName = findSignature(constantPool,info);
    Field* field = nullptr;
    // BaseType
    if (*descriptor == u"B" ||
        *descriptor == u"C" ||
        *descriptor == u"D" ||
        *descriptor == u"F" ||
        *descriptor == u"I" ||
        *descriptor == u"J" ||
        *descriptor == u"S" ||
        *descriptor == u"Z") {
        field = new BaseField(constantPool,info);
        field->accessFlags = accessFlags;
        // ObjectType
    } else {
        std::u16string l = u"L";
        std::u16string a = u"[";
        if (descriptor->compare(0, l.size(), l) == 0) {
            field = new ReferenceField(constantPool,info);
            field->accessFlags = accessFlags;
            // ArrayType
        } else if (descriptor->compare(0, a.size(), a) == 0) {
            field = new ArrayField(constantPool,info);
            field->accessFlags = accessFlags;
        } else {
            std::cerr << "unknown signature name: " << signatureName << std::endl;
            exit(common::ErrorCode::NullPointerError);
        }
    }

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

}

void rtda::heap::ArrayField::resolveField() {

}

rtda::heap::ArrayField::ArrayField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {

}

void rtda::heap::ReferenceField::resolveField() {

}

rtda::heap::ReferenceField::ReferenceField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info) {

}
