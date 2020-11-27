//
// Created by 刘立新 on 2020/11/17.
//

#ifndef CH01_CLASSPATH_H
#define CH01_CLASSPATH_H

#include <memory>
#include "Entry.h"
#include <string>

namespace class_path {
    class ClassPath {
    public:
        ClassPath(std::string& jreOption,std::string& cpOption);
        ~ClassPath();
        std::string toString();
        std::vector<uint8_t>* readClass(std::string &className);
    private:
        Entry* bootClassPath;
        Entry* extClassPath;
        Entry* userClassPath;
    };
}




#endif //CH01_CLASSPATH_H
