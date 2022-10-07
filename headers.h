//
// Created by Lenovo on 2022/6/7.
//

#ifndef DATASTRUCTURE_HEADERS_H
#define DATASTRUCTURE_HEADERS_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
} ListNode;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
} TreeNode;

namespace N_ARY_TREE
{
    class Node//N叉树
    {
    public:
        int val;
        std::vector<Node*> children;

        Node(){}

        Node(int _val)
        {
            val = _val;
        }

        Node(int _val, std::vector<Node*> _children)
        {
            val = _val;
            children = _children;
        }
    };
}

namespace BINARY_TREE
{
    class Node//具有next指针的完美二叉树
    {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(nullptr), right(nullptr), next(nullptr){}
        Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr){}
        Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next){}
    };
}

ListNode* createList(vector<int>& nums);

#endif //DATASTRUCTURE_HEADERS_H
