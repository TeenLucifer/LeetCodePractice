//
// Created by Lenovo on 2022/9/28.
//

#ifndef DATASTRUCTURE_REDBLACKTREE_H
#define DATASTRUCTURE_REDBLACKTREE_H

#include <vector>

enum TreeColor
{
    RED,
    BLACK
};

template <class Type>
class RedBlackTreeNode
{
public:
    RedBlackTreeNode(Type val);
    ~RedBlackTreeNode();

private:
    RedBlackTreeNode* left;
    RedBlackTreeNode* right;
    RedBlackTreeNode* parent;
    Type val;
    TreeColor color;
};

template<class Type>
class RedBlackTree
{
public:
    RedBlackTree(Type rootVal);
    ~RedBlackTree();

    RedBlackTree* findMin(RedBlackTreeNode<Type>* root);
    RedBlackTree* findMax(RedBlackTreeNode<Type>* root);
    RedBlackTree* fixInsert(RedBlackTreeNode<Type>* root);
    RedBlackTree* findSuccessorNode(RedBlackTreeNode<Type> *root);
    RedBlackTree* insert(Type val);
    RedBlackTree* transplant(RedBlackTreeNode<Type>* node1, RedBlackTreeNode<Type>* node2);
    RedBlackTree* fixDelete(RedBlackTreeNode<Type>* root);
    RedBlackTree* delete_(Type val);
    RedBlackTree* create(std::vector<Type> nums);
    RedBlackTree* singleLeftRotation(RedBlackTreeNode<Type>* root);
    RedBlackTree* singleRightRotation(RedBlackTreeNode<Type>* root);
    RedBlackTree* doubleLeftRightRotation(RedBlackTreeNode<Type>* root);
    RedBlackTree* doubleRightLeftRotation(RedBlackTreeNode<Type>* root);
    int getHeight(RedBlackTree* root);

private:
    RedBlackTreeNode<Type> *root;
    int height;
};


#endif //DATASTRUCTURE_REDBLACKTREE_H
