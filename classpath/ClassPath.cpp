//
// Created by 刘立新 on 2020/11/17.
//

#include "ClassPath.h"
#include "../util/CUtil.h"
#include <cstdlib>
inline std::string getJreDir(std::string &jreOption) {
    if (!jreOption.empty() && CUtil::fileExist(jreOption)) {
        return jreOption;
    }
    if (CUtil::fileExist("./jre")) {
        return "./jre";
    }
    char* javaHome = std::getenv("JAVA_HOME");
    if (javaHome != nullptr) {
        std::string s = std::string();
        if (CUtil::hasEnding(jreOption,"/")) {
            s.append(javaHome).append("jre");
        } else {
            s.append(javaHome).append("/jre");
        }
        return std::move(s);
    }
    return "";
}

class_path::ClassPath::ClassPath(std::string &jreOption, std::string &cpOption) {
    // parseBootAndExtClassPath
    auto jreDir = getJreDir(jreOption);
    if (jreDir.empty()) {
        std::cout << "empty jreDir\n";
        return;
    }
    // jre/lib/*
    auto jreLibPath = std::string(jreDir).append("/lib/*");
    this->bootClassPath = new WildcardEntry(jreLibPath);

    // jre/lib/ext/*
    auto jreExtPath = std::string (jreDir).append("/lib/ext/*");
    this->extClassPath = new WildcardEntry(jreExtPath);

    // parseUserClassPath
    if (cpOption.empty()) {
        this->userClassPath = EntryFactory::newEntry(".");
    } else {
        this->userClassPath = EntryFactory::newEntry(cpOption);
    }
}

class_path::ClassPath::~ClassPath() {
    delete this->userClassPath;
    delete this->extClassPath;
    delete this->bootClassPath;
}

std::string class_path::ClassPath::toString() {
    return "class path";
}

std::vector<uint8_t>* class_path::ClassPath::readClass(std::string& className) {

    std::string classNameWithSuffix = std::string (className).append(".class");
    auto cls = this->bootClassPath->readClass(classNameWithSuffix);
    if (!cls->empty()) {
        return cls;
    }
    cls = this->extClassPath->readClass(classNameWithSuffix);
    if (!cls->empty()) {
        return cls;
    }

    return this->userClassPath->readClass(classNameWithSuffix);
}

