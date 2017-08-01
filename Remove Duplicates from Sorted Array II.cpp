#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[index] || index == 0 || nums[index - 1] != nums[i])
                nums[++index] = nums[i];
        }

        return index + 1;
    }
};


int main() {
    freopen("C:\\Users\\fengy\\Desktop\\io\\in.txt", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取   
    freopen("C:\\Users\\fengy\\Desktop\\io\\\\out.txt", "w", stdout); //输出重定向，输出数据将保存在out.txt文件中   

    int a;
    vector<int> v;
    while (cin >> a) {
        v.push_back(a);
    }

    Solution s;
    int result = s.removeDuplicates(v);
    cout << result << endl;
    for (int i = 0; i < result; ++i)
        cout << v[i] << " ";
    cout << endl;

    fclose(stdin);//关闭文件   
    fclose(stdout);//关闭文件   
    return 0;
}