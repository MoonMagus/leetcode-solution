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
    int trap(vector<int>& height) {
        int size = height.size();
        int max = 0;
        for (int i = 1; i < size; ++i) {
            if (height[i] > height[max])
                max = i;
        }

        int total = 0;
        for (int i = 0, left_max = 0; i < max; ++i) {
            if (height[i] > left_max)
                left_max = height[i];

            total += min(height[max], left_max) - height[i];
        }

        for (int j = size - 1, right_max = 0; j > max; --j) {
            if (height[j] > right_max)
                right_max = height[j];

            total += min(height[max], right_max) - height[j];
        }

        return total;
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
    cout << so.trap(v[0]) << endl;

    releaseData();
    return 0;
}