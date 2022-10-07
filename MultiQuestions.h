//
// Created by Lenovo on 2022/6/10.
//

#ifndef DATASTRUCTURE_MULTIQUESTIONS_H
#define DATASTRUCTURE_MULTIQUESTIONS_H

#include "headers.h"

class MultiQuestions
{
public:
    MultiQuestions();
    ~MultiQuestions();

    vector<int> question238(vector<int>& nums);
    int question560(vector<int>& nums, int k);
    ListNode* question160_method1(ListNode *headA, ListNode *headB);//哈希
    ListNode* question160_method2(ListNode *headA, ListNode *headB);//双指针
    vector<int> question763(string s);
    vector<vector<string>> question49(vector<string>& strs);
    string question43(string num1, string num2);
    vector<string> question187(string s);
    string question5(string s);
    ListNode* question2(ListNode* l1, ListNode* l2);
    ListNode* question142_method1(ListNode* head);//哈希表，用ListNode类型作为key
    ListNode* question142_method2(ListNode* head);//双指针法
    ListNode* question82(ListNode* head);
    ListNode* question24(ListNode* head);
    ListNode* question25(ListNode* head, int k);
    ListNode* question25_2(ListNode* head, int k);
    void question143(ListNode* head);
    string question1249(string s);
    int question1823(int n, int k);
    TreeNode* question108(vector<int>& nums);
    TreeNode* question105(vector<int>& preorder, vector<int>& inorder);
    TreeNode* question106(vector<int>& inorder, vector<int>& postorder);
    bool question217(vector<int>& nums);
    int question53(vector<int>& nums);
    vector<int> question1(vector<int>& nums, int target);
    int question509(int n);
    int question70(int n);
    int question746(vector<int>& cost);
    int question62(int m, int n);
    int question63(vector<vector<int>>& obstacleGrid);
    int question343(int n);
    void question88(vector<int>& nums1, int m, vector<int>& nums2, int n);
    vector<int> question350(vector<int>& nums1, vector<int>& nums2);
    int question121(vector<int>& prices);
    vector<vector<int>> question566(vector<vector<int>>& mat, int r, int c);
    vector<vector<int>> question118(int numRows);
    bool question36(vector<vector<char>>& board);
    void question73(vector<vector<int>>& matrix);
    int question387(string s);
    bool question383(string ransomNote, string magazine);
    bool question242(string s, string t);
    int question96(int n);
    bool question416(vector<int>& nums);
    bool question141(ListNode* head);
    ListNode* question21(ListNode* head1, ListNode* head2);
    ListNode* question203(ListNode* head, int val);
    ListNode* question206(ListNode* head);
    ListNode* question83(ListNode* head);
    bool question20(string s);
    vector<int> question144(TreeNode* root);
    vector<int> question145(TreeNode* root);
    vector<int> question94(TreeNode* root);
    vector<int> question34(vector<int>& nums, int target);
    vector<int> question34_method2(vector<int>& nums, int target);//二分查找
    int question33(vector<int>& nums, int target);
    bool question74(vector<vector<int>>& nums, int target);
    int question153(vector<int>& nums, int target);
    int question162(vector<int>& nums);
    int question162_method2(vector<int>& nums);
    bool question844(string s, string t);
    bool question844_method2(string s, string t);
    vector<vector<int>> question986(vector<vector<int>>& firstList, vector<vector<int>>& secondList);
    vector<vector<int>> question986_method2(vector<vector<int>>& firstList, vector<vector<int>>& secondList);
    int question11(vector<int>& height);
    int question11_method2(vector<int>& height);
    vector<int> question438(string s, string p);
    vector<int> question438_method2(string s, string p);
    int question713(vector<int>& nums, int k);
    int question209(int target, vector<int>& nums);
    int question198(vector<int>& nums);
    int question213(vector<int>& nums);
    bool question55(vector<int>& nums);
    int question45(vector<int>& nums);
    vector<string> question22(int n);
    int question413(vector<int>& nums);
    int question91(string s);
    vector<vector<int>> question15(vector<int> nums);
    vector<vector<int>> question56(vector<vector<int>> intervals);
    vector<int> question119(int rowInex);
    vector<vector<int>> question59(int n);
    bool question240(vector<vector<int>>& matrix, int target);
    int question435(vector<vector<int>>& intervals);
    bool question334(vector<int>& nums);
    string question415(string num1, string num2);
    int question458(string s);
    bool question290(string pattern, string s);
    vector<vector<int>> question103(TreeNode* root);
    vector<TreeNode*> question95(int n);
    bool question98(TreeNode* root);
    void question99(TreeNode* root);
    TreeNode* question450(TreeNode* root, int key);//delete
    TreeNode* question700(TreeNode* root, int key);//search
    TreeNode* question701(TreeNode* root, int key);//add
    bool question110(TreeNode* root);
    bool question100(TreeNode* root1, TreeNode* root2);
    bool question101(TreeNode* root);
    vector<vector<int>> question102(TreeNode* root);
    vector<vector<int>> question107(TreeNode* root);
    vector<int> question199(TreeNode* root);
    vector<double> question637(TreeNode* root);
    vector<vector<int>> question429(N_ARY_TREE::Node* root);
    vector<int> question515(TreeNode* root);
    BINARY_TREE::Node* question116(BINARY_TREE::Node* root);
    BINARY_TREE::Node* question117(BINARY_TREE::Node* root);
    int question104(TreeNode* root);
    int question111(TreeNode* root);
    int question153(vector<int> &nums);
    bool question112(TreeNode* root, int targetSum);
    vector<vector<int>> question113(TreeNode* root, int targetSum);
    int question124(TreeNode* root);//深度优先搜索
    int question200_BFS(vector<vector<char>>& grid);
    int question200_DFS(vector<vector<char>>& grid);
    int question547_BFS(vector<vector<int>>& isConnected);
    int question547_DFS(vector<vector<int>>& isConnected);

