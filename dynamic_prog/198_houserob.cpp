#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int recrob(vector<int>& nums, int n)
    {
        // base case
        if (n < 0)
        {
            return 0;
        }

        if (n == 0)
        {
            return nums[0];
        }

        int incl = recrob(nums, n-2) + nums[n];
        int excl = recrob(nums, n-1) + 0;

        return max(incl, excl);
    }

    int memrob(vector<int>& nums, int n, vector<int>& dp)
    {
        // base case
        if (n < 0)
        {
            return 0;
        }

        if (n == 0)
        {
            return nums[0];
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int incl = memrob(nums, n-2, dp) + nums[n];
        int excl = memrob(nums, n-1, dp) + 0;

        dp[n] = max(incl, excl);
        return dp[n];
    }

    int tabrob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) return 0; // Handle edge case: empty array
        if (n == 1) return nums[0]; // Handle edge case: single element

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int incl = nums[i];
            if (i > 1) incl += dp[i - 2]; // Only add dp[i-2] if i > 1
            int excl = dp[i - 1];
            dp[i] = max(incl, excl);
        }

        return dp[n - 1];
    }
    
    int rob(vector<int>& nums) 
    {
        return tabrob(nums);
    }
};