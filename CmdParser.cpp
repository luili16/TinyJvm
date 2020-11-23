//
// Created by 刘立新 on 2020/11/11.
//

#include "CmdParser.h"

void CmdParser::recurseParseArg(Cmd &cmd, int index,int argc, char **argv) {

    if (index <= 0) {
        return;
    }

    if (index >= argc) {
        return;
    }

    // 命令路径
    char* argI = argv[index];
    if (std::strcmp(argI,Cmd::HELP) == 0) {
        cmd.help = argI;
        return;
    } else if (std::strcmp(argI,Cmd::VERSION) == 0) {
        cmd.version = argI;
        return;
    } else if (std::strcmp(argI,Cmd::CLASS_PATH) == 0) {
        index++;
        cmd.cp = argv[index];
    } else if (std::strcmp(argI,Cmd::MAIN_CLASS) == 0) {
        index++;
        cmd.cls = argv[index];
    } else if (std::strcmp(argI,Cmd::X_JRE_OPTIONS) == 0) {
        index++;
        cmd.xJre = argv[index];
    }
    index++;
    recurseParseArg(cmd,index,argc,argv);
}

void CmdParser::parseArg(Cmd &cmd, int argc, char **argv) {
    int index = 1;
    while (index < argc) {
        // 命令路径
        char* argI = argv[index];
        if (std::strcmp(argI,Cmd::HELP) == 0) {
            cmd.help = argI;
            return;
        } else if (std::strcmp(argI,Cmd::VERSION) == 0) {
            cmd.version = argI;
            return;
        } else if (std::strcmp(argI,Cmd::CLASS_PATH) == 0) {
            index++;
            cmd.cp = argv[index];
        } else if (std::strcmp(argI,Cmd::MAIN_CLASS) == 0) {
            index++;
            cmd.cls = argv[index];
        } else if (std::strcmp(argI,Cmd::X_JRE_OPTIONS) == 0) {
            index++;
            cmd.xJre = argv[index];
        }
        index++;
    }
}
