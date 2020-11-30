//
// Created by 刘立新 on 2020/11/27.
//

#ifndef CH01_ATTRIBUTEINFO_H
#define CH01_ATTRIBUTEINFO_H
#include <cstdint>
namespace class_file {
    class AttributeInfo {
    private:
        const uint16_t attributeNameIndex;
        const uint32_t attributeLength;
        const uint8_t* info;
    public:
        AttributeInfo(uint16_t attributeNameIndex,uint16_t attributeLength,const uint8_t* info);
        [[nodiscard]] uint16_t getAttributeNameIndex() const;
        [[nodiscard]] uint16_t getAttributeLength() const;
        [[nodiscard]] const uint8_t *getInfo() const;
    };
}



#endif //CH01_ATTRIBUTEINFO_H
