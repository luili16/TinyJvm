//
// Created by 刘立新 on 2020/11/20.
//

#ifndef CH01_CONSTANTCLASSINFO_H
#define CH01_CONSTANTCLASSINFO_H

#include "ConstantPoolInfo.h"
namespace class_file {
    /**
 * CONSTANT_Class_info {
 *      u1 tag;
 *      u2 name_index;
 * }
 */
    class ConstantClassInfo: public ConstantPoolInfo {
    public:
        const uint16_t nameIndex;
        explicit ConstantClassInfo(uint8_t tag, uint16_t nameIndex);
    };
}



#endif //CH01_CONSTANTCLASSINFO_H
