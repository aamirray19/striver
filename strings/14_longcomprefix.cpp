#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        // If the input vector is empty, return an empty string
        if (strs.empty()) return "";

        // Start with the first string as the initial prefix
        string prefix = strs[0];
        int prefix_len = prefix.length();  // Keep track of the current prefix length

        // Loop through all the remaining strings in the vector
        for (int i = 1; i < strs.size(); i++)
        {
            string s = strs[i];  // Current string to compare

            // While the current prefix is either longer than the string
            // OR the prefix does not match the beginning of the string
            while (prefix_len > s.length() || prefix != s.substr(0, prefix_len))
            {
                // Reduce the prefix length by 1 (trim from the end)
                prefix_len--;

                // If the prefix is reduced to zero, return empty string
                if (prefix_len == 0)
                {
                    return "";
                }

                // Update the prefix to the shortened version
                prefix = prefix.substr(0, prefix_len);
            }

            // After the while loop, we have a valid prefix match with current string
            // Continue to the next string
        }

        // After checking all strings, return the final common prefix
        return prefix;
    }
};


// Initial prefix = "flower" (from strs[0])
// Compare with "flow":
//     - "flower" != "flow" → trim to "flow"
//     - Now matches → move to next

// Compare with "flight":
//     - "flow" != "flig" → trim to "flo"
//     - "flo" != "fli" → trim to "fl"
//     - "fl" == "fl" → match

// Final prefix: "fl"
