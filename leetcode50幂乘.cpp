#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0)
        {
            x = 1/x;
            N = -N;
        }
        double cur = x;
        double ans = 1;
        for(auto i = N; i ;i/=2)
        {
            if(i%2)
                ans *= cur;
            cur = cur * cur;
        }
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}