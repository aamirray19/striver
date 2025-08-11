#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(int ind, int target, vector<int>& candidates, vector<int>& ans, vector<vector<int>>& allsum)
    {
        int n = candidates.size();
        //base case
        if (ind == n)
        {
            if (target == 0)
            {
                allsum.push_back(ans);
            }
            return;
        }

        if (candidates[ind] <= target)
        {
            //pick element
            ans.push_back(candidates[ind]);
            helper(ind, target - candidates[ind], candidates, ans, allsum);
            ans.pop_back();
        }
        helper(ind + 1, target, candidates, ans, allsum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> ans;
        vector<vector<int>> allsum;
        helper(0, target, candidates, ans, allsum);
        return allsum;
    }
};