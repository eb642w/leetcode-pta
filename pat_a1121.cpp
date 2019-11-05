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