#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binary_search(int num)
    {
        int start = 0;
        int end = num;
        long long square;
        int ans;

        while (start <= end)
        {
            long long mid = start + (end-start)/2;
            square = mid * mid;

            if (square == num)
            {
                return mid;
            }
            else if(square < num)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    };

    int mySqrt(int x) 
    {
        return binary_search(x);
    }
};