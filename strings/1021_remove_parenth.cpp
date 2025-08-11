#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int n = s.size();
        int cnt = 0;
        string ans;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                cnt++;
                if (cnt != 1)
                {
                    ans.push_back(s[i]);
                }
            }
            if (s[i] == ')')
            {
                cnt--;
                if (cnt != 0)
                {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};