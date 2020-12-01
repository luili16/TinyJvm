//
// Created by 刘立新 on 2020/12/1.
//

#ifndef CH01_ACCESSFLAGS_H
#define CH01_ACCESSFLAGS_H
#include "cstdint"
namespace class_file {
    class AccessFlags {
    public:
        static const uint16_t ACC_PUBLIC = 0x0001;
        static const uint16_t ACC_FINAL = 0x0010;
        static const uint16_t ACC_SUPER = 0x0020;
        static const uint16_t ACC_INTERFACE = 0x0200;
        static const uint16_t ACC_ABSTRACT = 0x0400;
        static const uint16_t ACC_SYNTHETIC = 0x1000;
        static const uint16_t ACC_ANNOTATION = 0x2000;
        static const uint16_t ACC_ENUM = 0x4000;
    };
}

#endif //CH01_ACCESSFLAGS_H
