//
// Created by 刘立新 on 2020/12/24.
//

#include "AttrSourceFile.h"

class_file::AttrSourceFile::AttrSourceFile(uint16_t attributeNameIndex, uint32_t attributeLength,
                                           const class_file::ConstantPool *constantPool, uint16_t sourceFileIndex):AttributeInfo(attributeNameIndex,attributeLength,constantPool),sourceFileIndex(sourceFileIndex) {

}
