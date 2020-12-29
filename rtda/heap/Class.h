//
// Created by 刘立新 on 2020/12/24.
//

#ifndef CH01_CLASS_H
#define CH01_CLASS_H

#include <cstdint>
#include <string>
#include "../../classfile/MethodInfo.h"
#include "../../classfile/CodeAttribute.h"
#include "../../classfile/FieldInfo.h"
#include "../../classfile/ConstantPool.h"
#include "../../classfile/Annotation.h"

#include "../Slot.h"

namespace rtda::heap {
    class Field;
    class Method;
    class Class {
    public:
        uint16_t accessFlags;
        std::shared_ptr<std::u16string> name;
        std::shared_ptr<std::u16string> superClassName;
        Class* superClass;
        uint16_t interfaceNamesLen = 0;
        std::shared_ptr<std::u16string>* interfaceNames;
        Class* interfaces;
        class_file::ConstantPool* constantPool;
        uint16_t fieldsLen;
        Field** fields;
        uint16_t methodsLen;
        Method** methods;
        std::shared_ptr<std::u16string> sourceFile;
        // not implement yet...
        // InnerClasses
        // EnclosingMethod
        // SourceDebugExtension
        // BoostrapMethods
        // Synthetic
        // Deprecated
        // Signature
        // RuntimeVisibleAnnotations
        // RuntimeVisibleTypeAnnotations



        uint16_t instanceSlotCount;
        uint16_t staticsSlotCount;
    };

    class Field {
    public:
        Class * thisClass = nullptr;
        uint16_t accessFlags = 0u;
        std::shared_ptr<std::u16string> name = nullptr;
        std::shared_ptr<std::u16string> descriptor = nullptr;
        // attributes see jvm8 Table 4.7-C at page 100
        std::shared_ptr<std::u16string> constantValue = nullptr;
        std::shared_ptr<std::u16string> synthetic = nullptr;

        explicit Field(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        ~Field() = default;
    };

    class Method {
    public:
        explicit Method(const class_file::ConstantPool* constantPool,const class_file::MethodInfo* methodInfo);
        Class* thisClass;
        uint16_t maxStack;
        uint16_t maxLocals;
        uint8_t *code;
        uint32_t codeLength;
        uint16_t numberOfExceptions;
        //std::u16string ** namesOfException;
        std::shared_ptr<std::u16string>* namesOfException;
    };
}




#endif //CH01_CLASS_H
