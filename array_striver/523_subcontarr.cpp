#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        mp[0] = -1;  // Important: handles subarrays starting at index 0
        int prefixsum = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            prefixsum = (prefixsum + nums[i]);
            if (k != 0) prefixsum %= k;

            if (mp.find(prefixsum) != mp.end()) {
                if (i - mp[prefixsum] >= 2) return true;
            } else {
                mp[prefixsum] = i;  // only set the first occurrence
            }
        }
        return false;
    }
};
