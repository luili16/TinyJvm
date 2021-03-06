//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTFLOATINFO_H
#define CH01_CONSTANTFLOATINFO_H

#include "ConstantPoolInfo.h"
namespace class_file {
    class ConstantFloatInfo: public ConstantPoolInfo {
    public:
        const float bytes;
        explicit ConstantFloatInfo(uint8_t tag,float bytes);
        ~ConstantFloatInfo() override = default;
    };
}



#endif //CH01_CONSTANTFLOATINFO_H
