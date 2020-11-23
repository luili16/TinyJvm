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
     static bool hasEnding(std::string const &fullString, std::string const &ending);
     static bool fileExist(const std::string& name);
     static void listFiles(const std::string &dir, std::vector<std::string>& files);
     static void replaceAll(std::string& str, const std::string& from, const std::string& to);
     static std::vector<std::string> split(const std::string& str,const std::string &delimiter);
};


#endif //CH01_CUTIL_H
