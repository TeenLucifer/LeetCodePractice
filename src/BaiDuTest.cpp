//
// Created by Lenovo on 2023/4/7.
//

#include "BaiDuTest.h"

BaiDuTest::BaiDuTest()
{}

BaiDuTest::~BaiDuTest()
{}

// ACM模式，我在这里定义的一个函数相当于main函数，而不是功能函数
int BaiDuTest::question1()
{
    int a;
    int b;

    while(cin >> a >> b)
    {
        cout << a + b << endl;
    }

    return 0;
}

int BaiDuTest::question2()
{
    int a;
    int b;
    int num;

    cin >> num;
    for(int i = 0; i < num; ++i)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}

int BaiDuTest::question3()
{
    int a;
    int b;

    while(cin >> a >> b)
    {
        if(a == 0 && b == 0)
        {
            break;
        }
        cout << a + b << endl;
    }
    return 0;
}

int BaiDuTest::question4()
{
    int n;
    int a;
    int sum = 0;

    while(cin >> n)
    {
        if(n == 0)
        {
            break;
        }
        for(int i = 0; i < n; ++i)
        {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}

int BaiDuTest::question5()
{
    int rows;
    int cols;
    int a;
    int sum = 0;

    cin >> rows;

    for(int i = 0; i < rows; ++i)
    {
        cin >> cols;
        for(int j = 0; j < cols; ++j)
        {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}

int BaiDuTest::question6()
{
    int cols;
    int a;
    int sum = 0;

    while(cin >> cols)
    {
        for(int i = 0; i < cols; ++i)
        {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}

int BaiDuTest::question7()
{
    int sum = 0;
    int a;
    while(cin >> a)
    {
        sum += int(a);
        if(cin.get() == '\n')
        {
            cout << sum << endl;
            sum = 0;
        }
    }
    return 0;
}

int BaiDuTest::question8()
{
    vector<string> strs;
    string str;
    int n;

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> str;
        strs.push_back(str);
    }
    sort(strs.begin(), strs.end());

    for(int i = 0; i < n; ++i)
    {
        cout << strs[i] << " ";
    }

    return 0;
}

int BaiDuTest::question9()
{
    vector<string> strs;
    string str;

    while(cin >> str)
    {
        strs.push_back(str);
        if(cin.get() == '\n')
        {
            sort(strs.begin(), strs.end());
            for(int i = 0; i < strs.size() - 1; ++i)
            {
                cout << strs[i] << " ";
            }
            cout << strs[strs.size() - 1] << endl;
            strs.clear();
        }
    }
    return 0;
}

int BaiDuTest::question10()
{
    vector<string> strs;
    string str;
    string tmp;
    char ch;

    while(cin >> tmp)
    {
        for(int i = 0; i < tmp.size(); ++i)
        {
            ch = tmp[i];
            if(ch == ',')
            {
                strs.push_back(str);
                str.clear();
                continue;
            }
            str.append(1, ch);
        }
        strs.push_back(str);
        str.clear();
        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs.size(); ++i)
        {
            if(i != strs.size() - 1)
            {
                cout << strs[i] << ",";
            }
            else
            {
                cout << strs[strs.size() - 1] << endl;
            }
        }
        strs.clear();
    }

    return 0;
}

int BaiDuTest::question11()
{
    long long a;
    long long b;

    cin >> a >> b;
    cout << a + b << endl;

    return 0;
}

int BaiDuTest::binary_search(vector<int> &nums, int begin, int end, int target)
{
    if(begin > end)
    {
        return -1;
    }

    int mid = (begin + end) / 2;

    if(nums[mid] > target)
    {
        return binary_search(nums, begin, mid - 1, target);
    }
    else if(nums[mid] < target)
    {
        return binary_search(nums, begin + 1, end, target);
    }
    else
    {
        return mid;
    }
}

int BaiDuTest::question12(vector<int> &nums, int target)//二分查找
{
    return binary_search(nums, 0, nums.size() - 1, target);
}

bool BaiDuTest::binary_search_2d(vector<vector<int>> &array, int x_begin, int x_end, int y_begin, int y_end, int target)
{
    if(x_begin == x_end || y_begin == y_end)
    {
        return false;
    }

    int x_mid = (x_begin + x_end) /  2;
    int y_mid = (y_begin + y_end) /  2;
    int num = array[x_mid][y_mid];

    if(num > target)
    {
        if(binary_search_2d(array, x_begin, x_mid, y_begin, y_end, target)) return true;
        if(binary_search_2d(array, x_mid + 1, x_end, y_begin, y_mid, target)) return true;
    }
    else if(num < target)
    {
        if(binary_search_2d(array, x_mid + 1, x_end, y_begin, y_end, target)) return true;
        if(binary_search_2d(array, x_begin, x_mid, y_mid + 1, y_end, target)) return true;
    }
    else
    {
        return true;
    }
    return false;
}

bool BaiDuTest::question13(vector<vector<int>> &array, int target)
{
    if(array.size() == 0)
    {
        return false;
    }
    return binary_search_2d(array, 0, array[0].size(), 0, array.size(), target);
}

int BaiDuTest::binary_search_Q14(vector<int> &nums, int begin, int end)
{
    if(begin == end)
    {
        return begin;
    }
    int mid = (begin + end) / 2;
    int num = nums[mid];

    if(num > nums[mid + 1])
    {
        return binary_search_Q14(nums, begin, mid);
    }
    else if(num < nums[mid + 1])
    {
        return binary_search_Q14(nums, mid + 1, end);
    }
}

int BaiDuTest::question14(vector<int> &nums)//寻找峰值
{
    if(nums.size() == 0)
    {
        return -1;
    }
    return binary_search_Q14(nums, 0, nums.size() - 1);
}

ListNode *BaiDuTest::question15(ListNode *head, int val)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* ptr = dummyHead;
    while(ptr->next != nullptr)
    {
        if(ptr->next->val == val)
        {
            ptr->next = ptr->next->next;
        }
        ptr = ptr->next;
    }
    return head;
}

ListNode *BaiDuTest::question16(ListNode *head)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* pre = nullptr;
    ListNode* cur = head;

    while(cur->next != nullptr)
    {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    dummyHead->next = pre;
    return dummyHead->next;
}

ListNode *BaiDuTest::question17(ListNode *head1, ListNode *head2)
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    ListNode* ptr1 = head1;
    ListNode* ptr2 = head2;

    while (ptr1 != nullptr || ptr2 != nullptr) {
        if(ptr1 == nullptr)
        {
            cur->next = ptr2;
        }
        if(ptr2 == nullptr)
        {
            cur->next = ptr1;
        }
        ListNode* newNode = new ListNode(0);
        if (ptr1->val < ptr2->val) {
            newNode->val = ptr1->val;
            ptr1 = ptr1->next;
        } else {
            newNode->val = ptr2->val;
            ptr2 = ptr2->next;
        }
        cur->next = newNode;
        cur = cur->next;
    }
    return dummyHead->next;
}

bool BaiDuTest::question18(ListNode *head)
{
    ListNode* ptr1 = head;
    ListNode* ptr2 = head;

    while(ptr2 != nullptr && ptr2->next != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;

        if(ptr1 == ptr2)
        {
            return true;
        }
    }
    return false;
}

ListNode *BaiDuTest::question19(ListNode *head)
{
    ListNode* ptr1 = head;
    ListNode* ptr2 = head;

    while(ptr2 != nullptr && ptr2->next != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;

        if(ptr1 == ptr2)
        {
            ListNode* idx1 = head;
            ListNode* idx2 = ptr1;
            while(idx1 != idx2)
            {
                idx1 = idx1->next;
                idx2 = idx2->next;
            }
            return idx1;
        }
    }
    return nullptr;
}

int BaiDuTest::question20(string str1, string str2)
{
    if(str1.size() != str2.size())
    {
        return -1;
    }
    unordered_map<char, int> map;

    for(int i = 0; i < str1.size(); ++i)
    {
        map[str1[i]]++;
    }
    for(int i = 0; i < str2.size(); ++i)
    {
        if(map.count(str2[i]))
        {
            if(--map[str2[i]] < 0)
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }

    return str1.size();
}

vector<int> BaiDuTest::question21(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_map<int, int> map;
    for(int i = 0; i < nums1.size(); ++i)
    {
        map[nums1[i]]++;
    }
    for(int i = 0; i < nums2.size(); ++i)
    {
        if(map.count(nums2[i]) && map[nums2[i]] != -1)
        {
            map[nums2[i]] = -1;
            res.push_back(nums2[i]);
        }
    }

    return res;
}

vector<vector<int>> BaiDuTest::question22(vector<int> &nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > 0)
        {
            break;
        }
        if(i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        unordered_set<int> map;
        for(int j = i + 1; j < nums.size(); ++j)
        {
            if(j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
            {
                continue;
            }
            int c = 0 - nums[i] - nums[j];
            if(map.count(c))
            {
                res.push_back({nums[i], nums[j], c});
                map.erase(c);
            }
            else
            {
                map.insert(nums[j]);
            }
        }
    }

    return res;
}

void BaiDuTest::quick_sort(vector<int> &nums, int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int i = low;
    int j = high;
    int pivot = nums[low];

    while(i < j)
    {
        while(i < j && nums[j] > pivot)
        {
            j--;
        }
        nums[i] = nums[j];
        while(i < j && nums[i] <= pivot)
        {
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    quick_sort(nums, low, i - 1);
    quick_sort(nums, i + 1, high);
}

vector<int> BaiDuTest::question23(vector<int> &nums)
{
    quick_sort(nums, 0, nums.size() - 1);
    return nums;
}

vector<vector<int>> BaiDuTest::question24(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if(root != nullptr)
    {
        que.push(root);
    }

    while(!que.empty())
    {
        int node_num = que.size();
        vector<int> vec;

        for(int i = 0; i < node_num; ++i)
        {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push((node->right));
            }
        }
        res.push_back(vec);
    }
    return res;
}

void BaiDuTest::dfs_Q25(vector<int>& vec, TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    dfs_Q25(vec, root->left);
    vec.push_back(root->val);
    dfs_Q25(vec, root->right);
}

vector<int> BaiDuTest::question25(TreeNode *root)
{
    vector<int> res;
    dfs_Q25(res, root);
    return res;
}

void BaiDuTest::dfs_Q26(vector<int> &pre, vector<int> &mid, vector<int> &back, TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    pre.push_back(root->val);
    dfs_Q26(pre, mid, back, root->left);
    mid.push_back(root->val);
    dfs_Q26(pre, mid, back, root->right);
    back.push_back(root->val);
}

vector<vector<int>> BaiDuTest::question26(TreeNode *root)
{
    vector<vector<int>> res;
    vector<int> pre;
    vector<int> mid;
    vector<int> back;

    dfs_Q26(pre, mid, back, root);

    res.push_back(pre);
    res.push_back(mid);
    res.push_back(back);

    return res;
}

int BaiDuTest::question_I()
{
    int n;
    int k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    double res = 0;
    double total = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(i < k - 1)
        {
            res += nums[i];
        }
        else
        {
            total += nums[i];
            cnt++;
        }
    }
    res += total / 1.0 / cnt;

    return 0;
}

bool BaiDuTest::isPalindrome(string s)
{
    int n = s.size();
    for(int i = 0; i < n / 2; ++i)
    {
        if(s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
string BaiDuTest::construct_string(int x)
{
    if(x == 0)
    {
        return "red";
    }

    if(x % 2 == 1)
    {
        string s = "red";
        for(int i = 0; i < x / 2; ++i)
        {
            s = "e" + s + "e";
        }
        return s;
    }
    string s1 = "r";
    for(int i = 0; i < x / 2 - 1; ++i)
    {
        s1 += "s";
    }
    s1 += "d";
    string s2 = "d";
    for(int i = 0; i < x / 2 - 1; ++i)
    {
        s2 = "e" + s2 + "e";
    }
    s2 = "r" + s2;
    return s1 + s2;
}
int BaiDuTest::question_II()
{
    int x;
    cin >> x;
    if(x == 1)
    {
        cout << "r" << endl;
    }
    if(x == 2)
    {
        cout << "rr" << endl;
    }
    int i = 1;
    while(i * (i + 1) / 2 <= x)
    {
        i++;
    }
    i--;
    string s(i * 2, 'r');
    for(int j = 0; j < i; ++j)
    {
        s[j * 2 + 1] = 'e';
        s[(i + j) * 2 + 1] = 'd';
    }
    int count = i * (i + 1) / 2;
    if(count < x)
    {
        s[s.length() / 2] = 'e';
        count++;
    }
    if(count < x)
    {
        s.insert(s.length() / 2 + 1, "e");
        count++;
    }
    if(count < x)
    {
        s.insert(s.length() / 2 + 2, "d");
        count++;
    }
    while(count < x)
    {
        s.insert(s.length() / 2 + 1, "red");
        count += 2;
    }
    cout << s << endl;

    return 0;
}