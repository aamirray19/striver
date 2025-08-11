#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(int ind, int k, int n, vector<int>& ans, vector<vector<int>>& allsum)
    {
        if (ans.size() == k)
        {
            if (accumulate(ans.begin(), ans.end(), 0) == n)
            {
                allsum.push_back(ans);
            }
            return;
        }

        for (int i = ind; i <= 9; i++)
        {
            ans.push_back(i);
            helper(i + 1, k, n, ans, allsum);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> ans; 
        vector<vector<int>> allsum;
        helper(1, k, n, ans, allsum);
        return allsum;
    }
};