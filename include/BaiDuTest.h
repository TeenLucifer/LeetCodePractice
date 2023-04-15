//
// Created by Lenovo on 2023/4/7.
//

#ifndef DATASTRUCTURE_BAIDUTEST_H
#define DATASTRUCTURE_BAIDUTEST_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class BaiDuTest
{
public:
    BaiDuTest();
    ~BaiDuTest();

    int question1();
    int question2();
    int question3();
    int question4();
    int question5();
    int question6();
    int question7();
    int question8();
    int question9();
    int question10();
    int question11();

    int binary_search(vector<int>& nums, int beging, int end, int target);
    int question12(vector<int>& nums, int target);//二分查找

    bool binary_search_2d(vector<vector<int>>& array, int x_begin, int x_end, int y_begin, int y_end, int target);
    bool question13(vector<vector<int>>& array, int target);//二维二分查找

    int binary_search_Q14(vector<int>& nums, int begin, int end);
    int question14(vector<int>& nums);//寻找峰值

    ListNode* question15(ListNode* head, int val);//删除链表元素

    ListNode* question16(ListNode* head);//反转链表

    ListNode* question17(ListNode* head1, ListNode* head2);//合并两个排序列表

    bool question18(ListNode* head);//判断链表中是否有环形结构

    ListNode* question19(ListNode* head);//链表中环的入口节点

    int question20(string str1, string str2);//异位字符串

    vector<int> question21(vector<int>& nums1, vector<int>& nums2);//数组的公共元素

    vector<vector<int>> question22(vector<int>& nums);//三数之和

    void quick_sort(vector<int>& nums, int low, int high);
    vector<int> question23(vector<int>& nums);//快速排序

    vector<vector<int>> question24(TreeNode* root);//广搜//二叉树层序遍历

    void dfs_Q25(vector<int>& vec, TreeNode* root);
    vector<int> question25(TreeNode* root);//深搜//二叉树中序遍历

    void dfs_Q26(vector<int>& pre, vector<int>& mid, vector<int>& back, TreeNode* root);
    vector<vector<int>> question26(TreeNode* root);//二叉树先序、中序、后续遍历

    int question_I();

    bool isPalindrome(string s);
    string construct_string(int x);
    int question_II();
};


#endif //DATASTRUCTURE_BAIDUTEST_H
