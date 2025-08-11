#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int result = 0;   //will store the max freq
        long long total = 0;    //will give total sum of the window
        int n = nums.size();
        while (r < n)
        {
            total += nums[r];
            while ((long long)nums[r] * (r - l + 1) > total + k)
            {
                total -= nums[l];
                l++;
            }
            result = max(result, r - l + 1);
            r++;
        }
        return result;
    }
};