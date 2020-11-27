//
// Created by 刘立新 on 2020/11/20.
//

#ifndef CH01_CONSTANTPOOL_H
#define CH01_CONSTANTPOOL_H
#include <cstdint>
#include "ConstantPoolInfo.h"

namespace class_file {
    class ConstantPool {

    public:
        ConstantPoolInfo* getConstantInfo(uint16_t index);
        explicit ConstantPool(uint16_t cpCount,ClassReader &reader);
    private:
        ConstantPoolInfo** constantPoolInfos;
        const std::uint16_t cpCount;
    };
}




#endif //CH01_CONSTANTPOOL_H
