//
// Created by Lenovo on 2022/9/14.
//

#ifndef DATASTRUCTURE_MINSTACK_H
#define DATASTRUCTURE_MINSTACK_H

#include "headers.h"

class MinStack
{
public:
    MinStack();
    ~MinStack();
    void push(int val);
    void pop();
    int top();
    int getMin();

private:
    stack<int> stk;
    stack<int> minStk;
};


#endif //DATASTRUCTURE_MINSTACK_H
