//
// Created by 刘立新 on 2020/12/22.
//

#include "gtest/gtest.h"
#include "../instructions/InstructionFactory.h"
#include "../instructions/constants/Const.h"
#include "../Interpreter.h"
#include "../rtda/heap/RunTimeConstantPool.h"
#include "../classpath/ClassPath.h"
#include "UtilTest.h"
using namespace std;
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

    std::u16string className = u"jvmgo/book/ch04/Math";
    string jreOption;
    string cpOption = "/Users/liulixin/CLionProjects/jvmcpp/ch01/test/testResource";
    shared_ptr<class_path::ClassPath> classPathPtr = make_shared<class_path::ClassPath>(jreOption, cpOption);
    rtda::heap::RunTimeConstantPool::globalInit(classPathPtr);

    auto javaClass = rtda::heap::RunTimeConstantPool::getInstance()->getClass(className);
    rtda::heap::Method* mainMethod = nullptr;
    for (int i = 0; i < javaClass->methodsLen; i++) {
        auto method = javaClass->methods[i];
        if (*method->name == u"main" && *method->descriptor == u"([Ljava/lang/String;)V") {
            mainMethod = method;
            break;
        }
    }
    ASSERT_NE(nullptr,mainMethod);
    uint8_t c0 = mainMethod->code[0];
    auto interpreter = new Interpreter();
    interpreter->interpret(mainMethod);
    rtda::heap::RunTimeConstantPool::globalDestroy();
}

