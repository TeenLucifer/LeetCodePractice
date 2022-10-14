//
// Created by Lenovo on 2022/9/14.
//

#include "MinStack.h"

MinStack::MinStack()
{
    minStk.push(INT_MAX);
}

MinStack::~MinStack()
{
}

void MinStack::push(int val)
{
    stk.push(val);
    minStk.push(minStk.top() > val ? val : minStk.top());
}

void MinStack::pop()
{
    stk.pop();
    minStk.pop();
}

int MinStack::top()
{
    return stk.top();
}

int MinStack::getMin()
{
    return minStk.top();
}