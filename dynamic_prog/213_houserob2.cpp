#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

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
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++)
        {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n-1) temp2.push_back(nums[i]);
        }

        return max(tabrob(temp1), tabrob(temp2));
    }
};