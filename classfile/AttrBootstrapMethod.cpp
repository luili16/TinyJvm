//
// Created by 刘立新 on 2020/12/14.
//

#include "AttrBootstrapMethod.h"

class_file::BootStrapMethod::BootStrapMethod(uint16_t bootstrapMethodRef,
                                   uint16_t numBootstrapArguments,
                                   const uint16_t *bootstrapArguments):
                                   bootstrapMethodRef(bootstrapMethodRef),
                                   numBootstrapArguments(numBootstrapArguments),
                                   bootstrapArguments(bootstrapArguments)
                                   {
}

class_file::AttrBootstrapMethod::AttrBootstrapMethod(uint16_t attributeNameIndex,
                                                     uint32_t attributeLength,
                                                     const ConstantPool* constantPool,
                                                     uint16_t numBootstrapMethods,
                                                     const class_file::BootStrapMethod **bootstrapMethods):
                                                     AttributeInfo(attributeNameIndex,attributeLength,constantPool),
        numBootstrapMethods(numBootstrapMethods),
        bootstrapMethods(bootstrapMethods)
        {

}

const class_file::BootStrapMethod *class_file::AttrBootstrapMethod::getBootstrapMethod(uint16_t index) const {
    return this->bootstrapMethods[index];
}

class_file::AttrBootstrapMethod::~AttrBootstrapMethod() {
    delete [] bootstrapMethods;
}
