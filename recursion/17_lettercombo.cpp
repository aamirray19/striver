#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int ind, string& digits, string curr_str, vector<string>& ans, map<char, string>& keyboard) 
    {
        // Base case
        if (curr_str.length() == digits.length()) {
            ans.push_back(curr_str);
            return;
        }

        char digit = digits[ind];
        string letters = keyboard[digit];

        for (char ch : letters) 
        {
            helper(ind + 1, digits, curr_str + ch, ans, keyboard); 
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty()) return {};
        map<char, string> keyboard = 
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans; 
        helper(0, digits, "", ans, keyboard); 
        return ans;
    }
};
