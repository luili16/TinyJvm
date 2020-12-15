//
// Created by 刘立新 on 2020/12/8.
//

#include "LocalVars.h"

rtda::LocalVars::LocalVars(uint32_t len):len(len){
    this->slots = new Slot*[len];
    for (int i = 0;i < len; i++) {
        this->slots[i] = new Slot();
    }
}

rtda::LocalVars::~LocalVars() {
    delete [] this->slots;
}

void rtda::LocalVars::setInt(uint32_t index, int32_t int32) {
    this->slots[index]->num = int32;
}

int32_t rtda::LocalVars::getInt(uint32_t index) {
    return this->slots[index]->num;
}

void rtda::LocalVars::setFloat(uint32_t index, float float32) {
    auto f = reinterpret_cast<uint8_t*>(&float32);
    auto j = reinterpret_cast<uint8_t*>(&(this->slots[index]->num));
    for (int i = 0; i < 4; i++) {
        j[i] = f[i];
    }
}

float rtda::LocalVars::getFloat(uint32_t index) {
    float f;
    auto fp = reinterpret_cast<uint8_t*>(&f);
    auto j = reinterpret_cast<uint8_t*>(&this->slots[index]->num);
    for (int i = 0; i < 4; i++) {
        fp[i] = j[i];
    }
    return f;
}

void rtda::LocalVars::setLong(uint32_t index, int64_t int64) {
    // low
    this->slots[index]->num = (uint32_t)int64;
    // high
    this->slots[index + 1]->num = (uint32_t)((uint64_t)int64 >> 32u);
}

int64_t rtda::LocalVars::getLong(uint32_t index) {
    uint64_t low = this->slots[index] -> num;
    uint64_t high = this->slots[index + 1] -> num;
    uint64_t u = high << 32u | low;
    return (int64_t)u;
}

void rtda::LocalVars::setDouble(uint32_t index, double float64) {

    auto u = reinterpret_cast<uint64_t*>(&float64);
    this->slots[index] -> num = (uint32_t)(*u);
    this->slots[index + 1] -> num = (uint32_t)(*u >> 32u);
}

double rtda::LocalVars::getDouble(uint32_t index) {
    uint64_t low = this->slots[index]->num;
    uint64_t high = this->slots[index + 1]->num;
    uint64_t u = high << 32u | low;
    double d = 0.0;
    auto dp = reinterpret_cast<uint64_t*>(&d);
    *dp = u;
    return d;
}
