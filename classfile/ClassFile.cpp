//
// Created by 刘立新 on 2020/11/20.
//

#include "ClassFile.h"

const class_file::ClassFile *class_file::ClassFile::read(class_file::ClassReader &reader) {

    uint32_t magic = reader.readUint32();
    uint16_t minorVersion = reader.readUint16();
    uint16_t majorVersion = reader.readUint16();
    uint16_t constantPoolCount = reader.readUint16();
    auto* constantPool = new ConstantPool(constantPoolCount,reader);
    

    return nullptr;
}

class_file::ClassFile::ClassFile(uint32_t magic,
                                 uint16_t minorVersion,
                                 uint16_t majorVersion,
                                 uint16_t constantPoolCount,
                                 const class_file::ConstantPool *constantPool,
                                 uint16_t accessFlags,
                                 uint16_t thisClass,
                                 uint16_t superClass,
                                 uint16_t interfacesCount,
                                 const uint16_t *interfaces,
                                 uint16_t fieldsCount,
                                 const class_file::FieldInfo *fields,
                                 uint16_t methodsCount,
                                 const class_file::MethodInfo *methods,
                                 uint16_t attributesCount,
                                 const class_file::AttributeInfo *attributes):
                                 magic(magic),
                                 minorVersion(minorVersion),
                                 majorVersion(majorVersion),
                                 constantPoolCount(constantPoolCount),
                                 constantPool(constantPool),
                                 accessFlags(accessFlags),
                                 thisClass(thisClass),
                                 superClass(superClass),
                                 interfacesCount(interfacesCount),
                                 interfaces(interfaces),
                                 fieldsCount(fieldsCount),
                                 fields(fields),
                                 methodsCount(methodsCount),
                                 methods(methods),
                                 attributesCount(attributesCount),
                                 attributes(attributes)
                                 {

}

uint32_t class_file::ClassFile::getMagic() const {
    return this->magic;
}

uint16_t class_file::ClassFile::getMinorVersion() const {
    return this->minorVersion;
}

uint16_t class_file::ClassFile::getMajorVersion() const {
    return this->majorVersion;
}

uint16_t class_file::ClassFile::getConstantPoolCount() const {
    return this->constantPoolCount;
}

const class_file::ConstantPool *class_file::ClassFile::getConstantPool() const {
    return this->constantPool;
}

uint16_t class_file::ClassFile::getAccessFlags() const {
    return this->accessFlags;
}

uint16_t class_file::ClassFile::getThisClass() const {
    return this->thisClass;
}

uint16_t class_file::ClassFile::getSuperClass() const {
    return this->superClass;
}

uint16_t class_file::ClassFile::getInterfacesCount() const {
    return this->interfacesCount;
}

const uint16_t *class_file::ClassFile::getInterfaces() const {
    return this->interfaces;
}

uint16_t class_file::ClassFile::getFieldsCount() const {
    return this->fieldsCount;
}

const class_file::FieldInfo *class_file::ClassFile::getFields() const {
    return this->fields;
}

uint16_t class_file::ClassFile::getMethodsCount() const {
    return this->methodsCount;
}

const class_file::MethodInfo *class_file::ClassFile::getMethodInfo() const {
    return this->methods;
}

uint16_t class_file::ClassFile::getAttributesCount() const {
    return this->attributesCount;
}

const class_file::AttributeInfo *class_file::ClassFile::getAttributes() const {
    return this->attributes;
}

class_file::ClassFile::~ClassFile() {
    delete constantPool;
    delete interfaces;
    delete fields;
    delete methods;
    delete attributes;
}
