//
// Created by Lenovo on 2023/4/11.
//

#include "HuaWeiTest.h"

HuaWeiTest::HuaWeiTest()
{}

HuaWeiTest::~HuaWeiTest()
{}

int HuaWeiTest::question1()//字符串最后一个单词长度
{
    string str;
    do
    {
        cin >> str;
    } while(cin.get() != '\n');
    cout << str.size() << endl;

    return 0;
}

int HuaWeiTest::question2()//计算某字符出现的字数
{
    string str;
    char ch;
    int cnt = 0;

    getline(cin, str);
    cin >> ch;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == ch || str[i] == toupper(ch) || str[i] == tolower(ch))
        {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}

int HuaWeiTest::question3()//字符串分隔
{
    string str;
    int strLength = 0;

    getline(cin, str);
    strLength = str.size();

    if(strLength == 0)
    {
        return 0;
    }

    string subStr;
    for(int i = 0; i < strLength / 8; ++i)
    {
        subStr = str.substr(i * 8, 8);
        cout << subStr << endl;
    }
    subStr = str.substr((strLength / 8) * 8, strLength % 8);
    for(int i = 0; i < (8 - strLength % 8); ++i)
    {
        subStr += "0";
    }
    cout << subStr << endl;

    return 0;
}

int HuaWeiTest::question4(int n)//斐波那契数列//DP
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i < n + 1; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int HuaWeiTest::question5(int n)//爬楼梯
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 1;
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < n + 1; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int HuaWeiTest::question6(vector<int> &cost)//使用最小花费爬楼梯
{
    int n = cost.size();
    if(n == 0)
    {
        return 0;
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = min(dp[0] + cost[0], 0);

    for(int i = 2; i < n + 1; ++i)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[n];
}

int HuaWeiTest::question7(int m, int n)//机器人路径
{
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = 1;

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i == 0 || j == 0)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }
                if(i == 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                if(j == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int HuaWeiTest::question8()//购物单//DP的背包问题
{
    int total_money;
    int total_num;
    cin >> total_money >> total_num;

    vector<vector<int>> table(total_num, vector<int>(3));
    //多少钱    重要度    属于哪个主件的附件
    for(int i = 0; i < total_num; ++i)
    {
        cin >> table[i][0] >> table[i][1] >> table[i][2];
    }

    vector<int> weights;//重量表
    vector<int> values;//价值表
    vector<int> additions;//附件表

    for(int i = 0; i < table.size(); ++i)
    {
        if(table[i][2] == 0)
        {
            weights.push_back(table[i][0]);
            values.push_back(table[i][0] * table[i][1]);
        }
        else
        {
            for(int j = 0; j < table.size(); ++j)
            {
                if(table[i][2] == j + 1)//i为主件j的附件
                {
                    weights.push_back(table[j][0] + table[i][0]);
                }
            }
        }
    }
    return 0;
}

bool HuaWeiTest::question9(vector<int> &nums)//分割等和子集//背包问题
{
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
    }
    if(sum % 2 != 0)
    {
        return false;
    }

    vector<int> values = nums;
    vector<vector<int>> dp(nums.size(), vector<int>(1 + (sum / 2)));

    for(int j = nums[0]; j < 1 + (sum / 2); ++j)
    {
        dp[0][j] = values[0];
    }

    for(int i = 1; i < nums.size(); ++i)
    {
        for(int j = 0; j < 1 + (sum / 2); ++j)
        {
            if(j < nums[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + values[i]);
            }
        }
    }
    for(int i = 0; i < nums.size(); ++i)
    {
        if(dp[i][sum / 2] == sum / 2)
        {
            return true;
        }
    }
    return false;
}

int HuaWeiTest::question10()//经典背包问题
{
    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    int bagWeight = 4;
    vector<vector<int>> dp(weights.size(), vector<int>(bagWeight + 1, 0));

    for(int j = weights[0]; j < bagWeight + 1; ++j)
    {
        dp[0][j] = values[0];
    }

    for(int i = 1; i < weights.size(); ++i)
    {
        for(int j = 0; j < bagWeight + 1; ++j)
        {
            if(weights[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }
    return dp[weights.size() - 1][bagWeight];
}