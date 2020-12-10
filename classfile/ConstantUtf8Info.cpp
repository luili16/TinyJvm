//
// Created by 刘立新 on 2020/11/23.
//

#include "ConstantUtf8Info.h"
#include <iostream>
#include "../common/ErrorCode.h"

class_file::ConstantUtf8Info::ConstantUtf8Info(uint8_t tag,
                                               uint16_t length,
                                               const uint8_t *bytes):
                                               ConstantPoolInfo(tag),
                                               length(length),
                                               bytes(bytes) {

}

class_file::ConstantUtf8Info::~ConstantUtf8Info() {
    delete [] bytes;
}
// mutf8 -> utf16 -> utf32(unicode) -> std::string
// see java.io.DataInputStream.readUTF(DataInput)
// https://github.com/openjdk-mirror/jdk7u-jdk/blob/master/src/share/classes/java/io/DataInputStream.java
std::shared_ptr<std::u16string> class_file::ConstantUtf8Info::decodeMUTF8() const {
    const uint16_t utfLen = this->length;
    const uint8_t * bytearr = this->bytes;
    //uint16_t chararr[utfLen];
    auto chararr = new uint16_t [utfLen];

    uint16_t c,char2,char3;
    uint16_t count = 0;
    uint16_t chararr_count = 0;

    while (count < utfLen) {
        c = bytearr[count] & 0xffu;
        if (c > 127) {
            break;
        }
        count++;
        chararr[chararr_count]=c;
        chararr_count++;
    }

    while (count < utfLen) {
        c = bytearr[count] & 0xffu;
        switch (c >> 4u) {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
                /* 0xxxxxxx*/
                count++;
                chararr[chararr_count++] = c;
                break;
            case 12:case 13:
                /* 110x xxxx   10xx xxxx*/
                count += 2;
                if (count > utfLen) {
                    std::cerr << "malformed input: partial character at end" << std::endl;
                    exit(common::ErrorCode::UTFDataFormatError);
                }
                char2 = bytearr[count - 1];
                if ((char2 & 0xC0u) != 0x80u) {
                    std::cerr << "malformed input: partial character at end" << std::endl;
                    exit(common::ErrorCode::UTFDataFormatError);
                }
                chararr[chararr_count++] = ((c & 0x1Fu) << 6u) | (char2 & 0x3Fu);
                break;
            case 14:
                /* 1110 xxxx  10xx xxxx  10xx xxxx */
                count += 3;
                if (count > utfLen) {
                    std::cerr << "malformed input: partial character at end" << std::endl;
                    exit(common::ErrorCode::UTFDataFormatError);
                }
                char2 = bytearr[count - 2];
                char3 = bytearr[count - 1];
                if (((char2 & 0xc0u) != 0x80) | ((char3 & 0xc0u) != 0x80u)) {
                    std::cerr << "malformed input: partial character at end" << std::endl;
                    exit(common::ErrorCode::UTFDataFormatError);
                }
                chararr[chararr_count++] = ((c&0xfu) << 12u) | ((char2 & 0x3fu) << 6u) | ((char3 & 0x3fu) << 0u);
                break;
            default:
                std::cerr << "malformed input around byte " << count << std::endl;
                exit(common::ErrorCode::UTFDataFormatError);
        }
    }

    const char16_t * rep = reinterpret_cast<char16_t *>(chararr);
    if (rep == nullptr) {
        std::cerr << "malformed input: partial character at end" << std::endl;
        exit(common::ErrorCode::UTFDataFormatError);
    }

    return std::make_shared<std::u16string>(rep, chararr_count);
}


