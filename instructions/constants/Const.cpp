//
// Created by 刘立新 on 2020/12/22.
//

#include "Const.h"
#include "../classfile/ConstantIntegerInfo.h"
#include "../classfile/ConstantLongInfo.h"
#include "../classfile/ConstantFloatInfo.h"
#include "../classfile/ConstantDoubleInfo.h"
#include "../classfile/ConstantFieldRefInfo.h"
#include "../classfile/ConstantStringInfo.h"
#include "../common/ErrorCode.h"
#include "../util/CUtil.h"
#include <iostream>


void instructions::constants::IConstM1::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt(-1);
}

void instructions::constants::IConst0::fetchOperands(instructions::base::BytecodeReader &reader) {
}

void instructions::constants::IConst0::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt(0);
}

void instructions::constants::IConst1::fetchOperands(instructions::base::BytecodeReader &reader) {
}

void instructions::constants::IConst1::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt(1);
}

void instructions::constants::IConst2::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::IConst2::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt(2);
}

void instructions::constants::IConst3::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::IConst3::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt(3);
}

void instructions::constants::IConst4::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::IConst4::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt(4);
}

void instructions::constants::IConst5::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::IConst5::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt(5);
}

void instructions::constants::AConstNull::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::AConstNull::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushRef(nullptr);
}

void instructions::constants::Nop::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::Nop::execute(rtda::Frame &frame) {

}

void instructions::constants::LConst0::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::LConst0::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushLong(0L);
}

void instructions::constants::LConst1::fetchOperands(instructions::base::BytecodeReader &reader) {
}

void instructions::constants::LConst1::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushLong(1L);
}

void instructions::constants::FConst0::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::FConst0::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushFloat(0.0f);
}

void instructions::constants::FConst1::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::FConst1::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushFloat(1.0f);
}

void instructions::constants::FConst2::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::FConst2::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushFloat(2.0f);
}

void instructions::constants::DConst0::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::DConst0::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushDouble(0.0);
}

void instructions::constants::DConst1::fetchOperands(instructions::base::BytecodeReader &reader) {

}

void instructions::constants::DConst1::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushDouble(1.0);
}

void instructions::constants::BiPush::fetchOperands(instructions::base::BytecodeReader &reader) {
    this->byte = reader.readUInt8();
}

void instructions::constants::BiPush::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt((int32_t)this->byte);
}

void instructions::constants::SiPush::execute(rtda::Frame &frame) {
    frame.getOperandStack()->pushInt((int32_t)this->index);
}

void instructions::constants::Ldc::execute(rtda::Frame &frame) {
    auto info = frame.method->thisClass->constantPool->getConstantInfo(this->index);
    if (typeid(*info) == typeid(class_file::ConstantIntegerInfo)) {
        auto data = dynamic_cast<const class_file::ConstantIntegerInfo*>(info)->bytes;
        frame.getOperandStack()->pushInt((int32_t)data);
    } else if (typeid(*info) == typeid(class_file::ConstantFloatInfo)) {
        auto data = dynamic_cast<const class_file::ConstantFloatInfo*>(info)->bytes;
        frame.getOperandStack()->pushFloat(data);
    } else if (typeid(*info) == typeid(class_file::ConstantDoubleInfo)) {
        auto data = dynamic_cast<const class_file::ConstantDoubleInfo*>(info)->bytes;
        frame.getOperandStack()->pushDouble(data);
    } else if (typeid(*info) == typeid(class_file::ConstantLongInfo)) {
        auto data = dynamic_cast<const class_file::ConstantLongInfo*>(info)->bytes;
        frame.getOperandStack()->pushLong((int64_t)data);
    } else {
        std::cerr << "ConstantRefInfo has not been implemented yet.";
        exit(common::ErrorCode::NotImplementedError);
    }
}

void instructions::constants::IConstM1::fetchOperands(instructions::base::BytecodeReader &reader) {

}
