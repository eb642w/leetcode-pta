#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>

#define MAX 300

using namespace std;


class UnionFind
{
public:
    UnionFind(int n)
    {
        parents = vector<int>(n+1, 0);
        ranks = vector<int>(n+1, 0);

        for(int i = 0;i < parents.size();++i)
        {
            parents[i] = i;
        }
    }

    int UFind(int id)
    {
        if(id != parents[id])
            parents[id] = UFind(parents[id]);
        return parents[id];
    }

    bool Union(int m, int n)//合并两个
    {
        int pm = UFind(m);
        int pn = UFind(n);

        if(pm == pn)
            return false;

        if(ranks[pm] > ranks[pn])
            parents[pn] = pm;
        else if(ranks[pn] > ranks[pm])
            parents[pm] = pn;
        else
        {
            parents[pm] = pn;
            ranks[pn]++;
        }
        return true;
    }

private:
    vector<int> parents;
    vector<int> ranks;
};


class Solution
{
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFind s(n);
        for(int i = 0;i < n;++i)
        {
            for(int j = i+1;j < n;++j)
            {
                if(M[i][j])
                    s.Union(i,j);
            }
        }
        set<int> a;
        for(int i = 0;i < n;++i)
        {
            a.insert(s.UFind(i));
        }
        return a.size();
    }
};

int main()
{

    return 0;
}

