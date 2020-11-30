//
// Created by 刘立新 on 2020/11/20.
//

#ifndef CH01_CLASSFILE_H
#define CH01_CLASSFILE_H
#include <cstdint>
#include "ConstantPool.h"
#include "Fields.h"
#include "Methods.h"
#include "ClassReader.h"


/*
ClassFile {
    u4             magic;
    u2             minor_version;
    u2             major_version;
    u2             constant_pool_count;
    cp_info        constant_pool[constant_pool_count-1];
    u2             access_flags;
    u2             this_class;
    u2             super_class;
    u2             interfaces_count;
    u2             interfaces[interfaces_count];
    u2             fields_count;
    field_info     fields[fields_count];
    u2             methods_count;
    method_info    methods[methods_count];
    u2             attributes_count;
    attribute_info attributes[attributes_count];
}
*/

namespace class_file {

    class ClassFile {
    private:
        const uint32_t magic;
        const uint16_t minorVersion;
        const uint16_t majorVersion;
        const uint16_t constantPoolCount;
        // size is constantPoolCount - 1
        const ConstantPool* constantPool;
        const uint16_t accessFlags;
        const uint16_t thisClass;
        const uint16_t superClass;
        const uint16_t interfacesCount;
        const uint16_t* interfaces;
        const uint16_t fieldsCount;
        const Fields* fields;
        const uint16_t methodsCount;
        const Methods* methods;
        const uint16_t attributesCount;
        const Attributes* attributes;
        explicit ClassFile(
                uint32_t magic,
                uint16_t minorVersion,
                uint16_t majorVersion,
                uint16_t constantPoolCount,
                const ConstantPool* constantPool,
                uint16_t accessFlags,
                uint16_t thisClass,
                uint16_t superClass,
                uint16_t interfacesCount,
                const uint16_t* interfaces,
                uint16_t fieldsCount,
                const Fields* fields,
                uint16_t methodsCount,
                const Methods* methods,
                uint16_t attributesCount,
                const Attributes* attributes
                );
        ~ClassFile();
    public:
        static const ClassFile* read(ClassReader &reader);
        [[nodiscard]] uint32_t getMagic() const;
        [[nodiscard]] uint16_t getMinorVersion() const;
        [[nodiscard]] uint16_t getMajorVersion() const;
        [[nodiscard]] uint16_t getConstantPoolCount() const;
        [[nodiscard]] const ConstantPool* getConstantPool() const;
        [[nodiscard]] uint16_t getAccessFlags() const;
        [[nodiscard]] uint16_t getThisClass() const;
        [[nodiscard]] uint16_t getSuperClass() const;
        [[nodiscard]] uint16_t getInterfacesCount() const;
        [[nodiscard]] const uint16_t* getInterfaces() const;
        [[nodiscard]] uint16_t getFieldsCount() const;
        [[nodiscard]] const Fields* getFields() const;
        [[nodiscard]] uint16_t getMethodsCount() const;
        [[nodiscard]] const Methods* getMethods() const;
        [[nodiscard]] uint16_t getAttributesCount() const;
        [[nodiscard]] const Attributes* getAttributes() const;
    };

}




#endif //CH01_CLASSFILE_H
