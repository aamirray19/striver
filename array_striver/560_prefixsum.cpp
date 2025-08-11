#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixsum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixsum += nums[i];
            int remove = prefixsum - k;
            cnt += mp[remove];
            mp[prefixsum] += 1;
        }
        return cnt;
    }
};