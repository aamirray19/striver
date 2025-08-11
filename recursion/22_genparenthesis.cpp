#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(int open, int close, vector<string>& result, int n, string curr_str) {
        // Base case
        if (curr_str.length() == n * 2) 
        {
            result.push_back(curr_str);
            return;
        }

        // Add an open parenthesis 
        if (open < n) helper(open + 1, close, result, n, curr_str + "(");
        
        // Add a close parenthesis 
        if (close < open) helper(open, close + 1, result, n, curr_str + ")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0, 0, ans, n, "");
        return ans;
    }
};