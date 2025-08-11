#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int ind, vector<int>& nums, vector<int>& ans, vector<vector<int>>& allsubsets) {
        int n = nums.size();
        if (ind == n) {
            allsubsets.push_back(ans);
            return;
        }

        // Pick the current element
        ans.push_back(nums[ind]);
        helper(ind + 1, nums, ans, allsubsets);

        // Do not pick the current element
        ans.pop_back();
        helper(ind + 1, nums, ans, allsubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allsubsets;
        helper(0, nums, ans, allsubsets);
        return allsubsets;
    }
};