//
// Created by Lenovo on 2022/6/10.
//

#include "MultiQuestions.h"
#include <algorithm>
#include <cmath>

MultiQuestions::MultiQuestions()
{}

MultiQuestions::~MultiQuestions()
{}

template <typename T1, typename T2>
void MultiQuestions::quickSort(T1& array, int low, int high)
{
    if(low >= high)
    {
        return;
    }

    int i = low;
    int j = high;
    T2 pivot = array[low];

    while(i < j)
    {
        while(i < j && array[j] >= pivot)
        {
            j--;
        }
        array[i] = array[j];
        while(i < j && array[i] <= pivot)
        {
            i++;
        }
        array[j] = array[i];
    }
    array[i] = pivot;
    quickSort<T1, T2>(array, low, i - 1);
    quickSort<T1, T2>(array, i + 1, high);
}

void MultiQuestions::interval_quickSort(vector<vector<int>> &intervals, int low, int high)
{
    if(low >= high)
    {
        return;
    }

    int i = low;
    int j = high;
    vector<int> pivot = intervals[i];
    while(i < j)
    {
        while(intervals[j][0] > pivot[0] && i < j)
        {
            --j;
        }
        intervals[i] = intervals[j];
        while(intervals[i][0] <= pivot[0] && i < j)
        {
            ++i;
        }
        intervals[j] = intervals[i];
    }
    intervals[i] = pivot;
    interval_quickSort(intervals, low, i - 1);
    interval_quickSort(intervals, i + 1, high);
}

