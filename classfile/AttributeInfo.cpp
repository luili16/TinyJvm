//
// Created by 刘立新 on 2020/11/27.
//

#include "AttributeInfo.h"

uint16_t class_file::AttributeInfo::getAttributeNameIndex() const {
    return this->attributeNameIndex;
}

class_file::AttributeInfo::AttributeInfo(uint16_t attributeNameIndex,
                                         uint16_t attributeLength,
                                         const uint8_t *info):
                                         attributeNameIndex(attributeNameIndex),
                                         attributeLength(attributeLength),
                                         info(info)
                                         {

}

uint16_t class_file::AttributeInfo::getAttributeLength() const {
    return this->attributeLength;
}

const uint8_t *class_file::AttributeInfo::getInfo() const {
    return this->info;
}
