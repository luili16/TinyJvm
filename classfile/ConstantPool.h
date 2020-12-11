//
// Created by 刘立新 on 2020/11/20.
//

#ifndef CH01_CONSTANTPOOL_H
#define CH01_CONSTANTPOOL_H
#include <cstdint>
#include "ConstantPoolInfo.h"
#include "ConstantUtf8Info.h"

namespace class_file {
    class ConstantPool {

    public:
        [[nodiscard]] const ConstantPoolInfo* getConstantInfo(uint16_t index) const;

        const ConstantUtf8Info* getConstantUtf8Info(uint16_t index) const;

        explicit ConstantPool(uint16_t cpCount,ClassReader &reader);
    private:
        ConstantPoolInfo** constantPoolInfos;
        const std::uint16_t cpCount;
    };
}




#endif //CH01_CONSTANTPOOL_H
