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
 * Recommendation system predicts the preference that a user would give to an item. Now you are asked to program a very simple recommendation system that rates the user's preference by the number of times that an item has been accessed by this user.

Input Specification:
Each input file contains one test case. For each test case, the first line contains two positive integers: N (≤ 50,000), the total number of queries, and K (≤ 10), the maximum number of recommendations the system must show to the user. Then given in the second line are the indices of items that the user is accessing -- for the sake of simplicity, all the items are indexed from 1 to N. All the numbers in a line are separated by a space.

Output Specification:
For each case, process the queries one by one. Output the recommendations for each query in a line in the format:

query: rec[1] rec[2] ... rec[K]
where query is the item that the user is accessing, and rec[i] (i=1, ... K) is the i-th item that the system recommends to the user. The first K items that have been accessed most frequently are supposed to be recommended in non-increasing order of their frequencies. If there is a tie, the items will be ordered by their indices in increasing order.

Note: there is no output for the first item since it is impossible to give any recommendation at the time. It is guaranteed to have the output for at least one query.
 * */

/*
 * 解题思路：
 * STL练习
 * 主要是按这次输入的前一次进行排序，用set重新定义< 即可自动排序
 * 注意的点是按观看次数多少降序，按编号升序
 *
 * 合理利用find begin erase auto
 *
 * */

struct recommend
{
    int totalWatch;
    int n;
    friend bool operator < (recommend a1, recommend a2)
    {
        return (a1.totalWatch == a2.totalWatch )? (a1.n < a2.n):(a1.totalWatch > a2.totalWatch);
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    int recod[50001]{0};
    set<recommend> list;
    recommend tmp={1,1};
    cin >> tmp.n;
    list.insert(tmp);
    recod[tmp.n]++;
    for(int i = 2;i <= n;++i)
    {
        cin >> tmp.n;
        cout << tmp.n << ":";
        int j = 0;
        for(auto it = list.begin(); it != list.end() and j < k;it++)
        {
            cout<<" "<<it->n;
            ++j;
        }
        cout<<endl;
        auto it = list.find(recommend{recod[tmp.n],tmp.n});
        if(it != list.end())    list.erase(it);
        recod[tmp.n]++;
        list.insert(recommend{recod[tmp.n],tmp.n});
    }
}