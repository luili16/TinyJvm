//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTLONGINFO_H
#define CH01_CONSTANTLONGINFO_H

#include "ConstantPoolInfo.h"
namespace class_file {
    /**
 * CONSTANT_Long_info {
 *      u1 tag;
 *      u4 high_bytes;
 *      u4 low_bytes;
 * }
 */
    class ConstantLongInfo: public ConstantPoolInfo {
    public:
        const uint32_t highBytes;
        const uint32_t lowBytes;
        explicit ConstantLongInfo(uint8_t tag,uint32_t highBytes,uint32_t lowBytes);
    };
}



#endif //CH01_CONSTANTLONGINFO_H
