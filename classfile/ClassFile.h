//
// Created by 刘立新 on 2020/11/20.
//

#ifndef CH01_CLASSFILE_H
#define CH01_CLASSFILE_H
#include <cstdint>
#include "ConstantPool.h"
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
    public:
        const uint32_t magic;
        const uint16_t minorVersion;
        const uint16_t majorVersion;
        const uint16_t constantPoolCount;
        const ConstantPool* constantPool;
        const uint16_t accessFlags;
        const uint16_t thisClass;
        const uint16_t superClass;
        const uint16_t interfacesCount;
    };

}




#endif //CH01_CLASSFILE_H
