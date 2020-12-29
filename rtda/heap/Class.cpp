//
// Created by 刘立新 on 2020/12/24.
//

#include "Class.h"
#include "../classfile/ConstantValueAttribute.h"

rtda::heap::Field::Field(const class_file::ConstantPool* constantPool,const class_file::FieldInfo *info) {
    this->accessFlags = info->getAccessFlags();
    this->name = constantPool->getConstantUtf8Info(info->getNameIndex())->decodeMUTF8();
    this->descriptor = constantPool->getConstantUtf8Info(info->getDescriptorIndex())->decodeMUTF8();
    for (int i = 0; i < info->getAttributesCount(); i++) {
        auto attriInfo = info->getAttributes()->getAttributeInfo(i);
        auto attributeName = attriInfo->getAttributeName();
        if (class_file::AttributeInfo::isConstantValue(*attributeName)) {
            this->constantValue = dynamic_cast<const class_file::ConstantUtf8Info*>(attriInfo)->decodeMUTF8();
        }
    }
}

rtda::heap::Method::Method(const class_file::ConstantPool *constantPool, const class_file::MethodInfo *methodInfo) {

}
