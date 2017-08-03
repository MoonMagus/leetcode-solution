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
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (auto n : nums)
            m[n] = false;

        int longest = 0;
        for (auto n : nums) {
            if (m[n]) continue;
            int len = 1;

            for (int pre = n - 1; m.find(pre) != m.end(); --pre) {
                ++len;
                m[pre] = true;
            }

            for (int next = n + 1; m.find(next) != m.end(); ++next) {
                ++len;
                m[next] = true;
            }

            longest = max(longest, len);
        }

        return longest;
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
    int len = so.longestConsecutive(v[0]);
    cout << len << endl;

    releaseData();
    return 0;
}