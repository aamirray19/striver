#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char> mp;
        unordered_map<char, char> rev_mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) == mp.end() && rev_mp.find(t[i]) == rev_mp.end())
            {
                mp[s[i]] = t[i];
                rev_mp[t[i]] = s[i];
            }
            else
            {
                if (mp[s[i]] != t[i] || rev_mp[t[i]] != s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};