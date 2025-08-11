#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:

    bool isBadVersion(int version);
   
    int binary_search(int n)
    {
        if (n == 1) return 1;
        int start = 1;
        int end = n;

        while (start <= end)
        {
            int mid = start + (end-start)/2;
            bool target = isBadVersion(mid);

            if (target == true)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }

    int firstBadVersion(int n) 
    {
        return binary_search(n);
    }
};