//
// Created by 刘立新 on 2020/11/11.
//

#ifndef CH01_ENTRY_H
#define CH01_ENTRY_H

#include "cstddef"
#include "string"
#include "vector"
class Entry;

class Entry {
public:
    constexpr static const char* pathListSeparator = ":";
    virtual std::shared_ptr<std::vector<uint8_t>> readClass(std::string &className) = 0;
    virtual std::string string() = 0;
    virtual ~Entry() = 0;
};

class DirEntry: public Entry {
public:
    std::shared_ptr<std::vector<uint8_t>> readClass(std::string &className) override;
    std::string string() override;
    explicit DirEntry(std::string path);
    ~DirEntry() override = default;
private:
    std::string path;
};

class ZipEntry: public Entry {
public:
    std::shared_ptr<std::vector<uint8_t>> readClass(std::string &className) override;
    std::string string() override;
    explicit ZipEntry(std::string path);
    ~ZipEntry() override;
private:
    std::string path;
};

class CompositeEntry: public Entry {
public:
    std::shared_ptr<std::vector<uint8_t>> readClass(std::string &className) override;
    std::string string() override;
    explicit CompositeEntry(const std::string &path);
    ~CompositeEntry() override;
private:
    std::vector<Entry*> entries;
};

class WildcardEntry: public Entry {
public:
    std::shared_ptr<std::vector<uint8_t>> readClass(std::string &className) override;
    std::string string() override;
    explicit WildcardEntry(const std::string &path);
    ~WildcardEntry() override;
private:
    std::vector<Entry*> entries;
    void createEntries(const std::string &path);
};

class EntryFactory {
public:
    static Entry* newEntry(const std::string& path);
};

#endif //CH01_ENTRY_H
