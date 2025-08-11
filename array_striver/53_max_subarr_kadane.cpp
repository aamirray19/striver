#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxi = INT16_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];

            if (sum > maxi)
            {
                maxi = sum;
            }

            if (sum < 0)
            {
                sum = 0;         //kadane algo
            }
        }
        return maxi;
    }
};