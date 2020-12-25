//
// Created by 刘立新 on 2020/12/23.
//

#ifndef CH01_GETSTATIC_H
#define CH01_GETSTATIC_H
#include "../instructions/base/Instruction.h"

namespace instructions::references {
    class GetStatic: public base::Index16Instruction {
    public:
        void execute(rtda::Frame &frame) override;
    };
}

#endif //CH01_GETSTATIC_H
