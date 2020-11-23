#include <iostream>
#include "Cmd.h"
#include "CmdParser.h"
#include "string"
#include "classpath/ClassPath.h"
#include "util/CUtil.h"

void startJVM(Cmd&cmd) {
    std::cout << "tiny jvm is starting..." << "\n";
    std::string xJre;
    if (cmd.xJre != nullptr) {
        xJre = std::string(cmd.xJre);
    } else {
        xJre = "";
    }
    std::string cp = std::string (cmd.cp);
    auto classPath = ClassPath(xJre,cp);
    std::string className = std::string (cmd.cls);
    CUtil::replaceAll(className,".","/");
    auto c = classPath.readClass(className);
    std::cout << "size is " << c->size() << "\n";
    std::cout << "char size: " << sizeof(char) <<"\n";
    std::cout << "int size: " << sizeof(int ) <<"\n";
}

int main(int argc, char** argv) {
    Cmd cmd = Cmd();
    CmdParser::parseArg(cmd,argc,argv);
    if (cmd.help != nullptr) {
        Cmd::printUsage();
    } else if (cmd.version != nullptr) {
        Cmd::printVersion();
    } else {
        std::cout << "cp: " << cmd.cp << "\n";
        std::cout << "cls: " << cmd.cls << "\n";
        //cout << "-xJre: " << cmd.xJre << "\n";
        if (cmd.isArgsAvailable()) {
            startJVM(cmd);
        } else {
            Cmd::printUsage();
        }
    }
    return 0;
}

