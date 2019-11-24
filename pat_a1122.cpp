#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>

#define MAX 300

using namespace std;


int main()
{
    int e[MAX][MAX]{0};
    int n, m;
    int a, b;
    int k;
    cin >> n >>m;
    for(int i = 0;i < m;++i)
    {
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    cin >> k;
    for(int i = 0;i < k;++i)
    {
        bool flag = true;
        cin >> a;
        if(a == n+1)
        {
            int start;
            cin >> start;
            map<int, int> mp;
            for(int j = 1;j < a;++j)
            {
                cin >> b;

                mp[b]++;
                if(mp[b]>1) flag = false;
                if(e[start][b] != 1)
                    flag = false;
                start = b;
            }
        }
        else{
            for(int j = 0;j < a;++j)
            {
                cin >> b;
            }
            flag = false;
        }
        if(!flag)
            cout << "NO" << endl;
        else
            cout <<"YES"<<endl;
    }
    return 0;
}


