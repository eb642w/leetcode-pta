#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> hash;

        for(auto it = strs.begin();it != strs.end();++it)
        {
            string s = *it;
            sort(s.begin(),s.end());
            if(hash.count(s))
                ans[hash[s]].push_back((*it));
            else
            {
                ans.push_back(vector<string>());
                ans.back().push_back((*it));
                hash[s] = (int)ans.size()-1;
            }
        }
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}