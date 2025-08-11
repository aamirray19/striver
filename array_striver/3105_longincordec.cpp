#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        if (nums.size() == 1) return 1;
        int l = 0;
        int r = 0;
        int maxlen1 = 0;
        int maxlen2 = 0;
        int cnt = 1;
        int n = nums.size() - 1;

        while (r < n)
        {
            if (nums[r] < nums[r+1])
            {
                cnt += 1;
            }
            else 
            {
                cnt = 1;
                l++;
            }
            maxlen1 = max(maxlen1, cnt);
            r++;
        }

        l = 0;
        r = 0;
        cnt = 1;
        while (r < n)
        {
            if (nums[r] > nums[r+1])
            {
                cnt += 1;
            }
            else
            {
                cnt = 1;
                l++;
            }
            maxlen2 = max(maxlen2, cnt);
            r++;
        }

        int total = max(maxlen1, maxlen2);
        return total;
    }
};