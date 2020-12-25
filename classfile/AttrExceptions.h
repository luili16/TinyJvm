//
// Created by 刘立新 on 2020/12/14.
//

#ifndef CH01_ATTREXCEPTIONS_H
#define CH01_ATTREXCEPTIONS_H

#include "AttributeInfo.h"
#include "cstdint"

namespace class_file {
    class AttrExceptions: public AttributeInfo {
    public:
        const uint16_t numberOfExceptions;
        const uint16_t *exceptionIndexTable;
        explicit AttrExceptions(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t numberOfExceptions,const uint16_t *exceptionIndexTable);
        ~AttrExceptions() override;
    };
}

#endif //CH01_ATTREXCEPTIONS_H
