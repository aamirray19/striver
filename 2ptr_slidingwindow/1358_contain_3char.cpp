#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, n = s.length();
        int count = 0;
        vector<int> lastSeen(3, -1); // Vector to track the last seen positions of 'a', 'b', and 'c'
        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                // Find the minimum index among the last seen positions of 'a', 'b', and 'c'
                int minLastSeen = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
                count += minLastSeen + 1;
            }
        }
        return count;
    }
};