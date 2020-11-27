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
        uint16_t getAttributeNameIndex() const;
    };
}



#endif //CH01_ATTRIBUTEINFO_H
