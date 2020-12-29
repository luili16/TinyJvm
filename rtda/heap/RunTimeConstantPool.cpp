//
// Created by 刘立新 on 2020/12/28.
//

#include "RunTimeConstantPool.h"

rtda::heap::Class *rtda::heap::RunTimeConstantPool::getClass(std::u16string &className) {

    auto classes = this->sharedPool->find(className);
    if (classes == this->sharedPool->end()) {

        this->classPath->readClass(className);





        // throw class not found exception?
        return nullptr;
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

