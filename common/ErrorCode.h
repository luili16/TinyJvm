//
// Created by 刘立新 on 2020/12/2.
//

#ifndef CH01_ERRORCODE_H
#define CH01_ERRORCODE_H

namespace common {
    class ErrorCode {
    public:
        static const int OK = 0;
        static const int UTFDataFormatError = 100;
        static const int StackOverflowError = 101;
        static const int JvmStackIsEmptyError = 102;
        static const int NullPointerError = 103;
    };
}


#endif //CH01_ERRORCODE_H