//
// Created by 刘立新 on 2020/11/27.
//

#ifndef CH01_METHODINFO_H
#define CH01_METHODINFO_H
#include "cstdint"
#include "AttributeInfo.h"

namespace class_file {
    class MethodInfo {
    private:
        const uint16_t accessFlags;
        const uint16_t nameIndex;
        const uint16_t descriptorIndex;
        const uint16_t attributesCount;
        const AttributeInfo* attributes;
    };
}



#endif //CH01_METHODINFO_H
