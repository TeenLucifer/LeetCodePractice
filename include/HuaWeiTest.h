//
// Created by Lenovo on 2023/4/11.
//

#ifndef DATASTRUCTURE_HUAWEITEST_H
#define DATASTRUCTURE_HUAWEITEST_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class HuaWeiTest
{
public:
    HuaWeiTest();
    ~HuaWeiTest();

    int question1();//字符串最后一个单词长度
    int question2();//计算某字符出现的次数
    int question3();//字符串分隔
    int question4(int n);//斐波那契数列//DP
    int question5(int n);//爬楼梯
    int question6(vector<int>& cost);//使用最小花费爬楼梯
    int question7(int m, int n);
    int question8();//购物单//DP的背包问题
    bool question9(vector<int>& nums);//分割等和子集//背包问题
    int question10();//经典背包问题
};


#endif //DATASTRUCTURE_HUAWEITEST_H
