#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(int ind, vector<int>& nums, vector<int>& ans, vector<vector<int>>& allsubsets)
    {
        int n = nums.size();
        allsubsets.push_back(ans);
        for (int i = ind; i < n; i++)
        {
            if (i != ind && nums[i] == nums[i-1]) continue;
            ans.push_back(nums[i]);
            helper(i + 1, nums, ans, allsubsets);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> allsubsets;
        helper(0, nums, ans, allsubsets);
        return allsubsets;
    }
};