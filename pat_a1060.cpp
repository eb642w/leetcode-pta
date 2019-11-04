#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

/*
 * If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123×10
​5
​​  with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

Input Specification:
Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10
​100
​​ , and that its total digit number is less than 100.

Output Specification:
For each test case, print in a line YES if the two numbers are treated equal, and then the number in the standard form 0.d[1]...d[N]*10^k (d[1]>0 unless the number is 0); or NO if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.
 *
 *
 * */



/*
 * 思路：
 * 输入是数字，但长度很长
 * 输出是0.xxx的科学计数法表示的数字
 *
 * 主要是对输入的字符串进行处理：
 * 1.如果字符串小于1，即0.多少，0.去掉，之后的如果还有n个0，10的指数就是-n，如0.001是10^-2
 *
 * 2.如果大于1，题目中提到可能有前导0，先去掉他们，然后算到首位数字到小数点前一位或者最后一位（没有小数点），指数就是位数
 *
 * 3.根据结果比较小鼠后面部分和整数部分
 *
 * 注意：
 * 因为可能有0.0000这种情况，对小数点后的0进行处理后，要把e的值改回0  测试点6
 *
 * */

string deal(string s, int & e, const int n)
{
    int i = 0;
    string res;
    while(s.size()>0 and s[0] == '0')   s.erase(s.begin());
    if(s[0] == '.')
    {
        s.erase(s.begin());
        while(s.size() > 0 and s[0] == '0')
        {
            s.erase(s.begin());
            e--;
        }
    }
    else
    {
        while(i < s.size() and s[i] != '.')
        {
            i++;
            e++;
        }
        if(s[i] == '.') s.erase(s.begin() + i);
    }

    if(s.size() == 0)
        e = 0;

    /*if(s.size() == 0)
    {
        res += '0';
    }
    else
    {
        for(int j = 0;j < n;++j)
        {
            if(j < s.size())
                res += s[j];
            else
                res += '0';
        }
    }*/

    for(int j = 0;j < n;++j)
    {
        if(j < s.size())
            res += s[j];
        else
            res += '0';
    }
    return res;
}


int main()
{
    int e1 = 0, e2 = 0, n;
    string s1, s2;
    string s3, s4;
    cin >> n >> s1 >> s2;

    s3 = deal(s1, e1, n);
    s4 = deal(s2, e2, n);

    if(s3 == s4 and e1 == e2)
    {
        cout << "YES 0." << s3<< "*10^" << e1 << endl;
    }
    else
    {
        cout << "NO 0." << s3<< "*10^" << e1 << " 0."<< s4 << "*10^" << e2 << endl;
    }
    return 0;

}




