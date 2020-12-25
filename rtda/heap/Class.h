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

namespace rtda::heap {

    class Class {

    };

    class ClassMember {
    public:
        Class* _class;
    };

    class Field {
    public:
        ClassMember* classMember = nullptr;
        uint16_t accessFlags = 0u;
        std::shared_ptr<std::u16string> name = nullptr;
        std::shared_ptr<std::u16string> descriptor = nullptr;
        // attributes see jvm8 Table 4.7-C at page 100
        std::shared_ptr<std::u16string> constantValue = nullptr;
        std::shared_ptr<std::u16string> synthetic = nullptr;

        explicit Field(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        ~Field();
    };

    class Method {
    public:

    private:
        ClassMember*classMember;
        uint16_t maxStack;
        uint16_t maxLocals;
        uint8_t *code;
        uint32_t codeLength;


    };
}




#endif //CH01_CLASS_H
