#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
#define MAX 10001
int seqA[MAX], seqB[MAX];
int text[MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;++i)
    {
        cin >> seqA[i] >> seqB[i];
    }
    int k;
    cin >> k;
    set<int> vexSet;
    for(int i = 0;i < k;++i)
    {
        bool flag = true;
        vexSet.clear();
        for(int j = 0;j < n;++j)
        {
            cin >> text[j];
            vexSet.insert(text[j]);
        }
        for(int j = 0;j < m;++j)
        {
            if(text[seqA[j]] == text[seqB[j]])
            {
                flag = false;
                break;
            }
        }
        if(!flag)
            cout << "No\n";
        else{
            cout << vexSet.size() << "-coloring\n";
        }
    }
}
