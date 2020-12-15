//
// Created by 刘立新 on 2020/12/15.
//

#include "gtest/gtest.h"
#include "../rtda/LocalVars.h"
#include "../rtda/OperandStack.h"

TEST(RtdaTest, testLocalVariable) {
    rtda::LocalVars vars = rtda::LocalVars(10);
    vars.setInt(0,100);
    vars.setInt(1,-100);
    vars.setLong(2,2997924580);
    vars.setLong(4,-2997924580);
    vars.setFloat(6,3.1415926f);
    vars.setDouble(7,2.71828182845);
    ASSERT_EQ(100,vars.getInt(0));
    ASSERT_EQ(-100,vars.getInt(1));
    ASSERT_EQ(2997924580,vars.getLong(2));
    ASSERT_EQ(-2997924580,vars.getLong(4));
    ASSERT_FLOAT_EQ(3.1415926f,vars.getFloat(6));
    ASSERT_DOUBLE_EQ(2.71828182845,vars.getDouble(7));
}

TEST(RtdaTest, testOperandStack) {
    rtda::OperandStack stack = rtda::OperandStack(10);
    stack.pushInt(100);
    stack.pushInt(-100);
    stack.pushLong(2997924580);
    stack.pushLong(-2997924580);
    stack.pushFloat(3.1415926f);
    stack.pushDouble(2.71828182845);
    ASSERT_DOUBLE_EQ(2.71828182845,stack.popDouble());
    ASSERT_FLOAT_EQ(3.1415926f,stack.popFloat());
    ASSERT_EQ(-2997924580,stack.popLong());
    ASSERT_EQ(2997924580,stack.popLong());
    ASSERT_EQ(-100,stack.popInt());
    ASSERT_EQ(100,stack.popInt());
}