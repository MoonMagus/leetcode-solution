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
#include <unordered_Set>
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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
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
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j)
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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        const int total = n1 + n2;
        if (total & 0x1)
            return findKthSortedArrays(begin(nums1), n1, begin(nums2), n2, total / 2 + 1);
        else
            return (findKthSortedArrays(begin(nums1), n1, begin(nums2), n2, total / 2) +
                findKthSortedArrays(begin(nums1), n1, begin(nums2), n2, total / 2 + 1)) / 2;
    }

private:
    template<typename Iterator>
    double findKthSortedArrays(Iterator A, int m, Iterator B, int n, int k) {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (m == 0)
            return B[k - 1];
        if (k == 1)
            return min(A[0], B[0]);

        int pa = min(k / 2, m);
        int pb = k - pa;
        if (A[pa - 1] < B[pb - 1])
            return findKthSortedArrays(next(A, pa), m - pa, B, n, k - pa);
        else if (A[pa - 1] > B[pb - 1])
            return findKthSortedArrays(A, m, next(B, pb), n - pb, k - pb);
        else
            return A[pa - 1];
    }
};

int main() {
    vector<vector<int>> v = initializeData(1);
    Solution so;

    releaseData();
    return 0;
}