template <typename T1, typename T2>
int MultiQuestions::binarySearch(T1 &nums, int low, int high, T2 target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(nums[mid] > target)
        {
            high = mid - 1;
        }
        else if(nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int MultiQuestions::binarySearch(vector<int> nums, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(nums[mid] > target)
        {
            high = mid - 1;
        }
        else if(nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int MultiQuestions::getTreeHeight(TreeNode *root)
{
    queue<TreeNode*> que;
    int height = 0;
    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        int size = que.size();
        for(int i = 0; i < size; ++i)
        {
            TreeNode* node = que.front();
            que.pop();

            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
        height++;
    }
    return height;
}

TreeNode* MultiQuestions::buildBinarySearchTree(vector<int> &nums, int low, int high)
{
    if(low > high)
    {
        return nullptr;
    }
    int mid = (low + high) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = buildBinarySearchTree(nums, low, mid - 1);
    node->right = buildBinarySearchTree(nums, mid + 1, high);
    return node;
}

vector<int> MultiQuestions::question238(vector<int> &nums)
{
    int n = nums.size();
    vector<int> productVec(n);

    int rightRes= 1;
    productVec[0] = 1;
    for(int i = 1; i < n; ++i)
    {
        productVec[i] = productVec[i - 1] * nums[i - 1];
    }
    for(int i = n - 1; i >= 0; --i)
    {
        productVec[i] = productVec[i] * rightRes;
        rightRes = rightRes * nums[i];
    }

    return productVec;
}

int MultiQuestions::question560(vector<int> &nums, int k)
{
    int n = nums.size();
    int pre = 0;
    int cnt = 0;
    unordered_map<int, int> hashTab;

    hashTab[0] = 1;
    for(int i = 0; i < n; ++i)
    {
        pre += nums[i];

        if(hashTab.find(pre - k) != hashTab.end())
        {
            cnt += hashTab[pre - k];
        }
        hashTab[pre]++;
    }
    return cnt;
}

ListNode* MultiQuestions::question160_method1(ListNode *headA, ListNode *headB)
{
    ListNode* node;
    return node;
}

ListNode* MultiQuestions::question160_method2(ListNode *headA, ListNode *headB)
{
    if(headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }

    ListNode *pA = headA;
    ListNode *pB = headB;

    while(pA != pB)
    {
        pA = (pA == nullptr ? headB : pA->next);
        pB = (pB == nullptr ? headA : pB->next);
    }

    return pA;
}

vector<int> MultiQuestions::question763(string s)
{
    vector<int> res;
    int n = s.size();
    int endList[26] = {-1};
    for(int i = 0; i < n; ++i)
    {
        int ch = s[i] - 'a';
        endList[ch] = endList[ch] > i ? endList[ch] : i;
    }
    int sectionStart = 0;
    int sectionEnd = 0;
    for(int i = 0; i < n; ++i)
    {
        int ch = s[i] - 'a';
        int end_c = endList[ch];
        sectionEnd = sectionEnd > end_c ? sectionEnd : end_c;

        if(i == sectionEnd)
        {
            int length = sectionEnd - sectionStart + 1;
            res.push_back(length);
            sectionStart = sectionEnd + 1;
        }
    }
    return res;
}

vector<vector<string>> MultiQuestions::question49(vector<string> &strs)
{
    int n = strs.size();
    unordered_map<string, vector<string>> hashTab;
    for(int i = 0; i < n; ++i)
    {
        string str = strs[i];
        string key = str;
        sort(key.begin(), key.end());
        hashTab[key].emplace_back(str);
    }
    vector<vector<string>> res;
    for(auto iter = hashTab.begin(); iter != hashTab.end(); ++iter)
    {
        res.emplace_back(iter->second);
    }

    return res;
}

string MultiQuestions::question43(string num1, string num2)
{
    if(num1 == "0" || num2 == "0")
    {
        return "0";
    }
    int n1 = num1.size();
    int n2 = num2.size();
    vector<string> strs;

    int i = n2 - 1;
    int carry = 0;
    while(i >= 0)
    {
        int bit2 = num2[i] - '0';
        string str;
        int j = n1 - 1;
        for(int k = 0; k < n2 - i - 1; ++k)
        {
            str.push_back('0');
        }
        while(j >= 0 || carry > 0)
        {
            int bit1 = j >= 0 ? num1[j] - '0' : 0;
            int product = bit2 * bit1 + carry;
            carry = product / 10;
            str.push_back(product % 10 + '0');
            j--;
        }
        std::reverse(str.begin(), str.end());
        strs.push_back(str);
        i--;
    }

    int add = 0;
    string resultString = strs[0];
    for(int k = 1; k < strs.size(); ++k)
    {
        string resTmp;
        string str = strs[k];
        int i_ = resultString.size() - 1;
        int j_ = str.size() - 1;
        while(i_ >= 0 || j_ >= 0 || add > 0)
        {
            int bit1 = i_ >= 0 ? resultString[i_] - '0' : 0;
            int bit2 = j_ >= 0 ? str[j_] - '0' : 0;
            int sum = bit1 + bit2 + add;
            add = sum / 10;
            resTmp.push_back(sum % 10 + '0');
            i_--;
            j_--;
        }
        std::reverse(resTmp.begin(), resTmp.end());
        resultString = resTmp;
    }
    return resultString;
}

vector<string> MultiQuestions::question187(string s)
{
    const int L = 10;
    unordered_map<char, int> bin{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    unordered_map<int, char> reverseBin{{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};
    unordered_map<int, int> hashTab;
    int key = 0;
    int n = s.size();
    vector<string> strs;

    for(int i = 0; i < L - 1; ++i)
    {
        key = (key << 2) | bin[s[i]];
    }
    for(int i = 0; i <= n - L; ++i)
    {
        key = ((key << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1);//位与后面一串是为了保留低20位，清除高位
        hashTab[key]++;
    }
    for(auto iter = hashTab.begin(); iter != hashTab.end(); ++iter)
    {
        if(iter->second >= 2)
        {
            string str;
            for(int i = L - 1; i >= 0; --i)
            {
                char ch = reverseBin[(iter->first >> (i * 2)) & (3)];
                str.push_back(ch);
            }
            strs.push_back(str);
        }
    }
    return strs;
}

string MultiQuestions::question5(string s)
{
    int n = s.size();
    if (n < 2)
    {
        return s;
    }

    int maxLen = 1;
    int begin = 0;
    // dp[i][j] 表示 s[i..j] 是否是回文串
    vector<vector<int>> dp(n, vector<int>(n));
    // 初始化：所有长度为 1 的子串都是回文串
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    // 递推开始
    // 先枚举子串长度
    for (int L = 2; L <= n; L++)
    {
        // 枚举左边界，左边界的上限设置可以宽松一些
        for (int i = 0; i < n; i++)
        {
            // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
            int j = L + i - 1;
            // 如果右边界越界，就可以退出当前循环
            if (j >= n)
            {
                break;
            }

            if (s[i] != s[j])
            {
                dp[i][j] = false;
            }
            else
            {
                if (j - i < 3)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
            if (dp[i][j] && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLen);
}

ListNode* MultiQuestions::question2(ListNode *l1, ListNode *l2)
{
    vector<int> numList1;
    vector<int> numList2;
    while(l1 != nullptr || l2 != nullptr)
    {
        if(l1 != nullptr)
        {
            numList1.push_back(l1->val);
        }
        if(l2 != nullptr)
        {
            numList2.push_back(l2->val);
        }

        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
    }

    vector<int> nums;
    int n1 = numList1.size();
    int n2 = numList2.size();
    int i = 0;
    int j = 0;
    int add = 0;
    while(i < n1 || j < n2 || add > 0)
    {
        int bit1 = i < n1 ? numList1[i] : 0;
        int bit2 = j < n2 ? numList2[j] : 0;
        int sum = bit1 + bit2 + add;
        nums.push_back(sum % 10);
        add = sum / 10;
        i++;
        j++;
    }

    return createList(nums);
}

ListNode* MultiQuestions::question142_method1(ListNode *head)
{
    ListNode* node = head;
    unordered_set<ListNode*> visited;
    while(node != nullptr)
    {
        if(visited.count(node))
        {
            return node;
        }
        visited.insert(node);
        node = node->next;
    }
    return nullptr;
}

ListNode* MultiQuestions::question142_method2(ListNode *head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* ptr = head;

    while(fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }
        if(fast == slow)
        {
            break;
        }
    }
    while(ptr != slow)
    {
        slow = slow->next;
        ptr = ptr->next;
    }
    return ptr;
}

ListNode* MultiQuestions::question82(ListNode *head)
{
    if(!head)
    {
        return head;
    }

    ListNode* dummy = new ListNode(0, head);

    ListNode* cur = dummy;
    while(cur->next && cur->next->next)
    {
        if(cur->next->val == cur->next->next->val)
        {
            int x = cur->next->val;
            while(cur->next && cur->next->val == x)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }

    return dummy->next;
}

ListNode* MultiQuestions::question24(ListNode *head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *newHead = head->next;
    head->next = question24(head);
    newHead->next = head;
    return newHead;
}

ListNode* MultiQuestions::question25(ListNode *head, int k)
{
    ListNode* dummyHead = new ListNode(0, head);
    ListNode* preNode = dummyHead;

    ListNode* start = head;
    ListNode* end = dummyHead;

    while(start)
    {
        end = preNode;
        for(int i = 0; i < k; ++i)
        {
            end = end->next;
            if(end == nullptr)
            {
                return dummyHead->next;
            }
        }

        //子问题，翻转链表，start-end之间的子数组
        ListNode* next = end->next;
        ListNode* prev = end->next;
        ListNode* curr = start;
        while(prev != end)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        preNode->next = end;
        start->next = next;
        preNode = start;
        start = start->next;
    }
    return dummyHead->next;
}

pair<ListNode*, ListNode*> MultiQuestions::myReverse(ListNode *head, ListNode *tail)
{
    ListNode* prev = tail->next;
    ListNode* p = head;
    while (prev != tail)
    {
        ListNode* nex = p->next;
        p->next = prev;
        prev = p;
        p = nex;
    }
    return {tail, head};
}

ListNode* MultiQuestions::question25_2(ListNode *head, int k)
{
    ListNode* hair = new ListNode(0);
    hair->next = head;
    ListNode* pre = hair;

    while (head)
    {
        ListNode* tail = pre;
        // 查看剩余部分长度是否大于等于 k
        for (int i = 0; i < k; ++i)
        {
            tail = tail->next;
            if (!tail)
            {
                return hair->next;
            }
        }
        ListNode* nex = tail->next;
        // 这里是 C++17 的写法，也可以写成
        // pair<ListNode*, ListNode*> result = myReverse(head, tail);
        // head = result.first;
        // tail = result.second;
        tie(head, tail) = myReverse(head, tail);
        // 把子链表重新接回原链表
        pre->next = head;
        tail->next = nex;
        pre = tail;
        head = tail->next;
    }

    return hair->next;
}

void MultiQuestions::question143(ListNode *head)
{
    ListNode* node = head;
    vector<ListNode*> listVec;
    int i = 0;
    int j = 0;
    while(node != nullptr)
    {
        listVec.push_back(node);
        node = node->next;
    }
    i = 0;
    j = listVec.size() - 1;
    while(i < j)
    {
        listVec[i]->next = listVec[j];
        i++;
        if(i == j)
        {
            break;
        }
        listVec[j]->next = listVec[i];
        j--;
    }
    listVec[i]->next = nullptr;
}

string MultiQuestions::question1249(string s)
{
    vector<int> vec1;
    vector<int> vec2;
    int n = s.size();
    string str;

    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '(')
        {
            vec1.push_back(i);
        }
        if(s[i] == ')')
        {
            if(vec1.empty())
            {
                vec2.push_back(i);
            }
            else
            {
                vec1.pop_back();
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(!(std::count(vec1.begin(), vec1.end(), i) || std::count(vec2.begin(), vec2.end(), i)))
        {
            str.push_back(s[i]);
        }
    }
    return str;
}

int MultiQuestions::question1823(int n, int k)
{
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        for (int i = 0; i < k; ++i)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

TreeNode* MultiQuestions::helper108(vector<int> &nums, int low, int high)
{
    if(low > high)
    {
        return nullptr;
    }
    int mid = (low + high) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = helper108(nums, low, mid - 1);
    node->right = helper108(nums, mid + 1, high);
    return node;
}

TreeNode* MultiQuestions::question108(vector<int> &nums)
{
   return helper108(nums, 0, nums.size() - 1);
}

TreeNode* MultiQuestions::myBuildTree(unordered_map<int, int>& index, const vector<int> &preorder, const vector<int> &inorder, int preorder_left,
                                      int preorder_right, int inorder_left, int inorder_right)
{
    if(preorder_left > preorder_right)
    {
        return nullptr;
    }

    int preorder_root = preorder_left;//preorder_root和inorder_root指的是idx而不是元素
    int inorder_root = index[preorder[preorder_root]];//中序遍历根节点的idx
    TreeNode* root = new TreeNode(preorder[preorder_root]);
    int size_left_subtree = inorder_root - inorder_left;
    root->left = myBuildTree(index, preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    root->right = myBuildTree(index, preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    return root;
}

TreeNode* MultiQuestions::question105(vector<int>& preorder, vector<int>& inorder)
{
    unordered_map<int, int> index;
    int n = preorder.size();
    for(int i = 0; i < n; ++i)
    {
        index[inorder[i]] = i;
    }
    return myBuildTree(index, preorder, inorder, 0, n - 1, 0, n - 1);
}

TreeNode* MultiQuestions::helper106(vector<int> &inorder, vector<int> &postorder)
{
    if(postorder.size() == 0)
    {
        return nullptr;
    }

    int inSize = inorder.size();
    int postSize = postorder.size();
    int pivot = postorder[postSize - 1];
    int inorder_idx = 0;
    TreeNode *node = new TreeNode(pivot);

    if(postorder.size() == 1)
    {
        return node;
    }

    for(int i = 0; i < inSize; ++i)
    {
        if(pivot == inorder[i])
        {
            inorder_idx = i;
            break;
        }
    }

    vector<int> inorder_left(inorder.begin(), inorder.begin() + inorder_idx);
    vector<int> inorder_right(inorder.begin() + inorder_idx + 1, inorder.end());

    vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
    vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.end() - 1);

    node->left = helper106(inorder_left, postorder_left);
    node->right = helper106(inorder_right, postorder_right);

    return node;
}

TreeNode* MultiQuestions::question106(vector<int> &inorder, vector<int> &postorder)
{
    if(inorder.size() == 0 || postorder.size() == 0)
    {
        return nullptr;
    }
    return helper106(inorder, postorder);
}

bool MultiQuestions::question217(vector<int>& nums)
{
    unordered_map<int, int> hashTab;
    int n = nums.size();
    for(int i = 0; i < n; ++i)
    {
        hashTab[nums[i]]++;
        if(hashTab[nums[i]] >= 2)
        {
            return true;
        }
    }
    return false;
}

int MultiQuestions::question53(vector<int> &nums)
{
    int pre = 0;
    int maxAns = nums[0];
    int n = nums.size();
    for(int i = 0; i < n; ++i)
    {
        int x = nums[i];
        pre = (pre + x) > x ? (pre + x) : x;
        maxAns = maxAns > pre ? maxAns : pre;
    }
    return maxAns;
}

vector<int> MultiQuestions::question1(vector<int>& nums, int target)
{
    unordered_map<int, int> hashTab;
    int n = nums.size();

    for(int i = 0; i < n; ++i)
    {
        hashTab[nums[i]] = i;
    }
    for(int i = 0; i < n; ++i)
    {
        if(hashTab.count(target - nums[i]))
        {
            hashTab[target - nums[i]];
            return vector<int>(nums[i], target - nums[i]);
        }
    }
}

int MultiQuestions::question509(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    int F0 = 0;
    int F1 = 1;
    int prePre = F0;
    int pre = F1;
    int Fn = 0;
    for(int i = 2; i <= n; ++i)
    {
        Fn = prePre + pre;
        prePre = pre;
        pre = Fn;
    }
    return Fn;
}

int MultiQuestions::question70(int n)
{
    int F1 = 1;
    int F2 = 2;
    int prePre = F1;
    int pre = F2;
    int Fn = 0;
    if(n < 3)
    {
        Fn = n;
    }
    for(int i = 3; i <= n; ++i)
    {
        Fn = prePre + pre;
        prePre = pre;
        pre = Fn;
    }
    return Fn;
}

int MultiQuestions::question746(vector<int>& cost)
{
    int n = cost.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; ++i)
    {
        cost[i - 1];
        dp[i] = min({dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]});
    }
    return dp[n];
}

int MultiQuestions::question62(int m, int n)
{
    vector<vector<int>> f(m, vector<int>(n));
    f[0][0] = 1;
    for(int i = 0; i < m; ++i)
    {
        f[i][0] = 1;
    }
    for(int i = 0; i < n; ++i)
    {
        f[0][i] = 1;
    }
    for(int i = 1; i < m; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}

int MultiQuestions::question63(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> f(m, vector<int>(n));
    f[0][0] = 1;
    for(int i = 0; i < m; ++i)
    {
        f[i][0] = (obstacleGrid[i][0] == 1) ? 0 : 1;
    }
    for(int i = 0; i < n; ++i)
    {
        f[0][i] = (obstacleGrid[0][i] == 1) ? 0 : 1;
    }
    for(int i = 1; i < m; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            f[i][j] = (obstacleGrid[i][j] == 1) ? 0 : (f[i - 1][j] + f[i][j - 1]);
        }
    }
    return f[m - 1][n - 1];
}

int MultiQuestions::question343(int n)
{
    vector<int> dp(n + 1);
    for(int i = 2; i <= n; ++i)
    {
        int curMax = 0;
        for(int j = 1; j < i; ++j)
        {
            curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
        }
        dp[i] = curMax;
    }
    return dp[n];
}

void MultiQuestions::question88(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int ptr1 = 0;
    int ptr2 = 0;
    vector<int> res;

    while(ptr1 != m || ptr2 != n)
    {
        int num = 0;
        if(ptr1 >= m)
        {
            num = nums2[ptr2];
            ptr2++;
        }
        else if(ptr2 >= n)
        {
            num = nums1[ptr1];
            ptr1++;
        }
        else
        {
            num = nums1[ptr1] < nums2[ptr2] ? nums1[ptr1++] : nums2[ptr2++];
        }
        res.push_back(num);
    }
    nums1 = res;
}

vector<int> MultiQuestions::question350(vector<int> &nums1, vector<int> &nums2)
{
    if(nums1.size() > nums2.size())
    {
        return question350(nums2, nums1);
    }
    unordered_map<int, int> hashTab;
    vector<int> res;
    int n = nums1.size();
    int m = nums2.size();

    for(int i = 0; i < n; ++i)
    {
        hashTab[nums1[i]]++;
    }
    for(int i = 0; i < m; ++i)
    {
        if(hashTab.count(nums2[i]))
        {
            hashTab[nums2[i]]--;
            res.push_back(nums2[i]);
        }
    }
    return res;
}

int MultiQuestions::question121(vector<int> &prices)
{
    int maxProfit = 0;
    int minPrice = INFINITY;
    int n = prices.size();

    for(int i = 0; i < n; ++i)
    {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

vector<vector<int>> MultiQuestions::question566(vector<vector<int>> &mat, int r, int c)
{
    vector<vector<int>> resMat(r, vector<int>(c));
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n * m; ++i)
    {
        resMat[i / c][i % c] = mat[i / m][i % m];
    }

    return resMat;
}

vector<vector<int>> MultiQuestions::question118(int numRows)
{
    vector<vector<int>> triangle;
    for(int i = 0; i <= numRows; ++i)
    {
        vector<int> row;
        for(int j = 0; j <= i; ++j)
        {
            int num = 0;
            if(j == 0 || j == i)
            {
                num = 1;
            }
            else
            {
                num = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            row.push_back(num);
        }
        triangle.push_back(row);
    }
    return triangle;
}

bool MultiQuestions::question36(vector<vector<char>> &board)
{
    int rows[9][9];
    int cols[9][9];
    int subBoxes[3][3][9];
    int n = board.size();
    int m = board[0].size();

    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    memset(subBoxes, 0, sizeof(subBoxes));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1;
                rows[i][num]++;
                cols[j][num]++;
                subBoxes[i / 3][j / 3][num]++;
                if(rows[i][num] > 1 || cols[j][num] > 1 || subBoxes[i / 3][j / 3][num] > 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void MultiQuestions::question73(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row, col;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = col[j] = true;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int MultiQuestions::question387(string s)
{
    unordered_map<char, int> hashTab;
    int n = s.size();

    for(int i = 0; i < n; ++i)
    {
        hashTab[s[i]]++;
    }
    for(int i = 0; i < n; ++i)
    {
        if(hashTab[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

bool MultiQuestions::question383(string ransomNote, string magazine)
{
    int n = ransomNote.size();
    int m = magazine.size();
    if(m < n)
    {
        return false;
    }

    unordered_map<char, int> hashTab;
    for(int i = 0; i < m; ++i)
    {
        hashTab[magazine[i]]++;
    }
    for(int i = 0; i < n; ++i)
    {
        if(hashTab.count(ransomNote[i]))
        {
            hashTab[ransomNote[i]]--;
            if(hashTab[ransomNote[i]] < 0)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool MultiQuestions::question242(string s, string t)
{
    unordered_map<char, int> hashTab;
    int n = s.size();
    int m = t.size();
    if(n != m)
    {
        return false;
    }

    for(int i = 0; i < n; ++i)
    {
        hashTab[s[i]]++;
    }
    for(int i = 0; i < m; ++i)
    {
        if(hashTab.count(t[i]))
        {
            hashTab[t[i]]--;
            if(hashTab[t[i]] < 0)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

int MultiQuestions::question96(int n)
{
    vector<int> G(n + 1);
    G[0] = 1;
    G[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}

bool MultiQuestions::question416(vector<int> &nums)
{
    return true;
}

bool MultiQuestions::question141(ListNode *head)
{
    ListNode* fastPtr;
    ListNode* slowPtr;

    do
    {
        if(fastPtr == nullptr || slowPtr == nullptr || fastPtr->next == nullptr)
        {
            return false;
        }
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }while(fastPtr != slowPtr);

    return true;
}

ListNode* MultiQuestions::question21(ListNode *head1, ListNode *head2)
{
    ListNode* ptr1 = head1;
    ListNode* ptr2 = head2;
    ListNode* res = new ListNode(-1);
    ListNode* preNode = res;

    while(ptr1 != nullptr && ptr2 != nullptr)
    {
        if(ptr1->val >= ptr2->val)
        {
            preNode->next = ptr2;
            ptr2 = ptr2->next;
        }
        else
        {
            preNode->next = ptr1;
            ptr1 = ptr1->next;
        }
        preNode = preNode->next;
    }
    preNode->next = ptr1 == nullptr ? ptr2 : ptr1;

    return res;
}

ListNode* MultiQuestions::question203(ListNode *head, int val)
{
    ListNode* dummyHead = new ListNode(-1);
    ListNode* node = dummyHead;
    dummyHead->next = head;

    while(node->next != nullptr)
    {
        if(node->next->val == val)
        {
            node->next = node->next->next;
        }
        else
        {
            node = node->next;
        }
    }
    return dummyHead->next;
}

ListNode* MultiQuestions::question206(ListNode *head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr->next != nullptr)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* MultiQuestions::question83(ListNode* head)
{
    unordered_map<int, int> hashTab;
    ListNode* dummyHead = new ListNode(-1);
    ListNode* node = dummyHead;
    dummyHead->next = head;
    while(node->next != nullptr)
    {
        hashTab[node->next->val]++;
        if(hashTab[node->next->val] > 1)
        {
            node->next = node->next->next;
        }
        else
        {
            node = node->next;
        }
    }

    return dummyHead->next;
}

bool MultiQuestions::question20(string s)
{
    int n = s.size();
    if (n % 2 == 1)
    {
        return false;
    }

    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
    };
    vector<char> stk;
    for (char ch : s)
    {
        if (pairs.count(ch))
        {
            if (stk.empty() || stk[stk.size() - 1] != pairs[ch])
            {
                return false;
            }
            stk.pop_back();
        }
        else
        {
            stk.push_back(ch);
        }
    }
    return stk.empty();
}

void MultiQuestions::preOrder(TreeNode *root, vector<int> &res)
{
    if(root == nullptr)
    {
        return;
    }
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

vector<int> MultiQuestions::question144(TreeNode *root)
{
    vector<int> res;
    preOrder(root, res);
    return res;
}

void MultiQuestions::postOrder(TreeNode *root, vector<int> &res)
{
    if(root == nullptr)
    {
        return;
    }
    postOrder(root->right, res);
    postOrder(root->left, res);
    res.push_back(root->val);
}

vector<int> MultiQuestions::question145(TreeNode *root)
{
    vector<int> res;
    postOrder(root, res);
    return res;
}

void MultiQuestions::midOrder(TreeNode *root, vector<int> &res)
{
    if(root == nullptr)
    {
        return;
    }
    postOrder(root->left, res);
    res.push_back(root->val);
    postOrder(root->right, res);
}

vector<int> MultiQuestions::question94(TreeNode *root)
{
    vector<int> res;
    postOrder(root, res);
    return res;
}



vector<int> MultiQuestions::question34(vector<int>& nums, int target)
{
    vector<int> res;
    int n = nums.size();
    int start = -1;
    int end = -1;

    for(int i = 0; i < n; ++i)
    {
        if(start == -1 && nums[i] == target)
        {
            start = i;
            end = i;
        }
        else if(start != -1 && nums[i] == target)
        {
            end = i;
        }
        else if(start != -1 && nums[i] != target)
        {
            break;
        }
    }
    res.push_back(start);
    res.push_back(end);
    return res;
}

int MultiQuestions::question33(vector<int> &nums, int target)
{
    int n = nums.size();
    int rtxIdx = 0;
    int res = -1;
    for(int i = 0; i < n - 1; ++i)
    {
        if(nums[i] > nums[i + 1])
        {
            rtxIdx = i;
        }
    }

    res = binarySearch(nums, 0, rtxIdx, target);
    if(res == -1)
    {
        res = binarySearch(nums, rtxIdx + 1, n - 1, target);
    }

    return res;
}

bool MultiQuestions::question74(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m * n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int idx1 = mid / n;
        int idx2 = mid % n;
        if(matrix[idx1][idx2] > target)
        {
            high = mid - 1;
        }
        else if(matrix[idx1][idx2] < target)
        {
            low = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int MultiQuestions::question153(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high])
        {
            high = pivot;
        }
        else
        {
            low = pivot + 1;
        }
    }
    return nums[low];
}

int MultiQuestions::question162(vector<int>& nums)
{
    int n = nums.size();

    // 辅助函数，输入下标 i，返回一个二元组 (0/1, nums[i])
    // 方便处理 nums[-1] 以及 nums[n] 的边界情况
    auto get = [&](int i) -> pair<int, int>
    {
        if (i == -1 || i == n)
        {
            return {0, 0};
        }
        return {1, nums[i]};
    };

    int left = 0, right = n - 1, ans = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1))
        {
            ans = mid;
            break;
        }
        if (get(mid) < get(mid + 1))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int MultiQuestions::question162_method2(vector<int> &nums)
{
    int n = nums.size() - 1;
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] > nums[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

bool MultiQuestions::question844(string s, string t)
{
    vector<int> stk1;
    vector<int> stk2;
    int n1 = s.size();
    int n2 = t.size();

    for(int i = 0; i < n1; ++i)
    {
        if(s[i] != '#')
        {
            stk1.push_back(s[i]);
        }
        else if(!stk1.empty())
        {
            stk1.pop_back();
        }
    }
    for(int i = 0; i < n2; ++i)
    {
        if(t[i] != '#')
        {
            stk2.push_back(t[i]);
        }
        else if(!stk2.empty())
        {
            stk2.pop_back();
        }
    }
    if(stk1.size() != stk2.size())
    {
        return false;
    }
    for(int i = 0; i < stk1.size(); ++i)
    {
        if(stk1[i] != stk2[i])
        {
            return false;
        }
    }
    return true;
}

bool MultiQuestions::question844_method2(string s, string t)
{
    vector<char> s_vec;
    vector<char> t_vec;
    bool flag = true;

    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != '#')
        {
            s_vec.push_back(s[i]);
        }
        else if(!s_vec.empty())
        {
            s_vec.pop_back();
        }
    }
    for(int i = 0; i < t.size(); ++i)
    {
        if(t[i] != '#')
        {
            t_vec.push_back(t[i]);
        }
        else if(!t_vec.empty())
        {
            t_vec.pop_back();
        }
    }
    if(s_vec.size() != t_vec.size())
    {
        return false;
    }
    else
    {
        for(int i = 0; i < s_vec.size(); ++i)
        {
            if(s_vec[i] != t_vec[i])
            {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> MultiQuestions::question986(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
{
    int n1 = firstList.size();
    int n2 = secondList.size();
    int i = 0;
    int j = 0;
    vector<vector<int>> res;

    while(i < n1 && j < n2)
    {
        int low = max(firstList[i][0], secondList[j][0]);
        int high = min(firstList[i][1], secondList[j][1]);
        if(low <= high)
        {
            res.push_back(vector<int>({low, high}));
        }
        if(firstList[i][1] < secondList[j][1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return res;
}

vector<vector<int>> MultiQuestions::question986_method2(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
{
    vector<vector<int>> ans;

    int n1 = firstList.size();
    int n2 = secondList.size();
    int i = 0;
    int j = 0;

    while(i < n1 && j < n2)
    {
        int low = max(firstList[i][0], secondList[j][0]);
        int high = min(firstList[i][1], secondList[j][1]);
        if(low <= high)
        {
            ans.push_back(vector<int>{low, high});
        }
        if(firstList[i][1] < secondList[j][1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

int MultiQuestions::question11(vector<int> &height)
{
    int n = height.size();
    int ptr1 = 0;
    int ptr2 = n - 1;
    int res = 0;

    while (ptr1 < ptr2)
    {
        int w = ptr2 - ptr1;
        int h = min(height[ptr1], height[ptr2]);
        int area = w * h;
        res = max(res, area);

        if(height[ptr1] < height[ptr2])
        {
            ++ptr1;
        }
        else
        {
            --ptr2;
        }
    }
    return res;
}

int MultiQuestions::question11_method2(vector<int>& height)
{
    int ans = 0;
    int ptr1 = 0;
    int ptr2 = height.size() - 1;

    while(ptr1 < ptr2)
    {
        int h = min(height[ptr1], height[ptr2]);
        int l = ptr2 - ptr1;
        ans = max(ans, l * h);
        if(height[ptr1] < height[ptr2])
        {
            ptr1++;
        }
        else
        {
            ptr2--;
        }
    }
    return ans;
}

vector<int> MultiQuestions::question438(string s, string p)
{
    int sLen = s.size(), pLen = p.size();

    if (sLen < pLen)
    {
        return vector<int>();
    }

    vector<int> ans;
    vector<int> sCount(26);
    vector<int> pCount(26);
    for (int i = 0; i < pLen; ++i)
    {
        ++sCount[s[i] - 'a'];
        ++pCount[p[i] - 'a'];
    }

    if (sCount == pCount)
    {
        ans.emplace_back(0);
    }

    for (int i = 0; i < sLen - pLen; ++i)
    {
        --sCount[s[i] - 'a'];
        ++sCount[s[i + pLen] - 'a'];

        if (sCount == pCount)
        {
            ans.emplace_back(i + 1);
        }
    }

    return ans;
}

vector<int> MultiQuestions::question438_method2(string s, string p)
{
    int sLen = s.length();
    int pLen = p.length();
    vector<int> sCount(26, 0);
    vector<int> pCount(26, 0);
    vector<int> ans;

    if(sLen < pLen)
    {
        return ans;
    }

    for(int i = 0; i < pLen; ++i)
    {
        ++sCount[s[i] - 'a'];
        ++pCount[p[i] - 'a'];
    }
    if(sCount == pCount)
    {
        ans.push_back(0);
    }
    for(int i = 0; i < sLen - pLen; ++i)
    {
        --sCount[s[i] - 'a'];
        ++sCount[s[i + pLen] - 'a'];
        if(sCount == pCount)
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

int MultiQuestions::question713(vector<int> &nums, int k)
{
    int n = nums.size();
    int res = 0;
    int prod = 1;
    int i = 0;
    for(int j = 0; j < n; ++j)
    {
        prod *= nums[j];
        while (i <= j && prod >= k)
        {
            prod /= nums[i];
            i++;
        }
        res += j - i + 1;
    }
    return res;
}

int MultiQuestions::question209(int target, vector<int> &nums)
{
    int n = nums.size();
    int length = INT_MAX;
    int sum = 0;
    int i = 0;
    if(n == 0)
    {
        return 0;
    }

    for(int j = 0; j < n; ++j)
    {
        sum += nums[j];
        while(i <= j && sum >= target)
        {
            length = min(length, j - i + 1);
            sum -= nums[i];
            i++;
        }
    }
    return length == INT_MAX ? 0 : length;
}

int MultiQuestions::question198(vector<int> &nums)
{
    int n = nums.size();
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return nums[0];
    }
    vector<int> dp = vector<int>(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; ++i)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[n - 1];
}

int MultiQuestions::question213(vector<int> &nums)
{
    int n = nums.size();
    if(n == 1)
    {
        return nums[0];
    }
    if(n == 2)
    {
        return max(nums[0], nums[1]);
    }
    int first1 = nums[0], second1 = max(nums[0], nums[1]);
    int first2 = nums[1], second2 = max(nums[1], nums[2]);
    for(int i = 2; i < n - 1; ++i)
    {
        int tmp = second1;
        second1 = max(first1 + nums[i], second1);
        first1 = tmp;
    }
    for(int i = 3; i < n; ++i)
    {
        int tmp = second2;
        second2 = max(first2 + nums[i], second2);
        first2 = tmp;
    }

    return max(second1, second2);
}

bool MultiQuestions::question55(vector<int> &nums)
{
    int n = nums.size();
    int rightMost = 0;

    for(int i = 0; i < n; ++i)
    {
        if(i <= rightMost)
        {
            rightMost = max(rightMost, i + nums[i]);
            if(rightMost >= n - 1)
            {
                return true;
            }
        }
    }
    return false;
}

int MultiQuestions::question45(vector<int> &nums)
{
    int maxPos = 0;
    int n = nums.size();
    int end = 0;
    int step = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        if(maxPos >= i)
        {
            maxPos = max(maxPos, i + nums[i]);
            if(i == end)
            {
                end = maxPos;
                ++step;
            }
        }
    }
    return step;
}

vector<string> MultiQuestions::question22(int n)
{
    vector<string> a;
    return a;
}

int MultiQuestions::question413(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }

    int d = nums[0] - nums[1], t = 0;
    int ans = 0;
    // 因为等差数列的长度至少为 3，所以可以从 i=2 开始枚举
    for (int i = 2; i < n; ++i)
    {
        if (nums[i - 1] - nums[i] == d)
        {
            ++t;
        }
        else
        {
            d = nums[i - 1] - nums[i];
            t = 0;
        }
        ans += t;
    }
    return ans;
}

int MultiQuestions::question91(string s)
{
    int n = s.size();
    vector<int> f(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i - 1] != '0')
        {
            f[i] += f[i - 1];
        }
        if(i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
        {
            f[i] += f[i - 2];
        }
    }
    return f[n];
}

vector<vector<int>> MultiQuestions::question15(vector<int> nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    int third = n - 1;
    quickSort<vector<int>, int>(nums, 0, n - 1);
    for(int first = 0; first < n; ++first)
    {
        int target = -nums[first];
        if(first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }
        for(int second = first + 1; second < n; ++second)
        {
            if(second > first + 1 && nums[second] == nums[second - 1])
            {
                continue;
            }
            while(third > second && nums[second] + nums[third] > target)
            {
                --third;
            }
            if(third == second)
            {
                break;
            }
            if(nums[second] + nums[third] == target)
            {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}

vector<vector<int>> MultiQuestions::question56(vector<vector<int>> intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    //quickSort<vector<vector<int>>, int>(intervals, 0, n - 1);

    return ans;
}

vector<int> MultiQuestions::question119(int rowIndex)
{
    vector<vector<int>> triangle;
    for(int i = 0; i < rowIndex; ++i)
    {
        vector<int> tmp_line;
        for(int j = 0; j <= i; ++j)
        {
            int tmp_element = 0;
            if(j == 0 || j == i)
            {
                tmp_element = 1;
                tmp_line.push_back(tmp_element);
            }
            else
            {
                tmp_element = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        triangle.push_back(tmp_line);
    }

    return triangle[rowIndex];
}

vector<vector<int>> question59(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int loopNum = n / 2;
    int element = 1;
    if(n % 2 == 1)
    {
        matrix[n / 2][n / 2] = n * n;
    }
    for(int i = 0; i < loopNum; ++i)
    {
        int h0 = i, l0 = i, h1 = n - 1 - i, l1 = n - 1 - i;
        for(; h0 < n - 1 - i; ++h0)
        {
            matrix[i][h0] = element++;
        }
        for(; l0 < n - 1 - i; ++l0)
        {
            matrix[l0][n - 1 - i] = element++;
        }
        for(; h1 > i; --h1)
        {
            matrix[n - 1 - i][h1] = element++;
        }
        for(; l1 > i; --l1)
        {
            matrix[l1][i] = element++;
        }
    }
    return matrix;
}

bool MultiQuestions::question240(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int rowIdx = 0;
    int colIdx = m - 1;

    while (rowIdx < m && colIdx >= 0)
    {
        if(matrix[rowIdx][colIdx] > target)
        {
            colIdx--;
        }
        else if(matrix[rowIdx][colIdx] < target)
        {
            rowIdx++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int MultiQuestions::question435(vector<vector<int>> &intervals)
{
    interval_quickSort(intervals, 0, intervals.size() - 1);//按照区间左端点对区间进行排序
    int cnt = 1;//不重叠的区间数量
    int right = intervals[0][1];
    for(int i = 0; i < intervals.size(); ++i)
    {
        if(intervals[i][0] >= right)
        {
            ++cnt;
            right = intervals[i][1];
        }
    }
    return intervals.size() - cnt;
}

bool MultiQuestions::question334(vector<int>& nums)
{
    int n = nums.size();
    vector<int> leftMin(n);
    vector<int> rightMax(n);

    leftMin[0] = nums[0];
    for(int i = 1; i < n; ++i)
    {
        int num = leftMin[i - 1] < nums[i] ? leftMin[i - 1] : nums[i];
        leftMin[i] = num;
    }
    rightMax[n - 1] = nums[n - 1];
    for(int i = n - 2; i >=0 ; --i)
    {
        int num = rightMax[i + 1] > nums[i] ? rightMax[i + 1] : nums[i];
        rightMax[i] = num;
    }
    for(int i = 1; i < n - 1; ++i)
    {
        if(nums[i] > leftMin[i - 1] && nums[i] < rightMax[i + 1])
        {
            return true;
        }
    }
    return false;
}

string MultiQuestions::question415(string num1, string num2)
{
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int add = 0;
    string ans = "";

    while(i >= 0 || j >= 0 || add != 0)
    {
        int x = num1[i];
        int y = num2[j];
        int sum = x + y + add;
        ans.push_back('0' + sum % 10);
        add = sum / 10;

        i--;
        j--;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int MultiQuestions::question458(string s)
{
    unordered_map<char, int> hashTab;
    int ans = 0;

    for(int i = 0; i < s.length(); ++i)
    {
        ++hashTab[s[i]];
    }
    for(auto iter = hashTab.begin(); iter != hashTab.end(); ++iter)
    {
        ans += iter->second / 2 * 2;
        if(iter->second % 2 == 1 && ans % 2 == 0)
        {
            ans++;
        }
    }
    return ans;
}

bool MultiQuestions::question290(string pattern, string s)
{
    unordered_map<string, char> str2char;
    unordered_map<char, string> char2str;
    int n = pattern.length();
    int m = s.length();
    int i = 0;

    for(char ch : pattern)
    {
        if(i > m)
        {
            return false;
        }
        int j = i;
        while(j < m && s[j] != ' ')
            j++;
        const string &tmp = s.substr(i, j - 1);
        if(str2char.count(tmp) && str2char[tmp] != ch)
        {
            return false;
        }
        if(char2str.count(ch) && char2str[ch] != tmp)
        {
            return false;
        }
    }
    return i > m;
}

vector<vector<int>> MultiQuestions::question103(TreeNode* root)
{
    return {{1}};
}

vector<TreeNode*> MultiQuestions::generateTrees(int start, int end)
{
    vector<TreeNode*> trees;
    if(start > end)
    {
        return {nullptr};
    }
    for(int i = start; i <= end; ++i)
    {
        vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
        vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

        for(int i_ = 0; i_ < leftTrees.size(); ++i_)
        {
            for(int j_ = 0; j_ < rightTrees.size(); ++j_)
            {
                TreeNode* tree = new TreeNode(i);
                tree->left = leftTrees[i_];
                tree->right = rightTrees[j_];
                trees.push_back(tree);
            }
        }
    }
    return trees;
}

vector<TreeNode*> MultiQuestions::question95(int n)
{
    if(!n)
    {
        return {};
    }
    return generateTrees(1, n);
}

bool MultiQuestions::helper98(TreeNode *root, long long& preVal)
{
    if(root != nullptr)
    {
        if(helper98(root->left, preVal))
        {
            if(root->val <= preVal)
            {
                return false;
            }
            else
            {
                preVal = root->val;
            }
            if(helper98(root->right, preVal))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

bool MultiQuestions::question98(TreeNode *root)
{
    long long preVal = INT_MIN - 1;
    return helper98(root, preVal);
}

void MultiQuestions::helper99(TreeNode *root, TreeNode* &preNode, TreeNode* &node1, TreeNode* &node2, bool &flag)
{
    if (flag)
    {
        return;
    }
    if(root != nullptr)
    {
        helper99(root->left, preNode, node1, node2, flag);
        if(root->val < preNode->val)
        {
            node2 = root;
            if(node1 == nullptr)
            {
                node1 = preNode;
            }
            else
            {
                flag = true;
                return;
            }
        }
        preNode = root;
        helper99(root->right, preNode, node1, node2, flag);
    }
}

void MultiQuestions::question99(TreeNode* root)
{
    TreeNode* preNode = new TreeNode(INT_MIN);
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    bool flag = false;

    helper99(root, preNode, node1, node2, flag);
    int tmp = node2->val;
    node2->val = node1->val;
    node1->val = tmp;
}

TreeNode* MultiQuestions::question450(TreeNode* root, int key)//delete
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if(root->val > key)
    {
        root->left = question450(root->left, key);
        return root;
    }
    if(root->val < key)
    {
        root->right = question450(root->right, key);
        return root;
    }
    if(root->val == key)
    {
        if(root->left == nullptr && root->right == nullptr)//leaf node
        {
            return nullptr;
        }
        if(root->left == nullptr)
        {
            return root->right;
        }
        if(root->right == nullptr)
        {
            return root->left;
        }
        TreeNode *successor = root->right;
        while (successor->left != nullptr)
        {
            successor = successor->left;
        }
        root->right = question450(root->right, successor->val);
        successor->left = root->left;
        successor->right = root->right;
        return successor;
    }
    return root;
}

TreeNode* MultiQuestions::helper700(TreeNode *root, int key)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if (root->val > key)
    {
        return helper700(root->left, key);
    }
    if (root->val < key)
    {
        return helper700(root->right, key);
    }
    if (root->val == key)
    {
        return root;
    }
}

TreeNode* MultiQuestions::question700(TreeNode* root, int key)//search
{
    return helper700(root, key);
}

TreeNode* MultiQuestions::question701(TreeNode* root, int key)//add
{
    if (root == nullptr)
    {
        return new TreeNode(key);
    }
    TreeNode *root_ = root;
    while (root_ != nullptr)
    {
        if(key < root_->val)
        {
            if(root_->left == nullptr)
            {
                root_->left = new TreeNode(key);
                break;
            }
            else
            {
                root_ = root_->left;
            }
        }
        else
        {
            if(root_->right == nullptr)
            {
                root_->right = new TreeNode(key);
                break;
            }
            else
            {
                root_ = root_->right;
            }
        }
    }
    return root;
}

int MultiQuestions::helper110(TreeNode *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    else
    {
        return max(helper110(root->left), helper110(root->right)) + 1;
    }
}

bool MultiQuestions::question110(TreeNode *root)
{
    if(root == nullptr)
    {
        return true;
    }
    else
    {
        return abs(helper110(root->left) - helper110(root->right)) <= 1 && question110(root->left) && question110(root->right);
    }
}

bool MultiQuestions::helper100(TreeNode *root1, TreeNode *root2)
{
    if(root1 == nullptr && root2 == nullptr) return true;
    else if(root1 == nullptr && root2 != nullptr) return false;
    else if(root1 != nullptr && root2 == nullptr) return false;
    else if(root1->val != root2->val) return false;

    bool left = helper100(root1->left, root2->left);
    bool right = helper100(root1->right, root2->right);

    return (left && right);
}

bool MultiQuestions::question100(TreeNode *root1, TreeNode *root2)
{
    return helper100(root1, root2);
}

bool MultiQuestions::helper101(TreeNode *left, TreeNode *right)
{
    if(left == nullptr && right == nullptr) return true;
    else if(left == nullptr && right != nullptr) return false;
    else if(left != nullptr && right == nullptr) return false;
    else if(left->val != right->val) return false;

    bool l = helper101(left->left, right->right);
    bool r = helper101(left->right, right->left);

    return (l && r);
}

bool MultiQuestions::question101(TreeNode *root)
{
    if(root == nullptr)
    {
        return true;
    }
    return helper101(root->left, root->right);
}

vector<vector<int>> MultiQuestions::question102(TreeNode* root)
{
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    if(root != nullptr)
    {
        que.push(root);
    }
    while(!que.empty())
    {
        int size = que.size();
        vector<int> tmp;
        for(int i = 0; i < size; ++i)
        {
            TreeNode *node = que.front();
            que.pop();
            tmp.push_back(node->val);
            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
        ans.push_back(tmp);
    }
    return ans;
}

vector<vector<int>> MultiQuestions::question107(TreeNode *root)
{
    vector<vector<int>> ans;
    stack<queue<TreeNode*>> stk;
    queue<TreeNode*> que;

    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        queue<TreeNode*> q;
        int size = que.size();
        for(int i = 0; i < size; ++i)
        {
            TreeNode *node = que.front();
            q.push(node);
            que.pop();
            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
        stk.push(q);
    }

    while(!stk.empty())
    {
        vector<int> tmp;
        queue<TreeNode*> q = stk.top();
        int size = q.size();
        stk.pop();
        for(int i = 0; i < size; ++i)
        {
            TreeNode* node = q.front();
            q.pop();
            tmp.push_back(node->val);
        }
        ans.push_back(tmp);
    }
    return ans;
}

vector<int> MultiQuestions::question199(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode*> que;

    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        int size = que.size();
        for(int i = 0; i < size; ++i)
        {
            TreeNode* node = que.front();
            que.pop();
            if(i == size - 1)
            {
                ans.push_back(node->val);
            }

            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
    }
    return ans;
}

vector<double> MultiQuestions::question637(TreeNode* root)
{
    vector<double> ans;
    queue<TreeNode*> que;

    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        int size = que.size();
        double sum = 0;
        for(int i = 0; i < size; ++i)
        {
            TreeNode* node = que.front();
            que.pop();

            sum += node->val;

            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
        ans.push_back(sum / size);
    }
    return ans;
}

vector<vector<int>> MultiQuestions::question429(N_ARY_TREE::Node *root)
{
    vector<vector<int>> ans;
    queue<N_ARY_TREE::Node*> que;

    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        vector<int> tmp;
        int size = que.size();

        for(int i = 0; i < size; ++i)
        {
            N_ARY_TREE::Node* node = que.front();
            que.pop();
            tmp.push_back(node->val);

            int _size = node->children.size();
            for(int j = 0; j < _size; ++j)
            {
                if(node->children[j] != nullptr)
                {
                    que.push(node->children[j]);
                }
            }
        }
        ans.push_back(tmp);
    }
    return ans;
}

vector<int> MultiQuestions::question515(TreeNode *root)
{
    vector<int> ans;
    queue<TreeNode*> que;

    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        int size = que.size();
        int max = 0;
        for(int i = 0; i < size; ++i)
        {
            TreeNode* node = que.front();
            que.pop();
            if(node->val > max)
            {
                max = node->val;
            }

            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }

        ans.push_back(max);
    }
    return ans;
}

BINARY_TREE::Node* MultiQuestions::question116(BINARY_TREE::Node *root)
{
    queue<BINARY_TREE::Node*> que;

    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        int size = que.size();

        for(int i = 0; i < size; ++i)
        {
            BINARY_TREE::Node* node = que.front();
            que.pop();
            if(i != size - 1)
            {
                BINARY_TREE::Node* nextNode = que.front();
                node->next = nextNode;
            }
            else
            {
                node->next = nullptr;
            }

            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
    }

    return root;
}

BINARY_TREE::Node* MultiQuestions::question117(BINARY_TREE::Node *root)
{
    queue<BINARY_TREE::Node*> que;

    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        int size = que.size();

        for(int i = 0; i < size; ++i)
        {
            BINARY_TREE::Node* node = que.front();
            que.pop();
            if(i != size - 1)
            {
                BINARY_TREE::Node* nextNode = que.front();
                node->next = nextNode;
            }
            else
            {
                node->next = nullptr;
            }

            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
    }

    return root;
}

int MultiQuestions::question104(TreeNode* root)
{
    int ans = 0;
    queue<TreeNode*> queue;
    if(root != nullptr)
    {
        queue.push(root);
    }
    while(!queue.empty())
    {
        int size = queue.size();
        for(int i = 0; i < size; ++i)
        {
            TreeNode* node = queue.front();
            queue.pop();

            if(node->left != nullptr)
            {
                queue.push(node->left);
            }
            if(node->right != nullptr)
            {
                queue.push(node->right);
            }
        }
        ans++;
    }
    return ans;
}

int MultiQuestions::question111(TreeNode* root)
{
    int ans = 0;
    bool flag = false;
    queue<TreeNode*> que;

    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        int size = que.size();

        ans++;
        for(int i = 0; i < size; ++i)
        {
            TreeNode* node = que.front();
            que.pop();

            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
            if(node->left == nullptr && node->right == nullptr)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }
    return ans;
}

int MultiQuestions::question153(vector<int> &nums)
{
    int key = nums[0];
    int pivot = 0;
    for(int i = 1; i < nums.size(); ++i)
    {
        if(key > nums[i])
        {
            pivot = i;
            break;
        }
        else
        {
            key = nums[i];
        }
    }

    return (nums[pivot] < nums[0]) ? nums[pivot] : nums[0];
}

bool MultiQuestions::helper112(TreeNode *root, int targetSum)
{
    if(!root->left && !root->right && targetSum == 0) return true;
    if(!root->left && !root->right) return false;

    if(root->left)
    {
        if(helper112(root->left, targetSum - root->left->val)) return true;
    }
    if(root->right)
    {
        if(helper112(root->right, targetSum - root->right->val)) return true;
    }
    return false;
}

bool MultiQuestions::question112(TreeNode* root, int targetSum)
{
    if(root == nullptr)
    {
        return false;
    }
    return helper112(root, targetSum - root->val);
}

void MultiQuestions::helper113(TreeNode *root, int targetSum, vector<vector<int>> &ans, vector<int> &path)
{
    if(!root->left && !root->right && targetSum == 0)
    {
        ans.push_back(path);
    }
    if(!root->left && !root->right) return;

    if(root->left)
    {
        path.push_back(root->left->val);
        helper113(root->left, targetSum - root->left->val, ans, path);
        path.pop_back();
    }
    if(root->right)
    {
        path.push_back(root->right->val);
        helper113(root->right, targetSum - root->right->val, ans, path);
        path.pop_back();
    }
    return;
}

vector<vector<int>> MultiQuestions::question113(TreeNode* root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> path;
    if(root == nullptr)
    {
        return vector<vector<int>>{};
    }
    path.push_back(root->val);
    helper113(root, targetSum - root->val, ans, path);

    return ans;
}

int MultiQuestions::helper124(TreeNode *root, int &sum)
{
    if(root == nullptr)
    {
        return 0;
    }

    int maxLeft = helper124(root, sum);
    int maxRight = helper124(root, sum);

    sum = max(sum, root->val + maxLeft + maxRight);

    return root->val + max(maxLeft, maxRight);
}

int MultiQuestions::question124(TreeNode *root)//深度优先搜索
{
    int sum = INT_MIN;
    vector<int> paths;
    if(root == nullptr)
    {
        return 0;
    }
    helper124(root, sum);

    return sum;
}

void MultiQuestions::helper200_BFS(vector<vector<char>> &grid, vector<vector<int>> &map, int x, int y)
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> que;
    que.push({x, y});
    map[x][y] = 1;
    while(!que.empty())
    {
        pair<int, int> pos = que.front();
        x = pos.first;
        y = pos.second;
        que.pop();

        if(y + 1 < n && grid[x][y + 1] == '1' && map[x][y + 1] == 0)
        {
            que.push({x, y + 1});
            map[x][y + 1] = 1;
        }
        if(y - 1 >= 0 && grid[x][y - 1] == '1' && map[x][y - 1] == 0)
        {
            que.push({x, y - 1});
            map[x][y - 1] = 1;
        }
        if(x + 1 < m && grid[x + 1][y] == '1' && map[x + 1][y] == 0)
        {
            que.push({x + 1, y});
            map[x + 1][y] = 1;
        }
        if(x - 1 >= 0 && grid[x - 1][y] == '1' && map[x - 1][y] == 0)
        {
            que.push({x - 1, y});
            map[x - 1][y] = 1;
        }
    }
}

int MultiQuestions::question200_BFS(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<int>> map(m, vector<int>(n, 0));

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(map[i][j] == false && grid[i][j] == '1')
            {
                ans++;
                helper200_BFS(grid, map, i, j);
            }
        }
    }
    return ans;
}

void MultiQuestions::helper200_DFS(vector<vector<char>>& grid, vector<vector<int>>& map, int x, int y)
{
    int m = grid.size();
    int n = grid[0].size();

    if(x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == '0' || map[x][y] == 1)
    {
        return;
    }
    if(grid[x][y] == '1' && map[x][y] == 0)
    {
        map[x][y] = 1;
    }
    helper200_DFS(grid, map, x + 1, y);
    helper200_DFS(grid, map, x - 1, y);
    helper200_DFS(grid, map, x, y + 1);
    helper200_DFS(grid, map, x, y - 1);
}

int MultiQuestions::question200_DFS(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<int>> map(m, vector<int>(n, 0));

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            ans++;
            helper200_DFS(grid, map, i, j);
        }
    }
    return ans;
}

int MultiQuestions::helper547_BFS(vector<vector<int>>& isConnected, vector<int>& visited, int x, int y)
{
    int m = isConnected.size();
    int n = isConnected[0].size();
    int cities = 0;
    queue<int> que;

    if(isConnected[x][y] == 1 && visited[y] == 0)
    {
        visited[y] = 1;
        cities++;
        que.push(x);
    }

    while(!que.empty())
    {
        int city = que.front();
        que.pop();
        for(int i = 0; i < n; ++i)
        {
            if(i != y && isConnected[city][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                que.push(i);
                cities++;
            }
        }
    }
    return cities;
}

int MultiQuestions::question547_BFS(vector<vector<int>> &isConnected)
{
    int m = isConnected.size();
    int n = isConnected[0].size();
    int ans = 0;
    vector<int> visited(m, 0);
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(isConnected[i][j] == 1 && visited[i] == 0)
            {
                helper547_BFS(isConnected, visited, i, j);
                ans++;
            }
        }
    }
    return ans;
}

void MultiQuestions::helper547_DFS(vector<vector<int>>& isConnected, vector<int>& visited, int x, int y)
{
    for (int j = 0; j < x; j++)
    {
        if (isConnected[y][j] == 1 && visited[j] == 0)
        {
            visited[j] = true;
            helper547_DFS(isConnected, visited, x, j);
        }
    }
}

int MultiQuestions::question547_DFS(vector<vector<int>> &isConnected)
{
    int m = isConnected.size();
    int n = isConnected[0].size();
    int ans = 0;
    vector<int> visited(m, 0);
    for(int i = 0; i < m; ++i)
    {
        if(visited[i] == 0)
        {
            helper547_DFS(isConnected, visited, m, i);
            ans++;
        }
    }
    return ans;
}