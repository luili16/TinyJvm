//
// Created by 刘立新 on 2020/12/24.
//

#ifndef CH01_ATTRSOURCEFILE_H
#define CH01_ATTRSOURCEFILE_H

#include "AttributeInfo.h"

namespace class_file {
    class AttrSourceFile: public AttributeInfo {
    public:
        explicit AttrSourceFile(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t sourceFileIndex);
        const uint16_t sourceFileIndex;
    };
}
#endif //CH01_ATTRSOURCEFILE_H
