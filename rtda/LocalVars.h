//
// Created by 刘立新 on 2020/12/8.
//

#ifndef CH01_LOCALVARS_H
#define CH01_LOCALVARS_H

#include <array>
#include "Slot.h"

namespace rtda {
    class LocalVars {
    public:
        const int len;
        explicit LocalVars(uint32_t len);
        ~LocalVars();
        void setInt(uint32_t index,int32_t int32);
        int32_t getInt(uint32_t index);
        void setFloat(uint32_t index,float float32);
        float getFloat(uint32_t index);
        void setLong(uint32_t index,int64_t int64);
        int64_t getLong(uint32_t index);
        void setDouble(uint32_t index,double float64);
        double getDouble(uint32_t index);
    private:
        Slot** slots;
    };
}




#endif //CH01_LOCALVARS_H
