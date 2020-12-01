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
#include "../util/CUtil.h"
#include <iostream>
#include <array>


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
            auto bytes = (int32_t)reader.readUint32();
            auto info = new ConstantIntegerInfo(tag, bytes);
            return info;
        }
        case CONSTANT_Float: {
            const size_t len = 4;
            std::array<uint8_t,len> buf = {};
            if (CUtil::isBigEndian()) {
                for (uint8_t & i : buf) {
                    i = reader.readUint8();
                }
            } else {

                for (auto i = buf.rbegin();i != buf.rend();i++) {
                    *i = reader.readUint8();
                }
            }
            float x;
            if (len != sizeof(float)) {
                std::cerr << "float size is not 4 byte wide\n";
                exit(-1);
            }
            auto px = reinterpret_cast<uint8_t*>(&x);
            std::copy(buf.cbegin(), buf.cend(),px);
            auto info = new ConstantFloatInfo(tag, x);
            return info;
        }
        case CONSTANT_Long: {
            auto bytes = (int64_t)reader.readUint64();
            auto info = new ConstantLongInfo(tag,bytes);
            return info;
        }
        case CONSTANT_Double: {
            const size_t len = 8;
            std::array<uint8_t,len> buf = {};
            if (CUtil::isBigEndian()) {
                for (uint8_t & i : buf) {
                    i= reader.readUint8();
                }
            } else {
                for (auto i = buf.rbegin();i != buf.rend(); i++) {
                    *i = reader.readUint8();
                }
            }

            double x;
            if (len != sizeof(double )) {
                std::cerr << "double size is not 8 byte wide\n";
                exit(-1);
            }
            auto px = reinterpret_cast<uint8_t *>(&x);
            std::copy(buf.cbegin(),buf.cend(),px);
            auto info = new ConstantDoubleInfo(tag,x);
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

class_file::ConstantPoolInfo::~ConstantPoolInfo() = default;

const uint8_t class_file::ConstantPoolInfo::CONSTANT_Class;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_Fieldref;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_Methodref;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_InterfaceMethodref;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_String;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_Integer;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_Float;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_Long;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_Double;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_NameAndType;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_Utf8;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_MethodHandle;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_MethodType;
const uint8_t class_file::ConstantPoolInfo::CONSTANT_InvokeDynamic;