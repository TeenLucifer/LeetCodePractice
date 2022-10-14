//
// Created by Lenovo on 2022/9/25.
//

#include "AVL.h"

BalancedTreeNode::BalancedTreeNode()
{

}

BalancedTreeNode::~BalancedTreeNode()
{

}

BalancedTreeNode *BalancedTreeNode::findMin(BalancedTreeNode *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    while(root != nullptr)
    {
        if(root->left == nullptr)
        {
            return root;
        }
        else
        {
            root = root->left;
        }
    }
}

BalancedTreeNode *BalancedTreeNode::findMax(BalancedTreeNode *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    while(root != nullptr)
    {
        if(root->right == nullptr)
        {
            return root;
        }
        else
        {
            root = root->right;
        }
    }
}

BalancedTreeNode *BalancedTreeNode::insert(BalancedTreeNode *root, int val)
{
    if(root == nullptr)
    {
        root = new BalancedTreeNode;
        root->val = val;
        root->height = 0;
        root->left = root->right = nullptr;
    }
    else if(val < root->val)
    {
        root->left = root->insert(root->left, val);
        int rHeight = this->getHeight(root->right);
        int lHeight = this->getHeight(root->left);
        if(lHeight - rHeight == 2)
        {
            if(val < root->left->val)
            {
                root = this->singleLeftRotation(root);
            }
            else
            {
                root = this->doubleLeftRightRotation(root);
            }
        }
    }
    else if(val > root->val)
    {
        root->right = root->insert(root->right, val);
        int rHeight = this->getHeight(root->right);
        int lHeight = this->getHeight(root->left);
        if(rHeight - lHeight == 2)
        {
            if(val > root->right->val)
            {
                root = this->singleRightRotation(root);
            }
            else
            {
                root = this->doubleRightLeftRotation(root);
            }
        }
    }
    root->height = std::max(this->getHeight(root->left), this->getHeight(root->right)) + 1;
    return root;
}

BalancedTreeNode *BalancedTreeNode::delete_(BalancedTreeNode *root, int val)
{
    if(root == nullptr)
    {
        return root;
    }
    else if(val < root->val)
    {
        root->left = this->delete_(root->left, val);
        int rHeight = this->getHeight(root->right);
        int lHeight = this->getHeight(root->left);
        if(rHeight - lHeight == 2)
        {
            if(val > root->right->val)
            {
                root = this->singleRightRotation(root);
            }
            else
            {
                root = this->doubleRightLeftRotation(root);
            }
        }
    }
    else if(val > root->val)
    {
        root->right = this->delete_(root->right, val);
        int rHeight = this->getHeight(root->right);
        int lHeight = this->getHeight(root->left);
        if(lHeight - rHeight == 2)
        {
            if(val < root->left->val)
            {
                root = this->singleLeftRotation(root);
            }
            else
            {
                root = this->doubleLeftRightRotation(root);
            }
        }
    }
    else
    {
        if(root->left && root->right)
        {
            BalancedTreeNode* tmp = this->findMin(root->right);
            root->val = tmp->val;
            root->right = this->delete_(root->right, tmp->val);
        }
        else
        {
            BalancedTreeNode* tmp = root;
            if(root->left == nullptr)
            {
                root = root->right;
            }
            else if(root->right == nullptr)
            {
                root = root->left;
            }
            delete tmp;
        }
    }
    return root;
}

BalancedTreeNode *BalancedTreeNode::create(std::vector<int> nums)
{
    BalancedTreeNode* root = nullptr;
    for(int i = 0; i < nums.size(); ++i)
    {
        root = this->insert(root, nums[i]);
    }
    return root;
}

BalancedTreeNode* BalancedTreeNode::singleLeftRotation(BalancedTreeNode* root)
{
    BalancedTreeNode* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    root->height = std::max(this->getHeight(root->left), this->getHeight(root->right));
    tmp->height = std::max(this->getHeight(tmp), this->getHeight(root)) + 1;
    return tmp;
}

BalancedTreeNode* BalancedTreeNode::singleRightRotation(BalancedTreeNode* root)
{
    BalancedTreeNode* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    root->height = std::max(this->getHeight(root->left), this->getHeight(root->right));
    tmp->height = std::max(this->getHeight(tmp->right), this->getHeight(root)) + 1;
    return tmp;
}

BalancedTreeNode* BalancedTreeNode::doubleLeftRightRotation(BalancedTreeNode* root)
{
    root->left = this->singleRightRotation(root->left);
    return this->singleLeftRotation(root);
}

BalancedTreeNode* BalancedTreeNode::doubleRightLeftRotation(BalancedTreeNode* root)
{
    root->right = this->singleLeftRotation(root->right);
    return this->singleRightRotation(root);
}

int BalancedTreeNode::getHeight(BalancedTreeNode* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return root->height;
}