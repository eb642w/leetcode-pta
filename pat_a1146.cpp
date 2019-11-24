#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>
#include <queue>
#define MAX 300

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int degree[n+1]{0};
    int degree1[n+1]{0};
    int start, ennd;
    vector<int> G[1010];
    vector<int> e[1010];
    for(int i = 0;i < m;++i)
    {
        cin >> start >> ennd;
        G[start].push_back(ennd);
        e[start].push_back(ennd);
        degree[ennd]++;
        degree1[ennd]++;
    }
    int k;
    cin >> k;
    bool flag = false;
    vector<int> out;
    for(int i = 0;i < k;++i)
    {
        for(int j = 1;j < n+1;++j)
        {
            for(int l = 0;l < e[j].size();++l)
            {
                G[j][l] = e[j][l];
            }
        }
        for(int j = 0;j < n+1;++j)
        {
            degree[j] = degree1[j];
        }
        for(int j = 0;j < n;++j)
        {
            int V;
            cin >> V;
            if(degree[V] != 0)
            {
                flag = true;
            }

            else
            {
                for(int l = 0;l < G[V].size();++l)
                {
                    degree[G[V][l]]--;
                }
            }
        }
        if(flag)
        {
            out.push_back(i);
        }
        flag = false;
    }

    for(int i = 0;i < out.size();++i)
    {
        if(i)
            cout << " " << out[i];
        else
            cout << out[i];
    }
    return 0;

}

