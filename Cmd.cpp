//
// Created by 刘立新 on 2020/10/29.
//

#include "iostream"
#include "string"
#include "Cmd.h"

using namespace std;

void Cmd::printUsage() {
    std::cout<<"Usage: %s [-options] class [args...]\n";
}

void Cmd::printVersion() {
    std::cout<<"version is 0.0.1\n";
}

bool Cmd::isArgsAvailable() const {
    //return this ->xJre != nullptr && this -> cls != nullptr && this->cp != nullptr;
    return this -> cls != nullptr && this->cp != nullptr;
}


