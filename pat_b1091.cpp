#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
/*题要求你编程解决一个更通用的问题：从任一给定的长度为 L 的数字中，找出最早出现的 K 位连续数字所组成的素数。

输入格式：
输入在第一行给出 2 个正整数，分别是 L（不超过 1000 的正整数，为数字长度）和 K（小于 10 的正整数）。接下来一行给出一个长度为 L 的正整数 N。

输出格式：
在一行中输出 N 中最早出现的 K 位连续数字所组成的素数。如果这样的素数不存在，则输出 404。
 注意，原始数字中的前导零也计算在位数之内。例如在 200236 中找 4 位素数，0023 算是解；但第一位 2 不能被当成 0002 输出，因为在原始数字中不存在这个 2 的前导零。*/

bool judge_prime(int n)
{
    int i = 3;
    if(n <= 1) return false;
    else if(n%2 == 0) return false;
    else
    {
        for(;i <= sqrt(n);i+=2)
        {
            if(n % i == 0) return false;
        }
        return true;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    string nums;
    cin >> nums;
    for(int i = 0;i < nums.size() - k + 1;++i)
    {
        string tmp = nums.substr(i, k);//学习了新的字符串操作
        int sum = 0;
        for(int j = 0;j < tmp.size();++j)
        {
            sum = sum * 10 + tmp[j] - '0';
        }
        if(judge_prime(sum)){
            cout<<tmp;
            return 0;
        }
    }
    printf("%d\n",404);
    return 0;
}