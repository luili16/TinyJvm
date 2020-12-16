//
// Created by 刘立新 on 2020/12/11.
//

#ifndef CH01_STACKMAPTABLEATTRIBUTE_H
#define CH01_STACKMAPTABLEATTRIBUTE_H

#include "cstdint"
#include "ClassReader.h"
#include "AttributeInfo.h"

namespace class_file {

    class StackMapFrame {

    };

    class StackMapTableAttribute: public AttributeInfo {
    public:
        static const StackMapTableAttribute*  newStackMapTableAttribute(ClassReader&reader);
        const uint16_t numberOfEntries;
        explicit StackMapTableAttribute(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t numberOfEntries,StackMapFrame** entries);
        const StackMapFrame* getEntry(uint16_t index);
    private:
        StackMapFrame** entries;
    };
}




#endif //CH01_STACKMAPTABLEATTRIBUTE_H
