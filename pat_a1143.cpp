#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <limits>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 102

using namespace std;



int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> preorder;
    preorder.resize(n);
    map<int, bool> preMap;
    for(int i = 0;i < n;++i)
    {
        cin >> preorder[i];
        preMap[preorder[i]] = true;

    }
    int u, v;
    for(int i = 0;i < m;++i)
    {
        cin >> u >> v;
        if(preMap[u] and !preMap[v])
        {
            cout <<"ERROR: "<< v <<" is not found.\n";
            continue;
        }
        else if(!preMap[u] and preMap[v])
        {
            cout <<"ERROR: "<< u <<" is not found.\n";
            continue;
        }
        else if(!preMap[u] and !preMap[v])
        {
            cout <<"ERROR: "<< u <<" and "<< v <<" are not found.\n";
            continue;
        }

        for(int j = 0;j < n;++j)
        {
            int ansce = preorder[j];
            if((ansce >= u and ansce <= v) or (ansce <= u and ansce >= v))
            {
                if(ansce == u)
                    cout << u <<" is an ancestor of " <<v <<".\n";
                else if(ansce == v)
                    cout << v <<" is an ancestor of " <<u <<".\n";
                else
                    cout <<"LCA of "<< u << " and " << v <<" is "<<ansce<<".\n";
                break;
            }
        }
    }
    return 0;
}


