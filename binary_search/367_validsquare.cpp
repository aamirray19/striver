#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool binary_search(int num)
    {
        int start = 0;
        int end = num;

        while (start <= end)
        {
            long long mid = start + (end-start)/2;

            if (mid*mid == num)
            {
                return true;
            }
            else if (mid*mid > num)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }

    bool isPerfectSquare(int num) 
    {
        return binary_search(num);
    }
};