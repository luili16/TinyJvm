//
// Created by 刘立新 on 2020/12/9.
//

#ifndef CH01_SLOT_H
#define CH01_SLOT_H

#include <cstdint>
#include "../rtda/Object.h"

namespace rtda {
    class Slot {
    public:
        uint32_t num = 0u;
        Object* ref = nullptr;
        explicit Slot();
    };
}




#endif //CH01_SLOT_H
