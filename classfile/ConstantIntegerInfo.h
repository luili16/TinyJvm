//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTINTEGERINFO_H
#define CH01_CONSTANTINTEGERINFO_H
#include "ConstantPoolInfo.h"
namespace class_file {
    /**
 * CONSTANT_Integer_info {
 *      u1 tag;
 *      u4 bytes;
 * }
 */
    class ConstantIntegerInfo: public ConstantPoolInfo {
    public:
        const uint32_t bytes;
        explicit ConstantIntegerInfo(uint8_t tag, uint32_t bytes);
    };
}



#endif //CH01_CONSTANTINTEGERINFO_H
