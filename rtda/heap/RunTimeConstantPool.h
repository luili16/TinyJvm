//
// Created by 刘立新 on 2020/12/28.
//

#ifndef CH01_RUNTIMECONSTANTPOOL_H
#define CH01_RUNTIMECONSTANTPOOL_H

#include <unordered_map>
#include <string>
#include "Class.h"
#include "../../classfile/ClassReader.h"
#include "../../classpath/ClassPath.h"

namespace rtda::heap {
    class RunTimeConstantPool {
    public:
        static void globalInit(std::shared_ptr<class_path::ClassPath>& classPath);
        static void globalDestroy();
        static RunTimeConstantPool* getInstance();
        Class* getClass(std::u16string& className);
    private:
        std::unordered_map<std::u16string, Class*>* sharedPool = new std::unordered_map<std::u16string,Class*>();
        std::shared_ptr<class_path::ClassPath> classPath;
        static RunTimeConstantPool* instance;
        explicit RunTimeConstantPool(std::shared_ptr<class_path::ClassPath>& classPath);
        RunTimeConstantPool(const RunTimeConstantPool&) = delete;
        RunTimeConstantPool& operator=(const RunTimeConstantPool&) = delete;
        ~RunTimeConstantPool();
    };
}


#endif //CH01_RUNTIMECONSTANTPOOL_H
