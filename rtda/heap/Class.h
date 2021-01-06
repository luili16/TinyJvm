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
        const class_file::ConstantPool* constantPool;
        uint16_t fieldsCount;
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
        static Field* newField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        Class * thisClass = nullptr;
        uint16_t accessFlags = 0u;
        std::shared_ptr<std::u16string> name = std::make_shared<std::u16string>();
        std::shared_ptr<std::u16string> descriptor = std::make_shared<std::u16string>();
        std::shared_ptr<std::u16string> signature = std::make_shared<std::u16string>();

        ~Field() = default;
        virtual void resolveField() = 0;
    };

    class BaseField: public Field {

    public:
        int32_t constantValue;
        explicit BaseField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);

        void resolveField() override;
    };

    class ByteField: public Field {
    public:
        int8_t constantValue;
        explicit ByteField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class CharField: public Field {
    public:
        int16_t constantValue;
        explicit CharField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class DoubleField: public Field {
    public:
        double constantValue;
        explicit DoubleField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class FloatField: public Field {
    public:
        float constantValue;
        explicit FloatField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class IntegerField: public Field {
    public:
        int32_t constantValue;
        explicit IntegerField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class LongField: public Field {
    public:
        int64_t constantValue;
        explicit LongField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class ReferenceField: public Field {
    public:
        std::shared_ptr<std::u16string> className;
        std::shared_ptr<std::u16string> nameAntType;
        std::shared_ptr<std::u16string> constantValue;
        explicit ReferenceField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class ShortField: public Field {
    public:
        int16_t constantValue;
        explicit ShortField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class BooleanField: public Field {
    public:
        bool constantValue;
        explicit BooleanField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class ArrayField: public Field {
    public:
        explicit ArrayField(const class_file::ConstantPool* constantPool,const class_file::FieldInfo*info);
        void resolveField() override;
    };

    class Method {
    public:
        explicit Method(const class_file::ConstantPool* constantPool,const class_file::MethodInfo* methodInfo);
        Class* thisClass;
        std::shared_ptr<std::u16string> name = std::shared_ptr<std::u16string>();
        std::shared_ptr<std::u16string> descriptor = std::shared_ptr<std::u16string>();
        uint16_t maxStack;
        uint16_t maxLocals;
        const uint8_t *code;
        uint32_t codeLength;
        uint16_t numberOfExceptions = 0;
        //std::u16string ** namesOfException;
        std::shared_ptr<std::u16string>* namesOfException = nullptr;
    };
}




#endif //CH01_CLASS_H
