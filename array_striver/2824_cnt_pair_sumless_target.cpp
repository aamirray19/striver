#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) 
    {
        int cnt = 0;
        int n = nums.size();

        for (int l = 0; l < n; l++)
        {
            for (int r = l + 1; r < n; r++)
            {
                int sum = nums[l] + nums[r];
                if (sum < target)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};