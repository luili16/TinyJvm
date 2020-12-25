//
// Created by 刘立新 on 2020/12/14.
//

#ifndef CH01_ATTRLINENUMBERTABLE_H
#define CH01_ATTRLINENUMBERTABLE_H

#include "AttributeInfo.h"

namespace class_file {

    class LineNumberTable0 {
    public:
        const uint16_t startPc;
        const uint16_t lineNumber;
        explicit LineNumberTable0(uint16_t startPc, uint16_t lineNumber);
    };

    class AttrLineNumberTable: public AttributeInfo {
    public:
        const uint16_t lineNumberTableLength;
        const LineNumberTable0** lineNumberTables;
        explicit AttrLineNumberTable(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t lineNumberTableLength,const LineNumberTable0** lineNumberTable);
        ~AttrLineNumberTable() override;
        [[nodiscard]] const LineNumberTable0* getLineNumberTable(uint16_t index) const;
    };

}




#endif //CH01_ATTRLINENUMBERTABLE_H
