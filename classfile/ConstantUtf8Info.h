//
// Created by 刘立新 on 2020/11/23.
//

#ifndef CH01_CONSTANTUTF8INFO_H
#define CH01_CONSTANTUTF8INFO_H

#include "ConstantPoolInfo.h"
#include <string>
namespace class_file {
    /**
 * CONSTANT_Utf8_info {
 *      u1 tag;
 *      u2 length;
 *      u1 bytes[length];
 * }
 */
    class ConstantUtf8Info: public ConstantPoolInfo {
    public:
        const uint16_t length;
        const uint8_t *bytes;
        explicit ConstantUtf8Info(uint8_t tag,uint16_t length,const uint8_t* bytes);

        std::shared_ptr<std::u16string> decodeMUTF8() const;
        ~ConstantUtf8Info() override;
    };
}



#endif //CH01_CONSTANTUTF8INFO_H
