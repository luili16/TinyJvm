//
// Created by 刘立新 on 2020/11/11.
//

#include "Entry.h"
#include "fstream"
#include "iostream"
#include "../util/CUtil.h"
#include <utility>
#include <vector>
#include "filesystem"
#include "dirent.h"
#include "cstddef"
#include <zip.h>


using namespace std;

std::shared_ptr<std::vector<uint8_t>> DirEntry::readClass(std::string &className) {
    // 判断指定的className是不是在目录中
    std::string fileName;
    if (CUtil::hasEnding(this->path,"/")) {
        fileName = std::string(this->path).append(className);
    } else {
        fileName = std::string(this->path).append("/").append(className);
    }
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        std::cout << "read file " << fileName << "fail.\n";
        return nullptr;
    }

    auto bytes = std::make_shared<std::vector<uint8_t>>();
    int len = 1024;
    char buf[len];
    while (!ifs.eof()) {
        ifs.read(buf,len);
        for (int i = 0; i < ifs.gcount(); i++) {
            bytes->push_back(buf[i]);
        }
    }

    return bytes;
}

DirEntry::DirEntry(std::string path) {
    this->path = std::move(path);
}

std::string DirEntry::string() {
    return this->path;
}

std::shared_ptr<std::vector<uint8_t>> ZipEntry::readClass(std::string &className) {
    //
    int e;
    zip_t *zipArchive = zip_open(this->path.data(),ZIP_RDONLY,&e);
    if (zipArchive == nullptr) {
        return std::make_shared<std::vector<uint8_t>>();
    }
    zip_file_t *file = zip_fopen(zipArchive,className.data(),ZIP_FL_COMPRESSED);
    if (file == nullptr) {
        return std::make_shared<std::vector<uint8_t>>();
    }
    auto bytes = std::make_shared<std::vector<uint8_t>>();
    char buf[1024];
    zip_int64_t count = 0;
    while ((count = zip_fread(file,buf,1024)) != 0) {
        for (int i = 0; i < count; i++) {
            bytes->push_back(buf[i]);
        }
    }
    return bytes;
}

ZipEntry::ZipEntry(std::string path) {
    this->path = std::move(path);
}

std::string ZipEntry::string() {
    return this->path;
}

ZipEntry::~ZipEntry() {

}

std::shared_ptr<std::vector<uint8_t>> CompositeEntry::readClass(std::string &className) {
    for (auto &e : this->entries) {
        auto c = e->readClass(className);
        if (!c->empty()) {
            return std::move(c);
        }
    }
    return std::make_shared<std::vector<uint8_t>>();
}

CompositeEntry::CompositeEntry(const std::string &path) {
    this->entries = vector<Entry*>();
    auto cps = CUtil::split(path,Entry::pathListSeparator);
    if (cps.empty()) {
        std::cout << "invalided path: " << path << "\n";
        exit(-1);
    } else {
        for (auto &c : cps) {
            auto entry = EntryFactory::newEntry(c);
            this->entries.push_back(entry);
        }
    }
}

std::string CompositeEntry::string() {
    std::string strs = std::string ();
    for (auto &c : this->entries) {
        strs.append(c->string()).append(std::string(Entry::pathListSeparator));
    }
    return std::move(strs);
}

CompositeEntry::~CompositeEntry() {
    for (auto e : this->entries) {
        delete e;
    }
}

std::shared_ptr<std::vector<uint8_t>> WildcardEntry::readClass(std::string &className) {
    for (auto &e : this->entries) {
        auto c = e->readClass(className);
        if (!c->empty()) {
            return std::move(c);
        }
    }
    return std::make_shared<std::vector<uint8_t>>();
}

void WildcardEntry::createEntries(const std::string &path) {
    DIR* dir = opendir(path.data());
    if (dir == nullptr) {
        std::cerr << "dir is null\n";
        return;
    }
    struct dirent *dirEntry;
    while ((dirEntry = readdir(dir)) != nullptr) {
        if (std::strcmp(dirEntry->d_name, ".") != 0 && std::strcmp(dirEntry->d_name, "..") != 0) {
            if (dirEntry->d_type == DT_DIR) {
                std::string nextDir;
                if (CUtil::hasEnding(path,"/")) {
                    nextDir = std::string(path).append(dirEntry->d_name);
                } else {
                    nextDir = std::string(path).append("/").append(dirEntry->d_name);
                }
                createEntries(nextDir);
            } else if (dirEntry->d_type == DT_REG) {
                char n[dirEntry->d_namlen];
                std::strcpy(n, dirEntry->d_name);
                auto fileStr = std::string (n);
                if (CUtil::hasEnding(fileStr,".jar") || CUtil::hasEnding(fileStr,".JAR")) {
                    std::string jarFile;
                    if (CUtil::hasEnding(path,"/")) {
                        jarFile = std::string(path).append(fileStr);
                    } else {
                        jarFile = std::string(path).append("/").append(fileStr);
                    }
                    auto entry = EntryFactory::newEntry(jarFile);
                    entries.push_back(entry);
                }
            }
        }
    }
    closedir(dir);
}

WildcardEntry::WildcardEntry(const std::string &path) {
    auto p = std::string (path);
    p.erase(path.length()-1,1);
    createEntries(p);
}



std::string WildcardEntry::string() {
    return "WildcardEntry";
}

WildcardEntry::~WildcardEntry() {
}

Entry* EntryFactory::newEntry(const std::string& path) {
    if (path.find(string(Entry::pathListSeparator)) != string::npos) {
        return new CompositeEntry(path);
    }

    if (CUtil::hasEnding(path, "*")) {
        return new WildcardEntry(path);
    }

    if (CUtil::hasEnding(path, ".jar") ||
        CUtil::hasEnding(path, ".JAR") ||
        CUtil::hasEnding(path, ".zip") ||
        CUtil::hasEnding(path, ".ZIP")
    ) {
        return new ZipEntry(path);
    }

    return new DirEntry(path);
}

Entry::~Entry() {
}
