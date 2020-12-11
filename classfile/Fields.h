//
// Created by 刘立新 on 2020/11/30.
//

#ifndef CH01_FIELDS_H
#define CH01_FIELDS_H
#include "FieldInfo.h"
#include "ConstantPool.h"
#include "ClassReader.h"
namespace class_file {
    class Fields {
    private:
        const uint16_t fieldsCount;
        FieldInfo** fieldInfos;
    public:
        static const Fields* newFields(const ConstantPool *constantPool,ClassReader&reader);
        explicit Fields(uint16_t fieldsCount, FieldInfo** fieldInfos);
        [[nodiscard]] uint16_t getFieldsCount() const;
        [[nodiscard]] const FieldInfo* getFieldInfo(uint16_t index) const;
    };
}



#endif //CH01_FIELDS_H
