#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxlen = 0;
        vector<int> hash(256, -1); 

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxlen = max(len, maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};

/*in this we use the sliding window tech where
1) we declare the reqd variables
2) create a hash vector where every letter whether caps or small is storen in ascii
3) now as r < n if the value is not empty in hash and 
4) then in this we check            
if (hash[s[r]] >= l) {
l = hash[s[r]] + 1;
where the repeating char was found and then we update the window 1 space ahead of the repeat char                   
5) then we update max len and r and return the maxlen value*/