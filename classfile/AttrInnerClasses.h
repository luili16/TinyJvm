//
// Created by 刘立新 on 2020/12/24.
//

#ifndef CH01_ATTRINNERCLASSES_H
#define CH01_ATTRINNERCLASSES_H

#include "AttributeInfo.h"

namespace class_file {
    class Classes;
    class AttrInnerClasses: public AttributeInfo {
    public:
        explicit AttrInnerClasses(uint16_t attributeNameIndex,
                                  uint32_t attributeLength,
                                  ConstantPool*constantPool,
                                  uint16_t numberOfClasses,
                                  const Classes** classes
                                  );
        const uint16_t numberOfClasses;
        const Classes** classes;
    };

    class Classes {
    public:
        explicit Classes(uint16_t innerClassInfoIndex,
                         uint16_t outerClassInfoIndex,
                         uint16_t innerNameIndex,
                         uint16_t innerClassAccessFlags
                         );
        const uint16_t innerClassInfoIndex;
        const uint16_t outerClassInfoIndex;
        const uint16_t innerNameIndex;
        const uint16_t innerClassAccessFlags;
    };
}

#endif //CH01_ATTRINNERCLASSES_H
