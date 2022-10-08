#include "MultiQuestions.h"
#include "t-rex.h"//for test

int main()
{
    MultiQuestions *multiQuestions = new MultiQuestions();
    TreeNode* node0 = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    node0->left = node1;
    node0->right = node2;

    multiQuestions->question129(node0);
    return 0;
}
