//
// Created by 刘立新 on 2020/11/16.
//

#ifndef CH01_CUTIL_H
#define CH01_CUTIL_H

#include <iostream>
#include "string"
#include "vector"
#include "cstddef"


class CUtil {
public:
    // 大端存储，是指数据的高字节保存在内存的低地址中，
    // 而数据的低字节保存在内存的高地址中；
    //小端存储，是指据的高字节保存在内存的高地址中，
    // 而数据的低字节保存在内存的低地址中；
    // return
    // true big endian
    // false little endian
    static bool isBigEndian();

    static bool hasEnding(std::string const &fullString, std::string const &ending);

    static bool fileExist(const std::string &name);

    static void listFiles(const std::string &dir, std::vector<std::string> &files);

    static void replaceAll(std::string &str, const std::string &from, const std::string &to);

    static std::vector<std::string> split(const std::string &str, const std::string &delimiter);

    static bool isStringEqual(std::string&a,std::string&b);

    static bool isU16StringEqual(std::u16string&a,std::u16string&b);
};


#endif //CH01_CUTIL_H
