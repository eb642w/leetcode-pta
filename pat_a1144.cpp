#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>

#define MAX 520

using namespace std;

int main()
{
    int n, num1;

    set<int> the_set;

    cin >> n;
    for(int i = 0;i < n;++i)
    {
        cin >> num1;
        if(num1 > 0)
        {
            the_set.insert(num1);
        }
    }
    int num = 1;
    bool flag = false;
    for(auto it = the_set.begin();it != the_set.end();it++)
    {
        if(*it == num)   num++;
        else if(*it < num)   continue;
        else    break;
    }
    cout << num;
    return 0;
}
