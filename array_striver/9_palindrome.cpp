#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int revint (int x)
    {
        int rev = 0;
        while (x > 0)
        {
            int digit = x % 10;
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
            {
                return 0;
            }
            rev = rev * 10 + digit;
            x = x / 10;
        }
        return rev;
    }

    bool isPalindrome(int x) 
    {
        int revnum = revint(x);
        if (x == revnum) return true;
        return false;
    }
};