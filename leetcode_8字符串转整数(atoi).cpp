#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:

    int myAtoi(string str)
    {
        //if(str == NULL)   return 0;
        int i = 0;
        bool isNegative = false;
        int res = 0;
        while(str[i] == ' ') {i++;}
        if(str[i] == '-')
        {
            isNegative = true;
        }else if(str[i] == '+')
        {

        }
        else if(isdigit(str[i]))
        {
            i--;
        }
        else
        {
            return 0;
        }
        i++;
        for(;i < str.size();++i)
        {
            int r = str[i] - '0';
            if(!isdigit(str[i]))
            {
                break;
            }
            else
            {
                if(res > INT_MAX/10 or (res == INT_MAX and r > 7))
                {
                    res = isNegative ? INT_MIN : INT_MAX;
                    return res;
                }
            }
            res = res * 10 + r;
        }
        return isNegative ? -res: res;
    }
};