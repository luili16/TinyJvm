//
// Created by 刘立新 on 2020/12/28.
//

#include "RunTimeConstantPool.h"
#include "../classfile/ClassFile.h"
#include "../classfile/ConstantClassInfo.h"
#include "../classfile/Fields.h"
#include <locale>
#include <codecvt>

std::string toUtf8(std::u16string& mUtf8) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
    std::string  a = convert.to_bytes(mUtf8);
    return a;
}

rtda::heap::Class *rtda::heap::RunTimeConstantPool::getClass(std::u16string &className) {

    auto classes = this->sharedPool->find(className);
    if (classes == this->sharedPool->end()) {
        std::string u8ClassName = toUtf8(className);

        auto reader = class_file::ClassReader(*this->classPath->readClass(u8ClassName));
        const class_file::ClassFile* classFile = class_file::ClassFile::read(reader);
        auto aClass = new Class();
        aClass->accessFlags = classFile->getAccessFlags();
        aClass->constantPool = classFile->getConstantPool();
        aClass->name = classFile->getConstantPool()->getConstantUtf8Info(dynamic_cast<const class_file::ConstantClassInfo*>(classFile->getConstantPool()->getConstantInfo(classFile->getThisClass()))->nameIndex)->decodeMUTF8();

        if (classFile->getSuperClass() != 0) {
            auto nameIndex = dynamic_cast<const class_file::ConstantClassInfo*>(classFile->getConstantPool()->getConstantInfo(classFile->getSuperClass()))->nameIndex;
            aClass->superClassName = classFile->getConstantPool()->getConstantUtf8Info(nameIndex)->decodeMUTF8();
            // ugly code! how to fix?
            aClass->superClass = this->getClass(*(aClass->superClassName));
        } else {
            // this class is java.lang.Object
            aClass->superClassName = std::make_shared<std::u16string>();
        }

        aClass->fieldsCount = classFile->getFieldsCount();
        aClass->fields = new Field*[aClass->fieldsCount];
        const class_file::Fields* fields = classFile->getFields();
        for (int i = 0; i < aClass->fieldsCount; i++) {
            auto fieldInfo = fields->getFieldInfo(i);
            //aClass->fields[i] = new Field(classFile->getConstantPool(),fieldInfo);
            //aClass->fields[i]->thisClass = aClass;
            //aClass->fields[i]->resolveField();
        }

        this->sharedPool->insert({className, aClass});
        // throw class not found exception?
        return aClass;
    }

    return classes->second;
}



rtda::heap::RunTimeConstantPool::RunTimeConstantPool(std::shared_ptr<class_path::ClassPath>& classPath) {
    this->classPath = classPath;
}

rtda::heap::RunTimeConstantPool::~RunTimeConstantPool() {
    delete this->sharedPool;
    this->sharedPool = nullptr;
}

void rtda::heap::RunTimeConstantPool::globalInit(std::shared_ptr<class_path::ClassPath>& classPath) {
    instance = new RunTimeConstantPool(classPath);
}

void rtda::heap::RunTimeConstantPool::globalDestroy() {
    delete instance;
    instance = nullptr;
}

rtda::heap::RunTimeConstantPool *rtda::heap::RunTimeConstantPool::getInstance() {
    return RunTimeConstantPool::instance;
}

rtda::heap::RunTimeConstantPool* rtda::heap::RunTimeConstantPool::instance = nullptr;

