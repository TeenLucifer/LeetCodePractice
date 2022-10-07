//
// Created by Lenovo on 2022/6/12.
//

//This file is for function test

#include "headers.h"
#include "t-rex.h"

ListNode* createList(vector<int>& nums)
{
    int n = nums.size();
    ListNode* head = nullptr;
    ListNode* node = nullptr;
    ListNode* nodeTmp = nullptr;
    for(int i = 0; i < n; ++i)
    {
        node = new ListNode(nums[i]);
        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            nodeTmp->next = node;
        }
        nodeTmp = node;
        nodeTmp->next = nullptr;
    }
    return head;
}

//字符串数字相乘，相乘后用到字符串相加
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    int carry = 0;
    int i = n2 - 1;
    vector<string> strs;
    while(i >= 0)
    {
        int j = n1 - 1;
        int bit2 = num2[i] - '0';
        string str;
        for(int k = 0; k < n2 - i - 1; ++k)
        {
            str.push_back('0');
        }
        while(j >= 0 || carry != 0)
        {
            int bit1 = j >= 0 ? num1[j] - '0' : 0;
            int product = bit1 * bit2 + carry;
            carry = product / 10;
            str.push_back((product % 10) + '0');
            j--;
        }
        std::reverse(str.begin(), str.end());
        strs.push_back(str);
        i--;
    }

    int add = 0;
    string ans = strs[0];
    for(int k = 1; k < strs.size(); ++k)
    {
        string num_add = strs[i];
        string ans_tmp;
        int i_ = ans.size() - 1;
        int j_ = num_add.size() - 1;
        while (i_ >= 0 || j_ >= 0 || add != 0)
        {
            int bit1_ = i_ >= 0 ? ans[i_] - '0' : 0;
            int bit2_ = j_ >= 0 ? num_add[j_] - '0' : 0;
            int sum = bit1_ + bit2_ + add;
            add = sum / 10;
            ans_tmp.push_back(sum % 10 + '0');
            i_--;
            j_--;
        }
        std::reverse(ans_tmp.begin(), ans_tmp.end());
        ans = ans_tmp;
    }
    return ans;
}

//最长回文子串，用动态规划，注意边界条件和状态转移方程就行
string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    int maxLen = 1;
    int begin = 0;

    for(int i = 0; i < n; ++i)
    {
        dp[i][i] = 1;
    }

    for(int L = 2; L <= n; ++L)
    {
        for(int i = 0; i < n; ++i)
        {
            int j = i + L - 1;
            if(j >= n)
            {
                break;
            }
            if(s[i] != s[j])
            {
                dp[i][j] = false;
            }
            else
            {
                if(j - i < 3)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if(dp[i][j] && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLen);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    vector<int> num1;
    vector<int> num2;
    vector<int> res;
    int add = 0;
    int n1 = 0;
    int n2 = 0;

    while (l1 != nullptr || l2 != nullptr)
    {
        if(l1 != nullptr)
        {
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        if(l2 != nullptr)
        {
            num2.push_back(l2->val);
            l2 = l2->next;
        }
    }

    n1 = num1.size() - 1;
    n2 = num2.size() - 1;
    while(n1 >= 0 || n2 >= 0 || add != 0)
    {
        int bit1 = n1 >= 0 ? num1[n1] : 0;
        int bit2 = n2 >= 0 ? num2[n2] : 0;
        int sum = bit1 + bit2 + add;
        res.push_back(sum % 10);
        add = sum / 10;
        n1--;
        n2--;
    }

    return createList(res);
}

void treeTraversal(TreeNode *tree, TreeOrder order)
{
    if(tree != nullptr)
    {
        if (order == PRE)
        {
            cout << tree->val << " ";
            treeTraversal(tree->left, order);
            treeTraversal(tree->right, order);
        }
        else if(order == MID)
        {
            treeTraversal(tree->left, order);
            cout << tree->val << " ";
            treeTraversal(tree->right, order);
        }
        else if(order == POST)
        {
            treeTraversal(tree->left, order);
            treeTraversal(tree->right, order);
            cout << tree->val << " ";
        }
    }
}

void treeTraversal_iter(TreeNode *root, TreeOrder order)
{
    stack<TreeNode*> stack;
    if(order == PRE)
    {
        stack.push(root);
        while (!stack.empty())
        {
            root = stack.top();
            stack.pop();
            cout << root->val;

            if(root->right != nullptr)
            {
                stack.push(root->right);
            }
            if(root->left != nullptr)
            {
                stack.push(root->left);
            }
        }
    }
    else if(order == MID)
    {
        while (!stack.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            cout << root->val;
            root = root -> right;
        }
    }
    else if(order == POST)
    {
        TreeNode* prev = nullptr;
        while (!stack.empty() ||  root != nullptr)
        {
            while (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(root->right == nullptr || root->right == prev)
            {
                cout << root->val;
                prev = root;
                root = nullptr;
            }
            else
            {
                stack.push(root);
                root = root->right;
            }
        }
    }
}

void quickSort(vector<int> nums, int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int i = low;
    int j = high;
    int pivot = nums[i];

    while(i < j)
    {
        while(i < j && pivot <= nums[j])
        {
            j--;
        }
        nums[i] = nums[j];
        while(i < j && pivot >= nums[i])
        {
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    quickSort(nums, low, i - 1);
    quickSort(nums, i + 1, high);
}

