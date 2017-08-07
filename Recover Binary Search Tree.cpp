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

// *********************************************************************************************************
class Solution {
private:
    void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* cur) {
        if (prev != NULL && prev->val > cur->val) {
            if (broken.first == NULL)
                broken.first = prev;

            broken.second = cur;
        }
    }

public:
    void recoverTree(TreeNode* root) {
        pair<TreeNode*, TreeNode*> broken;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while (cur != NULL) {
            if (!cur->left) {
                detect(broken, prev, cur);
                prev = cur;
                cur = cur->right;
            }
            else {
                // find prev node.
                auto node = cur->left;
                while (node->right != NULL && node->right != cur)
                    node = node->right;

                if (node->right == NULL) {
                    node->right = cur;
                    cur = cur->left;
                }
                else {
                    detect(broken, prev, cur);
                    prev->right = NULL;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }

        swap(broken.first->val, broken.second->val);
    }
};

int main() {
    vector<ListNode*> list = initializeList();

    releaseData();
    return 0;
}