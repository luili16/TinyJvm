//
// Created by 刘立新 on 2020/11/20.
//

#ifndef CH01_CONSTANTPOOLINFO_H
#define CH01_CONSTANTPOOLINFO_H
#include <cstdint>
#include "ClassReader.h"
namespace class_file {
    /**
 * cp_info {
 *     u1 tag;
 *     u1 info[];
 * }
 */
    class ConstantPoolInfo {
        const static uint8_t CONSTANT_Class              = 7;
        const static uint8_t CONSTANT_Fieldref           = 9;
        const static uint8_t CONSTANT_Methodref          = 10;
        const static uint8_t CONSTANT_InterfaceMethodref = 11;
        const static uint8_t CONSTANT_String             = 8;
        const static uint8_t CONSTANT_Integer            = 3;
        const static uint8_t CONSTANT_Float              = 4;
        const static uint8_t CONSTANT_Long               = 5;
        const static uint8_t CONSTANT_Double             = 6;
        const static uint8_t CONSTANT_NameAndType        = 12;
        const static uint8_t CONSTANT_Utf8               = 1;
        const static uint8_t CONSTANT_MethodHandle       = 15;
        const static uint8_t CONSTANT_MethodType         = 16;
        const static uint8_t CONSTANT_InvokeDynamic      = 18;

    public:
        static ConstantPoolInfo* newConstantPoolInfoByTag(uint8_t tag,ClassReader&reader);
        explicit ConstantPoolInfo(uint8_t tag);
        const uint8_t tag;
        ~ConstantPoolInfo() = default;
    };
}



#endif //CH01_CONSTANTPOOLINFO_H
