//
// Created by 刘立新 on 2020/11/16.
//

#include "CUtil.h"
#include "fstream"
#include "filesystem"
#include "dirent.h"
#include "cstdint"
#include <locale>
#include <codecvt>
#include <array>

bool CUtil::hasEnding(const std::string &fullString, const std::string &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(),ending.length(),ending));
    } else {
        return false;
    }
}

bool CUtil::fileExist(const std::string &name) {
    std::ifstream f(name.c_str());
    bool e = f.good();
    f.close();
    return e;
}

std::vector<std::string> CUtil::split(const std::string &str, const std::string &delimiter) {
    auto tokens = std::vector<std::string>();
    std::size_t last = 0;
    std::size_t next = 0;
    while ((next = str.find(delimiter,last)) != std::string::npos) {
        auto n = str.substr(last,next-last);
        tokens.push_back(std::move(n));
        last = next + 1;
    }
    return std::move(tokens);
}

void listFiles0(const std::string &path,std::vector<std::string> &outPaths) {
    DIR* dir = opendir(path.data());
    if (dir == nullptr) {
        std::cerr << "dir is null\n";
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (std::strcmp(entry->d_name,".") != 0 && std::strcmp(entry->d_name,"..") != 0) {
            if (entry->d_type == DT_DIR) {
                std::string nextDir;
                if (CUtil::hasEnding(path,"/")) {
                    nextDir = std::string(path).append(entry->d_name);
                } else {
                    nextDir = std::string(path).append("/").append(entry->d_name);
                }
                listFiles0(nextDir,outPaths);
            } else if (entry->d_type == DT_REG) {
                char n[entry->d_namlen];
                std::strcpy(entry->d_name,n);
                auto fileStr = std::string (n);
                outPaths.push_back(std::move(fileStr));
            }
        }
    }
    closedir(dir);
}

void CUtil::listFiles(const std::string &dir, std::vector<std::string>& files) {
    listFiles0(dir,files);
}

void CUtil::replaceAll(std::string &str, const std::string &from, const std::string &to) {
    if (from.empty()) {
        return;
    }
    std::size_t startPos = 0;
    while ((startPos = str.find(from,startPos)) != std::string::npos) {
        str.replace(startPos,from.length(),to);
        startPos += to.length();
    }
}

bool CUtil::isBigEndian() {
    uint16_t a = 0x1234;
    auto b = static_cast<uint8_t>(a);
    // true 大端存储
    return b == 0x12;
}

bool CUtil::isStringEqual(std::string &a, std::string &b) {
    return strcmp(a.c_str(), b.c_str()) == 0;
}

bool CUtil::isU16StringEqual(std::u16string &a, std::u16string &b) {



//    if (a.length() != b.length()) {
//        return false;
//    }
//
//
//
//    bool eq = strcmp(reinterpret_cast<const char*>(a.c_str()), reinterpret_cast<const char*>(b.c_str())) == 0;
//    return eq;

    return a == b;
}

std::string CUtil::toUtf8(std::u16string& mUtf8) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
    std::string utf8 = convert.to_bytes(mUtf8);
    return utf8;
}

float CUtil::floatCopy(uint16_t raw) {

    const size_t len = 4;
    auto data = reinterpret_cast<uint8_t*>(&raw);
    std::array<uint8_t,len> buf = {};
    if (isBigEndian()) {
        for (size_t i = 0; i < len; i++) {
            buf[i] = data[i];
        }
    } else {
        for (int i = 3; i>=0;i--) {
            buf[i] = data[i];
        }
    }
    float x;
    auto px = reinterpret_cast<uint8_t*>(&x);
    std::copy(buf.cbegin(), buf.cend(),px);
    return x;
}




