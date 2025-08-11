#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(int ind, string s, vector<string>& path, vector<vector<string>>& res)
    {
        //base case
        if (ind == s.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = ind; i <= s.size(); i++)
        {
            if (ispalindrome(s, ind, i))
            {
                path.push_back(s.substr(ind, i - ind + 1));
                helper(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool ispalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> path;
        helper(0, s, path, res);
        return res;
    }
}; 