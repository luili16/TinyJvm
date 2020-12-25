//
// Created by 刘立新 on 2020/12/22.
//

#include "gtest/gtest.h"
#include "../instructions/InstructionFactory.h"
#include "../instructions/constants/Const.h"
#include "../Interpreter.h"
#include "../classfile/ClassFile.h"
#include "UtilTest.h"

TEST(Instruction,opcodeConstantTest) {
    uint8_t opcodes[] = {
        0x12,
        0x15,
        0x16
    };
    auto byteCodeReader = instructions::base::BytecodeReader();
    byteCodeReader.restore((uint64_t)opcodes);
    auto factory = new instructions::InstructionFactory();
    auto instruction = factory->newInstruction(byteCodeReader.readUInt8());
    auto isLdc = typeid(*instruction) == typeid(instructions::constants::Ldc);
    ASSERT_EQ(true,isLdc);
    auto ldc = dynamic_cast<instructions::constants::Ldc*>(instruction);
    ASSERT_NE(nullptr,ldc);
    ldc->fetchOperands(byteCodeReader);
    ASSERT_EQ(0x1516,ldc->index);
}

static const class_file::MethodInfo* findMainMethod(const class_file::ClassFile& file) {
    auto count = file.getMethodsCount();
    for (uint16_t i = 0; i < count; i++) {
        auto methodInfo = file.getMethods()->getMethodInfo(i);
        if (u"main" == *file.getConstantPool()->getConstantUtf8Info(methodInfo->getNameIndex())->decodeMUTF8()&&
            u"([Ljava/lang/String;)V" == *file.getConstantPool()->getConstantUtf8Info(methodInfo->getDescriptorIndex())->decodeMUTF8()
                ) {
            std::cout << "found main method." << std::endl;
            return methodInfo;
        }
    }
    return nullptr;
}

TEST(Interpreter,interpreterTest) {
    std::string className = "jvmgo/book/ch04/Math";
    auto reader = UtilTest::createClassReader(className);
    auto classFile = class_file::ClassFile::read(*reader);
    auto info = findMainMethod(*classFile);
    auto interpreter = new Interpreter();
    interpreter->interpret(info);
}

