#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high)
        {
            int mid = (low+high)/2;
            if(nums[mid] > nums[high])
                low = mid+1;
            else
                high = mid;
        }
        int changePoint = low;
        low = 0;
        high = nums.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            int realMid = (mid+changePoint)%nums.size();
            if(nums[realMid] == target)
                return realMid;
            else if(nums[realMid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }

};

int main()
{
    vector<int> nums={4,5,6,7,0,1,2};
    int target = 3;
    Solution a;
    cout << a.search(nums, target);
    return 0;
}


