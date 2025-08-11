#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int ind, int target, vector<int>& candidates, vector<int>& ans, vector<vector<int>>& allsum) {
        int n = candidates.size();

        if (target == 0) {
            allsum.push_back(ans);
            return;
        }

        for (int i = ind; i < n; ++i) {
            // Skip duplicates
            if (i > ind && candidates[i] == candidates[i - 1]) continue;

            // If the current candidate is greater than the target, no point in continuing
            if (candidates[i] > target) break;

            // Pick 
            ans.push_back(candidates[i]);
            helper(i + 1, target - candidates[i], candidates, ans, allsum);  
            ans.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int> ans;
        vector<vector<int>> allsum;
        helper(0, target, candidates, ans, allsum);
        return allsum;
    }
};
