//
// Created by 刘立新 on 2020/11/30.
//

#include "Methods.h"
#include "Attributes.h"
const class_file::Methods *class_file::Methods::newMethods(class_file::ClassReader &reader) {

    uint16_t methodsCount = reader.readUint16();
    MethodInfo** methods;
    if (methodsCount == 0) {
        methods = nullptr;
    } else {
        methods = new MethodInfo*[methodsCount];
        for (uint16_t i = 0; i < methodsCount; i++) {
            uint16_t accessFlags = reader.readUint16();
            uint16_t nameIndex = reader.readUint16();
            uint16_t descriptorIndex = reader.readUint16();
            //uint16_t attributesCount = reader.readUint16();
            auto attributeInfo = Attributes::newAttributes(reader);
            methods[i] = new MethodInfo(accessFlags,nameIndex,descriptorIndex, attributeInfo->getAttributesCount(), attributeInfo);
        }
    }


    return new Methods(methodsCount,methods);
}

class_file::Methods::Methods(uint16_t methodsCount,
                             class_file::MethodInfo **methods):
                             methodsCount(methodsCount),
                             methods(methods)
                             {

}

uint16_t class_file::Methods::getMethodsCount() const {
    return this->methodsCount;
}

const class_file::MethodInfo *class_file::Methods::getMethodInfo(uint16_t index) const {
    return this->methods[index];
}
