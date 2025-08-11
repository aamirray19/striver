#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size();
        if (n==1) return 1;

        int i = 0;
        int j = 0;

        while(i < n)
        {
            char c = chars[i];
            int cnt = 0;

            //appending the consecutive characters 
            while (i < n && chars[i] == c)
            {
                i++;
                cnt++;
            }

            chars[j++] = c;

            if (cnt > 1)
            {
                string s = to_string(cnt);
                for (char c : s)
                {
                    chars[j++] = c;
                }
            }
        }
        return j;
    }
};