//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTDOUBLEINFO_H
#define CH01_CONSTANTDOUBLEINFO_H
#include "ConstantPoolInfo.h"
namespace class_file {
    class ConstantDoubleInfo: public ConstantPoolInfo {
    public:
        const uint32_t highBytes;
        const uint32_t lowBytes;
        explicit ConstantDoubleInfo(uint8_t tag,uint32_t highBytes,uint32_t lowBytes);
    };
}



#endif //CH01_CONSTANTDOUBLEINFO_H
