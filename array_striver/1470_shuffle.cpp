#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> result;
        int l = 0;
        int r = n;
        
        while (r < nums.size())
        {
            result.push_back(nums[l]);
            l++;
            result.push_back(nums[r]);
            r++;
        }
        return result;
    }
};