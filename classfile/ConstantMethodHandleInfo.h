//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTMETHODHANDLEINFO_H
#define CH01_CONSTANTMETHODHANDLEINFO_H

#include "ConstantPoolInfo.h"
namespace class_file {
    /**
 * CONSTANT_MethodHandle_info {
 *      u1 tag;
 *      u1 reference_kind;
 *      u2 reference_index;
 * }
 */
    class ConstantMethodHandleInfo: public ConstantPoolInfo {
    public:
        const uint8_t referenceKind;
        const uint16_t referenceIndex;
        explicit ConstantMethodHandleInfo(uint8_t tag,uint8_t referenceKind, uint16_t referenceIndex);
    };
}



#endif //CH01_CONSTANTMETHODHANDLEINFO_H
