#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValid(string s) 
        {
            stack<char> st;  // Stack to store opening brackets
            int idx = 0;     // Index to iterate through string
    
            while (idx < s.size())
            {
                // If current character is a closing bracket
                if (s[idx] == ')')
                {
                    // Check if stack is empty or top is not matching opening bracket
                    if (st.empty()) return false;
                    else if (st.top() == '(') st.pop();  // Correct match, pop it
                    else return false;
                }
                else if (s[idx] == ']')
                {
                    if (st.empty()) return false;
                    else if (st.top() == '[') st.pop();
                    else return false;
                }
                else if (s[idx] == '}')
                {
                    if (st.empty()) return false;
                    else if (st.top() == '{') st.pop();
                    else return false;
                }
                else
                {
                    // If it's an opening bracket, push onto the stack
                    st.push(s[idx]);
                }
                idx++;
            }
    
            // If stack is empty, all brackets matched
            return st.empty();
        }
    };
    