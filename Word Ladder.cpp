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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord)
            return 1;

        unordered_set<string> wordset;
        for (auto word : wordList)
            wordset.insert(word);

        if (wordset.find(endWord) == wordset.end())
            return 0;

        const int n = beginWord.size();
        unordered_map<string, int> map;
        queue<string> q;
        string cur = beginWord;
        map[cur] = 1;
        q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            const int dis = map[cur];
            for (int i = 0; i < n; ++i) {
                char c = cur[i];
                for (int j = 0; j < 26; ++j) {
                    if ('a' + j == cur[i])
                        continue;

                    cur[i] = 'a' + j;
                    if (cur == endWord)
                        return dis + 1;

                    if (wordset.find(cur) != wordset.end() && map.find(cur) == map.end()) {
                        map[cur] = dis + 1;
                        q.push(cur);
                    }
                }

                cur[i] = c;
            }
        }

        return 0;
    }
};

int main() {
    vector<ListNode*> list = initializeList();

    releaseData();
    return 0;
}