//
// Created by 刘立新 on 2020/12/24.
//

#include "AttrInnerClasses.h"

class_file::Classes::Classes(const uint16_t innerClassInfoIndex,
                             const uint16_t outerClassInfoIndex,
                             const uint16_t innerNameIndex,
                             const uint16_t innerClassAccessFlags):
                             innerClassInfoIndex(innerClassInfoIndex),
                             outerClassInfoIndex(outerClassInfoIndex),
                             innerNameIndex(innerNameIndex),
                             innerClassAccessFlags(innerClassAccessFlags)
                             {
}

class_file::AttrInnerClasses::AttrInnerClasses(uint16_t attributeNameIndex,
                                               uint32_t attributeLength,
                                               ConstantPool*constantPool,
                                               uint16_t numberOfClasses,
                                               const class_file::Classes **classes):
                                               AttributeInfo(attributeNameIndex,attributeLength,constantPool),
                                               numberOfClasses(numberOfClasses),
                                               classes(classes)
                                               {

}
