#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
/*
 * "Damn Single (单身狗)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), the total number of couples.
 Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999).
 After the list of couples, there is a positive integer M (≤ 10,000) followed by M ID's of the party guests.
 The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.

Output Specification:
First print in a line the total number of lonely guests. Then in the next line, print their ID's in increasing order.
 The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.
 *
 * */

/*
 * 如果使用映射的话会超时，对于较多的数据量时，暴力搜索就会超时TLE O(m*n)
 * 使用字符串2字符串的映射的,效率就是O(m)
 * */

int main()
{
    int n;
    cin >> n;
    map<string, string> cou_given;
    string a, b;
    for(int i = 0;i < n;++i)
    {
        cin >> a >> b;
        cou_given[a] = b;
        cou_given[b] = a;
    }

    int m;
    cin >> m;
    string int_tmp;
    set<string> to_out;
    vector<string> out;
    for(int i = 0;i < m;++i) {
        bool flag = false;
        cin >> int_tmp;
        if(cou_given[int_tmp].empty())
            out.push_back(int_tmp);
        else
            to_out.insert(int_tmp);
    }
    for(auto it = to_out.begin();it != to_out.end(); it++)
    {
        if(to_out.find(cou_given[*it]) == to_out.end())
            out.push_back(*it);
    }
    sort(out.begin(),out.end());
    cout << out.size() << endl;

    for(int i = 0;i < out.size();++i)
    {
        if(i == 0)
        {
            cout << out[i];
        }
        else
            cout << ' '<< out[i];
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
