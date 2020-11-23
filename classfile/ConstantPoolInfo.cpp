//
// Created by 刘立新 on 2020/11/20.
//

#include "ConstantPoolInfo.h"
#include "ConstantClassInfo.h"
#include "ConstantFieldRefInfo.h"
#include "ConstantMethodRefInfo.h"
#include "ConstantInterfaceMethodRefInfo.h"
#include "ConstantStringInfo.h"
ConstantPoolInfo* ConstantPoolInfo::newConstantPoolInfoByTag(uint8_t tag, ClassReader &reader) {

    switch (tag) {
        case CONSTANT_Class: {
            uint16_t nameIndex = reader.readUint16();
            auto info = new ConstantClassInfo(tag, nameIndex);
            return info;
        }
        case CONSTANT_Fieldref: {
            uint16_t classIndex = reader.readUint16();
            uint16_t nameAndTypeIndex = reader.readUint16();
            auto info = new ConstantFieldRefInfo(tag,classIndex,nameAndTypeIndex);
            return info;
        }
        case CONSTANT_Methodref: {
            uint16_t classIndex = reader.readUint16();
            uint16_t nameAndTypeIndex = reader.readUint16();
            auto info = new ConstantMethodRefInfo(tag,classIndex,nameAndTypeIndex);
            return info;
        }
        case CONSTANT_InterfaceMethodref: {
            uint16_t classIndex = reader.readUint16();
            uint16_t nameAndTypeIndex = reader.readUint16();
            auto info = new ConstantInterfaceMethodRefInfo(tag,classIndex,nameAndTypeIndex);
            return info;
        }
        case CONSTANT_String: {
            uint16_t stringIndex = reader.readUint16();
            auto info = new ConstantStringInfo(tag,stringIndex);
            return info;
        }
        case CONSTANT_Integer: {

            break;
        }
        case CONSTANT_Float: {
            break;
        }
        case CONSTANT_Long: {
            break;
        }
        case CONSTANT_Double: {
            break;
        }
        case CONSTANT_NameAndType: {
            break;
        }
        case CONSTANT_Utf8: {
            break;
        }
        case CONSTANT_MethodHandle: {
            break;
        }
        case CONSTANT_MethodType: {
            break;
        }
        case CONSTANT_InvokeDynamic: {
            break;
        }
        default: {
        }
    }

    return nullptr;
}

ConstantPoolInfo::ConstantPoolInfo(uint8_t tag):tag(tag) {
}
