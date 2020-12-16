//
// Created by 刘立新 on 2020/12/14.
//

#ifndef CH01_ATTRENCLOSINGMETHOD_H
#define CH01_ATTRENCLOSINGMETHOD_H

#include "cstdint"
#include "AttributeInfo.h"

namespace class_file {
    /**
 * EnclosingMethod_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
    u2 class_index;
    u2 method_index;
   }
 */
    class AttrEnclosingMethod: public AttributeInfo {
    public:
        const uint16_t classIndex;
        const uint16_t methodIndex;
        explicit AttrEnclosingMethod(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t classIndex,uint16_t methodIndex);
    };
}


#endif //CH01_ATTRENCLOSINGMETHOD_H
