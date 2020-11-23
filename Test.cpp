//
// Created by 刘立新 on 2020/11/16.
//

#include "Test.h"
#include "iostream"

Object::Object() {
    std::cout << "object 被创建了"<< "\n";
}

Object::~Object() {
    std::cout << "object 被销毁了"<< "\n";
}

void Object::doSomething() {
    std::cout << "Object.doSomething\n";
}

Test::~Test() {
    std::cout << "Test 被销毁了"<< "\n";
}

void Test::doSomething() {
    std::cout << "test.doSomething..." << "\n";
    o->doSomething();
}

Test::Test() {
    std::cout << "Test 被创建了"<< "\n";
    this -> o = std::make_unique<Object>();
}
