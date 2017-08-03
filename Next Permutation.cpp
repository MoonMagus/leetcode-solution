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
    void nextPermutation(vector<int>& nums) {
        int l = nums.size();
        // find the pivot number.
        int index = l - 2;
        while (index >= 0 && nums[index] >= nums[index + 1])
            --index;

        // if the permutation is max, return the min.
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the first larger number from right to left.
        for (int i = l - 1; i >= 0; --i) {
            if (nums[i] > nums[index]) {
                int larger = nums[i];
                nums[i] = nums[index];
                nums[index] = larger;
                break;
            }
        }

        //reverse behind region.
        reverse(nums.begin() + index + 1, nums.end());
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
    so.nextPermutation(v[0]);
    printData(v);

    releaseData();
    return 0;
}