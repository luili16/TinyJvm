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
    auto classPath = class_path::ClassPath(xJre,cp);
    std::string className = std::string (cmd.cls);
    CUtil::replaceAll(className,".","/");
    auto c = classPath.readClass(className);
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

