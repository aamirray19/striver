#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), ans=0;
        for(char c='A'; c<='Z'; c++){
            int i=0, j=0, count=0;
            while(j<n){
                if(s[j]!=c){
                    count++;
                }
                while(count>k){
                    ans=max(ans,j-i);
                    if(s[i]!=c) count--;
                    i++;
                }
                j++;
            }
            ans=max(ans,j-i);
        }

        return ans;
    }
};

/*Check for all the characters from c='A' to c='Z', since we're given that all characters would be uppercase. 
Then check for the longest substring one could make for every particular character, 
keeping the check for current count for replacement, using two pointers.
Keep updating answer for when count>k*/