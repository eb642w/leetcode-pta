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

int G_dis[MAX][MAX],G_time[MAX][MAX], dis[MAX],time[MAX],num[MAX];
int dis_pre[MAX], time_pre[MAX];
bool visit[MAX] = {false};
vector <int> dis_path, time_path, tmp_path;

void fin_dis(int s, int source)
{
    dis_path.push_back(s);
    if(source == s) return;
    fin_dis(dis_pre[s], source);
}

void fin_time(int s, int source)
{
    time_path.push_back(s);
    if(source == s) return;
    fin_time(time_pre[s], source);
}



int main()
{
    int n, m, source, des;
    int inf = INT_MAX;
    cin >> n >> m;
    int a, b, flag, d, t;
    fill(G_dis[0],G_dis[0] + MAX * MAX, inf);
    fill(G_time[0],G_time[0] + MAX * MAX, inf);
    fill(time, time + MAX, 100);
    fill(dis, dis+MAX, inf);

    for(int i = 0;i < m;++i)
    {
        cin >> a >> b >> flag >> d >> t;
        G_dis[a][b] = d;
        G_time[a][b] =t;
        if(flag)
        {
            G_dis[b][a] = d;
            G_time[b][a] = t;
        }
    }
    cin >> source >> des;

    for(int i = 0;i < n;++i)
    {
        time[i] = dis_pre[i] = i;
    }

    dis[source] = 0;
    for(int i = 0;i < n;++i)
    {
        int u = -1, minn = inf;
        for(int j = 0;j < n;++j)
        {
            if(visit[j] == false and dis[j] < minn)
            {
                minn = dis[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        visit[u] = true;
        for(int v = 0;v < n;++v)
        {
            if(visit[v] == false and G_dis[u][v] != inf)
            {
                if(G_dis[u][v] + dis[u] < dis[v])
                {
                    dis[v] = G_dis[u][v] + dis[u];
                    dis_pre[v] = u;
                    time[v] = time[u] + G_time[u][v];
                }
                else if(G_time[u][v] + time[v] < time[u] and G_dis[u][v] + dis[u] == dis[v])
                {
                    dis[v] = G_dis[u][v] + dis[u];
                    dis_pre[v] = u;
                }
            }
        }
    }
    fin_dis(des, source);
    fill(visit,visit + MAX,false);
    fill(time,time + MAX, inf);
    fill(num, num + MAX, 0);
    time[source] = 0;
    for(int i = 0;i < n;++i)
    {
        int u = -1, minn = inf;
        for(int j = 0;j < n;++j)
        {
            if(visit[j] == false and time[j] < minn)
            {
                u = j;
                minn = time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0;v < n;++v)
        {
            if(visit[v] == false and G_time[u][v] < inf)
            {
                if(G_time[u][v] + time[u] < time[v])
                {
                    time[v] = time[u] + G_time[u][v];
                    num[v] = num[u] + 1;
                    time_pre[v] = u;
                }
                else if(G_time[u][v] + time[u] == time[v]){
                    if(num[u] + 1 < num[v])
                    {
                        num[v] = num[u] + 1;
                        time_pre[v] = u;
                    }
                }
            }
        }
    }
    fin_time(des, source);
    if(dis_path == time_path)
    {
        cout << "Distance = " << dis[des] << "; Time = " << time[des] << ": ";
        for(int i = time_path.size() - 1;i >= 0;--i)
        {
            cout << time_path[i];
            if(i)
                cout << " -> ";
        }
    }
    else{
        cout << "Distance = " << dis[des] << ": ";
        for(int i = dis_path.size() - 1;i >= 0;--i)
        {
            cout << dis_path[i];
            if(i)
                cout << " -> ";
            else
                cout << endl;
        }
        cout  << "Time = " << time[des] << ": ";
        for(int i = time_path.size() - 1;i >= 0;--i)
        {
            cout << time_path[i];
            if(i)
                cout << " -> ";
        }
    }
    return 0;

}



