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
    int nv, ne;

    cin >> nv >> ne;
    int G[nv+1][nv+1]{0};
    int a, b;
    for(int i = 0;i < ne;++i)
    {
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    int m;
    cin >> m;
    for(int i = 0;i < m;++i)
    {
        int k;
        bool is_clique = true;
        bool is_max_clique = true;
        cin >> k;
        vector<int> clique(k);
        vector<bool> inCli(k, false);
        for(int j = 0;j < k;++j)
        {
            cin >> clique[j];
            inCli[clique[j]] = true;
        }

        for(int j = 0;j < k;++j)
        {
            for(int q = j+1;q < k ;++q)
            {
                if(!G[clique[j]][clique[q]])
                {
                    //cout
                    is_clique = false;
                    break;
                }
                    //²»ÊÇclique
            }
        }
        if(!is_clique)
        {
            cout <<"Not a Clique\n";
            continue;
        }


        for(int j = 1;j <= nv;++j)
        {
            if(!inCli[j])
            {
                int q;
                for(q = 0;q < k;++q)
                {
                    if(G[j][clique[q]] == 0)
                    {
                        break;
                    }
                }
                if(q == k)
                    is_max_clique = false;

            }
        }

        if(!is_max_clique)
        {
            cout << "Not Maximal\n";
        }
        else{
            cout << "Yes\n";
        }
    }
}