    template<typename T1, typename T2>
    void quickSort(T1& array, int low, int high);
    //需要先把nums排成有序才能构建二叉搜索树
    TreeNode* buildBinarySearchTree(vector<int> &nums, int low, int high);

private:
    void interval_quickSort(vector<vector<int>>& intervals, int low, int high);

    template<typename T1, typename T2>
    int binarySearch(T1& array, int low, int high, T2 target);
    int binarySearch(vector<int> array, int low, int high, int target);

    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail);
    TreeNode* helper108(vector<int> &nums, int low, int high);
    TreeNode* myBuildTree(unordered_map<int, int>& index, const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right);
    void preOrder(TreeNode* root, vector<int> &res);
    void postOrder(TreeNode* root, vector<int> &res);
    void midOrder(TreeNode* root, vector<int> &res);
    vector<TreeNode*> generateTrees(int start, int end);
    bool helper98(TreeNode *root, long long& preVal);
    void helper99(TreeNode *root, TreeNode* &preNode, TreeNode* &node1, TreeNode* &node2, bool &flag);
    TreeNode* helper700(TreeNode *root, int key);
    int helper110(TreeNode* root);
    bool helper100(TreeNode* root1, TreeNode* root2);
    bool helper101(TreeNode* left, TreeNode* right);
    TreeNode* helper106(vector<int> &inorder, vector<int> &postorder);
    bool helper112(TreeNode* root, int targetSum);
    void helper113(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> &path);
    int helper124(TreeNode* root, int &sum);
    void helper200_BFS(vector<vector<char>>& grid, vector<vector<int>>& map, int x, int y);
    void helper200_DFS(vector<vector<char>>& grid, vector<vector<int>>& map, int x, int y);
    int helper547_BFS(vector<vector<int>>& isConnected, vector<int>& visited, int x, int y);
    void helper547_DFS(vector<vector<int>>& isConnected, vector<int>& visited, int x, int y);
    int getTreeHeight(TreeNode* node);
};

#endif //DATASTRUCTURE_MULTIQUESTIONS_H
