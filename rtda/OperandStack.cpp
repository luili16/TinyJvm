//
// Created by 刘立新 on 2020/12/9.
//

#include "OperandStack.h"
#include "../common/ErrorCode.h"
#include <algorithm>
#include <iostream>

rtda::OperandStack::OperandStack(uint16_t maxStack): maxStack(maxStack) {
    this->slots = new Slot*[maxStack];
    for (int i = 0;i < maxStack; i++) {
        this->slots[i] = new Slot();
    }
}

rtda::OperandStack::~OperandStack() {
    delete [] slots;
}

void rtda::OperandStack::pushInt(int32_t int32) {
    size++;
    if (size >= maxStack) {
        std::cerr << "rtda::OperandStack::pushInt fail." << std::endl;
        exit(common::ErrorCode::IndexOutOfArrayError);
    }
    this->slots[size]->num = int32;
}

int32_t rtda::OperandStack::popInt() {
    int32_t int32 = this->slots[size]->num;
    size--;
    return int32;
}

void rtda::OperandStack::pushFloat(float float32) {
    auto fp = reinterpret_cast<uint32_t *>(&float32);
    size++;
    if (size >= maxStack) {
        std::cerr << "rtda::OperandStack::pushFloat fail." << std::endl;
        exit(common::ErrorCode::IndexOutOfArrayError);
    }
    this->slots[size]->num= *fp;
}

float rtda::OperandStack::popFloat() {
    float f = 0.0f;
    auto fp = reinterpret_cast<uint32_t*>(&f);
    *fp = this->slots[size]->num;
    size--;
    return f;
}

void rtda::OperandStack::pushLong(int64_t int64) {
    size++;
    if (size >= maxStack) {
        std::cerr << "rtda::OperandStack::pushLong fail." << std::endl;
        exit(common::ErrorCode::IndexOutOfArrayError);
    }
    this->slots[size]->num = (uint32_t)int64;
    size++;
    if (size >= maxStack) {
        std::cerr << "rtda::OperandStack::pushLong fail." << std::endl;
        exit(common::ErrorCode::IndexOutOfArrayError);
    }
    this->slots[size] -> num = (uint32_t)(((uint64_t)int64)>>32u);
}

int64_t rtda::OperandStack::popLong() {
    uint64_t high = this->slots[size]-> num;
    size--;
    uint64_t low = this->slots[size]-> num;
    size--;
    return high << 32u | low;
}

void rtda::OperandStack::pushDouble(double float64) {
    auto fp = reinterpret_cast<uint64_t *>(&float64);
    size++;
    if (size >= maxStack) {
        std::cerr << "rtda::OperandStack::pushDouble fail." << std::endl;
        exit(common::ErrorCode::IndexOutOfArrayError);
    }
    auto a = (uint32_t)(*fp);
    this->slots[size]->num = a;
    size++;
    if (size >= maxStack) {
        std::cerr << "rtda::OperandStack::pushDouble fail." << std::endl;
        exit(common::ErrorCode::IndexOutOfArrayError);
    }
    auto b = (uint32_t)(*fp >> 32u);
    this->slots[size]->num = b;
}

double rtda::OperandStack::popDouble() {
    uint64_t high = this->slots[size]->num;
    size--;
    uint64_t low = this->slots[size] -> num;
    size--;
    uint64_t data = high << 32u | low;
    double d = 0.0;
    auto dp = reinterpret_cast<uint64_t *>(&d);
    *dp = data;
    return d;
}

Object *rtda::OperandStack::popRef() {
    Object* ref = this->slots[size]->ref;
    size--;
    return ref;
}

void rtda::OperandStack::pushRef(Object*ref) {
    size++;
    if (size >= maxStack) {
        std::cerr << "rtda::OperandStack::pushFloat fail." << std::endl;
        exit(common::ErrorCode::IndexOutOfArrayError);
    }
    this->slots[size]->ref = ref;
}
