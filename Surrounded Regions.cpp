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
    void setMark(vector<vector<char>>& board, int i, int j) {
        const int m = board.size();
        if (m == 0)
            return;
        const int n = board[0].size();
        typedef pair<int, int> node;
        queue<node> q;
        q.push(node(i, j));
        board[i][j] = 'E';
        node cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            const int x = cur.first;
            const int y = cur.second;
            if (x > 0 && board[x - 1][y] == 'O') {
                q.push(node(x - 1, y));
                board[x - 1][y] = 'E';
            }

            if (x < m - 1 && board[x + 1][y] == 'O') {
                q.push(node(x + 1, y));
                board[x + 1][y] = 'E';
            }

            if (y > 0 && board[x][y - 1] == 'O') {
                q.push(node(x, y - 1));
                board[x][y - 1] = 'E';
            }

            if (y < n - 1 && board[x][y + 1] == 'O') {
                q.push(node(x, y + 1));
                board[x][y + 1] = 'E';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        if (m == 0)
            return;

        const int n = board[0].size();
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O')
                setMark(board, 0, i);
            if (board[m - 1][i] == 'O')
                setMark(board, m - 1, i);
        }

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O')
                setMark(board, i, 0);
            if (board[i][n - 1] == 'O')
                setMark(board, i, n - 1);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'E')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

int main() {
    vector<ListNode*> list = initializeList();

    releaseData();
    return 0;
}