//
// Created by 刘立新 on 2020/11/16.
//

#ifndef CH01_TEST_H
#define CH01_TEST_H
#include "string"
class Object;

class Test {
public:
    explicit Test();
    void doSomething();
    ~Test();

private:
    std::unique_ptr<Object> o;
};

class Object {
public:
    Object();
    void doSomething();
    ~Object();
};


#endif //CH01_TEST_H
