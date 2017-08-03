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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> r;
        int size = nums.size();
        if (size <= 2)
            return r;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = size - 1;
            int sum = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == sum) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) {
                        ++j;
                        --k;
                        continue;
                    }

                    r.push_back({ nums[i], nums[j], nums[k] });
                    ++j;
                    --k;
                }
                else if (nums[j] + nums[k] < -nums[i])
                    ++j;
                else
                    --k;
            }
        }

        return r;
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
    vector<vector<int>> r = so.threeSum(v[0]);
    printData(r);

    releaseData();
    return 0;
}