#pragma warning(disable:4996)
#include <cstdio>
#include <iostream> 
using namespace std;

int main() {
    freopen("C:\\Users\\fengy\\Desktop\\io\\in.txt", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取   
    freopen("C:\\Users\\fengy\\Desktop\\io\\\\out.txt", "w", stdout); //输出重定向，输出数据将保存在out.txt文件中   

    int a, b;
    while (cin >> a >> b)
        cout << a + b << endl; // 注意使用endl   

    fclose(stdin);//关闭文件   
    fclose(stdout);//关闭文件   
    return 0;
}