#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>
#include <queue>
#include <algorithm>

#define MAX 300

using namespace std;
class UnionFindSet{
public:
    UnionFindSet(int n)
    {
        parents = vector<int>(n+1, 0);
        ranks = vector<int>(n+1, 0);
        for(int i = 0;i <= n;++i)
        {
            parents[i] = i;
        }
    }

    int UFind(int id)
    {
        if(id != parents[id])
        {
            parents[id] = UFind(parents[id]);
        }
        return parents[id];
    }

    bool Union(int m, int n)
    {
        int pm = UFind(m);
        int pn = UFind(n);

        if(pm == pn)
            return false;

        if(ranks[pm] > ranks[pn])
            parents[pn] = pm;
        else if(ranks[pn] > ranks[pm])
            parents[pm] = pn;
        else{
            parents[pn] = pm;
            ranks[pm]++;
        }
        return true;
    }
private:
    vector<int> parents;
    vector<int> ranks;
};


class Solution {
public:
    bool similar(const string a, const string b)
    {
        int count = 0;
        for(int i = 0;i < a.size();++i)
        {
            if(a[i]!= b[i])
                count++;
            if(count>2)
                return false;
        }
        if(count == 2 or count == 0)
            return true;
        return false;
    }


    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        UnionFindSet s(n);
        for(int i = 0;i < n;++i)
        {
            for(int j = i+1;j < n;++j)
            {
                if(similar(A[i], A[j]))
                {
                    s.Union(i,j);
                }
            }
        }

        set<int> a;
        for(int i = 0;i < n;++i)
        {
            a.insert(s.UFind(i));
        }
        return (int)a.size();
    }
};

int main()
{
    return 0;
}
