//
// Created by Lenovo on 2022/9/28.
//

#include "RedBlackTree.h"

template <class Type>
RedBlackTreeNode<Type>::RedBlackTreeNode(Type val)
{
    this->val = val;
    color = BLACK;
}

template <class Type>
RedBlackTreeNode<Type>::~RedBlackTreeNode()
{

}

template <class Type>
RedBlackTree<Type>::RedBlackTree(Type rootVal)
{
    if(this->root == nullptr)
    {
        this->root = new RedBlackTreeNode<Type>(rootVal);
        this->root->color = BLACK;
    }
}

template <class Type>
RedBlackTree<Type>::~RedBlackTree()
{

}

template <class Type>
RedBlackTree<Type> *RedBlackTree<Type>::fixInsert(RedBlackTreeNode<Type> *root)
{
    RedBlackTreeNode<Type>* tmpNode = root;
    RedBlackTreeNode<Type>* uncle;

    while(true)
    {
        if(tmpNode->parent == nullptr)
        {
            break;
        }
        if(tmpNode->parent->color != RED)
        {
            break;
        }
        RedBlackTreeNode<Type>* parent = tmpNode->parent;
        RedBlackTreeNode<Type>* grandParent = tmpNode->parent->parent;
        if(grandParent != nullptr)
        {
            if(parent == grandParent->left)
            {
                uncle = grandParent->right;
                if(uncle != nullptr)
                {
                    //case 1. uncle is RED, set parent and uncle to BLACK
                    //set grandParent to RED, set grandParent as current node
                    if(uncle->color == RED)
                    {
                        uncle->color = BLACK;
                        parent->color = BLACK;
                        grandParent->color = RED;
                        tmpNode = grandParent;
                    }
                    //case 2. uncle is BLACK and tmpNode is parent's right
                    //set parent as tmpNode and leftRotate parent
                    else if(uncle->color == BLACK && tmpNode == parent->right)
                    {
                        tmpNode = tmpNode->parent;
                        singleLeftRotation(tmpNode);
                    }
                    //case 3. uncle is BLACK and tmpNode is parent's left
                    //set parent to BLACK, grandParent to RED and rightRotate grandParent
                    else if(uncle->color == BLACK && tmpNode == parent->left)
                    {
                        parent->color = BLACK;
                        grandParent->color = RED;
                        singleRightRotation(grandParent);
                    }
                }
                else if(uncle == nullptr)
                {
                    if(tmpNode == parent->right)
                    {
                        tmpNode = tmpNode->parent;
                        singleLeftRotation(tmpNode);
                    }
                    else
                    {
                        parent->color = BLACK;
                        grandParent->color = RED;
                        singleRightRotation(grandParent);
                    }
                }
            }
            else if(parent == grandParent->right)
            {
                uncle = grandParent->left;
                if(uncle != nullptr)
                {
                    //case 1. uncle is RED, set parent and uncle to BLACK
                    //set grandParent to RED, set grandParent as current node
                    if(uncle->color == RED)
                    {
                        uncle->color = BLACK;
                        parent->color = BLACK;
                        grandParent->color = RED;
                        tmpNode = grandParent;
                    }
                        //case 2. uncle is BLACK and tmpNode is parent's right
                        //set parent as tmpNode and rightRotate parent
                    else if(uncle->color == BLACK && tmpNode == parent->right)
                    {
                        tmpNode = tmpNode->parent;
                        singleRightRotation(tmpNode);
                    }
                        //case 3. uncle is BLACK and tmpNode is parent's left
                        //set parent to BLACK, grandParent to RED and leftRotate grandParent
                    else if(uncle->color == BLACK && tmpNode == parent->left)
                    {
                        parent->color = BLACK;
                        grandParent->color = RED;
                        singleLeftRotation(grandParent);
                    }
                }
                else if(uncle == nullptr)
                {
                    if(tmpNode == parent->left)
                    {
                        tmpNode = tmpNode->parent;
                        singleRightRotation(tmpNode);
                    }
                    else
                    {
                        parent->color = BLACK;
                        grandParent->color = RED;
                        singleLeftRotation(grandParent);
                    }
                }
            }
        }
    }
    root->color = BLACK;
    return root;
}

template <class Type>
RedBlackTree<Type> *RedBlackTree<Type>::insert(Type val)
{
    RedBlackTreeNode<Type> *tmpNode = this->root;
    while(tmpNode != nullptr)
    {
        if(val > tmpNode->val)
        {
            if(tmpNode->right == nullptr)
            {
                tmpNode->right = new RedBlackTreeNode<Type>(val);
                tmpNode->right->color = RED;
                tmpNode->right->parent = tmpNode;
                if(tmpNode->color == RED)
                {
                    this->fix(tmpNode);
                }
                return root;
            }
            else
            {
                tmpNode = tmpNode->right;
            }
        }
        else if(val < tmpNode->val)
        {
            if(tmpNode->left == nullptr)
            {
                tmpNode->left = new RedBlackTreeNode<Type>(val);
                tmpNode->left->color = RED;
                tmpNode->left->parent = tmpNode;
                if(tmpNode->color == RED)
                {
                    this->fix(tmpNode);
                }
                return root;
            }
            else
            {
                tmpNode = tmpNode->left;
            }
        }
        else
        {
            return nullptr;
        }
    }
}

