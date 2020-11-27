//
// Created by 刘立新 on 2020/11/20.
//

#include "ConstantPoolInfo.h"
#include "ConstantClassInfo.h"
#include "ConstantFieldRefInfo.h"
#include "ConstantMethodRefInfo.h"
#include "ConstantInterfaceMethodRefInfo.h"
#include "ConstantStringInfo.h"
#include "ConstantIntegerInfo.h"
#include "ConstantFloatInfo.h"
#include "ConstantLongInfo.h"
#include "ConstantDoubleInfo.h"
#include "ConstantNameAndTypeInfo.h"
#include "ConstantUtf8Info.h"
#include "ConstantMethodHandleInfo.h"
#include "ConstantMethodTypeInfo.h"
#include "ConstantInvokeDynamicInfo.h"
#include <iostream>

class_file::ConstantPoolInfo* class_file::ConstantPoolInfo::newConstantPoolInfoByTag(uint8_t tag, ClassReader &reader) {

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
            uint32_t bytes = reader.readUint32();
            auto info = new ConstantIntegerInfo(tag, bytes);
            return info;
        }
        case CONSTANT_Float: {
            uint32_t bytes = reader.readUint32();
            auto info = new ConstantFloatInfo(tag,bytes);
            return info;
        }
        case CONSTANT_Long: {
            uint32_t highBytes = reader.readUint32();
            uint32_t lowBytes = reader.readUint32();
            auto info = new ConstantLongInfo(tag,highBytes,lowBytes);
            return info;
        }
        case CONSTANT_Double: {
            uint32_t highBytes = reader.readUint32();
            uint32_t lowBytes = reader.readUint32();
            auto info = new ConstantDoubleInfo(tag,highBytes,lowBytes);
            return info;
        }
        case CONSTANT_NameAndType: {
            uint16_t nameIndex = reader.readUint16();
            uint16_t descriptorIndex = reader.readUint16();
            auto info = new ConstantNameAndTypeInfo(tag,nameIndex,descriptorIndex);
            return info;
        }
        case CONSTANT_Utf8: {
            uint16_t length = reader.readUint16();
            auto bytes = new uint8_t [length];
            auto hasRead = reader.readBytes(bytes,length);
            if (hasRead != length) {
                std::cerr << "except full read! length = " << length << " hasRead = " << hasRead << "!\n";
                exit(-1);
            }
            auto info = new ConstantUtf8Info(tag,length,bytes);
            return info;
        }
        case CONSTANT_MethodHandle: {
            uint8_t referenceKind = reader.readUint8();
            uint16_t referenceIndex = reader.readUint16();
            auto info = new ConstantMethodHandleInfo(tag,referenceKind,referenceIndex);
            return info;
        }
        case CONSTANT_MethodType: {
            uint16_t descriptorIndex = reader.readUint16();
            auto info = new ConstantMethodTypeInfo(tag,descriptorIndex);
            return info;
        }
        case CONSTANT_InvokeDynamic: {
            uint16_t bootstrapMethodAttrIndex = reader.readUint16();
            uint16_t nameAndTypeIndex = reader.readUint16();
            auto info = new ConstantInvokeDynamicInfo(tag,bootstrapMethodAttrIndex,nameAndTypeIndex);
            return info;
        }
        default: {
            std::cerr << "unknown tag: " << tag << "\n";
            exit(-1);
        }
    }
}

class_file::ConstantPoolInfo::ConstantPoolInfo(uint8_t tag):tag(tag) {
}
