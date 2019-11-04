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

string deal(string s, int & e, const int n)
{
    int i = 0;
    string res;
    while(s.size()>0 and s[0] == '0')   s.erase(s.begin());
    if(s[0] == '.')
    {
        s.erase(s.begin());
        while(s.size()>0 and s[0] == '0')
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





/*给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 用队列？

 从头开始，一个一个匹配
 1.字符不一样，继续
 2.字符一样或者'.' 进行匹配
    2.1

 * */

class Solution {
public:
    bool isMatch(string s, string p) {
        bool mathching = false;
        if(s.empty()) return true;
        else if(p.empty()) return false;
        int i = 0;

        for(;i < p.size();++i)
        {
            auto c = p[i];
            if(c == s[0] or c == '.')
            {
                mathching = !mathching;
            }
            else
                continue;
        }

    }



};

/*
class Solution
{
public:

    int myAtoi(string str)
    {
        //if(str == NULL)   return 0;
        int i = 0;
        bool isNegative = false;
        int res = 0;
        while(str[i] == ' ') {i++;}
        if(str[i] == '-')
        {
            isNegative = true;
        }else if(str[i] == '+')
        {

        }
        else if(isdigit(str[i]))
        {
            i--;
        }
        else
        {
            return 0;
        }
        i++;
        for(;i < str.size();++i)
        {
            int r = str[i] - '0';
            if(!isdigit(str[i]))
            {
                break;
            }
            else
            {
                if(res > INT_MAX/10 or (res == INT_MAX and r > 7))
                {
                    res = isNegative ? INT_MIN : INT_MAX;
                    return res;
                }
            }
            res = res * 10 + r;
        }
        return isNegative ? -res: res;
    }
};

int main()
{
    string str = "-2147483648";

    Solution a;

    cout<<a.myAtoi(str)<<endl;
}
*/
/*
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        vector<string> row(min(numRows,int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for(char c : s)
        {
            row[curRow]+=c;
            if(curRow == 0 or curRow == numRows - 1)goingDown = !goingDown;

            curRow += goingDown ? 1 : -1;

        }
        string res;
        for(string r : row)res += r;
        return res;

    }
};


int main() {
    Solution b;
    cout<<b.convert("leetcode",3)<<endl;
    return 0;
}
*/
