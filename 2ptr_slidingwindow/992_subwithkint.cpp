#include <bits/stdc++.h>
using namespace std;

// brute force 
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            map<int, int> mp;
            for (int j = i; j < n; j++)
            {
                mp[nums[j]]++;
                if (mp.size() == k)
                {
                    cnt++;
                }
            }
        }
        return cnt; 
    }
};

//optimal
class Solution {
public:

    int solve(vector<int>& nums, int k)
    {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int cnt = 0;
        map<int, int> mp;

        while (r < n)
        {
            mp[nums[r]]++;
            while (mp.size() > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return solve(nums, k) - solve(nums, k-1);
    }
};