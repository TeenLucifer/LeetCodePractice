//
// Created by Lenovo on 2022/9/25.
//

#ifndef DATASTRUCTURE_AVL_H
#define DATASTRUCTURE_AVL_H

#include <vector>

class BalancedTreeNode
{
private:
    int val;
    int height;
    BalancedTreeNode* left;
    BalancedTreeNode* right;
public:
    BalancedTreeNode();
    ~BalancedTreeNode();
    BalancedTreeNode* findMin(BalancedTreeNode* root);
    BalancedTreeNode* findMax(BalancedTreeNode* root);
    BalancedTreeNode* insert(BalancedTreeNode* root, int val);
    BalancedTreeNode* delete_(BalancedTreeNode* root, int val);
    BalancedTreeNode* create(std::vector<int> nums);
    BalancedTreeNode* singleLeftRotation(BalancedTreeNode* root);
    BalancedTreeNode* singleRightRotation(BalancedTreeNode* root);
    BalancedTreeNode* doubleLeftRightRotation(BalancedTreeNode* root);
    BalancedTreeNode* doubleRightLeftRotation(BalancedTreeNode* root);
    int getHeight(BalancedTreeNode* root);
};


#endif //DATASTRUCTURE_AVL_H
