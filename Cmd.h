//
// Created by 刘立新 on 2020/10/29.
//

#ifndef CH01_CMD_H
#define CH01_CMD_H

#include <string>

class Cmd {
public:
    constexpr static const char *HELP = "-help";
    constexpr static const char *VERSION = "-version";
    constexpr static const char *X_JRE_OPTIONS = "-xJre";
    constexpr static const char *CLASS_PATH = "-cp";
    constexpr static const char *MAIN_CLASS = "-cls";
    char* cmdPath = nullptr;
    char* help = nullptr;
    char* version = nullptr;
    char* xJre = nullptr;
    char* cp = nullptr;
    char* cls = nullptr;
    explicit Cmd() = default;
    static void printUsage();
    static void printVersion();
    bool isArgsAvailable() const ;
    ~Cmd() = default;
private:
};


#endif //CH01_CMD_H
