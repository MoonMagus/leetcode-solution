#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <list>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

vector<vector<int>> initializeData(int lineCount = 1) {
    freopen("C:\\Users\\fengy\\Desktop\\io\\in.txt", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取   
    freopen("C:\\Users\\fengy\\Desktop\\io\\\\out.txt", "w", stdout); //输出重定向，输出数据将保存在out.txt文件中   
    vector<vector<int>> v = vector<vector<int>>(lineCount);

    // Read data from text file.
    string line;
    for (int i = 0; i < lineCount && getline(cin, line); ++i) {
        istringstream iss(line);
        int number;
        while (iss >> number)
            v[i].push_back(number);
    }

    return v;
}

void printData(vector<vector<int>>& v) {
    for (int i = 0; i < v.length(); ++i) {
        for (int j = 0; j < v[i].length(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

vector<ListNode*> initializeList(int lineCount = 1) {
    freopen("C:\\Users\\fengy\\Desktop\\io\\in.txt", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取   
    freopen("C:\\Users\\fengy\\Desktop\\io\\\\out.txt", "w", stdout); //输出重定向，输出数据将保存在out.txt文件中   
    vector<ListNode*> listTable;

    // Read data from text file.
    string line;
    for (int i = 0; i < lineCount && getline(cin, line); ++i) {
        istringstream iss(line);
        int number;
        ListNode* head = NULL;
        ListNode* cur = NULL;
        while (iss >> number) {
            ListNode *node = new ListNode(number);
            if (head == NULL)
                head = node;

            if (cur)
                cur->next = node;
            cur = node;
        }

        listTable.push_back(head);
    }

    return listTable;
}

void printList(vector<ListNode*> listTable) {
    for (int i = 0; i < listTable.size(); ++i) {
        ListNode* cur = listTable[i];
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}

void releaseData() {
    fclose(stdin);         //关闭文件   
    fclose(stdout);        //关闭文件   
}

// *********************************************************************************************************
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(lower_bound(nums, target));
        result.push_back(upper_bound(nums, target));

        return result;
    }

private:
    int lower_bound(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0;
        int r = n - 1;
        // Maintenance: 1. if [l, r] include target, which must keep the lower_bound of target.
        //              2. if [l, r] not include target.
        //                 <1>. if target ever exists, then [l, r] <= target, when terminated, l will be valid index lower_bound index of [0, n -1].
        //                 <2>. if target never exists, then l will be invalid n (next value to end of array), or valid index of [0, n - 1].
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target > nums[m])
                // [m + 1, r] includes region [target_begin, target_end], this step only delete unecessary elements for target.
                l = m + 1;
            else if (target < nums[m])
                // [l, m - 1] includes region [target_begin, target_end], this step only delete unecessary elements for target.
                r = m - 1;
            else
                // [l, m - 1] include region [-oo, target] which will cut off existed target elements,
                // which each value of [-oo, target].
                r = m - 1;
        }

        if (l < n && nums[l] == target)
            return l;
        else
            return -1;
    }

    // Maintenance: 1. if [l, r] include target, which must keep the upper_bound of target.
    //              2. if [l, r] not include target.
    //                 <1>. if target ever exists, then [l, r] >= target, when terminated, r will be valid index upper_bound index of [0, n -1].
    //                 <2>. if target never exists, then r will be invalid -1 (prev value to begin of array), or valid index of [0, n - 1].
    int upper_bound(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target < nums[m])
                r = m - 1;
            else if (target > nums[m])
                l = m + 1;
            else
                l = m + 1;
        }

        if (r >= 0 && nums[r] == target)
            return r;
        else
            return -1;
    }
};

int main() {
    vector<ListNode*> list = initializeList();

    releaseData();
    return 0;
}