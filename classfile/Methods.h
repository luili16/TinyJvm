//
// Created by 刘立新 on 2020/11/30.
//

#ifndef CH01_METHODS_H
#define CH01_METHODS_H
#include "cstdint"
#include "MethodInfo.h"
#include "ClassReader.h"
#include "ConstantPool.h"
namespace class_file {
    class Methods {
    private:
        const uint16_t methodsCount;
        MethodInfo** methods;
    public:
        static const Methods* newMethods(const ConstantPool *constantPool,ClassReader&reader);
        explicit Methods(uint16_t methodsCount,MethodInfo** methods);
        [[nodiscard]] uint16_t getMethodsCount() const;
        [[nodiscard]] const MethodInfo* getMethodInfo(uint16_t index) const;
    };
}
#endif //CH01_METHODS_H
