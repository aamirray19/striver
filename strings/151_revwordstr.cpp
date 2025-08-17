#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        
        // Step 1: Extract words and skip extra spaces
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }

        // Push the last word if not empty
        if (!word.empty()) {
            words.push_back(word);
        }

        // Step 2: Reverse the vector of words
        reverse(words.begin(), words.end());

        // Step 3: Join them into a single string
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        return result;
    }
};
