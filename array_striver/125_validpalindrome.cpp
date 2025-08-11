#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string remvchar(string s) 
    {
        string word;
        for (char c : s) 
        {
            if (isalnum(c)) 
            { 
                word += tolower(c);
            }
        }
        return word;
    }

    bool isPalindrome(string s) {
        string full_word = remvchar(s);
        string reversed_word = full_word;  
        reverse(reversed_word.begin(), reversed_word.end());  

        return full_word == reversed_word;  
    }
};