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
        const int64_t bytes;
        explicit ConstantLongInfo(uint8_t tag,int64_t bytes);
        ~ConstantLongInfo() override = default;
    };
}



#endif //CH01_CONSTANTLONGINFO_H
