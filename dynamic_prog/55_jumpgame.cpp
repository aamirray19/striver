#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > reachable) return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        if (n == 1) return true;  // you’re already at the goal

        vector<bool> dp(n, false); 
        dp[n - 1] = true;  // you can always reach the end from the end

        for (int i = n - 2; i >= 0; i--) {
            int maxJump = min(i + nums[i], n - 1);
            for (int j = i + 1; j <= maxJump; j++) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];  
    }
};
