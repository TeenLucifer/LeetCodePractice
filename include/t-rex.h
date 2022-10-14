//
// Created by Lenovo on 2022/9/15.
//

#ifndef DATASTRUCTURE_T_REX_H
#define DATASTRUCTURE_T_REX_H

#include "headers.h"

enum TreeOrder
{
    PRE = 0,
    MID,
    POST
};
#define ORDER POST

void treeTraversal(TreeNode *tree, TreeOrder order);
void treeTraversal_iter(TreeNode *tree, TreeOrder order);

void quickSort(vector<int> nums, int low, int high);

#endif //DATASTRUCTURE_T_REX_H
