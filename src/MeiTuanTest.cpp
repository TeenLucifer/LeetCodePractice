//
// Created by Lenovo on 2023/4/13.
//

#include "MeiTuanTest.h"

MeiTuanTest::MeiTuanTest()
{}

MeiTuanTest::~MeiTuanTest()
{}

int MeiTuanTest::dfs_Q1(vector<pair<int, int>>& link, int root, int length)
{
    int max_length = 0;
    for(int i = 0; i < link.size(); ++i)
    {
        if(link[i].first == root)
        {
            int tmp = dfs_Q1(link, link[i].second, ++length);
            if(tmp > max_length)
            {
                max_length = tmp;
            }
        }
        else if(link[i].second == root)
        {
            int tmp = dfs_Q1(link, link[i].first, ++length);
            if(tmp > max_length)
            {
                max_length = tmp;
            }
        }
    }
    return max_length;
}

int MeiTuanTest::question1()
{
    int n;
    cin >> n;

    vector<pair<int, int>> link(n - 1, {0, 0});
    pair<int, int> choosen_edge;

    for(int i = 0; i < n - 1; ++i)
    {
        cin >> link[i].first;
        link[i].second = i + 2;
    }
    cin >> choosen_edge.first >> choosen_edge.second;

    cout << dfs_Q1(link, choosen_edge.first, 0) << endl;

    return 0;
}

int MeiTuanTest::question2()
{
    int n, m, a;
    cin >> n >> m >> a;
    vector<vector<string>> sits(n, vector<string>(m, ""));
    vector<vector<string>> sits_bak(n, vector<string>(m, ""));

    for(int i = 0; i < n; ++i)
    {
        vector<string> strs;
        for(int j = 0; j < m;++ j)
        {
            cin >> sits[i][j];
        }
    }
    sits_bak = sits;

    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            for(int k = 0; k < a; ++k)
            {
                if(sits[i][j][k] != sits_bak[(i + 1) % n][(j + 1) % m][k])
                {
                    res++;
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}

int MeiTuanTest::question3()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> a(n, 0);
    vector<int> dp(n + 1, INT_MAX);

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        int max_ = a[i - 1];
        int min_ = a[i - 1];
        for(int j = 0; j <= m && j<= i; ++j)
        {
            max_ = max(max_, a[i - j]);
            min_ = min(min_, a[i - j]);
            int cost = j * (max_ + min_) / 2 + s;
            dp[i] = min(dp[i], dp[i - j] + cost);
        }
    }
    cout << dp[n] << endl;

    return 0;
}

int MeiTuanTest::question4(int back_size, vector<int>& nums, vector<int>& values)
{
    int n = nums.size();
    vector<int> dp(back_size + 1, 0);

    for(int i = 0; i < n; ++i)
    {
        for(int j = back_size; j >= nums[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - nums[i] + values[i]]);
        }
    }
    cout << dp[back_size] << endl;

    return 0;
}