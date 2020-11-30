//
// Created by 刘立新 on 2020/11/27.
//

#ifndef CH01_UTILTEST_H
#define CH01_UTILTEST_H
#include "../classfile/ClassReader.h"
#include "../classpath/ClassPath.h"

class UtilTest {
public:
    static class_file::ClassReader* createClassReader();
    static class_path::ClassPath* createClassPath();
};


#endif //CH01_UTILTEST_H
