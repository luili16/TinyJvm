//
// Created by 刘立新 on 2020/12/14.
//

#include "AttrExceptions.h"

class_file::AttrExceptions::AttrExceptions(uint16_t attributeNameIndex,
                                           uint32_t attributeLength,
                                           uint16_t numberOfExceptions,
                                           const uint16_t *exceptionIndexTable):
                                           AttributeInfo(attributeNameIndex,attributeLength),
                                           numberOfExceptions(numberOfExceptions),
                                           exceptionIndexTable(exceptionIndexTable)
                                           {
}

class_file::AttrExceptions::~AttrExceptions() {
    delete [] exceptionIndexTable;
};
