/*
最短路径问题，多练几次！！！


*/

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>

#define MAX 520

using namespace std;

int G[MAX][MAX], weight[MAX], d[MAX],w[MAX],num[MAX];//weight[]是顶点的点权，w[]是出发点到目的地的点权之和
bool e[MAX] = {false};

void dijkstja(int cur_city, int n)
{
    for(int i = 0;i < n;++i)
    {
        int u = -1;
        int minn = INT_MAX;
        for(int j = 0;j < n;++j)
        {
            if(e[j] == false and d[j] < minn)
            {
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) return;
        e[u] = true;
        for(int v = 0;v < n;++v)
        {
            if(e[v] == false and G[u][v] != INT_MAX)
            {
                if(G[u][v] + d[u] < d[v])
                {
                    d[v] = G[u][v] + d[u];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }
                else if(G[u][v] + d[u] == d[v])
                {
                    num[v] = num[u] + num[v];
                    if(w[u] + weight[v] > w[v])
                        w[v] = weight[v] + w[u];
                }
            }
        }
    }
    return;
}



int main()
{

    int num_city,num_road,cur_city,pur_city;
    cin >> num_city >> num_road >> cur_city >> pur_city;
    fill(G[0],G[0] + MAX * MAX,INT_MAX);
    fill(d,d + MAX,INT_MAX);
    d[cur_city] = 0;
    for(int i = 0;i < num_city;++i)
    {
        cin >> weight[i];
    }
    w[cur_city] = weight[cur_city];
    num[cur_city] = 1;
    for(int i = 0;i < num_road;++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = G[b][a] = c;
    }
    dijkstja(cur_city, num_city);
    cout << num[pur_city] << " " << w[pur_city];

    return 0;
}

