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

rtda::heap::Field::Field(const class_file::ConstantPool* constantPool,const class_file::FieldInfo *info) {
    this->accessFlags = info->getAccessFlags();
    this->name = constantPool->getConstantUtf8Info(info->getNameIndex())->decodeMUTF8();
    this->descriptor = constantPool->getConstantUtf8Info(info->getDescriptorIndex())->decodeMUTF8();
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto attriInfo = info->getAttributes()->getAttributeInfo(i);
        auto attributeName = attriInfo->getAttributeName();
        if (class_file::AttributeInfo::isConstantValue(*attributeName)) {
            auto utf8Info = dynamic_cast<const class_file::ConstantValueAttribute*>(attriInfo);
            auto index = utf8Info->getConstantValueIndex();
            auto constantInfo = constantPool->getConstantInfo(index);

            if (typeid(*constantInfo) == typeid(class_file::ConstantLongInfo)) {

            } else if (typeid(*constantInfo) == typeid(class_file::ConstantIntegerInfo)) {
                int a= 0;
            } else if (typeid(*constantInfo) == typeid(class_file::ConstantDoubleInfo)) {
                int a= 0;
            } else if (typeid(*constantInfo) == typeid(class_file::ConstantFloatInfo)) {
                int a= 0;
            } else

                if (typeid(*constantInfo) == typeid(class_file::ConstantStringInfo)) {
                    auto constantStringInfo = dynamic_cast<const class_file::ConstantStringInfo*>(constantInfo);
                    auto constantString = constantPool->getConstantUtf8Info(constantStringInfo->stringIndex)->decodeMUTF8();
                    auto a = constantStringInfo;
                }
        }
    }
}

void rtda::heap::Field::resolveField() {

}

std::u16string* findSignature(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto attriInfo = info->getAttributes()->getAttributeInfo(i);
        auto attributeName = attriInfo->getAttributeName();
        if (class_file::AttributeInfo::isSignature(*attributeName)) {
            auto signatureInfo = dynamic_cast<const class_file::AttrSignature*>(attriInfo);
            auto signatureName= constantPool->getConstantUtf8Info(signatureInfo->signatureIndex)->decodeMUTF8();
        }
    }
}

rtda::heap::Field *
rtda::heap::Field::newField(const class_file::ConstantPool *constantPool, const class_file::FieldInfo *info) {

    auto accessFlags = info->getAccessFlags();
    auto name = constantPool->getConstantUtf8Info(info->getNameIndex())->decodeMUTF8();
    auto descriptor = constantPool->getConstantUtf8Info(info->getDescriptorIndex())->decodeMUTF8();
    auto signatureName = findSignature(constantPool,info);
    Field* field = nullptr;
    // BaseType
    if (*signatureName == u"B" ||
        *signatureName == u"C" ||
        *signatureName == u"D" ||
        *signatureName == u"F" ||
        *signatureName == u"I" ||
        *signatureName == u"J" ||
        *signatureName == u"S" ||
        *signatureName == u"Z") {
        //field = new BaseField();
        // ObjectType
    } else if (*signatureName == u"L") {

        // ArrayType
    } else if (*signatureName == u"[") {

    }


    return nullptr;
}

rtda::heap::Method::Method(const class_file::ConstantPool *constantPool, const class_file::MethodInfo *methodInfo) {

}

void rtda::heap::BaseField::resolveField() {

}

void rtda::heap::ArrayField::resolveField() {

}

void rtda::heap::ReferenceField::resolveField() {

}
