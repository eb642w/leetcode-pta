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

struct node {
    int id, people;
    double num, area;
    bool flag = false;
}ans[10000];

struct fam
{
    int id;
    int f_id;
    int m_id;
    int k;
    int esat_num, area;
    int c_id[10];
}data[1001];

struct out
{
    double area;
    double num;
    int id;
    int people;
    int pri_id;
    friend bool operator < (out a1, out a2)
    {
        if(a1.area == a2.area)
            return a1.id > a2.id;
        else
            return a1.area < a2.area;

    }
};

class UnionFindSet
{
public:
    UnionFindSet(int n)
    {
        parents = vector<int>(n+1, 0);
        ranks = vector<int>(n+1, 0);

        for(int i = 0;i < parents.size();++i)
        {
            parents[i] = i;
        }
    }

    int UnionFind(int x)
    {
        //printf("%d", x);
        //printf("%d", parents[x]);
        if(x != parents[x])
            parents[x] = UnionFind(parents[x]);
        return parents[x];
    }

    bool Union(int m, int n)
    {
        int pm = UnionFind(m);
        int pn = UnionFind(n);

        if(pm == pn)    return false;
        if(ranks[pm]>ranks[pn]) parents[pn] = pm;
        else if(ranks[pn] > ranks[pm])  parents[pm] = pn;
        else
        {
            parents[pn] = pm;
            ranks[pm]++;
        }
        return true;
    }


    vector<int> parents;
    vector<int> ranks;
};

int main()
{
    int n;
    cin >> n;
    UnionFindSet s(10000);
    bool visit[10000];
    int cnt = 0;
    //cout << s.parents[8888];
    for(int i = 0;i < n;++i)
    {
        int k;

        cin >> data[i].id >> data[i].f_id >> data[i].m_id >> k;
        visit[data[i].id] = true;

        if(data[i].f_id != -1)
        {
            visit[data[i].f_id] = true;
            s.Union(data[i].f_id,data[i].id);

        }
        if(data[i].m_id != -1)
        {
            visit[data[i].m_id] = true;
            s.Union(data[i].m_id,data[i].id);
        }
        for(int j = 0;j < k;++j)
        {
            cin >> data[i].c_id[j];
            visit[data[i].c_id[j]] = true;
            s.Union(data[i].id,data[i].c_id[j]);
        }
        cin >> data[i].esat_num >> data[i].area;
    }

    for(int i = 0;i < n;++i)
    {
        int id = s.UnionFind(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].esat_num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }

    for(int i = 0;i < 10000;++i)
    {
        if(visit[i])
        {
            int id = s.UnionFind(i);
            ans[id].people++;

        }

        if(ans[i].flag)
            cnt++;
    }


    out a1;
    priority_queue<out> to_out, real_to_out;

    for(int i = 0;i < 10000;++i)
    {
        if(ans[i].flag)
        {
            ans[i].num = (double)ans[i].num * 1.0 / ans[i].people;
            ans[i].area = (double)ans[i].area * 1.0 / ans[i].people;
            a1.area = ans[i].area;
            a1.people = ans[i].people;
            a1.num = ans[i].num;
            a1.id = ans[i].id;
            a1.pri_id = a1.id;
            to_out.push(a1);
        }
    }
    cout << cnt << endl;



    for(int i = 0;i < cnt;++i)
    {
        a1 = to_out.top();
        to_out.pop();
        for(int j = 0;j < 10000;++j)
        {
            if(visit[j])
            {
                if(a1.pri_id == s.UnionFind(j))
                {
                    if(a1.id > j)
                        a1.id = j;
                }
            }
        }
        real_to_out.push(a1);
    }

    for(int i = 0;i < cnt;++i)
    {
        a1 = real_to_out.top();
        real_to_out.pop();

        printf("%04d %d %.3f %.3f\n", a1.id, a1.people, a1.num, a1.area);
    }

    return 0;
}

