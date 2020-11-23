//
// Created by 刘立新 on 2020/11/11.
//

#ifndef CH01_CMDPARSER_H
#define CH01_CMDPARSER_H

#include "Cmd.h"

class CmdParser {
public:
    static void recurseParseArg(Cmd&cmd,int index,int argc,char** argv);
    static void parseArg(Cmd&cmd,int argc,char** argv);
};


#endif //CH01_CMDPARSER_H
