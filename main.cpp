#include <iostream>
#include "Cmd.h"
#include "CmdParser.h"
#include "string"
#include "classpath/ClassPath.h"
#include "classfile/ClassReader.h"
#include "classfile/ClassFile.h"
#include "classfile/MethodInfo.h"
#include "util/CUtil.h"
#include "Interpreter.h"
using namespace std;


const class_file::MethodInfo* findMainMethod(const class_file::ClassFile& file) {
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

void startJVM(Cmd&cmd) {
    std::cout << "tiny jvm is starting..." << "\n";
    std::string xJre;
    if (cmd.xJre != nullptr) {
        xJre = std::string(cmd.xJre);
    } else {
        xJre = "";
    }
    std::string cp = std::string (cmd.cp);
    auto classPath = class_path::ClassPath(xJre,cp);
    std::string className = std::string (cmd.cls);
    CUtil::replaceAll(className,".","/");
    auto reader = class_file::ClassReader(*classPath.readClass(className));
    auto classFile = class_file::ClassFile::read(reader);
    std::cout << "pointer int size: " << sizeof(int*) <<  "\n";
    std::cout << "pointer uint8 size: " << sizeof(uint8_t*) << "\n";
    auto mainMethodInfo = findMainMethod(*classFile);
    auto interpret = Interpreter();
    //interpret.interpret(classFile->getConstantPool(),mainMethodInfo);
}




int main(int argc, char** argv) {
    Cmd cmd = Cmd();
    CmdParser::parseArg(cmd,argc,argv);
    if (cmd.help != nullptr) {
        Cmd::printUsage();
        return 0;
    }

    if (cmd.version != nullptr) {
        Cmd::printVersion();
        return 0;
    }

    std::cout << "cp: " << cmd.cp << "\n";
    std::cout << "cls: " << cmd.cls << "\n";
    //cout << "-xJre: " << cmd.xJre << "\n";
    if (cmd.isArgsAvailable()) {
        startJVM(cmd);
    } else {
        Cmd::printUsage();
    }

    return 0;
}

