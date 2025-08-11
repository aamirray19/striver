#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive helper function to explore all expressions
    void helper(int ind, string num, long long target, string expr, long long eval, long long prev, vector<string>& ans) {
        // Base case: if we've processed the entire number string
        if (ind == num.size()) {
            // If the current expression evaluates to the target, add it to the answer
            if (eval == target) {
                ans.push_back(expr);
            }
            return;
        }

        // Try all possible splits of the number string starting at index 'ind'
        for (int i = ind; i < num.size(); i++) {
            // Skip numbers with leading zeros (e.g., "05", "00")
            if (i != ind && num[ind] == '0') break;

            // Extract substring from index 'ind' to 'i'
            string currStr = num.substr(ind, i - ind + 1);

            // Convert substring to number
            long long curr = stoll(currStr);

            if (ind == 0) {
                // First number: don't add an operator before it
                helper(i + 1, num, target, currStr, curr, curr, ans);
            } else {
                // ADDITION
                helper(i + 1, num, target, expr + '+' + currStr, eval + curr, curr, ans);

                // SUBTRACTION
                helper(i + 1, num, target, expr + '-' + currStr, eval - curr, -curr, ans);

                // MULTIPLICATION
                // Trick: back out the last operand, and replace it with (prev * curr)
                helper(i + 1, num, target, expr + '*' + currStr, eval - prev + prev * curr, prev * curr, ans);
            }
        }
    }

    // Main function
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(0, num, target, "", 0, 0, ans);
        return ans;
    }
};

