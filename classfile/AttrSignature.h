//
// Created by 刘立新 on 2020/12/24.
//

#ifndef CH01_ATTRSIGNATURE_H
#define CH01_ATTRSIGNATURE_H

#include "AttributeInfo.h"

namespace class_file {
    class AttrSignature: public AttributeInfo {
    public:
        explicit AttrSignature(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t signatureIndex);
        const uint16_t signatureIndex;
    };
}




#endif //CH01_ATTRSIGNATURE_H