template <class Type>
RedBlackTree<Type> *RedBlackTree<Type>::singleLeftRotation(RedBlackTreeNode<Type> *root)
{
    RedBlackTreeNode<Type>* right = root->right;
    RedBlackTreeNode<Type>* parent = root->parent;

    root->right = right->left;
    right->parent = parent;

    if(parent == nullptr)
    {
        this->root = right;
    }
    else if(root == parent->left)
    {
        parent->left = right;
    }
    else
    {
        parent->right = right;
    }
    right->left = root;
    root->parent = right;

    root = right;
    return root;
}

template <class Type>
RedBlackTree<Type> *RedBlackTree<Type>::singleRightRotation(RedBlackTreeNode<Type> *root)
{
    RedBlackTreeNode<Type> *left = root->left;
    RedBlackTreeNode<Type> *parent = root->parent;

    root->left = left->right;
    left->parent = parent;

    if(parent == nullptr)
    {
        this->root = left;
    }
    else if(root == parent->right)
    {
        parent->right = left;
    }
    else
    {
        parent->left = left;
    }
    left->right = root;
    root->parent = left;

    root = left;
    return root;
}

template <class Type>
RedBlackTree<Type> *RedBlackTree<Type>::findSuccessorNode(RedBlackTreeNode<Type> *root)
{
    RedBlackTreeNode<Type> *tmpNode = root->right;
    while(tmpNode->left != nullptr)
    {
        tmpNode = tmpNode->left;
    }
    return tmpNode;
}

template <class Type>
RedBlackTree<Type> *RedBlackTree<Type>::fixDelete(RedBlackTreeNode<Type> *root)
{
    while(root != this->root && root->color == BLACK)
    {
        if(root == root->parent->left)
        {
            RedBlackTreeNode<Type> *right = root->parent->right;
            if(right->color == RED)
            {
                right->color = BLACK;
                root->parent->color = RED;
                singleLeftRotation(root->parent);
                right = root->parent->right;
            }
            if(right->left->color == BLACK && right->right->color == BLACK)
            {
                right->color = RED;
                root = root->parent;
            }
            else if(right->right->color == BLACK)
            {

            }
        }
    }
}

template <class Type>
RedBlackTree<Type> *RedBlackTree<Type>::transplant(RedBlackTreeNode<Type> *node1, RedBlackTreeNode<Type> *node2)
{
    //将node1替换为node2
    if(node1->parent == nullptr)
    {
        this->root = node2;
    }
    else if(node1 == node1->parent->left)
    {
        node1->parent->left = node2;
    }
    else if(node1 == node1->parent->right)
    {
        node1->parent->right = node2;
    }
    node2->parent = node1->parent;

    return this->root;
}

template <class Type>
RedBlackTree<Type> *RedBlackTree<Type>::delete_(Type val)
{
    RedBlackTreeNode<Type> *tmpNode = this->root;
    if(tmpNode == nullptr)
    {
        return nullptr;
    }
    while(tmpNode != nullptr && tmpNode->val != val)
    {
        if(val < tmpNode->val)
        {
            tmpNode = tmpNode->left;
        }
        else if(val > tmpNode->val)
        {
            tmpNode = tmpNode->right;
        }
    }

    if(tmpNode != nullptr)
    {
        TreeColor color = tmpNode->color;
        RedBlackTreeNode<Type> *successorNode = tmpNode;
        RedBlackTreeNode<Type> *recNode;//用于记录的节点
        if(tmpNode->right != nullptr)
        {
            recNode = tmpNode->right;
            transplant(tmpNode, tmpNode->right);
        }
        else if(tmpNode->left != nullptr)
        {
            recNode = tmpNode->left;
            transplant(tmpNode, tmpNode->left);
        }
        else
        {
            successorNode = findSuccessorNode(tmpNode->right);
            color = successorNode->color;
            recNode = successorNode->right;
            if(successorNode->parent == tmpNode)//存疑
            {
                recNode->parent = successorNode;
            }
            else
            {
                transplant(successorNode, successorNode->right);
                successorNode->right = tmpNode->right;
                successorNode->right->parent = successorNode;
            }
            transplant(tmpNode, successorNode);
            successorNode->left = tmpNode->left;
            successorNode->left->parent = successorNode;
            successorNode->color = tmpNode->color;
        }
        if(color == BLACK)
        {
            fixDelete(recNode);
        }
    }
    return root;
}
