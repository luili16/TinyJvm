//
// Created by 刘立新 on 2020/12/11.
//

#ifndef CH01_RAWATTRIBUTEINFO_H
#define CH01_RAWATTRIBUTEINFO_H

#include "AttributeInfo.h"

namespace class_file {
    class RawAttributeInfo: public AttributeInfo  {
    public:
        explicit RawAttributeInfo(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint8_t * info);
    private:
        uint8_t * info;
    };
}


#endif //CH01_RAWATTRIBUTEINFO_H
