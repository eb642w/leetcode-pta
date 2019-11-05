#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;++i)
    {
        int m;
        cin >> m;
        vector<int> input;
        int tmp;
        bool flag = true;
        for(int j = 0;j < m;++j)
        {
            cin >> tmp;
            input.push_back(tmp);
        }
        for(int j = 0;j < m; ++j)
        {
            for(int k = j+1; k < m;++k)
            {
                if(abs(k - j) == abs(input[k]- input[j]) or input[k] == input[j])
                {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(flag)
            cout << "YES" <<endl;
    }
    return 0;
}