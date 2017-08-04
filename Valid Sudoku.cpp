#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool used[9];
    bool isExist(char c) {
        if (c == '.')
            return false;
        if (used[c - '1'])
            return true;
        else {
            used[c - '1'] = true;
            return false;
        }
    }


public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            memset(used, false, sizeof(bool) * 9);
            for (int j = 0; j < 9; ++j) {
                if (isExist(board[i][j]))
                    return false;
            }

            memset(used, false, sizeof(bool) * 9);
            for (int j = 0; j < 9; ++j) {
                if (isExist(board[j][i]))
                    return false;
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                memset(used, false, sizeof(bool) * 9);
                for (int m = 0; m < 3; ++m) {
                    for (int n = 0; n < 3; ++n) {
                        if (isExist(board[i * 3 + m][j * 3 + n]))
                            return false;
                    }
                }
            }
        }

        return true;
    }
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

void releaseData() {
    fclose(stdin);         //关闭文件   
    fclose(stdout);        //关闭文件   
}

void printData(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> &v = initializeData();

    Solution so;

    releaseData();
    return 0;
}