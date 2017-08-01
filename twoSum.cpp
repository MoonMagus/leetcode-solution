#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                result.push_back(m[target - nums[i]]);
                result.push_back(i);

                return result;
            }

            m[nums[i]] = i;
        }

        return result;
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
    vector<int> result = s.twoSum(v, 12);
    if (result.size() == 2) {
        cout << "first_index: " << result[0] << endl << "second_index: " << result[1] << endl;
    }
    else {
        cout << "no result" << endl;
    }

    fclose(stdin);//关闭文件   
    fclose(stdout);//关闭文件   
    return 0;
}