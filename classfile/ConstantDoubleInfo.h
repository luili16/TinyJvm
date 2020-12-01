//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTDOUBLEINFO_H
#define CH01_CONSTANTDOUBLEINFO_H
#include "ConstantPoolInfo.h"
namespace class_file {
    class ConstantDoubleInfo: public ConstantPoolInfo {
    public:
        const double bytes;
        explicit ConstantDoubleInfo(uint8_t tag,double bytes);
        ~ConstantDoubleInfo() override = default;
    };
}



#endif //CH01_CONSTANTDOUBLEINFO_H
